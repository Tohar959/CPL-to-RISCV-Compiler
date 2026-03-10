%{
#include <stdio.h>
#include <string.h>
#include "compiler.h"
#include "symbolTable.h"
#include "parser.tab.h"

extern int yylineno;
extern int error_count;
extern FILE* lst_file;

int line_num = 1;
int column = 0;

void count_column() { column += yyleng; }
void count_line() { line_num++; column = 0; }

%}

%option noyywrap
%x comment
DIGIT    [0-9]
LETTER   [a-zA-Z]
ID       {LETTER}({LETTER}|{DIGIT})*
NUM      {DIGIT}+(\.{DIGIT}*)?
WHITESPACE [ \t]+

%%

"/*" 		BEGIN(comment);
<comment>[^*]*

<comment>"*/" BEGIN(0);

"//"            { /* Single-line comment */
                  int c;
                  while ((c = input()) != '\n' && c != 0) {
                      /* Consume until end of line */
                  }
                  if (c == '\n') {
                      unput(c); /* Put back the newline to be handled below */
                  }
                }


"break"         { count_column(); return BREAK; }
"case"          { count_column(); return CASE; }
"class"         { count_column(); return CLASS; }
"const"         { count_column(); return CONST; }
"default"       { count_column(); return DEFAULT; }
"else"          { count_column(); return ELSE; }
"end"           { count_column(); return END; }
"foreach"       { count_column(); return FOREACH; }
"if"            { count_column(); return IF; }
"int"           { count_column(); return INT_TYPE; }
"not"           { count_column(); return NOT; }
"read"          { count_column(); return READ; }
"real"          { count_column(); return REAL_TYPE; }
"send"          { count_column(); return SEND; }
"start"         { count_column(); return START; }
"out"        	{ count_column(); return OUT; }
"string"        { count_column(); return STRING_TYPE; }
"switch"        { count_column(); return SWITCH; }
"then"          { count_column(); return THEN; }
"till"          { count_column(); return TILL; }
"var"           { count_column(); return VAR; }
"while"         { count_column(); return WHILE; }
"with"          { count_column(); return WITH; }
"write"         { count_column(); return WRITE; }

"=="            { count_column(); yylval.op = EQ_OP; return RELOP; }
"<>"            { count_column(); yylval.op = NEQ_OP; return RELOP; }
"<"             { count_column(); yylval.op = LT_OP; return RELOP; }
">"             { count_column(); yylval.op = GT_OP; return RELOP; }
">="            { count_column(); yylval.op = GTE_OP; return RELOP; }
"<="            { count_column(); yylval.op = LTE_OP; return RELOP; }
"="             { count_column(); return ASSIGNOP; }
"+"             { count_column(); yylval.op = PLUS_OP; return ADDOP; }
"-"             { count_column(); yylval.op = MINUS_OP; return ADDOP; }
"*"             { count_column(); yylval.op = MUL_OP; return MULOP; }
"/"             { count_column(); yylval.op = DIV_OP; return MULOP; }
"||"            { count_column(); return OROP; }
"&&"            { count_column(); return ANDOP; }
"("             { count_column(); return LPAREN; }
")"             { count_column(); return RPAREN; }
"{"             { count_column(); return LBRACE; }
"}"             { count_column(); return RBRACE; }
":"             { count_column(); return COLON; }
";"             { count_column(); return SEMICOLON; }
","             { count_column(); return COMMA; }

{ID}            { 
    count_column();
    if (strlen(yytext) > 9) {
        fprintf(stderr, "LEXICAL ERROR at line %d: Identifier too long\n", line_num);
        if (lst_file) fprintf(lst_file, "LEXICAL ERROR at line %d: Identifier too long\n", line_num);
        error_count++;
    }
    yylval.values.name = strdup(yytext);
    if (!yylval.values.name) {
        yyerror("Memory allocation failed for identifier");
        error_count++;
    }
    return ID;
}

{NUM}           {
    count_column();
    yylval.values.type = T_INT;
    if (strchr(yytext, '.')) {
        yylval.values.type = T_REAL;
        yylval.values.value.rval = atof(yytext);
    } else {
        yylval.values.value.ival = atoi(yytext);
    }
    return NUM;
}

\"([^\"\n]|\\\")*\"    { 
    count_column();
    yylval.values.type = T_STRING;
    char *str = strdup(yytext+1);
    str[strlen(str)-1] = '\0';
    yylval.values.value.sval = str;
    return SENTENCE;
}

\n              { count_line(); yylineno = line_num; } 
{WHITESPACE}    { count_column(); }

.               { 
    fprintf(stderr, "LEXICAL ERROR at line %d: Invalid character '%s'\n", line_num, yytext);
    if (lst_file) fprintf(lst_file, "LEXICAL ERROR at line %d: Invalid character '%s'\n", line_num, yytext);
    count_column();
    error_count++;
}

%%