all:test

test:lista_test
	./test/lista_test

lista.o: lista.c lista.h
	gcc -c src/lista.c

lista_test.o: lista_test.c lista.h
	gcc -c test/lista_test.c

lista_test: lista_test.o lista.c
	gcc lista_test.o lista.o -o lista_test

clean: 
	rm -fv lista_test lista_test.o lista.o
