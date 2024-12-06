CC    = gcc
FLAGS = -ansi -pedantic -g -Wall
LD    = ld

all: main.c trie.o 
	$(CC) $(FLAGS) main.c trie.o -o char_trie

trie.o: trie_branch_init.o trie_branch_free.o trie_init.o trie_free.o trie_insert_string.o trie_print.o
	$(LD) -relocatable trie_branch_init.o trie_branch_free.o trie_init.o trie_free.o trie_insert_string.o trie_print.o -o trie.o

trie_branch_init.o: trie_branch_init.c
	$(CC) $(FLAGS) -c trie_branch_init.c -o trie_branch_init.o

trie_branch_free.o: trie_branch_free.c
	$(CC) $(FLAGS) -c trie_branch_free.c -o trie_branch_free.o

trie_init.o: trie_init.c
	$(CC) $(FLAGS) -c trie_init.c -o trie_init.o

trie_free.o: trie_free.c
	$(CC) $(FLAGS) -c trie_free.c -o trie_free.o

trie_insert_string.o: trie_insert_string.c
	$(CC) $(FLAGS) -c trie_insert_string.c -o trie_insert_string.o

trie_print.o: trie_print.c
	$(CC) $(FLAGS) -c trie_print.c -o trie_print.o

clear:
	if [ -e trie.o ]; then rm trie.o; fi
	if [ -e trie_init.o ]; then rm trie_init.o; fi
	if [ -e trie_free.o ]; then rm trie_free.o; fi
	if [ -e trie_insert_string.o ]; then rm trie_insert_string.o; fi
	if [ -e trie_branch_init.o ]; then rm trie_branch_init.o; fi
	if [ -e trie_branch_free.o ]; then rm trie_branch_free.o; fi
	if [ -e trie_print.o ]; then rm trie_print.o; fi

