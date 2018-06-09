CC = g++
CFLAGS = -Wall
PROGS = java

$(PROGS): lex.yy.o parser.tab.o Syntree.o TypeTree.o SymbolTable.o InnerSynTree.o Method.o
	$(CC) $(CFLAGS) -o $@ $^
	
parser.tab.o: parser.tab.cpp parser.tab.hpp Syntree.hpp InnerSynTree.hpp TypeTree.hpp SymbolTable.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
	
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v $<
	
lex.yy.o: lex.yy.c parser.tab.hpp Syntree.hpp InnerSynTree.hpp TypeTree.hpp SymbolTable.hpp
	$(CC) $(CFLAGS) -Wno-sign-compare -c -o $@ $<
	
lex.yy.c: lexer.lex
	flex $<
	
Syntree.o: Syntree.cpp Syntree.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

InnerSynTree.o: InnerSynTree.cpp InnerSynTree.hpp 
	$(CC) $(CFLAGS) -c -o $@ $<
	
TypeTree.o: TypeTree.cpp TypeTree.hpp 
	$(CC) $(CFLAGS) -c -o $@ $<
	
SymbolTable.o: SymbolTable.cpp SymbolTable.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

Method.o: Method.cpp Method.hpp
	$(CC) $(CFLAGS) -c -o $@ $<