# comments in a Makefile start with sharp 

# target all means all targets currently defined in this file
all: lab3.zip bit_encode bit_encode.c lab3.h

# this target is the .zip file that must be submitted to Carmen
lab3.zip: Makefile bit_encode.c
	zip lab3.zip bit_encode.c lab3.h Makefile
 
# this target is the book list executable that requires redirected stdin
bit_encode: bit_encode.o
	gcc bit_encode.o -o bit_encode

# this target is the dependency for lab3
bit_encode.o: bit_encode.c lab3.h
	gcc -ansi -pedantic -g -c -o bit_encode.o bit_encode.c

# this target deletes all files produced from the Makefile
# so that a completely new compile of all items is required
clean:
	rm -rf *.o bit_encode lab3.zip
