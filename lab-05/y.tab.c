/* A Bison parser, made by GNU Bison 3.8.2.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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


#include "lex.yy.c"
#include "hash.c"
#include <stdbool.h>

void yyerror(char *);

void parsed(const char * msg) {
    printf("[line: %d] => %s syntax is OK\n", yylineno, msg);
}

int scope = 0;
int dtype = 0;
int type = -1;
symbol_table *table;

void add_variable(symbol_table *t, char *name, int dtype) {
    symbol *var = create_symbol(name, dtype, scope, yylineno);
    insert_table(t, var);
}

bool is_declared(symbol_table *t, char *name) {
    symbol *var = lookup_table(t, name, scope);
    if (var == NULL) {
        return false;
    }
    return true;
}

void delete_variables(symbol_table *t) {
    remove_table(t, scope);
}

int get_type(symbol_table *t, char *name, int scope) {
    symbol *var = lookup_table(t, name, scope);
    if (var == NULL) {
        return -1;
    }
    return var->dtype;
}


#line 115 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    LT_TOK = 258,                  /* LT_TOK  */
    GT_TOK = 259,                  /* GT_TOK  */
    EQ_TOK = 260,                  /* EQ_TOK  */
    MINUS_TOK = 261,               /* MINUS_TOK  */
    PLUS_TOK = 262,                /* PLUS_TOK  */
    MULT_TOK = 263,                /* MULT_TOK  */
    DIV_TOK = 264,                 /* DIV_TOK  */
    MOD_TOK = 265,                 /* MOD_TOK  */
    BNOT_TOK = 266,                /* BNOT_TOK  */
    NOT_TOK = 267,                 /* NOT_TOK  */
    AND_TOK = 268,                 /* AND_TOK  */
    OR_TOK = 269,                  /* OR_TOK  */
    XOR_TOK = 270,                 /* XOR_TOK  */
    LBRACE_TOK = 271,              /* LBRACE_TOK  */
    RBRACE_TOK = 272,              /* RBRACE_TOK  */
    LBRACKET_TOK = 273,            /* LBRACKET_TOK  */
    RBRACKET_TOK = 274,            /* RBRACKET_TOK  */
    LPAREN_TOK = 275,              /* LPAREN_TOK  */
    RPAREN_TOK = 276,              /* RPAREN_TOK  */
    SEMICOLON_TOK = 277,           /* SEMICOLON_TOK  */
    COMMA_TOK = 278,               /* COMMA_TOK  */
    SINGLE_QUOTE_TOK = 279,        /* SINGLE_QUOTE_TOK  */
    DOUBLE_QUOTE_TOK = 280,        /* DOUBLE_QUOTE_TOK  */
    MAIN_TOK = 281,                /* MAIN_TOK  */
    WHILE_TOK = 282,               /* WHILE_TOK  */
    DO_TOK = 283,                  /* DO_TOK  */
    FOR_TOK = 284,                 /* FOR_TOK  */
    BREAK_TOK = 285,               /* BREAK_TOK  */
    CONTINUE_TOK = 286,            /* CONTINUE_TOK  */
    IF_TOK = 287,                  /* IF_TOK  */
    ELSE_TOK = 288,                /* ELSE_TOK  */
    SWITCH_TOK = 289,              /* SWITCH_TOK  */
    CASE_TOK = 290,                /* CASE_TOK  */
    VOID_TOK = 291,                /* VOID_TOK  */
    INT_TOK = 292,                 /* INT_TOK  */
    FLOAT_TOK = 293,               /* FLOAT_TOK  */
    CHAR_TOK = 294,                /* CHAR_TOK  */
    RETURN_TOK = 295,              /* RETURN_TOK  */
    ID_TOK = 296,                  /* ID_TOK  */
    LT_EQ_TOK = 297,               /* LT_EQ_TOK  */
    GT_EQ_TOK = 298,               /* GT_EQ_TOK  */
    EQ_EQ_TOK = 299,               /* EQ_EQ_TOK  */
    PLUS_EQ_TOK = 300,             /* PLUS_EQ_TOK  */
    MINUS_EQ_TOK = 301,            /* MINUS_EQ_TOK  */
    MULT_EQ_TOK = 302,             /* MULT_EQ_TOK  */
    DIV_EQ_TOK = 303,              /* DIV_EQ_TOK  */
    MOD_EQ_TOK = 304,              /* MOD_EQ_TOK  */
    PLUS_PLUS_TOK = 305,           /* PLUS_PLUS_TOK  */
    MINUS_MINUS_TOK = 306,         /* MINUS_MINUS_TOK  */
    LOG_AND_TOK = 307,             /* LOG_AND_TOK  */
    LOG_OR_TOK = 308,              /* LOG_OR_TOK  */
    INTCONST = 309,                /* INTCONST  */
    FLOATCONST = 310,              /* FLOATCONST  */
    CHARCONST = 311,               /* CHARCONST  */
    STRCONST = 312                 /* STRCONST  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LT_TOK 258
#define GT_TOK 259
#define EQ_TOK 260
#define MINUS_TOK 261
#define PLUS_TOK 262
#define MULT_TOK 263
#define DIV_TOK 264
#define MOD_TOK 265
#define BNOT_TOK 266
#define NOT_TOK 267
#define AND_TOK 268
#define OR_TOK 269
#define XOR_TOK 270
#define LBRACE_TOK 271
#define RBRACE_TOK 272
#define LBRACKET_TOK 273
#define RBRACKET_TOK 274
#define LPAREN_TOK 275
#define RPAREN_TOK 276
#define SEMICOLON_TOK 277
#define COMMA_TOK 278
#define SINGLE_QUOTE_TOK 279
#define DOUBLE_QUOTE_TOK 280
#define MAIN_TOK 281
#define WHILE_TOK 282
#define DO_TOK 283
#define FOR_TOK 284
#define BREAK_TOK 285
#define CONTINUE_TOK 286
#define IF_TOK 287
#define ELSE_TOK 288
#define SWITCH_TOK 289
#define CASE_TOK 290
#define VOID_TOK 291
#define INT_TOK 292
#define FLOAT_TOK 293
#define CHAR_TOK 294
#define RETURN_TOK 295
#define ID_TOK 296
#define LT_EQ_TOK 297
#define GT_EQ_TOK 298
#define EQ_EQ_TOK 299
#define PLUS_EQ_TOK 300
#define MINUS_EQ_TOK 301
#define MULT_EQ_TOK 302
#define DIV_EQ_TOK 303
#define MOD_EQ_TOK 304
#define PLUS_PLUS_TOK 305
#define MINUS_MINUS_TOK 306
#define LOG_AND_TOK 307
#define LOG_OR_TOK 308
#define INTCONST 309
#define FLOATCONST 310
#define CHARCONST 311
#define STRCONST 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LT_TOK = 3,                     /* LT_TOK  */
  YYSYMBOL_GT_TOK = 4,                     /* GT_TOK  */
  YYSYMBOL_EQ_TOK = 5,                     /* EQ_TOK  */
  YYSYMBOL_MINUS_TOK = 6,                  /* MINUS_TOK  */
  YYSYMBOL_PLUS_TOK = 7,                   /* PLUS_TOK  */
  YYSYMBOL_MULT_TOK = 8,                   /* MULT_TOK  */
  YYSYMBOL_DIV_TOK = 9,                    /* DIV_TOK  */
  YYSYMBOL_MOD_TOK = 10,                   /* MOD_TOK  */
  YYSYMBOL_BNOT_TOK = 11,                  /* BNOT_TOK  */
  YYSYMBOL_NOT_TOK = 12,                   /* NOT_TOK  */
  YYSYMBOL_AND_TOK = 13,                   /* AND_TOK  */
  YYSYMBOL_OR_TOK = 14,                    /* OR_TOK  */
  YYSYMBOL_XOR_TOK = 15,                   /* XOR_TOK  */
  YYSYMBOL_LBRACE_TOK = 16,                /* LBRACE_TOK  */
  YYSYMBOL_RBRACE_TOK = 17,                /* RBRACE_TOK  */
  YYSYMBOL_LBRACKET_TOK = 18,              /* LBRACKET_TOK  */
  YYSYMBOL_RBRACKET_TOK = 19,              /* RBRACKET_TOK  */
  YYSYMBOL_LPAREN_TOK = 20,                /* LPAREN_TOK  */
  YYSYMBOL_RPAREN_TOK = 21,                /* RPAREN_TOK  */
  YYSYMBOL_SEMICOLON_TOK = 22,             /* SEMICOLON_TOK  */
  YYSYMBOL_COMMA_TOK = 23,                 /* COMMA_TOK  */
  YYSYMBOL_SINGLE_QUOTE_TOK = 24,          /* SINGLE_QUOTE_TOK  */
  YYSYMBOL_DOUBLE_QUOTE_TOK = 25,          /* DOUBLE_QUOTE_TOK  */
  YYSYMBOL_MAIN_TOK = 26,                  /* MAIN_TOK  */
  YYSYMBOL_WHILE_TOK = 27,                 /* WHILE_TOK  */
  YYSYMBOL_DO_TOK = 28,                    /* DO_TOK  */
  YYSYMBOL_FOR_TOK = 29,                   /* FOR_TOK  */
  YYSYMBOL_BREAK_TOK = 30,                 /* BREAK_TOK  */
  YYSYMBOL_CONTINUE_TOK = 31,              /* CONTINUE_TOK  */
  YYSYMBOL_IF_TOK = 32,                    /* IF_TOK  */
  YYSYMBOL_ELSE_TOK = 33,                  /* ELSE_TOK  */
  YYSYMBOL_SWITCH_TOK = 34,                /* SWITCH_TOK  */
  YYSYMBOL_CASE_TOK = 35,                  /* CASE_TOK  */
  YYSYMBOL_VOID_TOK = 36,                  /* VOID_TOK  */
  YYSYMBOL_INT_TOK = 37,                   /* INT_TOK  */
  YYSYMBOL_FLOAT_TOK = 38,                 /* FLOAT_TOK  */
  YYSYMBOL_CHAR_TOK = 39,                  /* CHAR_TOK  */
  YYSYMBOL_RETURN_TOK = 40,                /* RETURN_TOK  */
  YYSYMBOL_ID_TOK = 41,                    /* ID_TOK  */
  YYSYMBOL_LT_EQ_TOK = 42,                 /* LT_EQ_TOK  */
  YYSYMBOL_GT_EQ_TOK = 43,                 /* GT_EQ_TOK  */
  YYSYMBOL_EQ_EQ_TOK = 44,                 /* EQ_EQ_TOK  */
  YYSYMBOL_PLUS_EQ_TOK = 45,               /* PLUS_EQ_TOK  */
  YYSYMBOL_MINUS_EQ_TOK = 46,              /* MINUS_EQ_TOK  */
  YYSYMBOL_MULT_EQ_TOK = 47,               /* MULT_EQ_TOK  */
  YYSYMBOL_DIV_EQ_TOK = 48,                /* DIV_EQ_TOK  */
  YYSYMBOL_MOD_EQ_TOK = 49,                /* MOD_EQ_TOK  */
  YYSYMBOL_PLUS_PLUS_TOK = 50,             /* PLUS_PLUS_TOK  */
  YYSYMBOL_MINUS_MINUS_TOK = 51,           /* MINUS_MINUS_TOK  */
  YYSYMBOL_LOG_AND_TOK = 52,               /* LOG_AND_TOK  */
  YYSYMBOL_LOG_OR_TOK = 53,                /* LOG_OR_TOK  */
  YYSYMBOL_INTCONST = 54,                  /* INTCONST  */
  YYSYMBOL_FLOATCONST = 55,                /* FLOATCONST  */
  YYSYMBOL_CHARCONST = 56,                 /* CHARCONST  */
  YYSYMBOL_STRCONST = 57,                  /* STRCONST  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_S = 59,                         /* S  */
  YYSYMBOL_open_paren = 60,                /* open_paren  */
  YYSYMBOL_close_paren = 61,               /* close_paren  */
  YYSYMBOL_main = 62,                      /* main  */
  YYSYMBOL_block = 63,                     /* block  */
  YYSYMBOL_blocks = 64,                    /* blocks  */
  YYSYMBOL_statements = 65,                /* statements  */
  YYSYMBOL_statement = 66,                 /* statement  */
  YYSYMBOL_operation = 67,                 /* operation  */
  YYSYMBOL_declaration = 68,               /* declaration  */
  YYSYMBOL_assignment = 69,                /* assignment  */
  YYSYMBOL_return_statement = 70,          /* return_statement  */
  YYSYMBOL_function = 71,                  /* function  */
  YYSYMBOL_params = 72,                    /* params  */
  YYSYMBOL_function_call = 73,             /* function_call  */
  YYSYMBOL_args = 74,                      /* args  */
  YYSYMBOL_expression = 75,                /* expression  */
  YYSYMBOL_if_statement = 76,              /* if_statement  */
  YYSYMBOL_for_statement = 77,             /* for_statement  */
  YYSYMBOL_while_statement = 78,           /* while_statement  */
  YYSYMBOL_condition = 79,                 /* condition  */
  YYSYMBOL_arithmetic_op = 80,             /* arithmetic_op  */
  YYSYMBOL_relational_op = 81,             /* relational_op  */
  YYSYMBOL_datatype = 82,                  /* datatype  */
  YYSYMBOL_id_token = 83                   /* id_token  */
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
typedef yytype_int8 yy_state_t;

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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   304

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


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
      55,    56,    57
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   130,   130,   131,   132,   133,   134,   135,   138,   141,
     145,   149,   152,   153,   156,   157,   158,   159,   160,   163,
     164,   167,   168,   169,   170,   173,   180,   192,   209,   212,
     215,   216,   217,   220,   223,   224,   225,   228,   229,   245,
     253,   261,   269,   277,   278,   279,   280,   281,   282,   285,
     286,   287,   290,   293,   296,   297,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   312,   313,   314,   315,
     316,   317,   320,   321,   322,   323,   326,   327
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LT_TOK", "GT_TOK",
  "EQ_TOK", "MINUS_TOK", "PLUS_TOK", "MULT_TOK", "DIV_TOK", "MOD_TOK",
  "BNOT_TOK", "NOT_TOK", "AND_TOK", "OR_TOK", "XOR_TOK", "LBRACE_TOK",
  "RBRACE_TOK", "LBRACKET_TOK", "RBRACKET_TOK", "LPAREN_TOK", "RPAREN_TOK",
  "SEMICOLON_TOK", "COMMA_TOK", "SINGLE_QUOTE_TOK", "DOUBLE_QUOTE_TOK",
  "MAIN_TOK", "WHILE_TOK", "DO_TOK", "FOR_TOK", "BREAK_TOK",
  "CONTINUE_TOK", "IF_TOK", "ELSE_TOK", "SWITCH_TOK", "CASE_TOK",
  "VOID_TOK", "INT_TOK", "FLOAT_TOK", "CHAR_TOK", "RETURN_TOK", "ID_TOK",
  "LT_EQ_TOK", "GT_EQ_TOK", "EQ_EQ_TOK", "PLUS_EQ_TOK", "MINUS_EQ_TOK",
  "MULT_EQ_TOK", "DIV_EQ_TOK", "MOD_EQ_TOK", "PLUS_PLUS_TOK",
  "MINUS_MINUS_TOK", "LOG_AND_TOK", "LOG_OR_TOK", "INTCONST", "FLOATCONST",
  "CHARCONST", "STRCONST", "$accept", "S", "open_paren", "close_paren",
  "main", "block", "blocks", "statements", "statement", "operation",
  "declaration", "assignment", "return_statement", "function", "params",
  "function_call", "args", "expression", "if_statement", "for_statement",
  "while_statement", "condition", "arithmetic_op", "relational_op",
  "datatype", "id_token", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-84)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     225,    95,   -84,   -84,   -84,   -84,   -84,    95,   -84,   -84,
     -84,   -84,   -84,    69,   -84,   -84,   -16,   -84,   -84,   -84,
     -84,   -84,   154,   -84,   -19,     3,   124,    22,   134,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,    95,    95,    -6,     7,    95,    95,   -26,   -84,
      95,   -84,   154,   154,    -2,    95,    27,   154,    23,   183,
     -84,   154,     9,   154,    26,   -21,   -84,    95,   -84,   -84,
     -84,     9,    20,   -84,   219,   -84,    -1,    28,    29,    31,
     -84,    35,   -84,   -84,   -84,   -84,   -21,   -84,    95,   247,
      95,   219,   -84,   -84,     6,   154,    32,    34,    36,   -84,
       9,   247,     9,   -84,    38,    39,   247,   -11,    40,   -84,
     -84,     9,   -84
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    43,    73,    72,    75,    74,     0,    77,    39,
      40,    41,    42,     0,     6,     5,     0,    21,    22,    20,
       7,    37,    23,    24,     0,    38,     0,    38,     0,     1,
       3,     2,     4,    19,    66,    67,    68,    57,    56,    58,
      59,    60,    69,    70,    71,    61,    62,    63,    64,    65,
      47,    48,     0,     0,     0,    25,     0,    36,     0,    44,
       0,    28,    45,    46,     0,     0,    32,    27,     0,    35,
      76,    46,     0,    26,     0,     0,    33,    36,     8,    18,
      10,     0,    31,    34,    13,    29,    32,     0,     0,     0,
      18,     0,    14,    15,    16,    17,     0,    30,     0,     0,
       0,    13,     9,    11,    25,    55,     0,     0,     0,    12,
       0,     0,     0,    53,     0,    49,     0,     0,     0,    50,
      51,     0,    52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,   -84,   -84,    55,   -71,   -30,   -17,    18,   -83,
     -84,   -84,   -84,    61,   -10,   -84,     1,     2,   -40,   -84,
     -84,   -66,   -84,   -20,     4,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    13,    79,   103,    14,    90,    91,    84,    92,    16,
      17,    18,    19,    20,    74,    21,    68,    22,    93,    94,
      95,    23,    52,    60,    96,    27
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      25,    80,    53,    26,    24,    78,    33,    54,    56,    28,
      85,    65,    65,    25,    64,    70,   107,    24,    15,    72,
       8,    89,     8,    57,    55,    78,    58,    66,   114,    58,
      58,    31,   106,   118,   108,     3,     4,     5,     6,   113,
      70,   115,    57,    86,    76,    58,   119,    81,    98,    99,
     122,   100,   102,   110,    62,    63,   111,   112,    67,    69,
     116,   121,    71,     3,     4,     5,     6,    73,    30,    29,
      75,   109,   117,   101,    32,    82,    97,   120,    83,    69,
       0,     0,     0,     0,    25,    53,     0,     0,     0,     1,
      75,     2,     0,     0,     0,     0,   104,     0,     0,    25,
     105,    25,   105,     0,     0,     3,     4,     5,     6,     7,
       8,    25,     0,     0,     0,     1,    25,     2,     0,     0,
       0,     0,     0,     9,    10,    11,    12,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     8,    34,    35,    36,
      37,    38,    39,    40,    41,    59,     0,     0,     0,     9,
      10,    11,    12,     0,     0,     0,    61,    34,    35,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    78,     0,     0,     0,     1,
       0,     2,     0,     0,     0,     1,    87,     2,    88,     0,
       0,    89,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,     1,     0,     2,
       0,     0,     0,     9,    10,    11,    12,     0,     0,     9,
      10,    11,    12,     3,     4,     5,     6,     0,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,    10,    11,    12
};

static const yytype_int8 yycheck[] =
{
       0,    72,    22,     1,     0,    16,    22,    26,     5,     7,
      81,     5,     5,    13,    20,    41,    99,    13,     0,    21,
      41,    32,    41,    20,    24,    16,    23,    20,   111,    23,
      23,    13,    98,   116,   100,    36,    37,    38,    39,   110,
      41,   112,    20,    23,    21,    23,   117,    21,    20,    20,
     121,    20,    17,    21,    52,    53,    22,    21,    56,    57,
      22,    21,    60,    36,    37,    38,    39,    65,    13,     0,
      66,   101,    33,    90,    13,    75,    86,   117,    77,    77,
      -1,    -1,    -1,    -1,    84,   105,    -1,    -1,    -1,    20,
      86,    22,    -1,    -1,    -1,    -1,    96,    -1,    -1,    99,
      98,   101,   100,    -1,    -1,    36,    37,    38,    39,    40,
      41,   111,    -1,    -1,    -1,    20,   116,    22,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    57,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    41,     3,     4,     5,
       6,     7,     8,     9,    10,    21,    -1,    -1,    -1,    54,
      55,    56,    57,    -1,    -1,    -1,    22,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    16,    -1,    -1,    -1,    20,
      -1,    22,    -1,    -1,    -1,    20,    27,    22,    29,    -1,
      -1,    32,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    36,    37,    38,    39,    40,    41,    20,    -1,    22,
      -1,    -1,    -1,    54,    55,    56,    57,    -1,    -1,    54,
      55,    56,    57,    36,    37,    38,    39,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    20,    22,    36,    37,    38,    39,    40,    41,    54,
      55,    56,    57,    59,    62,    66,    67,    68,    69,    70,
      71,    73,    75,    79,    82,    83,    75,    83,    75,     0,
      62,    66,    71,    22,     3,     4,     5,     6,     7,     8,
       9,    10,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    80,    81,    26,    83,     5,    20,    23,    21,
      81,    22,    75,    75,    20,     5,    20,    75,    74,    75,
      41,    75,    21,    75,    72,    82,    21,    23,    16,    60,
      63,    21,    83,    74,    65,    63,    23,    27,    29,    32,
      63,    64,    66,    76,    77,    78,    82,    72,    20,    20,
      20,    65,    17,    61,    83,    75,    79,    67,    79,    64,
      21,    22,    21,    63,    67,    63,    22,    33,    67,    63,
      76,    21,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    59,    59,    59,    59,    60,    61,
      62,    63,    64,    64,    65,    65,    65,    65,    65,    66,
      66,    67,    67,    67,    67,    68,    69,    69,    70,    71,
      72,    72,    72,    73,    74,    74,    74,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    76,
      76,    76,    77,    78,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    81,    81,    81,    81,
      81,    81,    82,    82,    82,    82,    83,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       5,     4,     3,     0,     2,     2,     2,     2,     0,     2,
       1,     1,     1,     1,     1,     2,     4,     3,     3,     6,
       4,     2,     0,     4,     3,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     2,     2,     5,
       7,     7,     9,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 8: /* open_paren: LBRACE_TOK  */
#line 138 "parser.y"
                                { scope++; }
#line 1467 "y.tab.c"
    break;

  case 9: /* close_paren: RBRACE_TOK  */
#line 141 "parser.y"
                                { delete_variables(table); scope--; }
#line 1473 "y.tab.c"
    break;

  case 10: /* main: datatype MAIN_TOK LPAREN_TOK RPAREN_TOK block  */
#line 145 "parser.y"
                                                                       {parsed("main function");}
#line 1479 "y.tab.c"
    break;

  case 19: /* statement: operation SEMICOLON_TOK  */
#line 163 "parser.y"
                                          {type = -1;}
#line 1485 "y.tab.c"
    break;

  case 25: /* declaration: datatype id_token  */
#line 173 "parser.y"
                                                         {
    parsed("declaration statement");
    add_variable(table, var_name, dtype);
    iterate_table(table);
}
#line 1495 "y.tab.c"
    break;

  case 26: /* assignment: datatype id_token EQ_TOK expression  */
#line 180 "parser.y"
                                                         {
    if (type == -1) {
        type = dtype;
    } else if (type != dtype) {
        yyerror("type mismatch");
        return 1;
    }

    add_variable(table, var_name, dtype);
    iterate_table(table);
    parsed("assignment statement");
}
#line 1512 "y.tab.c"
    break;

  case 27: /* assignment: id_token EQ_TOK expression  */
#line 192 "parser.y"
                                                          {
    int current_type = get_type(table, var_name, scope);
    if (type == -1) {
        type = current_type;
    } else if (type != current_type) {
        yyerror("type mismatch");
        return 1;
    }

    if(!is_declared(table, var_name)) {
        yyerror("variable not declared");
        return 1;
    } 
    parsed("assignment statement");
}
#line 1532 "y.tab.c"
    break;

  case 28: /* return_statement: RETURN_TOK expression SEMICOLON_TOK  */
#line 209 "parser.y"
                                                         {parsed("return statement");}
#line 1538 "y.tab.c"
    break;

  case 29: /* function: datatype id_token LPAREN_TOK params RPAREN_TOK block  */
#line 212 "parser.y"
                                                                       {parsed("function");}
#line 1544 "y.tab.c"
    break;

  case 33: /* function_call: id_token LPAREN_TOK args RPAREN_TOK  */
#line 220 "parser.y"
                                                      {parsed("function call");}
#line 1550 "y.tab.c"
    break;

  case 38: /* expression: id_token  */
#line 229 "parser.y"
                                                                               {
                    if(!is_declared(table, var_name)) {
                        yyerror("variable not declared");
                        return 1;
                    }

                    if(type == -1) {
                        type = get_type(table, var_name, scope);
                    } else {
                        int current_type = get_type(table, var_name, scope);
                        if (current_type != type) {
                            yyerror("type mismatch");
                            return 1;
                        }
                    }
                }
#line 1571 "y.tab.c"
    break;

  case 39: /* expression: INTCONST  */
#line 245 "parser.y"
                            {
                    if(type == -1) {
                        type = INT_TOK;
                    } else if (type != INT_TOK) {
                        yyerror("type mismatch");
                        return 1;
                    }
                }
#line 1584 "y.tab.c"
    break;

  case 40: /* expression: FLOATCONST  */
#line 253 "parser.y"
                             {
                    if(type == -1) {
                        type = FLOAT_TOK;
                    } else if (type != FLOAT_TOK) {
                        yyerror("type mismatch");
                        return 1;
                    }
                }
#line 1597 "y.tab.c"
    break;

  case 41: /* expression: CHARCONST  */
#line 261 "parser.y"
                            {
                    if(type == -1) {
                        type = CHAR_TOK;
                    } else if (type != CHAR_TOK) {
                        yyerror("type mismatch");
                        return 1;
                    }
                }
#line 1610 "y.tab.c"
    break;

  case 42: /* expression: STRCONST  */
#line 269 "parser.y"
                           {
                    if(type == -1) {
                        type = CHAR_TOK;
                    } else if (type != CHAR_TOK) {
                        yyerror("type mismatch");
                        return 1;
                    }
                }
#line 1623 "y.tab.c"
    break;

  case 49: /* if_statement: IF_TOK LPAREN_TOK condition RPAREN_TOK block  */
#line 285 "parser.y"
                                                                                {parsed("if statement");}
#line 1629 "y.tab.c"
    break;

  case 50: /* if_statement: IF_TOK LPAREN_TOK condition RPAREN_TOK block ELSE_TOK block  */
#line 286 "parser.y"
                                                                                {parsed("if-else statement");}
#line 1635 "y.tab.c"
    break;

  case 51: /* if_statement: IF_TOK LPAREN_TOK condition RPAREN_TOK block ELSE_TOK if_statement  */
#line 287 "parser.y"
                                                                                     {parsed("else-if statement");}
#line 1641 "y.tab.c"
    break;

  case 52: /* for_statement: FOR_TOK LPAREN_TOK operation SEMICOLON_TOK operation SEMICOLON_TOK operation RPAREN_TOK block  */
#line 290 "parser.y"
                                                                                                                {parsed("for statement");}
#line 1647 "y.tab.c"
    break;

  case 53: /* while_statement: WHILE_TOK LPAREN_TOK condition RPAREN_TOK block  */
#line 293 "parser.y"
                                                                  {parsed("while statement");}
#line 1653 "y.tab.c"
    break;

  case 72: /* datatype: INT_TOK  */
#line 320 "parser.y"
                                { dtype = INT_TOK;}
#line 1659 "y.tab.c"
    break;

  case 73: /* datatype: VOID_TOK  */
#line 321 "parser.y"
                                { dtype = VOID_TOK;}
#line 1665 "y.tab.c"
    break;

  case 74: /* datatype: CHAR_TOK  */
#line 322 "parser.y"
                                { dtype = CHAR_TOK;}
#line 1671 "y.tab.c"
    break;

  case 75: /* datatype: FLOAT_TOK  */
#line 323 "parser.y"
                                { dtype = FLOAT_TOK;}
#line 1677 "y.tab.c"
    break;

  case 77: /* id_token: ID_TOK  */
#line 327 "parser.y"
                              { 
                    int current_type = get_type(table, var_name, scope);
                    if (type == -1) {
                        type = current_type;
                    } else if (type != current_type) {
                        yyerror("type mismatch");
                        return 1;
                    }
}
#line 1691 "y.tab.c"
    break;


#line 1695 "y.tab.c"

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
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

  return yyresult;
}

#line 338 "parser.y"


void yyerror(char *s) {
	printf("SYNTAX ERROR: %s LINE NUMBER: %d\n", s, yylineno);
}

int main()
{
    table = create_table();

    if (yyparse()==0) printf("\nPARSING COMPLETED SUCCESSFULLY ✅\n");
    else printf("\nPARSING ERROR (at line no:  %d) ❌\n", yylineno);

    return(0);	

}
