/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PROGRAM = 258,                 /* PROGRAM  */
    CLASS = 259,                   /* CLASS  */
    START = 260,                   /* START  */
    END = 261,                     /* END  */
    VAR = 262,                     /* VAR  */
    CONST = 263,                   /* CONST  */
    INT_TYPE = 264,                /* INT_TYPE  */
    REAL_TYPE = 265,               /* REAL_TYPE  */
    STRING_TYPE = 266,             /* STRING_TYPE  */
    IF = 267,                      /* IF  */
    THEN = 268,                    /* THEN  */
    ELSE = 269,                    /* ELSE  */
    WHILE = 270,                   /* WHILE  */
    FOREACH = 271,                 /* FOREACH  */
    WITH = 272,                    /* WITH  */
    SWITCH = 273,                  /* SWITCH  */
    CASE = 274,                    /* CASE  */
    DEFAULT = 275,                 /* DEFAULT  */
    BREAK = 276,                   /* BREAK  */
    READ = 277,                    /* READ  */
    OUT = 278,                     /* OUT  */
    WRITE = 279,                   /* WRITE  */
    SSTART = 280,                  /* SSTART  */
    SEND = 281,                    /* SEND  */
    TILL = 282,                    /* TILL  */
    NOT = 283,                     /* NOT  */
    LT = 284,                      /* LT  */
    GT = 285,                      /* GT  */
    EQ = 286,                      /* EQ  */
    NEQ = 287,                     /* NEQ  */
    LTE = 288,                     /* LTE  */
    GTE = 289,                     /* GTE  */
    PLUS = 290,                    /* PLUS  */
    MINUS = 291,                   /* MINUS  */
    MUL = 292,                     /* MUL  */
    DIV = 293,                     /* DIV  */
    ASSIGNOP = 294,                /* ASSIGNOP  */
    OROP = 295,                    /* OROP  */
    ANDOP = 296,                   /* ANDOP  */
    LPAREN = 297,                  /* LPAREN  */
    RPAREN = 298,                  /* RPAREN  */
    LBRACE = 299,                  /* LBRACE  */
    RBRACE = 300,                  /* RBRACE  */
    COMMA = 301,                   /* COMMA  */
    SEMICOLON = 302,               /* SEMICOLON  */
    COLON = 303,                   /* COLON  */
    BANG = 304,                    /* BANG  */
    STEP = 305,                    /* STEP  */
    ADDOP = 306,                   /* ADDOP  */
    MULOP = 307,                   /* MULOP  */
    RELOP = 308,                   /* RELOP  */
    NUM = 309,                     /* NUM  */
    ID = 310,                      /* ID  */
    SENTENCE = 311                 /* SENTENCE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 58 "parser.y"

    struct {
        variable_type type;
        value_type value;
        char *name;
        int offset;
    } values;
    op_type op;

#line 130 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
