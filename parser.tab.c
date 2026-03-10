/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 127 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_CLASS = 4,                      /* CLASS  */
  YYSYMBOL_START = 5,                      /* START  */
  YYSYMBOL_END = 6,                        /* END  */
  YYSYMBOL_VAR = 7,                        /* VAR  */
  YYSYMBOL_CONST = 8,                      /* CONST  */
  YYSYMBOL_INT_TYPE = 9,                   /* INT_TYPE  */
  YYSYMBOL_REAL_TYPE = 10,                 /* REAL_TYPE  */
  YYSYMBOL_STRING_TYPE = 11,               /* STRING_TYPE  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_THEN = 13,                      /* THEN  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_FOREACH = 16,                   /* FOREACH  */
  YYSYMBOL_WITH = 17,                      /* WITH  */
  YYSYMBOL_SWITCH = 18,                    /* SWITCH  */
  YYSYMBOL_CASE = 19,                      /* CASE  */
  YYSYMBOL_DEFAULT = 20,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 21,                     /* BREAK  */
  YYSYMBOL_READ = 22,                      /* READ  */
  YYSYMBOL_OUT = 23,                       /* OUT  */
  YYSYMBOL_WRITE = 24,                     /* WRITE  */
  YYSYMBOL_SSTART = 25,                    /* SSTART  */
  YYSYMBOL_SEND = 26,                      /* SEND  */
  YYSYMBOL_TILL = 27,                      /* TILL  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_LT = 29,                        /* LT  */
  YYSYMBOL_GT = 30,                        /* GT  */
  YYSYMBOL_EQ = 31,                        /* EQ  */
  YYSYMBOL_NEQ = 32,                       /* NEQ  */
  YYSYMBOL_LTE = 33,                       /* LTE  */
  YYSYMBOL_GTE = 34,                       /* GTE  */
  YYSYMBOL_PLUS = 35,                      /* PLUS  */
  YYSYMBOL_MINUS = 36,                     /* MINUS  */
  YYSYMBOL_MUL = 37,                       /* MUL  */
  YYSYMBOL_DIV = 38,                       /* DIV  */
  YYSYMBOL_ASSIGNOP = 39,                  /* ASSIGNOP  */
  YYSYMBOL_OROP = 40,                      /* OROP  */
  YYSYMBOL_ANDOP = 41,                     /* ANDOP  */
  YYSYMBOL_LPAREN = 42,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 43,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 44,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 45,                    /* RBRACE  */
  YYSYMBOL_COMMA = 46,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 47,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 48,                     /* COLON  */
  YYSYMBOL_BANG = 49,                      /* BANG  */
  YYSYMBOL_STEP = 50,                      /* STEP  */
  YYSYMBOL_ADDOP = 51,                     /* ADDOP  */
  YYSYMBOL_MULOP = 52,                     /* MULOP  */
  YYSYMBOL_RELOP = 53,                     /* RELOP  */
  YYSYMBOL_NUM = 54,                       /* NUM  */
  YYSYMBOL_ID = 55,                        /* ID  */
  YYSYMBOL_SENTENCE = 56,                  /* SENTENCE  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_program = 58,                   /* program  */
  YYSYMBOL_59_1 = 59,                      /* $@1  */
  YYSYMBOL_declarations = 60,              /* declarations  */
  YYSYMBOL_declarList = 61,                /* declarList  */
  YYSYMBOL_decl = 62,                      /* decl  */
  YYSYMBOL_list = 63,                      /* list  */
  YYSYMBOL_type = 64,                      /* type  */
  YYSYMBOL_cdecl = 65,                     /* cdecl  */
  YYSYMBOL_stmt_list = 66,                 /* stmt_list  */
  YYSYMBOL_stmt = 67,                      /* stmt  */
  YYSYMBOL_out_stmt = 68,                  /* out_stmt  */
  YYSYMBOL_in_stmt = 69,                   /* in_stmt  */
  YYSYMBOL_assignment_stmt = 70,           /* assignment_stmt  */
  YYSYMBOL_control_stmt = 71,              /* control_stmt  */
  YYSYMBOL_72_2 = 72,                      /* $@2  */
  YYSYMBOL_73_3 = 73,                      /* $@3  */
  YYSYMBOL_74_4 = 74,                      /* $@4  */
  YYSYMBOL_75_5 = 75,                      /* $@5  */
  YYSYMBOL_76_6 = 76,                      /* $@6  */
  YYSYMBOL_77_7 = 77,                      /* $@7  */
  YYSYMBOL_stmt_block = 78,                /* stmt_block  */
  YYSYMBOL_switch_stmt = 79,               /* switch_stmt  */
  YYSYMBOL_cases = 80,                     /* cases  */
  YYSYMBOL_step = 81,                      /* step  */
  YYSYMBOL_bool_expr = 82,                 /* bool_expr  */
  YYSYMBOL_bool_term = 83,                 /* bool_term  */
  YYSYMBOL_bool_factor = 84,               /* bool_factor  */
  YYSYMBOL_expression = 85,                /* expression  */
  YYSYMBOL_term = 86,                      /* term  */
  YYSYMBOL_factor = 87                     /* factor  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   201

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   101,   101,   101,   119,   120,   123,   124,   127,   131,
     137,   173,   210,   214,   218,   224,   250,   254,   255,   258,
     259,   284,   285,   286,   287,   290,   313,   329,   362,   387,
     410,   414,   410,   422,   426,   422,   434,   434,   466,   466,
     504,   507,   510,   518,   527,   533,   548,   573,   583,   586,
     596,   599,   607,   675,   679,   699,   703,   733,   736,   737,
     765
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "CLASS",
  "START", "END", "VAR", "CONST", "INT_TYPE", "REAL_TYPE", "STRING_TYPE",
  "IF", "THEN", "ELSE", "WHILE", "FOREACH", "WITH", "SWITCH", "CASE",
  "DEFAULT", "BREAK", "READ", "OUT", "WRITE", "SSTART", "SEND", "TILL",
  "NOT", "LT", "GT", "EQ", "NEQ", "LTE", "GTE", "PLUS", "MINUS", "MUL",
  "DIV", "ASSIGNOP", "OROP", "ANDOP", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "COMMA", "SEMICOLON", "COLON", "BANG", "STEP", "ADDOP",
  "MULOP", "RELOP", "NUM", "ID", "SENTENCE", "$accept", "program", "$@1",
  "declarations", "declarList", "decl", "list", "type", "cdecl",
  "stmt_list", "stmt", "out_stmt", "in_stmt", "assignment_stmt",
  "control_stmt", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "stmt_block",
  "switch_stmt", "cases", "step", "bool_expr", "bool_term", "bool_factor",
  "expression", "term", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
#endif

#define YYPACT_NINF (-84)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-17)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,   -17,    32,    38,   -84,   -84,    49,    86,   -84,    39,
     -84,   -84,   -84,     0,   -84,    44,    13,   -84,   103,   -84,
     -84,    65,   -84,    77,   -84,    67,    79,    81,    82,   -84,
      87,   -84,   -84,   -84,   -84,   -84,   -84,   -84,    70,   -84,
     -43,    51,    85,    89,    74,    75,    29,    18,    46,    92,
      78,   -84,    90,    51,   -84,   -84,   -23,    93,   -84,    57,
      83,   -84,    51,    84,    94,    97,    35,    98,     2,   -84,
      95,    14,    91,   -84,    51,    24,   -30,    51,   123,    51,
      35,    35,    35,    64,   112,   118,    99,    60,   100,   101,
     -84,   -84,   102,   107,   -84,   -84,    93,   -84,   -84,    83,
     104,   -84,   -84,    27,    96,   -84,   -84,   -84,   136,   -84,
      36,   108,   -84,   -84,   105,   106,   125,   -84,   -84,   -84,
     139,   140,   110,   -84,   -84,   146,   109,   109,   -84,    36,
      36,   114,    36,    36,    54,   -84,   111,   -84,   -84,   115,
      66,    96,   113,   116,   -84,   -84,   -84
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     2,     5,     0,    18,     0,
      12,    13,    14,     0,     7,     0,     0,     9,     0,     6,
       4,     0,     3,     0,    33,     0,     0,     0,     0,    18,
       0,    17,    22,    23,    19,    21,    24,    40,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     0,     0,    60,    59,     0,    48,    50,     0,
      55,    57,     0,     0,     0,     0,     0,     0,     0,    41,
      20,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,    28,     0,     0,    53,    58,    47,    30,    49,    54,
      52,    56,    34,     0,     0,    27,    26,    25,    16,    51,
       0,     0,    36,    38,     0,     0,     0,    15,    31,    35,
       0,     0,     0,    18,    42,     0,     0,     0,    18,    44,
       0,     0,     0,     0,     0,    32,     0,    37,    39,     0,
       0,     0,     0,     0,    43,    45,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -84,   -84,   -84,   -84,   -84,   148,   -84,   145,    61,   -29,
     -83,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,    62,   -84,    30,    41,   -48,    88,   -72,    -7,   117,
     119
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     6,     8,    13,    14,    40,    15,    20,    16,
      31,    32,    33,    34,    35,   110,   125,    42,   111,   120,
     121,    36,    37,   116,   132,    56,    57,    58,    59,    60,
      61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,     9,    93,    50,    51,    75,   -16,    98,    18,    10,
      11,    12,   -16,    95,    83,   -16,   -16,    77,   -16,    22,
      78,    80,   -16,    81,   -16,    23,     1,   118,    24,    25,
      23,    26,     4,    24,    25,    27,    26,    28,     3,    68,
      27,    71,    28,     5,   -16,    89,    76,   135,    23,   137,
     138,    24,    25,    80,    26,   -16,     7,    29,    27,    87,
      28,    91,    29,    69,    77,    80,    23,    94,    30,    24,
      25,    66,    26,    30,   100,   139,    27,    66,    28,    52,
      29,   112,   113,    54,    55,    67,    17,     9,    66,    54,
      55,    30,    21,    53,   129,    10,    11,    12,    29,   134,
      54,    55,    70,    95,    77,    54,    55,   102,    80,    30,
      81,    80,    10,    11,    12,   114,   115,   142,   143,    41,
      39,    44,    43,    45,    46,    49,    48,    62,    63,    64,
      65,    72,    74,    73,    79,    82,    97,    85,    84,   103,
      86,    88,    90,   104,    18,    92,   105,   106,   107,   108,
     109,   124,    29,   136,   123,    80,   126,   127,   128,   122,
     130,    19,   141,    38,   131,    96,   140,   145,   133,   117,
     146,   144,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,     0,     0,
       0,   101
};

static const yytype_int16 yycheck[] =
{
      29,     1,    74,    46,    47,    53,     6,    79,     8,     9,
      10,    11,    12,    43,    62,    15,    16,    40,    18,     6,
      43,    51,    22,    53,    24,    12,     4,   110,    15,    16,
      12,    18,     0,    15,    16,    22,    18,    24,    55,    46,
      22,    48,    24,     5,    44,    43,    53,   130,    12,   132,
     133,    15,    16,    51,    18,    55,     7,    44,    22,    66,
      24,    47,    44,    45,    40,    51,    12,    43,    55,    15,
      16,    42,    18,    55,    81,    21,    22,    42,    24,    28,
      44,    54,    55,    54,    55,    56,    47,     1,    42,    54,
      55,    55,    48,    42,   123,     9,    10,    11,    44,   128,
      54,    55,    56,    43,    40,    54,    55,    43,    51,    55,
      53,    51,     9,    10,    11,    19,    20,    51,    52,    42,
      55,    42,    55,    42,    42,    55,    39,    42,    39,    55,
      55,    39,    42,    55,    41,    52,    13,    43,    54,    27,
      43,    43,    47,    25,     8,    54,    47,    47,    47,    47,
      43,    26,    44,    39,    48,    51,    17,    17,    48,    54,
      14,    13,    47,    18,    55,    77,    55,    54,   127,   108,
      54,   141,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    82
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    58,    55,     0,     5,    59,     7,    60,     1,
       9,    10,    11,    61,    62,    64,    66,    47,     8,    62,
      65,    48,     6,    12,    15,    16,    18,    22,    24,    44,
      55,    67,    68,    69,    70,    71,    78,    79,    64,    55,
      63,    42,    74,    55,    42,    42,    42,    66,    39,    55,
      46,    47,    28,    42,    54,    55,    82,    83,    84,    85,
      86,    87,    42,    39,    55,    55,    42,    56,    85,    45,
      56,    85,    39,    55,    42,    82,    85,    40,    43,    41,
      51,    53,    52,    82,    54,    43,    43,    85,    43,    43,
      47,    47,    54,    84,    43,    43,    83,    13,    84,    86,
      85,    87,    43,    27,    25,    47,    47,    47,    47,    43,
      72,    75,    54,    55,    19,    20,    80,    65,    67,    78,
      76,    77,    54,    48,    26,    73,    17,    17,    48,    66,
      14,    55,    81,    81,    66,    67,    39,    67,    67,    21,
      55,    47,    51,    52,    80,    54,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    59,    58,    60,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    67,    67,    67,    68,    68,    69,    70,    70,
      72,    73,    71,    74,    75,    71,    76,    71,    77,    71,
      71,    78,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    85,    85,    86,    86,    87,    87,
      87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     7,     3,     0,     2,     1,     4,     2,
       3,     1,     1,     1,     1,     7,     0,     2,     0,     1,
       3,     1,     1,     1,     1,     5,     5,     5,     4,     4,
       0,     0,    10,     0,     0,     7,     0,    10,     0,    10,
       1,     3,     7,     7,     3,     5,     5,     3,     1,     3,
       1,     4,     3,     3,     3,     1,     3,     1,     3,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 101 "parser.y"
                        {
        // Initialize both data and text sections
        if (error_count == 0) {
            emit(".data");
            emit("prompt:  .string \"Enter value: \"");
            emit("newline: .string \"\\n\"");
        }
    }
#line 1599 "parser.tab.c"
    break;

  case 3: /* program: CLASS ID START $@1 declarations stmt_list END  */
#line 109 "parser.y"
                               {
        // Only generate exit if no errors
        if (error_count == 0) {
            emit("    # Program exit");
            emit("    li a7, 10");
            emit("    ecall");
        }
    }
#line 1612 "parser.tab.c"
    break;

  case 4: /* declarations: VAR declarList cdecl  */
#line 119 "parser.y"
                                  { (yyval.values) = (yyvsp[-1].values); }
#line 1618 "parser.tab.c"
    break;

  case 5: /* declarations: %empty  */
#line 120 "parser.y"
              { (yyval.values).type = T_NONE; }
#line 1624 "parser.tab.c"
    break;

  case 6: /* declarList: declarList decl  */
#line 123 "parser.y"
                            { (yyval.values) = (yyvsp[0].values); }
#line 1630 "parser.tab.c"
    break;

  case 7: /* declarList: decl  */
#line 124 "parser.y"
                { (yyval.values) = (yyvsp[0].values); }
#line 1636 "parser.tab.c"
    break;

  case 8: /* decl: type COLON list SEMICOLON  */
#line 127 "parser.y"
                                {
        (yyval.values).type = (yyvsp[-3].values).type;
        (yyvsp[-1].values).type = (yyvsp[-3].values).type;
    }
#line 1645 "parser.tab.c"
    break;

  case 9: /* decl: error SEMICOLON  */
#line 131 "parser.y"
                      {
        error_recovery();
        (yyval.values).type = T_NONE;
    }
#line 1654 "parser.tab.c"
    break;

  case 10: /* list: list COMMA ID  */
#line 137 "parser.y"
                    {
        variable_type current_type = (yyvsp[-2].values).type;
        symbol_node *existing = lookup(my_symbolTable, (yyvsp[0].values).name);
        if (existing) {
			sprintf(error_msg,"Variable already declared %s",(yyvsp[0].values).name);
            yyerror(error_msg);
            YYERROR;
        }
        
        symbol_node *node = enter(my_symbolTable, (yyvsp[0].values).name, current_type, false);
        if (!node) {
			sprintf(error_msg,"Failed to add variable to symbol table %s",(yyvsp[0].values).name);
            yyerror(error_msg);
            YYERROR;
        }
        
        node->attri->offset = stack_offset;
        stack_offset += (current_type == T_REAL) ? 8 : 4;
        
        switch(current_type) {
            case T_REAL:
                emit("%s: .float 0.0", (yyvsp[0].values).name);
                break;
            case T_INT:
                emit("%s: .word 0", (yyvsp[0].values).name);
                break;
            case T_STRING:
                emit("%s: .space 256", (yyvsp[0].values).name); // Allocate 256 bytes for strings
                break;
            default:
                yyerror("Unsupported variable type");
                YYERROR;
        }
        
        (yyval.values).type = current_type;
    }
#line 1695 "parser.tab.c"
    break;

  case 11: /* list: ID  */
#line 173 "parser.y"
         {
        variable_type current_type = (yyvsp[(-1) - (1)].values).type;
        symbol_node *existing = lookup_symbol(my_symbolTable, (yyvsp[0].values).name);
        if (existing) {
			sprintf(error_msg,"Variable %s already declared ",(yyvsp[0].values).name);
            yyerror(error_msg);
            YYERROR;

        }
        symbol_node *node = enter(my_symbolTable, (yyvsp[0].values).name, current_type, false);
        if (!node) {
            yyerror("Failed to add variable to symbol table");
            YYERROR;
        }
        
        node->attri->offset = stack_offset;
        stack_offset += (current_type == T_REAL) ? 8 : 4;
        
        switch(current_type) {
            case T_REAL:
                emit("%s: .float 0.0", (yyvsp[0].values).name);
                break;
            case T_INT:
                emit("%s: .word 0", (yyvsp[0].values).name);
                break;
            case T_STRING:
                emit("%s: .string \"\"", (yyvsp[0].values).name);
                break;
            default:
                yyerror("Unsupported variable type");
                YYERROR;
				break;
        }
        
        (yyval.values).type = current_type;	
    }
#line 1736 "parser.tab.c"
    break;

  case 12: /* type: INT_TYPE  */
#line 210 "parser.y"
               { 
        (yyval.values).type = T_INT;
        (yyval.values).value.ival = 0;
    }
#line 1745 "parser.tab.c"
    break;

  case 13: /* type: REAL_TYPE  */
#line 214 "parser.y"
                { 
        (yyval.values).type = T_REAL;
        (yyval.values).value.rval = 0.0;
    }
#line 1754 "parser.tab.c"
    break;

  case 14: /* type: STRING_TYPE  */
#line 218 "parser.y"
                  { 
        (yyval.values).type = T_STRING;
        (yyval.values).value.sval = NULL;
    }
#line 1763 "parser.tab.c"
    break;

  case 15: /* cdecl: CONST type ID ASSIGNOP NUM SEMICOLON cdecl  */
#line 224 "parser.y"
                                                  {
        variable_type current_type = (yyvsp[-5].values).type;

        // Type checking for constant assignment
        if (current_type != (yyvsp[-2].values).type && !(current_type == T_REAL && (yyvsp[-2].values).type == T_INT)) {
            yyerror("Type mismatch in constant declaration");
            YYERROR;
        }

        // Insert into the symbol table as a constant
        symbol_node *node = enter(my_symbolTable, (yyvsp[-4].values).name, current_type, true);
        if (!node) {
            yyerror("Failed to add constant to symbol table");
            YYERROR;
        }

        // Store value based on type
        if (current_type == T_INT) {
            emit("%s: .word %d", (yyvsp[-4].values).name, (yyvsp[-2].values).value.ival);
            node->attri->value.ival = (yyvsp[-2].values).value.ival;
        } else if (current_type == T_REAL) {
            emit("%s: .float %f", (yyvsp[-4].values).name, (yyvsp[-2].values).value.rval);
            node->attri->value.rval = (yyvsp[-2].values).value.rval;
        }
		
    }
#line 1794 "parser.tab.c"
    break;

  case 16: /* cdecl: %empty  */
#line 250 "parser.y"
     {(yyval.values).type = T_NONE; emit(".text");  }
#line 1800 "parser.tab.c"
    break;

  case 17: /* stmt_list: stmt_list stmt  */
#line 254 "parser.y"
                          { (yyval.values) = (yyvsp[0].values); }
#line 1806 "parser.tab.c"
    break;

  case 18: /* stmt_list: %empty  */
#line 255 "parser.y"
           {}
#line 1812 "parser.tab.c"
    break;

  case 19: /* stmt: assignment_stmt  */
#line 258 "parser.y"
                      { (yyval.values) = (yyvsp[0].values); }
#line 1818 "parser.tab.c"
    break;

  case 20: /* stmt: ID ASSIGNOP SENTENCE  */
#line 260 "parser.y"
        {
		symbol_node *entry = lookup(my_symbolTable, (yyvsp[-2].values).name);
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
			emit("%s: .string \"%s\"", (yyvsp[-2].values).name, (yyvsp[0].values).value.sval);
			(yyval.values).type = T_STRING;
		}
	}
#line 1847 "parser.tab.c"
    break;

  case 21: /* stmt: control_stmt  */
#line 284 "parser.y"
                   { (yyval.values) = (yyvsp[0].values); }
#line 1853 "parser.tab.c"
    break;

  case 22: /* stmt: out_stmt  */
#line 285 "parser.y"
               { (yyval.values) = (yyvsp[0].values); }
#line 1859 "parser.tab.c"
    break;

  case 23: /* stmt: in_stmt  */
#line 286 "parser.y"
              { (yyval.values) = (yyvsp[0].values); }
#line 1865 "parser.tab.c"
    break;

  case 24: /* stmt: stmt_block  */
#line 287 "parser.y"
                 { (yyval.values) = (yyvsp[0].values); }
#line 1871 "parser.tab.c"
    break;

  case 25: /* out_stmt: WRITE LPAREN expression RPAREN SEMICOLON  */
#line 290 "parser.y"
                                                   {
            if ((yyvsp[-2].values).type == T_STRING) {
                emit("# Printing string variable");
                emit("    la a0, %s", (yyvsp[-2].values).name);
                emit("    li a7, 4");
                emit("    ecall");
            } else if ((yyvsp[-2].values).type == T_INT) {
                emit("# Printing integer variable");
                emit("    lw a0, %s", (yyvsp[-2].values).name);
                emit("    li a7, 1");
                emit("    ecall");
            } else if ((yyvsp[-2].values).type == T_REAL) {
                emit("# Printing float variable");
				emit("    la t0, %s", (yyvsp[-2].values).name);
                emit("    flw fa0, 0(t0)"); 
                emit("    li a7, 2");
                emit("    ecall");
            }
            // Add newline after output
            emit("    la a0, newline");
            emit("    li a7, 4");
            emit("    ecall");
        }
#line 1899 "parser.tab.c"
    break;

  case 26: /* out_stmt: WRITE LPAREN SENTENCE RPAREN SEMICOLON  */
#line 313 "parser.y"
                                             {
            emit(".data");
            emit("str_%d: .string \"%s\"", string_counter, (yyvsp[-2].values).value.sval);
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
#line 1917 "parser.tab.c"
    break;

  case 27: /* in_stmt: READ LPAREN ID RPAREN SEMICOLON  */
#line 329 "parser.y"
                                         {
    symbol_node *sym = lookup(my_symbolTable, (yyvsp[-2].values).name);
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
        emit("    la t0, %s", (yyvsp[-2].values).name);
        emit("    sw a0, 0(t0)"); 
    } else if (sym->attri->type == T_REAL) {
        emit("    li a7, 6");
        emit("    ecall");
        emit("    la t0, %s", (yyvsp[-2].values).name);
        emit("    fsw fa0, 0(t0)"); 
    }
    (yyval.values).type = sym->attri->type;
}
#line 1953 "parser.tab.c"
    break;

  case 28: /* assignment_stmt: ID ASSIGNOP expression SEMICOLON  */
#line 362 "parser.y"
                                                  {
    symbol_node *entry = lookup(my_symbolTable, (yyvsp[-3].values).name);
    if (!entry) {
        yyerror("Undeclared variable");
        YYERROR;
    }
    if (entry->attri->constant) {
        yyerror("Cannot assign into a constant variable");
        YYERROR;
    }
    if (entry->attri->type == T_REAL) {
        if ((yyvsp[-1].values).type == T_INT) {
            emit("    fcvt.s.w fa1, a0"); 
            emit("    la t0, %s", (yyvsp[-3].values).name);
            emit("    fsw fa1, 0(t0)");    
        } else {
            emit("    la t0, %s", (yyvsp[-3].values).name);
            emit("    fsw fa0, 0(t0)");
        }
    } else {
        emit("    la t0, %s", (yyvsp[-3].values).name);
        emit("    sw a0, 0(t0)");
    }
    (yyval.values).type = (yyvsp[-1].values).type;
}
#line 1983 "parser.tab.c"
    break;

  case 29: /* assignment_stmt: ID ASSIGNOP SENTENCE SEMICOLON  */
#line 388 "parser.y"
{
    symbol_node *entry = lookup(my_symbolTable, (yyvsp[-3].values).name);
    if (!entry || entry->attri->type != T_STRING) {
        yyerror("String assignment to non-string variable");
        YYERROR;
    }

    emit("#Insert to new msg into the string variable");
    emit(".data");
    emit("msg_%d: .string \"%s\"\n .text", string_counter, (yyvsp[-1].values).value.sval);

    emit("    la t0, msg_%d", string_counter);
    emit("    la t1, %s", (yyvsp[-3].values).name);
    emit("    sw t0, 0(t1)");

    (yyval.values).type = T_STRING;
    string_counter++;
}
#line 2006 "parser.tab.c"
    break;

  case 30: /* $@2: %empty  */
#line 410 "parser.y"
                                             {
        label = label_counter++;
        emit("    beqz a0, else_%d", label);  
    }
#line 2015 "parser.tab.c"
    break;

  case 31: /* $@3: %empty  */
#line 414 "parser.y"
         {                                   
        emit("    j endif_%d", label);       
        emit("else_%d:", label);             
    }
#line 2024 "parser.tab.c"
    break;

  case 32: /* control_stmt: IF LPAREN bool_expr RPAREN THEN $@2 stmt $@3 ELSE stmt  */
#line 418 "parser.y"
              {                              
        emit("endif_%d:", label);            
        (yyval.values).type = T_NONE;
    }
#line 2033 "parser.tab.c"
    break;

  case 33: /* $@4: %empty  */
#line 422 "parser.y"
            {
        label = label_counter++;
        emit("while_%d:", label);            
    }
#line 2042 "parser.tab.c"
    break;

  case 34: /* $@5: %empty  */
#line 426 "parser.y"
                            {
        emit("    beqz a0, endwhile_%d", label);  
    }
#line 2050 "parser.tab.c"
    break;

  case 35: /* control_stmt: WHILE $@4 LPAREN bool_expr RPAREN $@5 stmt_block  */
#line 429 "parser.y"
               {
        emit("    j while_%d", label);      
        emit("endwhile_%d:", label);         
        (yyval.values).type = T_NONE;
    }
#line 2060 "parser.tab.c"
    break;

  case 36: /* $@6: %empty  */
#line 434 "parser.y"
                                       {
        label = label_counter++;
        symbol_node *entry = lookup(my_symbolTable, (yyvsp[-4].values).name);
        if (!entry) {
            entry = enter(my_symbolTable, (yyvsp[-4].values).name, T_INT, false);
            if (!entry) {
                yyerror("Failed to create loop variable");
                YYERROR;
            }
        }
        
        
        emit("    # Initialize loop variable %s", (yyvsp[-4].values).name);
        emit("    li t0, %d", (yyvsp[-2].values).value.ival);
        emit("    la t1, %s", (yyvsp[-4].values).name);
        emit("    sw t0, 0(t1)");
        
        
        emit("loop_%d:", label);
        
        
        emit("    # Check loop condition");
        emit("    lw t0, %s", (yyvsp[-4].values).name);
        emit("    li t1, %d", (yyvsp[0].values).value.ival);
        emit("    bgt t0, t1, endloop_%d", label);
    }
#line 2091 "parser.tab.c"
    break;

  case 37: /* control_stmt: FOREACH ID ASSIGNOP NUM TILL NUM $@6 WITH step stmt  */
#line 460 "parser.y"
                   {
        emit("    # Loop increment and continuation");
        emit("    j loop_%d", label);
        emit("endloop_%d:", label);
        (yyval.values).type = T_NONE;
    }
#line 2102 "parser.tab.c"
    break;

  case 38: /* $@7: %empty  */
#line 466 "parser.y"
                                      {
        label = label_counter++;
        symbol_node *entry = lookup(my_symbolTable, (yyvsp[-4].values).name);
        symbol_node *end_var = lookup(my_symbolTable, (yyvsp[0].values).name);
        
        if (!entry) {
            entry = enter(my_symbolTable, (yyvsp[-4].values).name, T_INT, false);
            if (!entry) {
                yyerror("Failed to create loop variable");
                YYERROR;
            }
        }
        if (!end_var) {
            yyerror("Undeclared end variable in foreach loop");
            YYERROR;
        }
        
        
        emit("    # Initialize loop variable %s", (yyvsp[-4].values).name);
        emit("    li t0, %d", (yyvsp[-2].values).value.ival);
        emit("    la t1, %s", (yyvsp[-4].values).name);
        emit("    sw t0, 0(t1)");
        
       
        emit("loop_%d:", label);
        
       
        emit("    # Check loop condition");
        emit("    lw t0, %s", (yyvsp[-4].values).name);
        emit("    lw t1, %s", (yyvsp[0].values).name);
        emit("    bgt t0, t1, endloop_%d", label);
    }
#line 2139 "parser.tab.c"
    break;

  case 39: /* control_stmt: FOREACH ID ASSIGNOP NUM TILL ID $@7 WITH step stmt  */
#line 498 "parser.y"
                   {
        emit("    # Loop increment and continuation");
        emit("    j loop_%d", label);
        emit("endloop_%d:", label);
        (yyval.values).type = T_NONE;
    }
#line 2150 "parser.tab.c"
    break;

  case 40: /* control_stmt: switch_stmt  */
#line 504 "parser.y"
                  { (yyval.values) = (yyvsp[0].values); }
#line 2156 "parser.tab.c"
    break;

  case 41: /* stmt_block: LBRACE stmt_list RBRACE  */
#line 507 "parser.y"
                                    { (yyval.values) = (yyvsp[-1].values); }
#line 2162 "parser.tab.c"
    break;

  case 42: /* switch_stmt: SWITCH LPAREN ID RPAREN SSTART cases SEND  */
#line 510 "parser.y"
                                                       {
    emit("switch_start:");
    emit("    lw t1, %s", (yyvsp[-4].values).name);  
    emit("    # Jump to appropriate case");
    (yyval.values).type = T_NONE;
}
#line 2173 "parser.tab.c"
    break;

  case 43: /* cases: CASE NUM COLON stmt_list BREAK SEMICOLON cases  */
#line 518 "parser.y"
                                                      {
        int label = label_counter++;
        emit("case_%d:", label);
        emit("    li t0, %d", (yyvsp[-5].values).value.ival);
        emit("    bne t1, t0, case_%d", label + 1);
       
        emit("    j end_switch");
        (yyval.values).type = T_NONE;
    }
#line 2187 "parser.tab.c"
    break;

  case 44: /* cases: DEFAULT COLON stmt_list  */
#line 527 "parser.y"
                              {
        emit("default_case:");
        (yyval.values).type = T_NONE;
    }
#line 2196 "parser.tab.c"
    break;

  case 45: /* step: ID ASSIGNOP ID ADDOP NUM  */
#line 533 "parser.y"
                               {
		if ((yyvsp[-1].op) == PLUS_OP) {
			emit("#add by %d", (yyvsp[0].values).value.ival);
			emit("    lw t0, %s", (yyvsp[-4].values).name);
			emit("    addi t0, t0, %d", (yyvsp[0].values).value.ival);
			emit("    la t1, %s", (yyvsp[-4].values).name);
			emit("    sw t0, 0(t1)");
		} else if ((yyvsp[-1].op) == MINUS_OP) {
			emit("#sub by %d", (yyvsp[0].values).value.ival);
			emit("    lw t0, %s", (yyvsp[-4].values).name);
			emit("    addi t0, t0, %d", -(yyvsp[0].values).value.ival);
			emit("    la t1, %s", (yyvsp[-4].values).name);
			emit("    sw t0, 0(t1)");
		}
	}
#line 2216 "parser.tab.c"
    break;

  case 46: /* step: ID ASSIGNOP ID MULOP NUM  */
#line 548 "parser.y"
                                   {
		if ((yyvsp[-1].op) == MUL_OP) {
			emit("#Mul by %d", (yyvsp[0].values).value.ival);
			emit("    lw t0, %s", (yyvsp[-4].values).name);
			emit("    li t1, %d", (yyvsp[0].values).value.ival); 
			emit("    mul t0, t0, t1");
			emit("    la t2, %s", (yyvsp[-4].values).name);
			emit("    sw t0, 0(t2)");
		} else if ((yyvsp[-1].op) == DIV_OP) {
			if ((yyvsp[0].values).value.ival == 0) {
				yyerror("Can't divid by zero!");
				YYERROR;
			} else {
				emit("Div by %d", (yyvsp[0].values).value.ival);
				emit("    lw t0, %s", (yyvsp[-4].values).name);
				emit("    li t1, %d", (yyvsp[0].values).value.ival); 
				emit("    div t0, t0, t1");
				emit("    la t2, %s", (yyvsp[-4].values).name);
				emit("    sw t0, 0(t2)");
			}
		}
	}
#line 2243 "parser.tab.c"
    break;

  case 47: /* bool_expr: bool_expr OROP bool_term  */
#line 573 "parser.y"
                                    { 
              if ((yyvsp[-2].values).type != T_INT || (yyvsp[0].values).type != T_INT) {
                  yyerror("Operands must be integers in boolean expression");
                  YYERROR;

              }
			  emit("    mv a1, a0");
              emit("    or a0, a1, a0");
              (yyval.values).type = T_INT;
          }
#line 2258 "parser.tab.c"
    break;

  case 48: /* bool_expr: bool_term  */
#line 583 "parser.y"
                     { (yyval.values) = (yyvsp[0].values); }
#line 2264 "parser.tab.c"
    break;

  case 49: /* bool_term: bool_term ANDOP bool_factor  */
#line 586 "parser.y"
                                       {
              if ((yyvsp[-2].values).type != T_INT || (yyvsp[0].values).type != T_INT) {
                  yyerror("Operands must be integers in boolean expression");
                  YYERROR;

              }
			  emit("    mv a1, a0");
              emit("    and a0, a1, a0");;
              (yyval.values).type = T_INT;
          }
#line 2279 "parser.tab.c"
    break;

  case 50: /* bool_term: bool_factor  */
#line 596 "parser.y"
                       { (yyval.values) = (yyvsp[0].values); }
#line 2285 "parser.tab.c"
    break;

  case 51: /* bool_factor: NOT LPAREN bool_factor RPAREN  */
#line 599 "parser.y"
                                           {
                if ((yyvsp[-1].values).type != T_INT) {
                    yyerror("Operand must be integer in boolean expression");
                    YYERROR;
                }
                emit("    seqz a0, a0");  
                (yyval.values).type = T_INT;
            }
#line 2298 "parser.tab.c"
    break;

  case 52: /* bool_factor: expression RELOP expression  */
#line 607 "parser.y"
                                          {
                 if ((yyvsp[-2].values).type != (yyvsp[0].values).type) {
                    yyerror("Type mismatch in comparison");
                    YYERROR;
                }

                if ((yyvsp[-2].values).type == T_REAL) {
                    emit("    la t0, %s", (yyvsp[-2].values).name);
                    emit("    flw fa0, 0(t0)");
                    emit("    la t0, %s", (yyvsp[0].values).name);
                    emit("    flw fa1, 0(t0)");
                    
                  
                    switch ((yyvsp[-1].op)) {
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
                    
                    emit("    la t0, %s", (yyvsp[-2].values).name);
                    emit("    lw a1, 0(t0)");
                    emit("    la t0, %s", (yyvsp[0].values).name);
                    emit("    lw a0, 0(t0)");
                    
                    switch ((yyvsp[-1].op)) {
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
                (yyval.values).type = T_INT;
            }
#line 2371 "parser.tab.c"
    break;

  case 53: /* bool_factor: LPAREN bool_expr RPAREN  */
#line 675 "parser.y"
                                      { (yyval.values) = (yyvsp[-1].values); }
#line 2377 "parser.tab.c"
    break;

  case 54: /* expression: expression ADDOP term  */
#line 679 "parser.y"
                                  {
    if ((yyvsp[-2].values).type == T_INT) {
        emit("    mv a1, a0");      
        emit("    la t0, %s", (yyvsp[0].values).name);  
        emit("    lw a0, 0(t0)");   
        if ((yyvsp[-1].op) == PLUS_OP)
            emit("    add a0, a1, a0");
        else
            emit("    sub a0, a1, a0");   
    } else {
        emit("    fmv.s fa1, fa0");   
        emit("    la t0, %s", (yyvsp[0].values).name);  
        emit("    flw fa0, 0(t0)"); 
        if ((yyvsp[-1].op) == PLUS_OP)
            emit("    fadd.s fa0, fa1, fa0");
        else
            emit("    fsub.s fa0, fa1, fa0");
    }
    (yyval.values) = (yyvsp[-2].values);
	}
#line 2402 "parser.tab.c"
    break;

  case 55: /* expression: term  */
#line 699 "parser.y"
                  { (yyval.values) = (yyvsp[0].values); }
#line 2408 "parser.tab.c"
    break;

  case 56: /* term: term MULOP factor  */
#line 703 "parser.y"
                        {
         if ((yyvsp[-2].values).type != (yyvsp[0].values).type) {
             yyerror("Type mismatch in term");
             YYERROR;

         }
    if ((yyvsp[-2].values).type == T_INT) {
        emit("    mv a1, a0");       
        emit("    la t0, %s", (yyvsp[0].values).name);  
        emit("    lw a2, 0(t0)");   
        if ((yyvsp[-1].op) == MUL_OP) {
            emit("    mul a0, a1, a2");
        } else {
            emit("    div a0, a1, a2");
        }
			}
	else {
		emit("    la t0, %s", (yyvsp[-2].values).name);
        emit("    flw fa0, %s", (yyvsp[-2].values).name);   
        emit("    la t0, %s", (yyvsp[0].values).name);  
        emit("    flw fa1, 0(t0)"); 
		if ((yyvsp[-1].op) == MUL_OP) {
			emit("    fmul.s fa0, fa0, fa1");
		} else {
			emit("    fdiv.s fa0, fa0, fa1");
		}
    }
    (yyval.values) = (yyvsp[-2].values);
}
#line 2442 "parser.tab.c"
    break;

  case 57: /* term: factor  */
#line 733 "parser.y"
             { (yyval.values) = (yyvsp[0].values); }
#line 2448 "parser.tab.c"
    break;

  case 58: /* factor: LPAREN expression RPAREN  */
#line 736 "parser.y"
                                 { (yyval.values) = (yyvsp[-1].values); }
#line 2454 "parser.tab.c"
    break;

  case 59: /* factor: ID  */
#line 737 "parser.y"
           { 
          symbol_node *sym = lookup(my_symbolTable, (yyvsp[0].values).name);
          if (!sym) {
              yyerror("Undeclared variable");
			  yyerror((yyvsp[0].values).name);
              YYERROR;

			  
          }
          (yyval.values).type = sym->attri->type;
          switch (sym->attri->type) {
              case T_INT:
                  emit("    la t0, %s", (yyvsp[0].values).name); 
                  emit("    lw a0, 0(t0)");
                  break;
              case T_REAL:
                  emit("    la t0, %s", (yyvsp[0].values).name);
                  emit("    flw fa0, 0(t0)" );
                  break;
              case T_STRING:
                  emit("    la a0, %s", (yyvsp[0].values).name); 
                  break;
              default:
                  yyerror("Unsupported variable type in factor:ID");
                  YYERROR;
          }

        }
#line 2487 "parser.tab.c"
    break;

  case 60: /* factor: NUM  */
#line 765 "parser.y"
            { 
          (yyval.values).type = (yyvsp[0].values).type;
          if ((yyvsp[0].values).type == T_INT) {
              emit("    li a0, %d", (yyvsp[0].values).value.ival);
          } else if ((yyvsp[0].values).type == T_REAL) {
				emit("    .data");
				emit("    .align 2");
				emit("float_const_%d: .float %f", float_const_counter, (yyvsp[0].values).value.rval);
				emit("    .text");
				emit("    la t0, float_const_%d", float_const_counter);
				emit("    flw fa0, 0(t0)");
				float_const_counter++;
          } else {
              yyerror("Unsupported number type");
			  
              YYERROR;
			 
          }
        }
#line 2511 "parser.tab.c"
    break;


#line 2515 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 786 "parser.y"
 

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
