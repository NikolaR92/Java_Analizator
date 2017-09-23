%option noyywrap
%option nounput
%{

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "parser.tab.hpp"

%}

%x M_LINE_COMMENT S_LINE_COMMENT


%%
"class" return CLASS_TOKEN;
"extends" return EXTEND_TOKEN;
"public" return PUBLIC_TOKEN;
"private" return PRIVATE_TOKEN;
"protected" return PROTECTED_TOKEN;
"static" return STATIC_TOKEN;
"final" return FINAL_TOKEN;
"return" return RETURN_TOKEN;
"null" return NULL_TOKEN;
"this" return THIS_TOKEN;
"super" return SUPER_TOKEN;
"true" return TRUE_TOKEN;
"false" return FALSE_TOKEN;
"new" return NEW_TOKEN;
"boolean" return BOOLEAN_TOKEN;
"char" return CHAR_TOKEN;
"int" return INT_TOKEN;
"float" return FLOAT_TOKEN;
"double" return DOUBLE_TOKEN;
"if" return IF_TOKEN;
"else" return ELSE_TOKEN;
"do" return DO_TOKEN;
"while" return WHILE_TOKEN;
"for" return FOR_TOKEN;
"import" return IMPORT_TOKEN;
"package" return PACKAGE_TOKEN;

"++" return PLUS_PLUS_TOKEN;
"--" return MINUS_MINUS_TOKEN;
"-=" return MINUS_EQ_TOKEN;
"+=" return PLUS_EQ_TOKEN;
"*=" return MULT_EQ_TOKEN;
"/=" return DIV_EQ_TOKEN;
"%=" return MOD_EQ_TOKEN;
">=" return GT_EQ_TOKEN;
"<=" return LT_EQ_TOKEN;
"==" return EQ_EQ_TOKEN;
"!=" return NOT_EQ_TOKEN;
"&&" return AND_TOKEN;
"||" return OR_TOKEN;
"\[\]" return DIM_TOKEN;

[+-]?[0-9]+ return int_token;
[+-]?[0-9]+\.?[0-9]* return float_token;
[-<>:=.()+*/{}\[\]!%;,] return *yytext;
[a-zA-Z$_][a-zA-Z$0-9_]* return ID_TOKEN;
\'[a-zA-Z0-9]\' return char_token;

"/*" { BEGIN(M_LINE_COMMENT); }
<M_LINE_COMMENT>"*/" {BEGIN(INITIAL);}
<M_LINE_COMMENT>.* { }
<M_LINE_COMMENT>\n { }



"//" { BEGIN(S_LINE_COMMENT); }
<S_LINE_COMMENT>\n {BEGIN(INITIAL);}
<S_LINE_COMMENT>.* { }

[ \t\n]  { }

. {
	cerr << "Leksicka greska: nepoznat karakter" << *yytext <<endl;
	exit(EXIT_FAILURE);
	}
%%
