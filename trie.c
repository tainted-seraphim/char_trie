#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

static void trie_branch_depth_print(const struct trie_branch *b, long depth);
static void print_string_n_times(const char *str, long count);

void trie_print(const struct trie *t)
{
	unsigned long index;
	if (!t || !t->branch_count) {
		printf("null\n");
		return;
	}
	printf("*\n");
	for (index = 0; index < t->branch_count; index++) {
		trie_branch_depth_print(t->branches[index], 1);
	}
}


static void trie_branch_depth_print(const struct trie_branch *b, long depth)
{
	unsigned long index;
	print_string_n_times("  ", depth);
	trie_branch_print(b);
	for (index = 0; index < b->branch_count; index++) {
		trie_branch_depth_print(b->branches[index], depth + 1);
	}

}

static void print_string_n_times(const char *str, long count)
{
	long index;
	for (index = 0; index < count; index++) {
		printf("%s", str);
	}
}



