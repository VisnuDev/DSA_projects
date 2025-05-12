OBJ=$(patsubst %c, %o, $(wildcard *.c))
res_apc.out : $(OBJ)
	gcc -o $@ $^

clean : 
	rm *.o *.exe *.out

