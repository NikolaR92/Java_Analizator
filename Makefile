PROGRAM = java

program: sub-make
	mv src/$(PROGRAM) .
	
sub-make:
	$(MAKE) -C src/
	
.PHONY: clean beauty

clean:
	-rm src/*.o src/*tab* src/*~ src/lex.yy.* *.output $(PROGRAM)