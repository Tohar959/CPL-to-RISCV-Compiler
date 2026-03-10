%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <strings.h> 
#include "compiler.h"
#include "symbolTable.h"

const char* type_to_string(variable_type type) {
    switch(type) {
        case T_INT: return "INT";
        case T_REAL: return "REAL";
        case T_STRING: return "STRING";
        case T_NONE: return "NONE";
        default: return "UNKNOWN";
    }
}
//Global variables
symbolTable* my_symbolTable = NULL;
char error_msg[256];
int label_counter = 0;
int label ;
int float_reg = 0;
int float_const_counter = 0;
int error_count = 0;
int string_counter = 0;
int stack_offset = 0;
extern int column;
FILE* asm_file = NULL;
FILE* lst_file = NULL;
extern FILE* yyin, *lst_file, *asm_file;
extern int yylineno, error_count;
char* input_filename = NULL;

// Function declarations
void error_recovery();
void yyerror(const char *s);
int yylex(void);
void emit(const char *format, ...);
void lst_emit(const char *format, ...);
void add_variable(const char *name, variable_type type);
void add_constant(const char *name, variable_type type, int ival, double rval);
void print_stamp(FILE* stream);

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d, column %d: %s\n", yylineno, column, s);
    if (lst_file) {
        fprintf(lst_file, "Error at line %d, column %d: %s\n", yylineno, column, s);
        fflush(lst_file);
    }
    memset(error_msg, 0, 256);
    error_count++;
}
%}

%define parse.error verbose
%union {
    struct {
        variable_type type;
        value_type value;
        char *name;
        int offset;
    } values;
    op_type op;
}

%token PROGRAM CLASS START END VAR CONST INT_TYPE REAL_TYPE STRING_TYPE
%token IF THEN ELSE WHILE FOREACH WITH SWITCH CASE DEFAULT BREAK
%token READ OUT WRITE SSTART SEND TILL NOT
%token LT GT EQ NEQ LTE GTE
%token PLUS MINUS MUL DIV
%token ASSIGNOP OROP ANDOP
%token LPAREN RPAREN LBRACE RBRACE COMMA SEMICOLON COLON BANG
%token STEP

%token <op> ADDOP MULOP RELOP

// Type declarations
%type <values> program declarations declarList decl list type
%type <values> stmt_list stmt assignment_stmt control_stmt out_stmt in_stmt
%type <values> switch_stmt cases  
%type <values> stmt_block 
%type <values> bool_expr bool_term bool_factor expression term factor
%token <values> NUM ID SENTENCE
%type <values> step cdecl

// Operator precedence and associativity
%left OROP
%left ANDOP
%left EQ NEQ
%left LT GT LTE GTE
%left PLUS MINUS
%left MUL DIV
%right NOT
%right ASSIGNOP
%start program

%%

program: CLASS ID START {
        // Initialize both data and text sections
        if (error_count == 0) {
            emit(".data");
            emit("prompt:  .string \"Enter value: \"");
            emit("newline: .string \"\\n\"");
        }
    }
    declarations stmt_list END {
        // Only generate exit if no errors
        if (error_count == 0) {
            emit("    # Program exit");
            emit("    li a7, 10");
            emit("    ecall");
        }
    }
    ;

declarations: VAR declarList cdecl{ $$ = $2; }
            | { $$.type = T_NONE; }
            ;

declarList: declarList decl { $$ = $2; }
         | decl { $$ = $1; }
         ;

decl: type COLON list SEMICOLON {
        $$.type = $1.type;
        $3.type = $1.type;
    }
    | error SEMICOLON {
        error_recovery();
        $$.type = T_NONE;
    }
    ;

list: list COMMA ID {
        variable_type current_type = $1.type;
        symbol_node *existing = lookup(my_symbolTable, $3.name);
        if (existing) {
			sprintf(error_msg,"Variable already declared %s",$3.name);
            yyerror(error_msg);
            YYERROR;
        }
        
        symbol_node *node = enter(my_symbolTable, $3.name, current_type, false);
        if (!node) {
			sprintf(error_msg,"Failed to add variable to symbol table %s",$3.name);
            yyerror(error_msg);
            YYERROR;
        }
        
        node->attri->offset = stack_offset;
        stack_offset += (current_type == T_REAL) ? 8 : 4;
        
        switch(current_type) {
            case T_REAL:
                emit("%s: .float 0.0", $3.name);
                break;
            case T_INT:
                emit("%s: .word 0", $3.name);
                break;
            case T_STRING:
                emit("%s: .space 256", $3.name); // Allocate 256 bytes for strings
                break;
            default:
                yyerror("Unsupported variable type");
                YYERROR;
        }
        
        $$.type = current_type;
    }
    | ID {
        variable_type current_type = $<values>-1.type;
        symbol_node *existing = lookup_symbol(my_symbolTable, $1.name);
        if (existing) {
			sprintf(error_msg,"Variable %s already declared ",$1.name);
            yyerror(error_msg);
            YYERROR;

        }
        symbol_node *node = enter(my_symbolTable, $1.name, current_type, false);
        if (!node) {
            yyerror("Failed to add variable to symbol table");
            YYERROR;
        }
        
        node->attri->offset = stack_offset;
        stack_offset += (current_type == T_REAL) ? 8 : 4;
        
        switch(current_type) {
            case T_REAL:
                emit("%s: .float 0.0", $1.name);
                break;
            case T_INT:
                emit("%s: .word 0", $1.name);
                break;
            case T_STRING:
                emit("%s: .string \"\"", $1.name);
                break;
            default:
                yyerror("Unsupported variable type");
                YYERROR;
				break;
        }
        
        $$.type = current_type;	
    }
	;
type: INT_TYPE { 
        $$.type = T_INT;
        $$.value.ival = 0;
    }
    | REAL_TYPE { 
        $$.type = T_REAL;
        $$.value.rval = 0.0;
    }
    | STRING_TYPE { 
        $$.type = T_STRING;
        $$.value.sval = NULL;
    }
    ;

cdecl: CONST type ID ASSIGNOP NUM SEMICOLON cdecl {
        variable_type current_type = $2.type;

        // Type checking for constant assignment
        if (current_type != $5.type && !(current_type == T_REAL && $5.type == T_INT)) {
            yyerror("Type mismatch in constant declaration");
            YYERROR;
        }

        // Insert into the symbol table as a constant
        symbol_node *node = enter(my_symbolTable, $3.name, current_type, true);
        if (!node) {
            yyerror("Failed to add constant to symbol table");
            YYERROR;
        }

        // Store value based on type
        if (current_type == T_INT) {
            emit("%s: .word %d", $3.name, $5.value.ival);
            node->attri->value.ival = $5.value.ival;
        } else if (current_type == T_REAL) {
            emit("%s: .float %f", $3.name, $5.value.rval);
            node->attri->value.rval = $5.value.rval;
        }
		
    }
    |{$$.type = T_NONE; emit(".text");  }
	;
			 

stmt_list: stmt_list stmt { $$ = $2; }
         | {}
         ;

stmt: assignment_stmt { $$ = $1; }
	|ID ASSIGNOP SENTENCE 
	{
		symbol_node *entry = lookup(my_symbolTable, $1.name);
		if(!entry )
		{
			yyerror("ID is not declered");
            YYERROR;

		}
		else if(entry->attri->constant == true)
		{
			yyerror("Can't assign into consant variable");
            YYERROR;

		}
        else if (entry->attri->type != T_STRING) {
            yyerror("String assignment to non-string variable");
            YYERROR;

        }
		else{
			emit("%s: .string \"%s\"", $1.name, $3.value.sval);
			$$.type = T_STRING;
		}
	}
    | control_stmt { $$ = $1; }
    | out_stmt { $$ = $1; }
    | in_stmt { $$ = $1; }
    | stmt_block { $$ = $1; }
    ;
	
out_stmt: WRITE LPAREN expression RPAREN SEMICOLON {
            if ($3.type == T_STRING) {
                emit("# Printing string variable");
                emit("    la a0, %s", $3.name);
                emit("    li a7, 4");
                emit("    ecall");
            } else if ($3.type == T_INT) {
                emit("# Printing integer variable");
                emit("    lw a0, %s", $3.name);
                emit("    li a7, 1");
                emit("    ecall");
            } else if ($3.type == T_REAL) {
                emit("# Printing float variable");
				emit("    la t0, %s", $3.name);
                emit("    flw fa0, 0(t0)"); 
                emit("    li a7, 2");
                emit("    ecall");
            }
            // Add newline after output
            emit("    la a0, newline");
            emit("    li a7, 4");
            emit("    ecall");
        }
    | WRITE LPAREN SENTENCE RPAREN SEMICOLON {
            emit(".data");
            emit("str_%d: .string \"%s\"", string_counter, $3.value.sval);
            emit(".text");
            emit("    la a0, str_%d", string_counter);
            emit("    li a7, 4");
            emit("    ecall");
            // Add newline
            emit("    la a0, newline");
            emit("    li a7, 4");
            emit("    ecall");
            string_counter++;
        }
    ;


in_stmt: READ LPAREN ID RPAREN SEMICOLON {
    symbol_node *sym = lookup(my_symbolTable, $3.name);
    if (!sym || sym->attri->type == T_NONE)
	{
        yyerror("Undeclared or invalidly typed variable");
        YYERROR;
		}
    
    if (sym->attri->constant) {
        yyerror("Cannot read into constant");
        YYERROR;
    }

    emit("#print the enter msg");
    emit("    la a0, prompt");
    emit("    li a7, 4");
    emit("    ecall");

    if (sym->attri->type == T_INT) {
        emit("    li a7, 5");
        emit("    ecall");
        emit("    la t0, %s", $3.name);
        emit("    sw a0, 0(t0)"); 
    } else if (sym->attri->type == T_REAL) {
        emit("    li a7, 6");
        emit("    ecall");
        emit("    la t0, %s", $3.name);
        emit("    fsw fa0, 0(t0)"); 
    }
    $$.type = sym->attri->type;
}
;

assignment_stmt: ID ASSIGNOP expression SEMICOLON {
    symbol_node *entry = lookup(my_symbolTable, $1.name);
    if (!entry) {
        yyerror("Undeclared variable");
        YYERROR;
    }
    if (entry->attri->constant) {
        yyerror("Cannot assign into a constant variable");
        YYERROR;
    }
    if (entry->attri->type == T_REAL) {
        if ($3.type == T_INT) {
            emit("    fcvt.s.w fa1, a0"); 
            emit("    la t0, %s", $1.name);
            emit("    fsw fa1, 0(t0)");    
        } else {
            emit("    la t0, %s", $1.name);
            emit("    fsw fa0, 0(t0)");
        }
    } else {
        emit("    la t0, %s", $1.name);
        emit("    sw a0, 0(t0)");
    }
    $$.type = $3.type;
}
| ID ASSIGNOP SENTENCE SEMICOLON 
{
    symbol_node *entry = lookup(my_symbolTable, $1.name);
    if (!entry || entry->attri->type != T_STRING) {
        yyerror("String assignment to non-string variable");
        YYERROR;
    }

    emit("#Insert to new msg into the string variable");
    emit(".data");
    emit("msg_%d: .string \"%s\"\n .text", string_counter, $3.value.sval);

    emit("    la t0, msg_%d", string_counter);
    emit("    la t1, %s", $1.name);
    emit("    sw t0, 0(t1)");

    $$.type = T_STRING;
    string_counter++;
}

;


control_stmt:IF LPAREN bool_expr RPAREN THEN {
        label = label_counter++;
        emit("    beqz a0, else_%d", label);  
    } 
    stmt {                                   
        emit("    j endif_%d", label);       
        emit("else_%d:", label);             
    } 
    ELSE stmt {                              
        emit("endif_%d:", label);            
        $$.type = T_NONE;
    }
    | WHILE {
        label = label_counter++;
        emit("while_%d:", label);            
    } 
    LPAREN bool_expr RPAREN {
        emit("    beqz a0, endwhile_%d", label);  
    } 
    stmt_block {
        emit("    j while_%d", label);      
        emit("endwhile_%d:", label);         
        $$.type = T_NONE;
    }
    | FOREACH ID ASSIGNOP NUM TILL NUM {
        label = label_counter++;
        symbol_node *entry = lookup(my_symbolTable, $2.name);
        if (!entry) {
            entry = enter(my_symbolTable, $2.name, T_INT, false);
            if (!entry) {
                yyerror("Failed to create loop variable");
                YYERROR;
            }
        }
        
        
        emit("    # Initialize loop variable %s", $2.name);
        emit("    li t0, %d", $4.value.ival);
        emit("    la t1, %s", $2.name);
        emit("    sw t0, 0(t1)");
        
        
        emit("loop_%d:", label);
        
        
        emit("    # Check loop condition");
        emit("    lw t0, %s", $2.name);
        emit("    li t1, %d", $6.value.ival);
        emit("    bgt t0, t1, endloop_%d", label);
    }
    WITH step stmt {
        emit("    # Loop increment and continuation");
        emit("    j loop_%d", label);
        emit("endloop_%d:", label);
        $$.type = T_NONE;
    }
    | FOREACH ID ASSIGNOP NUM TILL ID {
        label = label_counter++;
        symbol_node *entry = lookup(my_symbolTable, $2.name);
        symbol_node *end_var = lookup(my_symbolTable, $6.name);
        
        if (!entry) {
            entry = enter(my_symbolTable, $2.name, T_INT, false);
            if (!entry) {
                yyerror("Failed to create loop variable");
                YYERROR;
            }
        }
        if (!end_var) {
            yyerror("Undeclared end variable in foreach loop");
            YYERROR;
        }
        
        
        emit("    # Initialize loop variable %s", $2.name);
        emit("    li t0, %d", $4.value.ival);
        emit("    la t1, %s", $2.name);
        emit("    sw t0, 0(t1)");
        
       
        emit("loop_%d:", label);
        
       
        emit("    # Check loop condition");
        emit("    lw t0, %s", $2.name);
        emit("    lw t1, %s", $6.name);
        emit("    bgt t0, t1, endloop_%d", label);
    }
    WITH step stmt {
        emit("    # Loop increment and continuation");
        emit("    j loop_%d", label);
        emit("endloop_%d:", label);
        $$.type = T_NONE;
    }
    | switch_stmt { $$ = $1; }
    ;

stmt_block: LBRACE stmt_list RBRACE { $$ = $2; }
          ;
			
switch_stmt: SWITCH LPAREN ID RPAREN SSTART cases SEND {
    emit("switch_start:");
    emit("    lw t1, %s", $3.name);  
    emit("    # Jump to appropriate case");
    $$.type = T_NONE;
}
;

cases: CASE NUM COLON stmt_list BREAK SEMICOLON cases {
        int label = label_counter++;
        emit("case_%d:", label);
        emit("    li t0, %d", $2.value.ival);
        emit("    bne t1, t0, case_%d", label + 1);
       
        emit("    j end_switch");
        $$.type = T_NONE;
    }
    | DEFAULT COLON stmt_list {
        emit("default_case:");
        $$.type = T_NONE;
    }
    ;

step: ID ASSIGNOP ID ADDOP NUM {
		if ($4 == PLUS_OP) {
			emit("#add by %d", $5.value.ival);
			emit("    lw t0, %s", $1.name);
			emit("    addi t0, t0, %d", $5.value.ival);
			emit("    la t1, %s", $1.name);
			emit("    sw t0, 0(t1)");
		} else if ($4 == MINUS_OP) {
			emit("#sub by %d", $5.value.ival);
			emit("    lw t0, %s", $1.name);
			emit("    addi t0, t0, %d", -$5.value.ival);
			emit("    la t1, %s", $1.name);
			emit("    sw t0, 0(t1)");
		}
	}
	| ID ASSIGNOP ID MULOP NUM {
		if ($4 == MUL_OP) {
			emit("#Mul by %d", $5.value.ival);
			emit("    lw t0, %s", $1.name);
			emit("    li t1, %d", $5.value.ival); 
			emit("    mul t0, t0, t1");
			emit("    la t2, %s", $1.name);
			emit("    sw t0, 0(t2)");
		} else if ($4 == DIV_OP) {
			if ($5.value.ival == 0) {
				yyerror("Can't divid by zero!");
				YYERROR;
			} else {
				emit("Div by %d", $5.value.ival);
				emit("    lw t0, %s", $1.name);
				emit("    li t1, %d", $5.value.ival); 
				emit("    div t0, t0, t1");
				emit("    la t2, %s", $1.name);
				emit("    sw t0, 0(t2)");
			}
		}
	}
    ;


bool_expr: bool_expr OROP bool_term { 
              if ($1.type != T_INT || $3.type != T_INT) {
                  yyerror("Operands must be integers in boolean expression");
                  YYERROR;

              }
			  emit("    mv a1, a0");
              emit("    or a0, a1, a0");
              $$.type = T_INT;
          }
         | bool_term { $$ = $1; }
         ;

bool_term: bool_term ANDOP bool_factor {
              if ($1.type != T_INT || $3.type != T_INT) {
                  yyerror("Operands must be integers in boolean expression");
                  YYERROR;

              }
			  emit("    mv a1, a0");
              emit("    and a0, a1, a0");;
              $$.type = T_INT;
          }
         | bool_factor { $$ = $1; }
         ;

bool_factor: NOT LPAREN bool_factor RPAREN {
                if ($3.type != T_INT) {
                    yyerror("Operand must be integer in boolean expression");
                    YYERROR;
                }
                emit("    seqz a0, a0");  
                $$.type = T_INT;
            }
            | expression RELOP expression {
                 if ($1.type != $3.type) {
                    yyerror("Type mismatch in comparison");
                    YYERROR;
                }

                if ($1.type == T_REAL) {
                    emit("    la t0, %s", $1.name);
                    emit("    flw fa0, 0(t0)");
                    emit("    la t0, %s", $3.name);
                    emit("    flw fa1, 0(t0)");
                    
                  
                    switch ($2) {
                        case LT_OP: 
                            emit("    flt.s a0, fa0, fa1"); 
                            break;
                        case GT_OP: 
                            emit("    flt.s a0, fa1, fa0"); 
                            break;
                        case EQ_OP: 
                            emit("    feq.s a0, fa0, fa1"); 
                            break;
                        case NEQ_OP:
                            emit("    feq.s a0, fa0, fa1");
                            emit("    xori a0, a0, 1");
                            break;
                        case LTE_OP: 
                            emit("    fle.s a0, fa0, fa1"); 
                            break;
                        case GTE_OP: 
                            emit("    fle.s a0, fa1, fa0"); 
                            break;
                    }
                } else {
                    
                    emit("    la t0, %s", $1.name);
                    emit("    lw a1, 0(t0)");
                    emit("    la t0, %s", $3.name);
                    emit("    lw a0, 0(t0)");
                    
                    switch ($2) {
                        case LT_OP: 
                            emit("    slt a0, a1, a0"); 
                            break;
                        case GT_OP: 
                            emit("    slt a0, a0, a1"); 
                            break;
                        case EQ_OP:
                            emit("    xor a0, a1, a0");
                            emit("    seqz a0, a0");
                            break;
                        case NEQ_OP:
                            emit("    xor a0, a1, a0");
                            emit("    snez a0, a0");
                            break;
                        case LTE_OP:
                            emit("    slt a0, a0, a1");  
                            emit("    xori a0, a0, 1");  
                            break;
                        case GTE_OP:
                            emit("    slt a0, a1, a0");  
                            emit("    xori a0, a0, 1"); 
                            break;
                    }
                }
                $$.type = T_INT;
            }
            | LPAREN bool_expr RPAREN { $$ = $2; }
            ;


expression: expression ADDOP term {
    if ($1.type == T_INT) {
        emit("    mv a1, a0");      
        emit("    la t0, %s", $3.name);  
        emit("    lw a0, 0(t0)");   
        if ($2 == PLUS_OP)
            emit("    add a0, a1, a0");
        else
            emit("    sub a0, a1, a0");   
    } else {
        emit("    fmv.s fa1, fa0");   
        emit("    la t0, %s", $3.name);  
        emit("    flw fa0, 0(t0)"); 
        if ($2 == PLUS_OP)
            emit("    fadd.s fa0, fa1, fa0");
        else
            emit("    fsub.s fa0, fa1, fa0");
    }
    $$ = $1;
	}
           | term { $$ = $1; }
           ;


term: term MULOP factor {
         if ($1.type != $3.type) {
             yyerror("Type mismatch in term");
             YYERROR;

         }
    if ($1.type == T_INT) {
        emit("    mv a1, a0");       
        emit("    la t0, %s", $3.name);  
        emit("    lw a2, 0(t0)");   
        if ($2 == MUL_OP) {
            emit("    mul a0, a1, a2");
        } else {
            emit("    div a0, a1, a2");
        }
			}
	else {
		emit("    la t0, %s", $1.name);
        emit("    flw fa0, %s", $1.name);   
        emit("    la t0, %s", $3.name);  
        emit("    flw fa1, 0(t0)"); 
		if ($2 == MUL_OP) {
			emit("    fmul.s fa0, fa0, fa1");
		} else {
			emit("    fdiv.s fa0, fa0, fa1");
		}
    }
    $$ = $1;
}

    | factor { $$ = $1; }
    ;

factor: LPAREN expression RPAREN { $$ = $2; }
      | ID { 
          symbol_node *sym = lookup(my_symbolTable, $1.name);
          if (!sym) {
              yyerror("Undeclared variable");
			  yyerror($1.name);
              YYERROR;

			  
          }
          $$.type = sym->attri->type;
          switch (sym->attri->type) {
              case T_INT:
                  emit("    la t0, %s", $1.name); 
                  emit("    lw a0, 0(t0)");
                  break;
              case T_REAL:
                  emit("    la t0, %s", $1.name);
                  emit("    flw fa0, 0(t0)" );
                  break;
              case T_STRING:
                  emit("    la a0, %s", $1.name); 
                  break;
              default:
                  yyerror("Unsupported variable type in factor:ID");
                  YYERROR;
          }

        }
      | NUM { 
          $$.type = $1.type;
          if ($1.type == T_INT) {
              emit("    li a0, %d", $1.value.ival);
          } else if ($1.type == T_REAL) {
				emit("    .data");
				emit("    .align 2");
				emit("float_const_%d: .float %f", float_const_counter, $1.value.rval);
				emit("    .text");
				emit("    la t0, float_const_%d", float_const_counter);
				emit("    flw fa0, 0(t0)");
				float_const_counter++;
          } else {
              yyerror("Unsupported number type");
			  
              YYERROR;
			 
          }
        }
      ;

%% 

void print_stamp(FILE* stream) {
    fprintf(stream, "# Compiled by: [Tohar Hermon and Omer Zoran]\n");
    fprintf(stream, "# Student ID: [315816819, 207769761]\n");
    fprintf(stream, "# Date: [29.03.2025]\n\n");
}

void emit(const char *format, ...) {
    va_list args;
    va_start(args, format);
 
    if (asm_file && error_count == 0) {
        vfprintf(asm_file, format, args);
        fprintf(asm_file, "\n");
    }
    
    va_end(args);
}

void lst_emit(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    if (lst_file) {
        vfprintf(lst_file, format, args);
        fprintf(lst_file, "\n");
    }
    
    va_end(args);
}

void add_variable(const char *name, variable_type type) {
    symbol_node *values = enter(my_symbolTable, (char*)name, type, false);
    if (!values) {
        yyerror("Failed to add variable to symbol table");

    }
}

void add_constant(const char *name, variable_type type, int ival, double rval) {
    symbol_node *values = enter(my_symbolTable, (char*)name, type, true);
    if (!values) {
        yyerror("Failed to add constant to symbol table");
        error_count++;
		error_recovery();
    } else {
        if (type == T_INT) {
            values->attri->value.ival = ival;
        } else if (type == T_REAL) {
            values->attri->value.rval = rval;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.cpl>\n", argv[0]);
        return 1;
    }

    char *ext = strrchr(argv[1], '.');
    if (!ext || (strcasecmp(ext, ".cpl") != 0)) {
        fprintf(stderr, "Error: Input file must have .cpl extension\n");
        return 1;
    }

    input_filename = argv[1];
    
    // Create output filenames
    char base_filename[256];
    strncpy(base_filename, argv[1], ext - argv[1]);
    base_filename[ext - argv[1]] = '\0';
    
    char lst_filename[256];
    strcpy(lst_filename, base_filename);
    strcat(lst_filename, ".lst");
    
    char asm_filename[256];
    strcpy(asm_filename, base_filename);
    strcat(asm_filename, ".s");

    // Open input file
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Error: Could not open input file %s\n", argv[1]);
        return 1;
    }

    // Open listing file
    lst_file = fopen(lst_filename, "w");
    if (!lst_file) {
        fprintf(stderr, "Error: Could not create listing file\n");
        fclose(yyin);
        return 1;
    }

    // Open assembly file
    asm_file = fopen(asm_filename, "w");
    if (!asm_file) {
        fprintf(stderr, "Error: Could not create assembly file\n");
        fclose(lst_file);
        fclose(yyin);
        return 1;
    }

    // Print stamps to all outputs
    print_stamp(stderr);
    print_stamp(lst_file);
    print_stamp(asm_file);

    rewind(yyin);
    char line[1024];
    int current_line = 1;
    while (fgets(line, sizeof(line), yyin)) {
        line[strcspn(line, "\n")] = '\0';
        fprintf(lst_file, "%4d: %s\n", current_line, line);
        current_line++;
    }
    rewind(yyin);

    fprintf(lst_file, "\n=== Compilation Messages ===\n");

    // Initialize symbol table and parse
    my_symbolTable = createTable();
    yyparse();
    
    fprintf(lst_file, "\n=== Compilation Summary ===\n");
    if (error_count == 0) {
        fprintf(lst_file, "Compilation successful - 0 errors\n");
        fprintf(lst_file, "Output file generated: %s\n", asm_filename);
    } else {
        fprintf(lst_file, "Compilation failed - %d error%s found\n", 
               error_count, error_count == 1 ? "" : "s");
        if (error_count > 0) {
            remove(asm_filename);  
            fprintf(lst_file, "No valid assembly file generated due to errors\n");
        }
    }

    // Cleanup
    if (asm_file) fclose(asm_file);
    if (lst_file) fclose(lst_file);
    if (yyin) fclose(yyin);
    if (my_symbolTable) destroyTable(my_symbolTable);
    
    return error_count ? 1 : 0;
}

void error_recovery()
{
	int yyerrstatus = 0;
	yyclearin;
	yyerrok;
}