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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 500
void yyerror(char *s);
int scope = 0;
int dtype;
int flag = 0;

typedef struct val {
	char name[20];
	int dtype;
	int scope;
	
	struct val *next;
} Symbol;
typedef struct table {
	Symbol *entry[TABLE_SIZE];
	int size;
} SymTable;

SymTable table;

int hash (char *str) {
	int h = 5381;
	int c;
	
	while((c = *str++)) {
		h = ((h << 5) + h) + c;	
	}
	
	return h % TABLE_SIZE;
}

void setupSymbolTable() {
	for(int i=0;i<TABLE_SIZE;i++) {
		table.entry[i] = NULL;
	}
	table.size = 0;
}

void printTable() {
	printf("Entry no.\tSymbol name\tDatatype\tScope\n");
	for(int i=0;i<TABLE_SIZE;i++) {
		if(table.entry[i] != NULL) {
			Symbol *head = table.entry[i];
			while(head != NULL) {
				printf("%d\t\t%s\t\t%d\t\t%d\n", i, head->name, head->dtype, head->scope);
				head = head->next;
			}
		}
	}
}

int isPresent(char *sym) {
	int hval = hash(sym);
	Symbol *head = table.entry[hval];

	if(head == NULL) {
		return 0;
	}

	while(head != NULL) {
		if(strcmp(head->name, sym) == 0)
			return 1;
		
		head = head->next;
	}

	return 0;
}

int alreadyDeclared(char *sym) {
	int hval = hash(sym);
	Symbol *head = table.entry[hval];
	if(head == NULL) {
		return 0;
	}
	while(head != NULL) {
		if(strcmp(head->name, sym) == 0 && head->scope == scope) {
			if(head->dtype == dtype)
				return 1;
			else
				return 2;
		}
		head = head->next;
	}
	return 0;
}


int addSymbol(char *sym) {
	if(table.size == TABLE_SIZE) {
		return -1;
	}
	int hval = hash(sym);
	Symbol *head = table.entry[hval];
	Symbol *tmp = (Symbol *)malloc(sizeof(Symbol));
	strcpy(tmp->name, sym);
	tmp->dtype = dtype;
	tmp->scope = scope;
	tmp->next = NULL;
	if(head == NULL) {
		head = tmp;
		table.size++;
		table.entry[hval] = head;
		return 0;
	}
	while(head->next != NULL) {
		head = head->next;
	}
	head->next = tmp;
	return 0;
}


int addFunction(char *sym) {
	if(table.size == TABLE_SIZE) {
		return -1;
	}
	int hval = hash(sym);
	Symbol *head = table.entry[hval];
	Symbol *tmp = (Symbol *)malloc(sizeof(Symbol));
	strcpy(tmp->name, sym);
	tmp->dtype = dtype;
	tmp->scope = 0;
	tmp->next = NULL;
	if(head == NULL) {
		head = tmp;
		table.size++;
		table.entry[hval] = head;
		
		return 0;
	}
	while(head->next != NULL) {
		head = head->next;
	}
	head->next = tmp;
	return 0;
}


int getDatatype(char *sym) {
	int hval = hash(sym);
	Symbol *head = table.entry[hval];
	while(head != NULL && strcmp(head->name, sym) != 0) {
		head = head->next;
	}
	if(head == NULL) return 0;
	return head->dtype;
}


void deleteNodes(int i, int key) {
	Symbol *tmp, *p, *q;
	Symbol *head = table.entry[i];

	while(head != NULL && head->scope == key) {
		tmp = head;
		head = head->next;
		free(tmp);
	}

	if(head == NULL) {
		table.entry[i] = head;
		return;
	}

	table.entry[i] = head;
	p = head;
	q = head->next;
	while(q != NULL) {
		if(q->scope == key) {
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else {
			p = p->next;
			q = q->next;
		}
	}
}


void deleteScopeSyms(int s) {
	for(int i=0;i<TABLE_SIZE;i++) {
		if(table.entry[i] != NULL) {
			deleteNodes(i, s);
			if(table.entry[i] == NULL) {
				table.size--;
			}
		}
	}
	
	
	
}


void freeTable() {
	for(int i=0;i<TABLE_SIZE;i++) {
		Symbol *head = table.entry[i];
		Symbol *tmp;
		while(head != NULL) {
			tmp = head;
			head = head->next;
			free(tmp);
		}
	}
}

FILE *out_file;
int interm_label = 0, temp_label = 0, backpatch_label = 0;
int new_tmp_index = 1;
int temp = 0;
char *interm_table[100];
char expr_var[20], tmp_var[20];

char *new_temp_var() {
	static char t[5];
	sprintf(t, "t%d", new_tmp_index);
	return t;
}

void generate(int label, char *str) {
	interm_table[label] = (char *)malloc((strlen(str) + 1) * sizeof(char));
	strcpy(interm_table[label], str); 
}

void write_to_file() {
	for(int i=0;i<100;i++) {
		if(interm_table[i] != NULL) {
			fprintf(out_file, "%d: %s", i, interm_table[i]);
			free(interm_table[i]);
			interm_table[i] = NULL;
		}
	}
}

#line 314 "y.tab.c"

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

#line 525 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
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
  YYSYMBOL_LPAREN_TOK = 3,                 /* LPAREN_TOK  */
  YYSYMBOL_GT_TOK = 4,                     /* GT_TOK  */
  YYSYMBOL_LT_TOK = 5,                     /* LT_TOK  */
  YYSYMBOL_RPAREN_TOK = 6,                 /* RPAREN_TOK  */
  YYSYMBOL_ASSIGN_TOK = 7,                 /* ASSIGN_TOK  */
  YYSYMBOL_MINUS_TOK = 8,                  /* MINUS_TOK  */
  YYSYMBOL_PLUS_TOK = 9,                   /* PLUS_TOK  */
  YYSYMBOL_MULT_TOK = 10,                  /* MULT_TOK  */
  YYSYMBOL_DIV_TOK = 11,                   /* DIV_TOK  */
  YYSYMBOL_MOD_TOK = 12,                   /* MOD_TOK  */
  YYSYMBOL_NOT_TOK = 13,                   /* NOT_TOK  */
  YYSYMBOL_SEMICOLON_TOK = 14,             /* SEMICOLON_TOK  */
  YYSYMBOL_HASH_TOK = 15,                  /* HASH_TOK  */
  YYSYMBOL_DOT_TOK = 16,                   /* DOT_TOK  */
  YYSYMBOL_COMMA_TOK = 17,                 /* COMMA_TOK  */
  YYSYMBOL_LCURL_TOK = 18,                 /* LCURL_TOK  */
  YYSYMBOL_RCURL_TOK = 19,                 /* RCURL_TOK  */
  YYSYMBOL_LSQUARE_TOK = 20,               /* LSQUARE_TOK  */
  YYSYMBOL_RSQUARE_TOK = 21,               /* RSQUARE_TOK  */
  YYSYMBOL_BIT_AND_TOK = 22,               /* BIT_AND_TOK  */
  YYSYMBOL_BIT_OR_TOK = 23,                /* BIT_OR_TOK  */
  YYSYMBOL_BACKSLASH_TOK = 24,             /* BACKSLASH_TOK  */
  YYSYMBOL_SPEECH_TOK = 25,                /* SPEECH_TOK  */
  YYSYMBOL_INVCOMMA_TOK = 26,              /* INVCOMMA_TOK  */
  YYSYMBOL_XOR_TOK = 27,                   /* XOR_TOK  */
  YYSYMBOL_NEG_TOK = 28,                   /* NEG_TOK  */
  YYSYMBOL_EQ_TOK = 29,                    /* EQ_TOK  */
  YYSYMBOL_GTE_TOK = 30,                   /* GTE_TOK  */
  YYSYMBOL_LTE_TOK = 31,                   /* LTE_TOK  */
  YYSYMBOL_LSHIFT_TOK = 32,                /* LSHIFT_TOK  */
  YYSYMBOL_RSHIFT_TOK = 33,                /* RSHIFT_TOK  */
  YYSYMBOL_AND_TOK = 34,                   /* AND_TOK  */
  YYSYMBOL_OR_TOK = 35,                    /* OR_TOK  */
  YYSYMBOL_NEQ_TOK = 36,                   /* NEQ_TOK  */
  YYSYMBOL_INC_TOK = 37,                   /* INC_TOK  */
  YYSYMBOL_DEC_TOK = 38,                   /* DEC_TOK  */
  YYSYMBOL_PLUS_ASSIGN_TOK = 39,           /* PLUS_ASSIGN_TOK  */
  YYSYMBOL_MINUS_ASSIGN_TOK = 40,          /* MINUS_ASSIGN_TOK  */
  YYSYMBOL_MULT_ASSIGN_TOK = 41,           /* MULT_ASSIGN_TOK  */
  YYSYMBOL_DIV_ASSIGN_TOK = 42,            /* DIV_ASSIGN_TOK  */
  YYSYMBOL_MOD_ASSIGN_TOK = 43,            /* MOD_ASSIGN_TOK  */
  YYSYMBOL_DO_TOK = 44,                    /* DO_TOK  */
  YYSYMBOL_WHILE_TOK = 45,                 /* WHILE_TOK  */
  YYSYMBOL_FOR_TOK = 46,                   /* FOR_TOK  */
  YYSYMBOL_IF_TOK = 47,                    /* IF_TOK  */
  YYSYMBOL_ELSE_TOK = 48,                  /* ELSE_TOK  */
  YYSYMBOL_RET_TOK = 49,                   /* RET_TOK  */
  YYSYMBOL_PRINT_TOK = 50,                 /* PRINT_TOK  */
  YYSYMBOL_SCAN_TOK = 51,                  /* SCAN_TOK  */
  YYSYMBOL_DEF_TOK = 52,                   /* DEF_TOK  */
  YYSYMBOL_TYPEDEF_TOK = 53,               /* TYPEDEF_TOK  */
  YYSYMBOL_BREAK_TOK = 54,                 /* BREAK_TOK  */
  YYSYMBOL_CONTINUE_TOK = 55,              /* CONTINUE_TOK  */
  YYSYMBOL_SIZEOF_TOK = 56,                /* SIZEOF_TOK  */
  YYSYMBOL_CASE_TOK = 57,                  /* CASE_TOK  */
  YYSYMBOL_SWITCH_TOK = 58,                /* SWITCH_TOK  */
  YYSYMBOL_MAIN_TOK = 59,                  /* MAIN_TOK  */
  YYSYMBOL_INCLUDE_TOK = 60,               /* INCLUDE_TOK  */
  YYSYMBOL_PRINTF_TOK = 61,                /* PRINTF_TOK  */
  YYSYMBOL_SCANF_TOK = 62,                 /* SCANF_TOK  */
  YYSYMBOL_ID_TOK = 63,                    /* ID_TOK  */
  YYSYMBOL_INT_CONST_TOK = 64,             /* INT_CONST_TOK  */
  YYSYMBOL_CHAR_CONST_TOK = 65,            /* CHAR_CONST_TOK  */
  YYSYMBOL_REAL_CONST_TOK = 66,            /* REAL_CONST_TOK  */
  YYSYMBOL_STRING_CONST_TOK = 67,          /* STRING_CONST_TOK  */
  YYSYMBOL_INT_TOK = 68,                   /* INT_TOK  */
  YYSYMBOL_CHAR_TOK = 69,                  /* CHAR_TOK  */
  YYSYMBOL_FLOAT_TOK = 70,                 /* FLOAT_TOK  */
  YYSYMBOL_DOUBLE_TOK = 71,                /* DOUBLE_TOK  */
  YYSYMBOL_LONG_TOK = 72,                  /* LONG_TOK  */
  YYSYMBOL_SHORT_TOK = 73,                 /* SHORT_TOK  */
  YYSYMBOL_VOID_TOK = 74,                  /* VOID_TOK  */
  YYSYMBOL_YYACCEPT = 75,                  /* $accept  */
  YYSYMBOL_S = 76,                         /* S  */
  YYSYMBOL_S1 = 77,                        /* S1  */
  YYSYMBOL_open_paren = 78,                /* open_paren  */
  YYSYMBOL_close_paren = 79,               /* close_paren  */
  YYSYMBOL_header = 80,                    /* header  */
  YYSYMBOL_MAIN_FN = 81,                   /* MAIN_FN  */
  YYSYMBOL_82_1 = 82,                      /* $@1  */
  YYSYMBOL_USER_FN = 83,                   /* USER_FN  */
  YYSYMBOL_84_2 = 84,                      /* $@2  */
  YYSYMBOL_param = 85,                     /* param  */
  YYSYMBOL_params = 86,                    /* params  */
  YYSYMBOL_datatype = 87,                  /* datatype  */
  YYSYMBOL_start_block = 88,               /* start_block  */
  YYSYMBOL_end_block = 89,                 /* end_block  */
  YYSYMBOL_block = 90,                     /* block  */
  YYSYMBOL_blocks = 91,                    /* blocks  */
  YYSYMBOL_STATEMENTS = 92,                /* STATEMENTS  */
  YYSYMBOL_stmt = 93,                      /* stmt  */
  YYSYMBOL_PRINTF_ST = 94,                 /* PRINTF_ST  */
  YYSYMBOL_expression = 95,                /* expression  */
  YYSYMBOL_arith_op = 96,                  /* arith_op  */
  YYSYMBOL_DECLARE_ASSIGN = 97,            /* DECLARE_ASSIGN  */
  YYSYMBOL_array_ele = 98,                 /* array_ele  */
  YYSYMBOL_array_size = 99,                /* array_size  */
  YYSYMBOL_varlist = 100,                  /* varlist  */
  YYSYMBOL_EXP_ASSIGN = 101,               /* EXP_ASSIGN  */
  YYSYMBOL_IF_ST = 102,                    /* IF_ST  */
  YYSYMBOL_103_3 = 103,                    /* $@3  */
  YYSYMBOL_ELSE_PART = 104,                /* ELSE_PART  */
  YYSYMBOL_105_4 = 105,                    /* $@4  */
  YYSYMBOL_IF_PART = 106,                  /* IF_PART  */
  YYSYMBOL_CONDITIONAL = 107,              /* CONDITIONAL  */
  YYSYMBOL_cond_exp = 108,                 /* cond_exp  */
  YYSYMBOL_comparison = 109,               /* comparison  */
  YYSYMBOL_WHILE_ST = 110,                 /* WHILE_ST  */
  YYSYMBOL_111_5 = 111,                    /* $@5  */
  YYSYMBOL_ITERATIVE = 112,                /* ITERATIVE  */
  YYSYMBOL_FUNCTION_CALL = 113,            /* FUNCTION_CALL  */
  YYSYMBOL_args = 114,                     /* args  */
  YYSYMBOL_arg = 115                       /* arg  */
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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   205

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   329


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   369,   369,   370,   371,   372,   373,   376,   377,   378,
     379,   380,   381,   384,   387,   390,   391,   394,   394,   407,
     407,   426,   427,   430,   448,   468,   469,   470,   471,   472,
     475,   478,   481,   482,   485,   486,   487,   490,   491,   494,
     495,   496,   497,   498,   499,   505,   508,   511,   521,   531,
     536,   541,   546,   551,   554,   557,   577,   578,   579,   580,
     581,   584,   587,   593,   594,   600,   601,   607,   625,   643,
     672,   701,   719,   739,   761,   761,   774,   774,   788,   791,
     792,   799,   802,   822,   823,   824,   825,   826,   827,   828,
     829,   832,   832,   846,   858,   871,   872,   875,   876
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
  "\"end of file\"", "error", "\"invalid token\"", "LPAREN_TOK", "GT_TOK",
  "LT_TOK", "RPAREN_TOK", "ASSIGN_TOK", "MINUS_TOK", "PLUS_TOK",
  "MULT_TOK", "DIV_TOK", "MOD_TOK", "NOT_TOK", "SEMICOLON_TOK", "HASH_TOK",
  "DOT_TOK", "COMMA_TOK", "LCURL_TOK", "RCURL_TOK", "LSQUARE_TOK",
  "RSQUARE_TOK", "BIT_AND_TOK", "BIT_OR_TOK", "BACKSLASH_TOK",
  "SPEECH_TOK", "INVCOMMA_TOK", "XOR_TOK", "NEG_TOK", "EQ_TOK", "GTE_TOK",
  "LTE_TOK", "LSHIFT_TOK", "RSHIFT_TOK", "AND_TOK", "OR_TOK", "NEQ_TOK",
  "INC_TOK", "DEC_TOK", "PLUS_ASSIGN_TOK", "MINUS_ASSIGN_TOK",
  "MULT_ASSIGN_TOK", "DIV_ASSIGN_TOK", "MOD_ASSIGN_TOK", "DO_TOK",
  "WHILE_TOK", "FOR_TOK", "IF_TOK", "ELSE_TOK", "RET_TOK", "PRINT_TOK",
  "SCAN_TOK", "DEF_TOK", "TYPEDEF_TOK", "BREAK_TOK", "CONTINUE_TOK",
  "SIZEOF_TOK", "CASE_TOK", "SWITCH_TOK", "MAIN_TOK", "INCLUDE_TOK",
  "PRINTF_TOK", "SCANF_TOK", "ID_TOK", "INT_CONST_TOK", "CHAR_CONST_TOK",
  "REAL_CONST_TOK", "STRING_CONST_TOK", "INT_TOK", "CHAR_TOK", "FLOAT_TOK",
  "DOUBLE_TOK", "LONG_TOK", "SHORT_TOK", "VOID_TOK", "$accept", "S", "S1",
  "open_paren", "close_paren", "header", "MAIN_FN", "$@1", "USER_FN",
  "$@2", "param", "params", "datatype", "start_block", "end_block",
  "block", "blocks", "STATEMENTS", "stmt", "PRINTF_ST", "expression",
  "arith_op", "DECLARE_ASSIGN", "array_ele", "array_size", "varlist",
  "EXP_ASSIGN", "IF_ST", "$@3", "ELSE_PART", "$@4", "IF_PART",
  "CONDITIONAL", "cond_exp", "comparison", "WHILE_ST", "$@5", "ITERATIVE",
  "FUNCTION_CALL", "args", "arg", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-68)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -50,   -25,   -75,   -75,   -75,   -75,    42,    11,   -75,
      11,   -14,    38,     7,   -75,   -75,   -75,   -75,   -75,   -75,
      11,    63,    89,   -75,    11,    25,   -75,    80,   -75,    11,
       6,    39,    -5,    80,    87,   -75,   100,   119,    23,   108,
     -75,     6,     3,   -75,   -75,   -75,   -75,   156,   -75,    34,
     -75,   113,   114,   108,    39,    70,   -75,   -75,   134,    78,
     -75,    68,   -75,   112,     1,   -16,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,    39,     6,   -75,   -75,   -75,   -75,   139,
     -75,   -75,   128,   -75,   -75,   -75,     6,   144,    92,    39,
     -75,   -31,   129,    83,   -31,   -75,   135,   136,   108,   110,
     -75,   108,   -75,   155,   -75,   -75,   166,   164,   -75,   150,
     158,   -75,   187,   -75,    23,   169,   169,   180,   170,     6,
      83,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,     6,   -75,   -75,   -75,   -75,   -75,     6,     6,   -75,
     -75,   187,   -75,   108,   -75,   151,   134,   134,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,     6,   -75,   -75,
     187
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    25,    28,    26,    27,    29,     0,     3,     4,
       0,     0,     0,     0,    17,     1,     2,     5,     9,    11,
      10,     0,    19,    61,     0,     0,    16,     0,     7,    12,
       0,     0,     0,     0,    72,     6,     0,    13,     0,     0,
       8,     0,    47,    49,    51,    50,    52,    70,    53,    67,
      68,     0,     0,     0,     0,     0,    22,    25,     0,     0,
      30,     0,    18,     0,     0,     0,    48,    94,    57,    56,
      58,    59,    60,     0,     0,    65,    66,    20,    71,     0,
      14,    21,    24,    31,    91,    74,     0,     0,     0,     0,
      33,     0,     0,    36,    38,    45,     0,     0,     0,    80,
      41,     0,    42,     0,    54,    96,    97,     0,    64,     0,
       0,    69,    55,    15,     0,     0,     0,     0,     0,     0,
       0,    32,    35,    37,    39,    40,    78,    76,    79,    93,
      43,     0,    95,    62,    63,    23,    13,     0,     0,    44,
      46,    73,    34,     0,    98,    81,     0,     0,    77,    83,
      84,    88,    85,    86,    89,    90,    87,     0,    92,    75,
      82
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   185,    -7,   -40,   -35,    20,    21,   -75,    45,   -75,
     167,    88,   -36,   -75,   109,   -38,   -74,   -67,   -75,   -75,
     -30,   -75,    90,   -75,   -75,   -23,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,    65,   -75,   -75,   -75,   -75,   -58,   117,
      74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,    17,    38,    81,    18,    19,    27,    20,    33,
      39,    58,    11,    61,    90,    91,    92,    93,    94,    95,
     106,    74,    96,    66,    34,    23,    97,    98,   116,   128,
     143,    99,   100,   146,   157,   101,   115,   102,    48,    67,
     107
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    62,    59,   103,    41,   108,    64,   105,    50,    41,
      13,    63,    25,    28,    84,    77,    85,    35,    86,   122,
       8,     9,    40,    65,   120,    89,     1,   123,     8,     9,
      87,    78,    88,   103,    14,   103,   103,    57,     3,     4,
       5,    30,    15,     6,   112,    10,   142,   109,   110,    22,
     111,    31,    24,    10,    32,    89,   117,    89,    89,    51,
     126,    52,   103,   129,    42,    43,    44,    45,    46,    42,
      43,    44,    45,    46,    26,   137,   138,    29,    59,     2,
       3,     4,     5,    37,    89,     6,    60,    83,    36,   141,
      12,    57,     3,     4,     5,    64,    30,     6,    12,   119,
      21,    60,    49,   -67,    54,   148,    31,   145,   145,    32,
      21,   158,   159,    84,    21,    85,    55,    86,   104,    21,
      68,    69,    70,    71,    72,    56,    60,   160,    84,    87,
      85,    88,    86,    79,    75,    76,    57,     3,     4,     5,
      80,    82,     6,   113,    87,   114,    88,    64,    83,   124,
     125,    57,     3,     4,     5,   149,   150,     6,   127,    68,
      69,    70,    71,    72,    68,    69,    70,    71,    72,   130,
     132,   133,   136,    73,    68,    69,    70,    71,    72,   134,
     151,   152,   153,   131,   140,   154,   155,   156,    68,    69,
      70,    71,    72,    16,   139,    68,    69,    70,    71,    72,
      53,   121,   135,   147,   118,   144
};

static const yytype_uint8 yycheck[] =
{
      30,    39,    38,    61,     3,    21,     3,     6,    31,     3,
      60,    41,     5,    20,    45,    53,    47,    24,    49,    93,
       0,     0,    29,    20,    91,    61,    15,    94,     8,     8,
      61,    54,    63,    91,    59,    93,    94,    68,    69,    70,
      71,     7,     0,    74,    74,     0,   120,    63,    64,    63,
      73,    17,    14,     8,    20,    91,    86,    93,    94,    64,
      98,    66,   120,   101,    63,    64,    65,    66,    67,    63,
      64,    65,    66,    67,    67,   115,   116,    14,   114,    68,
      69,    70,    71,     3,   120,    74,    18,    19,    63,   119,
       0,    68,    69,    70,    71,     3,     7,    74,     8,     7,
      10,    18,    63,    14,    17,   143,    17,   137,   138,    20,
      20,   146,   147,    45,    24,    47,    16,    49,     6,    29,
       8,     9,    10,    11,    12,     6,    18,   157,    45,    61,
      47,    63,    49,    63,    21,    21,    68,    69,    70,    71,
       6,    63,    74,     4,    61,    17,    63,     3,    19,    14,
      14,    68,    69,    70,    71,     4,     5,    74,    48,     8,
       9,    10,    11,    12,     8,     9,    10,    11,    12,    14,
       6,    21,     3,    17,     8,     9,    10,    11,    12,    21,
      29,    30,    31,    17,    14,    34,    35,    36,     8,     9,
      10,    11,    12,     8,    14,     8,     9,    10,    11,    12,
      33,    92,   114,   138,    87,   131
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    68,    69,    70,    71,    74,    76,    80,    81,
      83,    87,    97,    60,    59,     0,    76,    77,    80,    81,
      83,    97,    63,   100,    14,     5,    67,    82,    77,    14,
       7,    17,    20,    84,    99,    77,    63,     3,    78,    85,
      77,     3,    63,    64,    65,    66,    67,    95,   113,    63,
     100,    64,    66,    85,    17,    16,     6,    68,    86,    87,
      18,    88,    90,    95,     3,    20,    98,   114,     8,     9,
      10,    11,    12,    17,    96,    21,    21,    90,   100,    63,
       6,    79,    63,    19,    45,    47,    49,    61,    63,    87,
      89,    90,    91,    92,    93,    94,    97,   101,   102,   106,
     107,   110,   112,   113,     6,     6,    95,   115,    21,    63,
      64,   100,    95,     4,    17,   111,   103,    95,   114,     7,
      92,    89,    91,    92,    14,    14,    90,    48,   104,    90,
      14,    17,     6,    21,    21,    86,     3,    78,    78,    14,
      14,    95,    91,   105,   115,    95,   108,   108,    90,     4,
       5,    29,    30,    31,    34,    35,    36,   109,    79,    79,
      95
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    75,    76,    76,    76,    76,    76,    77,    77,    77,
      77,    77,    77,    78,    79,    80,    80,    82,    81,    84,
      83,    85,    85,    86,    86,    87,    87,    87,    87,    87,
      88,    89,    90,    90,    91,    91,    91,    92,    92,    93,
      93,    93,    93,    93,    93,    93,    94,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    96,    96,
      96,    97,    98,    98,    98,    99,    99,   100,   100,   100,
     100,   100,   100,   101,   103,   102,   105,   104,   106,   107,
     107,   108,   108,   109,   109,   109,   109,   109,   109,   109,
     109,   111,   110,   112,   113,   114,   114,   115,   115
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     3,     2,     3,     1,
       1,     1,     2,     1,     1,     7,     3,     0,     5,     0,
       5,     3,     2,     4,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     3,     2,     1,     2,     1,     2,
       2,     1,     1,     2,     3,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     1,
       1,     2,     3,     3,     2,     3,     3,     1,     3,     5,
       3,     4,     2,     3,     0,     5,     0,     3,     2,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     2,     2,     3,     2,     1,     3
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
  case 13: /* open_paren: LPAREN_TOK  */
#line 384 "parser.y"
                                                                                                                        {scope++;}
#line 1755 "y.tab.c"
    break;

  case 14: /* close_paren: RPAREN_TOK  */
#line 387 "parser.y"
                                                                                                                {scope--;}
#line 1761 "y.tab.c"
    break;

  case 15: /* header: HASH_TOK INCLUDE_TOK LT_TOK ID_TOK DOT_TOK ID_TOK GT_TOK  */
#line 390 "parser.y"
                                                                                                {printf("Header syntax correct;\tline no:\t%d\n", yylineno);}
#line 1767 "y.tab.c"
    break;

  case 16: /* header: HASH_TOK INCLUDE_TOK STRING_CONST_TOK  */
#line 391 "parser.y"
                                                                                                                {printf("Header syntax correct;\tline no:\t%d\n", yylineno);}
#line 1773 "y.tab.c"
    break;

  case 17: /* $@1: %empty  */
#line 394 "parser.y"
                                                                                {	char msg[50];
														sprintf(msg, "main:\n");
														generate(interm_label, msg);
														interm_label++;
													}
#line 1783 "y.tab.c"
    break;

  case 18: /* MAIN_FN: INT_TOK MAIN_TOK $@1 param block  */
#line 399 "parser.y"
                                                                                        {	char msg[50];
														sprintf(msg, "end main\n");
														generate(interm_label, msg);
														interm_label++;
														printf("Main function syntax OK;\tline no:\t%d\n", yylineno);
													}
#line 1794 "y.tab.c"
    break;

  case 19: /* $@2: %empty  */
#line 407 "parser.y"
                                                                                {	int c = addFunction((yyvsp[0].string)); 
														if(c == -1) { 
															char msg[100]; 
															sprintf(msg, ": Symbol table full"); 
															yyerror(msg);
														}
														char msg[50];
														sprintf(msg, "%s:\n", (yyvsp[0].string));
														generate(interm_label, msg);
														interm_label++;
													}
#line 1810 "y.tab.c"
    break;

  case 20: /* USER_FN: datatype ID_TOK $@2 param block  */
#line 418 "parser.y"
                                                                                        {	char msg[50];
														sprintf(msg, "end %s\n", (yyvsp[-3].string));
														generate(interm_label, msg);
														interm_label++;
														printf("User defined function OK;\tline no:\t%d\n", yylineno);
													}
#line 1821 "y.tab.c"
    break;

  case 23: /* params: datatype ID_TOK COMMA_TOK params  */
#line 430 "parser.y"
                                                                                                {	int c = alreadyDeclared((yyvsp[-2].string));
																		char msg[100];
																		if(c == 1) {
																			sprintf(msg, ": Multiple declarations of the identifier in same scope");
																			yyerror(msg);
																		}
																		else if(c == 2) {
																			sprintf(msg, ": Conflicting types for identifier");
																			yyerror(msg);
																		}
																		else {
																			int x = addSymbol((yyvsp[-2].string));
																			if(x == -1) {
																				sprintf(msg, ": Symbol table full");
																				yyerror(msg);
																			}
																		}
																	}
#line 1844 "y.tab.c"
    break;

  case 24: /* params: datatype ID_TOK  */
#line 448 "parser.y"
                                                                                                                        {	int c = alreadyDeclared((yyvsp[0].string));
																		char msg[100];
																		if(c == 1) {
																			sprintf(msg, ": Multiple declarations of the identifier in same scope");
																			yyerror(msg);
																		}
																		else if(c == 2) {
																			sprintf(msg, ": Conflicting types for identifier");
																			yyerror(msg);
																		}
																		else {
																			int x = addSymbol((yyvsp[0].string));
																			if(x == -1) {
																				sprintf(msg, ": Symbol table full");
																				yyerror(msg);
																			}
																		}
																	}
#line 1867 "y.tab.c"
    break;

  case 25: /* datatype: INT_TOK  */
#line 468 "parser.y"
                                                                                                                        {dtype = 1;}
#line 1873 "y.tab.c"
    break;

  case 26: /* datatype: FLOAT_TOK  */
#line 469 "parser.y"
                                                                                                                                {dtype = 2;}
#line 1879 "y.tab.c"
    break;

  case 27: /* datatype: DOUBLE_TOK  */
#line 470 "parser.y"
                                                                                                                        {dtype = 2;}
#line 1885 "y.tab.c"
    break;

  case 28: /* datatype: CHAR_TOK  */
#line 471 "parser.y"
                                                                                                                                {dtype = 4;}
#line 1891 "y.tab.c"
    break;

  case 29: /* datatype: VOID_TOK  */
#line 472 "parser.y"
                                                                                                                                {dtype = 5;}
#line 1897 "y.tab.c"
    break;

  case 30: /* start_block: LCURL_TOK  */
#line 475 "parser.y"
                                                                                                                {scope++;}
#line 1903 "y.tab.c"
    break;

  case 31: /* end_block: RCURL_TOK  */
#line 478 "parser.y"
                                                                                                                        {deleteScopeSyms(scope); scope--;}
#line 1909 "y.tab.c"
    break;

  case 39: /* stmt: DECLARE_ASSIGN SEMICOLON_TOK  */
#line 494 "parser.y"
                                                                                                {printf("Declaration over;\tline no:\t%d\n", yylineno);}
#line 1915 "y.tab.c"
    break;

  case 40: /* stmt: EXP_ASSIGN SEMICOLON_TOK  */
#line 495 "parser.y"
                                                                                                                {printf("Assignment over;\tline no:\t%d\n", yylineno);}
#line 1921 "y.tab.c"
    break;

  case 41: /* stmt: CONDITIONAL  */
#line 496 "parser.y"
                                                                                                                        {printf("Conditional block ends;\tline no:\t%d\n", yylineno);}
#line 1927 "y.tab.c"
    break;

  case 42: /* stmt: ITERATIVE  */
#line 497 "parser.y"
                                                                                                                                {printf("Iterative block ends;\tline no:\t%d\n", yylineno);}
#line 1933 "y.tab.c"
    break;

  case 44: /* stmt: RET_TOK expression SEMICOLON_TOK  */
#line 499 "parser.y"
                                                                                                        {	char msg[50];
																		sprintf(msg, "return %s\n", (yyvsp[-1].Dtype).place);
																		generate(interm_label, msg);
																		interm_label++;
																		printf("Return statement found;\tline no:\t%d\n", yylineno);
																	}
#line 1944 "y.tab.c"
    break;

  case 46: /* PRINTF_ST: PRINTF_TOK args SEMICOLON_TOK  */
#line 508 "parser.y"
                                                                                                {printf("printf statement found;\tline no:\t%d\n", yylineno);}
#line 1950 "y.tab.c"
    break;

  case 47: /* expression: ID_TOK  */
#line 511 "parser.y"
                                                                                                                        {	if(!isPresent((yyvsp[0].string))) {
																			char msg[100];
																			sprintf(msg, ": Undefined identifier found");
																			yyerror(msg);
																		}
																		else {
																			(yyval.Dtype).dtype = getDatatype((yyvsp[0].string));
																			(yyval.Dtype).place = strdup((yyvsp[0].string));
																		}
																	}
#line 1965 "y.tab.c"
    break;

  case 48: /* expression: ID_TOK array_ele  */
#line 521 "parser.y"
                                                                                                                        {	if(!isPresent((yyvsp[-1].string))) {
																			char msg[100];
																			sprintf(msg, ": Undefined identifier found");
																			yyerror(msg);
																		}
																		else {
																			(yyval.Dtype).dtype = getDatatype((yyvsp[-1].string));
																			(yyval.Dtype).place = strdup((yyvsp[-1].string));
																		}
																	}
#line 1980 "y.tab.c"
    break;

  case 49: /* expression: INT_CONST_TOK  */
#line 531 "parser.y"
                                                                                                                        {	(yyval.Dtype).dtype = 1;
				   														char tmp[20];
																		sprintf(tmp, "%d", (yyvsp[0].number));
																		(yyval.Dtype).place = strdup(tmp);
																	}
#line 1990 "y.tab.c"
    break;

  case 50: /* expression: REAL_CONST_TOK  */
#line 536 "parser.y"
                                                                                                                        {	(yyval.Dtype).dtype = 2;
																		char tmp[20];
																		sprintf(tmp, "%.2f", (yyvsp[0].decimal));
																		(yyval.Dtype).place = strdup(tmp);
																	}
#line 2000 "y.tab.c"
    break;

  case 51: /* expression: CHAR_CONST_TOK  */
#line 541 "parser.y"
                                                                                                                        {	(yyval.Dtype).dtype = 4;
																		char tmp[5];
																		sprintf(tmp, "%s", (yyvsp[0].string));
																		(yyval.Dtype).place = strdup(tmp);
																	}
#line 2010 "y.tab.c"
    break;

  case 52: /* expression: STRING_CONST_TOK  */
#line 546 "parser.y"
                                                                                                                        {	(yyval.Dtype).dtype = 5;
																		char tmp[100];
																		sprintf(tmp, "%s", (yyvsp[0].string));
																		(yyval.Dtype).place = strdup(tmp);
																	}
#line 2020 "y.tab.c"
    break;

  case 53: /* expression: FUNCTION_CALL  */
#line 551 "parser.y"
                                                                                                                        {	(yyval.Dtype).dtype = (yyvsp[0].Dtype).dtype;
																		(yyval.Dtype).place = strdup((yyvsp[0].Dtype).place);
																	}
#line 2028 "y.tab.c"
    break;

  case 54: /* expression: LPAREN_TOK expression RPAREN_TOK  */
#line 554 "parser.y"
                                                                                                        {	(yyval.Dtype).dtype = (yyvsp[-1].Dtype).dtype;
																		(yyval.Dtype).place = strdup((yyvsp[-1].Dtype).place);
																	}
#line 2036 "y.tab.c"
    break;

  case 55: /* expression: expression arith_op expression  */
#line 557 "parser.y"
                                                                                                        {	if((yyvsp[-2].Dtype).dtype != (yyvsp[0].Dtype).dtype) {
																			char msg[100];
																			sprintf(msg, ": Type matching error in expression");
																			yyerror(msg);
																		}
																		else {
																			char *tmp = new_temp_var();
																			new_tmp_index++;
																			(yyval.Dtype).place = strdup(tmp);

																			char msg[50];
																			sprintf(msg, "%s = %s %s %s\n", (yyval.Dtype).place, (yyvsp[-2].Dtype).place, (yyvsp[-1].string), (yyvsp[0].Dtype).place);
																			generate(interm_label, msg);
																			strcpy(expr_var, (yyval.Dtype).place);
																			interm_label++;
																		}
																		(yyval.Dtype).dtype = (yyvsp[-2].Dtype).dtype;
																	}
#line 2059 "y.tab.c"
    break;

  case 56: /* arith_op: PLUS_TOK  */
#line 577 "parser.y"
                                        {(yyval.string) = strdup((yyvsp[0].string));}
#line 2065 "y.tab.c"
    break;

  case 57: /* arith_op: MINUS_TOK  */
#line 578 "parser.y"
                                                {(yyval.string) = strdup((yyvsp[0].string));}
#line 2071 "y.tab.c"
    break;

  case 58: /* arith_op: MULT_TOK  */
#line 579 "parser.y"
                                                {(yyval.string) = strdup((yyvsp[0].string));}
#line 2077 "y.tab.c"
    break;

  case 59: /* arith_op: DIV_TOK  */
#line 580 "parser.y"
                                                {(yyval.string) = strdup((yyvsp[0].string));}
#line 2083 "y.tab.c"
    break;

  case 60: /* arith_op: MOD_TOK  */
#line 581 "parser.y"
                                                {(yyval.string) = strdup((yyvsp[0].string));}
#line 2089 "y.tab.c"
    break;

  case 62: /* array_ele: LSQUARE_TOK ID_TOK RSQUARE_TOK  */
#line 587 "parser.y"
                                                                                                {	if(!isPresent((yyvsp[-1].string))) {
																			char msg[100];
																			sprintf(msg, ": Undeclared identifier found");
																			yyerror(msg);
																		}
																	}
#line 2100 "y.tab.c"
    break;

  case 64: /* array_ele: LSQUARE_TOK RSQUARE_TOK  */
#line 594 "parser.y"
                                                                                                                {	char msg[100];
																		sprintf(msg, ": Unspecified array element access");
																		yyerror(msg);
																	}
#line 2109 "y.tab.c"
    break;

  case 66: /* array_size: LSQUARE_TOK REAL_CONST_TOK RSQUARE_TOK  */
#line 601 "parser.y"
                                                                                                {	char msg[100];
																		sprintf(msg, ": Incorrect type for array size");
																		yyerror(msg);
																	}
#line 2118 "y.tab.c"
    break;

  case 67: /* varlist: ID_TOK  */
#line 607 "parser.y"
                                                                                                                        {	int c = alreadyDeclared((yyvsp[0].string));
																		char msg[100];
																		if(c == 1) {
																			sprintf(msg, ": Multiple declarations of the identifier in same scope");
																			yyerror(msg);
																		}
																		else if(c == 2) {
																			sprintf(msg, ": Conflicting types for identifier");
																			yyerror(msg);
																		}
																		else {
																			int x = addSymbol((yyvsp[0].string));
																			if(x == -1) {
																				sprintf(msg, ": Symbol table full");
																				yyerror(msg);
																			}
																		}
																	}
#line 2141 "y.tab.c"
    break;

  case 68: /* varlist: ID_TOK COMMA_TOK varlist  */
#line 625 "parser.y"
                                                                                                        {	int c = alreadyDeclared((yyvsp[-2].string));
																		char msg[100];
																		if(c == 1) {
																			sprintf(msg, ": Multiple declarations of the identifier in same scope");
																			yyerror(msg);
																		}
																		else if(c == 2) {
																			sprintf(msg, ": Conflicting types for identifier");
																			yyerror(msg);
																		}
																		else {
																			int x = addSymbol((yyvsp[-2].string));
																			if(x == -1) {
																				sprintf(msg, ": Symbol table full");
																				yyerror(msg);
																			}
																		}
																	}
#line 2164 "y.tab.c"
    break;

  case 69: /* varlist: ID_TOK ASSIGN_TOK expression COMMA_TOK varlist  */
#line 643 "parser.y"
                                                                                        {	int c = alreadyDeclared((yyvsp[-4].string));
																		char msg[100];
																		if(c == 1) {
																			sprintf(msg, ": Multiple declarations of identifier in same scope");
																			yyerror(msg);
																		}
																		else if(c == 2) {
																			sprintf(msg, ": Conflicting types for identifier");
																			yyerror(msg);
																		}
																		else {
																			int x = addSymbol((yyvsp[-4].string));
																			if(x == -1) {
																				sprintf(msg, ": Symbol table full");
																				yyerror(msg);
																			}
																		}
																		if(dtype != (yyvsp[-2].Dtype).dtype) {
																			sprintf(msg, ": Type mismatch between identifier and expression");
																			yyerror(msg);
																		}
																		else {
																			char msg[100];
																			sprintf(msg, "%s = %s\n", (yyvsp[-4].string), (yyvsp[-2].Dtype).place);
																			generate(interm_label, msg);
																			strcpy(expr_var, (yyvsp[-4].string));
																			interm_label++;
																		}
																	}
#line 2198 "y.tab.c"
    break;

  case 70: /* varlist: ID_TOK ASSIGN_TOK expression  */
#line 672 "parser.y"
                                                                                                        {	int c = alreadyDeclared((yyvsp[-2].string));
																		char msg[100];
																		if(c == 1) {
																			sprintf(msg, ": Multiple declarations of identifier in same scope");
																			yyerror(msg);
																		}
																		else if(c == 2) {
																			sprintf(msg, ": Conflicting types for identifier");
																			yyerror(msg);
																		}
																		else {
																			int x = addSymbol((yyvsp[-2].string));
																			if(x == -1) {
																				sprintf(msg, ": Symbol table full");
																				yyerror(msg);
																			}
																		}
																		if(getDatatype((yyvsp[-2].string)) != (yyvsp[0].Dtype).dtype) {
																			sprintf(msg, ": Type mismatch between identifier and expression");
																			yyerror(msg);
																		}
																		else {
																			char msg[100];
																			sprintf(msg, "%s = %s\n", (yyvsp[-2].string), (yyvsp[0].Dtype).place);
																			generate(interm_label, msg);
																			strcpy(expr_var, (yyvsp[-2].string));
																			interm_label++;
																		}
																	}
#line 2232 "y.tab.c"
    break;

  case 71: /* varlist: ID_TOK array_size COMMA_TOK varlist  */
#line 701 "parser.y"
                                                                                                {	int c = alreadyDeclared((yyvsp[-3].string));
																		char msg[100];
																		if(c == 1) {
																			sprintf(msg, ": Multiple declarations of identifier in same scope");
																			yyerror(msg);
																		}
																		else if(c == 2) {
																			sprintf(msg, ": Conflicting types for identifier");
																			yyerror(msg);
																		}
																		else {
																			int x = addSymbol((yyvsp[-3].string));
																			if(x == -1) {
																				sprintf(msg, ": Symbol table full");
																				yyerror(msg);
																			}
																		}
																	}
#line 2255 "y.tab.c"
    break;

  case 72: /* varlist: ID_TOK array_size  */
#line 719 "parser.y"
                                                                                                                        {	int c = alreadyDeclared((yyvsp[-1].string));
																		char msg[100];
																		if(c == 1) {
																			sprintf(msg, ": Multiple declarations of identifier in same scope");
																			yyerror(msg);
																		}
																		else if(c == 2) {
																			sprintf(msg, ": Conflicting types for identifier");
																			yyerror(msg);
																		}
																		else {
																			int x = addSymbol((yyvsp[-1].string));
																			if(x == -1) {
																				sprintf(msg, ": Symbol table full");
																				yyerror(msg);
																			}
																		}
																	}
#line 2278 "y.tab.c"
    break;

  case 73: /* EXP_ASSIGN: ID_TOK ASSIGN_TOK expression  */
#line 739 "parser.y"
                                                                                                {	if(!isPresent((yyvsp[-2].string))) {
																			char msg[100];
																			sprintf(msg, ": Undefined identifier found");
																			yyerror(msg);
																		}
																		else {
																			if(getDatatype((yyvsp[-2].string)) != (yyvsp[0].Dtype).dtype) {
																				char msg[100];
																				sprintf(msg, ": Type mismatch between identifier and expression");
																				yyerror(msg);
																			}
																			else {
																				char msg[100];
																				sprintf(msg, "%s = %s\n", (yyvsp[-2].string), (yyvsp[0].Dtype).place);
																				generate(interm_label, msg);
																				strcpy(expr_var, (yyvsp[-2].string));
																				interm_label++;
																			}
																		}
																	}
#line 2303 "y.tab.c"
    break;

  case 74: /* $@3: %empty  */
#line 761 "parser.y"
                               {temp_label = interm_label;}
#line 2309 "y.tab.c"
    break;

  case 75: /* IF_ST: IF_TOK $@3 open_paren cond_exp close_paren  */
#line 762 "parser.y"
                                                                                                        {	char *tmp = new_temp_var();
																		new_tmp_index++;
																		char msg[50];
																		sprintf(msg, "%s = not %s\n", tmp, expr_var);
																		generate(interm_label, msg);
																		interm_label++;
																		backpatch_label = interm_label;
																		strcpy(tmp_var, tmp);
																		interm_label++;
																	}
#line 2324 "y.tab.c"
    break;

  case 76: /* $@4: %empty  */
#line 774 "parser.y"
                                        {	
								char msg[50];
								sprintf(msg, "if %s goto %d\n", tmp_var, interm_label+1);
								generate(backpatch_label, msg);
								backpatch_label = interm_label;
								interm_label++;
							}
#line 2336 "y.tab.c"
    break;

  case 77: /* ELSE_PART: ELSE_TOK $@4 block  */
#line 781 "parser.y"
                                                {	
								char msg[50];
								sprintf(msg, "goto %d\n", interm_label);
								generate(backpatch_label, msg);
							}
#line 2346 "y.tab.c"
    break;

  case 80: /* CONDITIONAL: IF_PART  */
#line 792 "parser.y"
                                        {	
								char msg[50];
								sprintf(msg, "if %s goto %d\n", tmp_var, interm_label);
								generate(backpatch_label, msg);
							}
#line 2356 "y.tab.c"
    break;

  case 81: /* cond_exp: expression  */
#line 799 "parser.y"
                                                                                                                        {	(yyval.Dtype).dtype = (yyvsp[0].Dtype).dtype;
																		(yyval.Dtype).place = strdup((yyvsp[0].Dtype).place);
																	}
#line 2364 "y.tab.c"
    break;

  case 82: /* cond_exp: expression comparison expression  */
#line 802 "parser.y"
                                                                                                        {	if((yyvsp[-2].Dtype).dtype != (yyvsp[0].Dtype).dtype) {
																			char msg[100];
																			sprintf(msg, ": Type matching error in expression");
																			yyerror(msg);
																		}
																		else {
																			char *tmp = new_temp_var();
																			new_tmp_index++;
																			(yyval.Dtype).place = strdup(tmp);

																			char msg[50];
																			sprintf(msg, "%s = %s %s %s\n", (yyval.Dtype).place, (yyvsp[-2].Dtype).place, (yyvsp[-1].string), (yyvsp[0].Dtype).place);
																			generate(interm_label, msg);
																			strcpy(expr_var, (yyval.Dtype).place);
																			interm_label++;
																		}
																		(yyval.Dtype).dtype = (yyvsp[-2].Dtype).dtype;
																	}
#line 2387 "y.tab.c"
    break;

  case 83: /* comparison: GT_TOK  */
#line 822 "parser.y"
                                        {(yyval.string) = strdup((yyvsp[0].string));}
#line 2393 "y.tab.c"
    break;

  case 84: /* comparison: LT_TOK  */
#line 823 "parser.y"
                                                {(yyval.string) = strdup((yyvsp[0].string));}
#line 2399 "y.tab.c"
    break;

  case 85: /* comparison: GTE_TOK  */
#line 824 "parser.y"
                                                {(yyval.string) = strdup((yyvsp[0].string));}
#line 2405 "y.tab.c"
    break;

  case 86: /* comparison: LTE_TOK  */
#line 825 "parser.y"
                                                {(yyval.string) = strdup((yyvsp[0].string));}
#line 2411 "y.tab.c"
    break;

  case 87: /* comparison: NEQ_TOK  */
#line 826 "parser.y"
                                                {(yyval.string) = strdup((yyvsp[0].string));}
#line 2417 "y.tab.c"
    break;

  case 88: /* comparison: EQ_TOK  */
#line 827 "parser.y"
                                                {(yyval.string) = strdup((yyvsp[0].string));}
#line 2423 "y.tab.c"
    break;

  case 89: /* comparison: AND_TOK  */
#line 828 "parser.y"
                                                {(yyval.string) = strdup((yyvsp[0].string));}
#line 2429 "y.tab.c"
    break;

  case 90: /* comparison: OR_TOK  */
#line 829 "parser.y"
                                                {(yyval.string) = strdup((yyvsp[0].string));}
#line 2435 "y.tab.c"
    break;

  case 91: /* $@5: %empty  */
#line 832 "parser.y"
                                  {temp_label = interm_label;}
#line 2441 "y.tab.c"
    break;

  case 92: /* WHILE_ST: WHILE_TOK $@5 open_paren cond_exp close_paren  */
#line 833 "parser.y"
                                                                                {	
															char *tmp = new_temp_var();
															new_tmp_index++;
															char msg[50];
															sprintf(msg, "%s = not %s\n", tmp, expr_var);
															generate(interm_label, msg);
															interm_label++;
															backpatch_label = interm_label;
															strcpy(tmp_var, tmp);
															interm_label++;
														}
#line 2457 "y.tab.c"
    break;

  case 93: /* ITERATIVE: WHILE_ST block  */
#line 846 "parser.y"
                                                                                        {
															char msg[50];
															sprintf(msg, "goto %d\n", temp_label);
															generate(interm_label, msg);
															interm_label++;

															
															sprintf(msg, "if %s goto %d\n", tmp_var, interm_label);
															generate(backpatch_label, msg);
														}
#line 2472 "y.tab.c"
    break;

  case 94: /* FUNCTION_CALL: ID_TOK args  */
#line 858 "parser.y"
                                                                                                                {	printf("Function call statement found;\tline no:\t%d\n", yylineno);
																		if(!isPresent((yyvsp[-1].string))) {
																			char msg[100];
																			sprintf(msg, ": Undeclared identifier found");
																			yyerror(msg);
																		}
																		else {
																			(yyval.Dtype).dtype = getDatatype((yyvsp[-1].string));
																			(yyval.Dtype).place = strdup((yyvsp[-1].string));
																		}
																	}
#line 2488 "y.tab.c"
    break;


#line 2492 "y.tab.c"

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

#line 879 "parser.y"


void yyerror(char *s) {
	flag = 1;
	printf("\nParsing error at line: %d; Error%s\n\n", yylineno, s);
}

int main() {
	yyin = fopen("test.c", "r");
	out_file = fopen("im-code.txt", "w");
	setupSymbolTable();
	if(yyparse() == 0){
		if(flag == 0)
			printf("Parsed Successfully\n");
		else
			printf("Parsing Finished\n");
	}
	else {
		printf("\nSyntax error at line no.: %d\n", yylineno);
		printf("Last read token: %s\n", yytext);
	}
	write_to_file();
	fclose(yyin);
	fclose(out_file);
	freeTable();
	return 0;
}

