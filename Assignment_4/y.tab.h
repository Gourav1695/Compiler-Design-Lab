/* A Bison parser, made by GNU Bison 3.8.2.  */

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
