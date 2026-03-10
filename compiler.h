#ifndef COMPILER_H
#define COMPILER_H


typedef enum {
    T_NONE, T_INT, T_REAL, T_STRING, T_BOOL, T_CLASS, T_UNDEF = -1
} variable_type;

typedef union {
    int ival;
    double rval;
    char* sval;
} value_type;

typedef enum{MUL_OP, DIV_OP, PLUS_OP, MINUS_OP, EQ_OP, NEQ_OP, LT_OP, BG_OP, GTE_OP, GT_OP, LTE_OP }op_type;

typedef union YYSTYPE YYSTYPE;

// Add extern declarations for shared variables
extern int error_count;
extern int yylineno;
extern int column;
extern int error_count;
extern FILE* lst_file;
extern FILE* asm_file;


void yyerror(const char* s);
int yylex(void);
void emit(const char* format, ...);
void lst_emit(const char* format, ...);

#endif /* COMPILER_H */