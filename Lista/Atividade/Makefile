all:test

test:lista_test
	./test/lista_test

lista.o: lista.c lista.h
	gcc -c ./src/lista.c

lista_test.o: lista_test.c lista.h
	gcc -I"./src/lista.h" -c ./test/lista_test.c

lista_test: lista_test.o lista.c
	gcc ./test/lista_test.o ./src/lista.o -o ./test/lista_test

clean: 
	rm -fv ./test/lista_test ./test/lista_test.o ./src/lista.o
