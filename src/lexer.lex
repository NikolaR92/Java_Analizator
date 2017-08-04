%option noyywrap
%option nounput
%{

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include parser.tab.hpp

%}

%%

/* kljucene reci u java jeziku */
public return PUBLIC_TOKEN;
class return CLASS_TOKEN;
static return STATIC_TOKEN;
if return IF_TOKEN;
else return ELSE_TOKEN;
new return NEW_TOKEN;

/* tokeni tipova */
void return VOID_TOKEN;
char return CHAR_TOKEN;
double return DOUBLE_TOKEN;
float return FLOAT_TOKEN;
int return INT_TOKEN;
[A-Z][A-Za-z0-9_]* return OBJECT_TOKEN;

/*ostali znakovi*/
[0-9]+ return BROJ_TOKEN;
["](\\["]|[^"])*["] return STRING_TOKEN;
[<>:=.();+*/-{}\[\]] return *yytext;
[a-z_][a-z0-9_] return ID_TOKEN;

[ \t\n]  { }

. {
	fprintf(stderr,"Leksicka greska: nepoznat karakter '%c'\n",*yytext);
	exit(EXIT_FAILURE);
	}
%%
