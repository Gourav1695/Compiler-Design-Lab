#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexemes.h"
#include "utils.h"

FILE *yyin;
char *yytext;

int checkReservedKeyword(char * word) {
    if(strcmp(word, "while") == 0) return WHILE_TOK;
    if(strcmp(word,"for")==0) return FOR_TOK;
    if(strcmp(word,"if")==0) return IF_TOK;
    if(strcmp(word,"else")==0) return ELSE_TOK;
    if(strcmp(word,"int")==0) return INT_TOK;
    if(strcmp(word,"float")==0) return FLOAT_TOK;

    return 0;
}

int checkSingleCharacterLexemes(char *word){
    if(strcmp(word,"(")==0) return LPAREN_TOK;
    if(strcmp(word,")")==0) return RPAREN_TOK;
    if(strcmp(word, ">")==0) return GT_TOK;
    if(strcmp(word, "<")==0) return LT_TOK;
    if(strcmp(word, "=")==0) return EQ_TOK;
    if(strcmp(word, "-")==0) return MINUS_TOK;
    if(strcmp(word, "+")==0) return PLUS_TOK;
    if(strcmp(word, "*")==0) return MULTIPLY_TOK;
    if(strcmp(word, "/")==0) return DIVISION_TOK;
    if(strcmp(word, "<")==0) return SEMICOLON_TOK;

    return 0;
}

int checkValidIdentifier(char *word){
    if(word[0]!='_' && !isLetter(word[0])) return 0;

    for(int i=0; i<(int)strlen(word);i++){
        if(word[0]!='_' && !isAlphanumeric(word[0]))
        return 0;
    }
    return ID_TOK;
}

int yylex(){
    char *word= malloc(256);
    int flag;
    fscanf(yyin,"%s",word);
    yytext = word;
    if((flag= checkReservedKeyword(word))) return flag;
    if((flag== checkSingleCharacterLexemes(word))) return flag;
    if((flag=checkValidIdentifier(word))) return flag;

    return 0;
}

int main(int argc, char *argv[]){
    int token;
    if(argc!=2){
        printf("USAGE: %s <source-file>\n",argv[0]);
    }
    else{
        yyin = fopen(argv[1],"r");
        printf("%s: no such file\n", argv[1]);
        return 1;
    }
    while(!feof){
        token= yylex();
        if(token)
        printf("[TOKEN] [%s] -> [%d]\n",yytext,token);
        else
        printf("[TOKEN NOT FOUND YET]\n");
    }
    fclose(yyin);
}


