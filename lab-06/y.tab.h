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
    LPAREN_TOK = 258,              /* LPAREN_TOK  */
    GT_TOK = 259,                  /* GT_TOK  */
    LT_TOK = 260,                  /* LT_TOK  */
    RPAREN_TOK = 261,              /* RPAREN_TOK  */
    ASSIGN_TOK = 262,              /* ASSIGN_TOK  */
    MINUS_TOK = 263,               /* MINUS_TOK  */
    PLUS_TOK = 264,                /* PLUS_TOK  */
    MULT_TOK = 265,                /* MULT_TOK  */
    DIV_TOK = 266,                 /* DIV_TOK  */
    MOD_TOK = 267,                 /* MOD_TOK  */
    NOT_TOK = 268,                 /* NOT_TOK  */
    SEMICOLON_TOK = 269,           /* SEMICOLON_TOK  */
    HASH_TOK = 270,                /* HASH_TOK  */
    DOT_TOK = 271,                 /* DOT_TOK  */
    COMMA_TOK = 272,               /* COMMA_TOK  */
    LCURL_TOK = 273,               /* LCURL_TOK  */
    RCURL_TOK = 274,               /* RCURL_TOK  */
    LSQUARE_TOK = 275,             /* LSQUARE_TOK  */
    RSQUARE_TOK = 276,             /* RSQUARE_TOK  */
    BIT_AND_TOK = 277,             /* BIT_AND_TOK  */
    BIT_OR_TOK = 278,              /* BIT_OR_TOK  */
    BACKSLASH_TOK = 279,           /* BACKSLASH_TOK  */
    SPEECH_TOK = 280,              /* SPEECH_TOK  */
    INVCOMMA_TOK = 281,            /* INVCOMMA_TOK  */
    XOR_TOK = 282,                 /* XOR_TOK  */
    NEG_TOK = 283,                 /* NEG_TOK  */
    EQ_TOK = 284,                  /* EQ_TOK  */
    GTE_TOK = 285,                 /* GTE_TOK  */
    LTE_TOK = 286,                 /* LTE_TOK  */
    LSHIFT_TOK = 287,              /* LSHIFT_TOK  */
    RSHIFT_TOK = 288,              /* RSHIFT_TOK  */
    AND_TOK = 289,                 /* AND_TOK  */
    OR_TOK = 290,                  /* OR_TOK  */
    NEQ_TOK = 291,                 /* NEQ_TOK  */
    INC_TOK = 292,                 /* INC_TOK  */
    DEC_TOK = 293,                 /* DEC_TOK  */
    PLUS_ASSIGN_TOK = 294,         /* PLUS_ASSIGN_TOK  */
    MINUS_ASSIGN_TOK = 295,        /* MINUS_ASSIGN_TOK  */
    MULT_ASSIGN_TOK = 296,         /* MULT_ASSIGN_TOK  */
    DIV_ASSIGN_TOK = 297,          /* DIV_ASSIGN_TOK  */
    MOD_ASSIGN_TOK = 298,          /* MOD_ASSIGN_TOK  */
    DO_TOK = 299,                  /* DO_TOK  */
    WHILE_TOK = 300,               /* WHILE_TOK  */
    FOR_TOK = 301,                 /* FOR_TOK  */
    IF_TOK = 302,                  /* IF_TOK  */
    ELSE_TOK = 303,                /* ELSE_TOK  */
    RET_TOK = 304,                 /* RET_TOK  */
    PRINT_TOK = 305,               /* PRINT_TOK  */
    SCAN_TOK = 306,                /* SCAN_TOK  */
    DEF_TOK = 307,                 /* DEF_TOK  */
    TYPEDEF_TOK = 308,             /* TYPEDEF_TOK  */
    BREAK_TOK = 309,               /* BREAK_TOK  */
    CONTINUE_TOK = 310,            /* CONTINUE_TOK  */
    SIZEOF_TOK = 311,              /* SIZEOF_TOK  */
    CASE_TOK = 312,                /* CASE_TOK  */
    SWITCH_TOK = 313,              /* SWITCH_TOK  */
    MAIN_TOK = 314,                /* MAIN_TOK  */
    INCLUDE_TOK = 315,             /* INCLUDE_TOK  */
    PRINTF_TOK = 316,              /* PRINTF_TOK  */
    SCANF_TOK = 317,               /* SCANF_TOK  */
    ID_TOK = 318,                  /* ID_TOK  */
    INT_CONST_TOK = 319,           /* INT_CONST_TOK  */
    CHAR_CONST_TOK = 320,          /* CHAR_CONST_TOK  */
    REAL_CONST_TOK = 321,          /* REAL_CONST_TOK  */
    STRING_CONST_TOK = 322,        /* STRING_CONST_TOK  */
    INT_TOK = 323,                 /* INT_TOK  */
    CHAR_TOK = 324,                /* CHAR_TOK  */
    FLOAT_TOK = 325,               /* FLOAT_TOK  */
    DOUBLE_TOK = 326,              /* DOUBLE_TOK  */
    LONG_TOK = 327,                /* LONG_TOK  */
    SHORT_TOK = 328,               /* SHORT_TOK  */
    VOID_TOK = 329                 /* VOID_TOK  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LPAREN_TOK 258
#define GT_TOK 259
#define LT_TOK 260
#define RPAREN_TOK 261
#define ASSIGN_TOK 262
#define MINUS_TOK 263
#define PLUS_TOK 264
#define MULT_TOK 265
#define DIV_TOK 266
#define MOD_TOK 267
#define NOT_TOK 268
#define SEMICOLON_TOK 269
#define HASH_TOK 270
#define DOT_TOK 271
#define COMMA_TOK 272
#define LCURL_TOK 273
#define RCURL_TOK 274
#define LSQUARE_TOK 275
#define RSQUARE_TOK 276
#define BIT_AND_TOK 277
#define BIT_OR_TOK 278
#define BACKSLASH_TOK 279
#define SPEECH_TOK 280
#define INVCOMMA_TOK 281
#define XOR_TOK 282
#define NEG_TOK 283
#define EQ_TOK 284
#define GTE_TOK 285
#define LTE_TOK 286
#define LSHIFT_TOK 287
#define RSHIFT_TOK 288
#define AND_TOK 289
#define OR_TOK 290
#define NEQ_TOK 291
#define INC_TOK 292
#define DEC_TOK 293
#define PLUS_ASSIGN_TOK 294
#define MINUS_ASSIGN_TOK 295
#define MULT_ASSIGN_TOK 296
#define DIV_ASSIGN_TOK 297
#define MOD_ASSIGN_TOK 298
#define DO_TOK 299
#define WHILE_TOK 300
#define FOR_TOK 301
#define IF_TOK 302
#define ELSE_TOK 303
#define RET_TOK 304
#define PRINT_TOK 305
#define SCAN_TOK 306
#define DEF_TOK 307
#define TYPEDEF_TOK 308
#define BREAK_TOK 309
#define CONTINUE_TOK 310
#define SIZEOF_TOK 311
#define CASE_TOK 312
#define SWITCH_TOK 313
#define MAIN_TOK 314
#define INCLUDE_TOK 315
#define PRINTF_TOK 316
#define SCANF_TOK 317
#define ID_TOK 318
#define INT_CONST_TOK 319
#define CHAR_CONST_TOK 320
#define REAL_CONST_TOK 321
#define STRING_CONST_TOK 322
#define INT_TOK 323
#define CHAR_TOK 324
#define FLOAT_TOK 325
#define DOUBLE_TOK 326
#define LONG_TOK 327
#define SHORT_TOK 328
#define VOID_TOK 329

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 244 "parser.y"

	int number;		
	float decimal;	
	char *string;	
	struct Dtype {	
		int dtype;
		char *place;	
	} Dtype;

#line 225 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
