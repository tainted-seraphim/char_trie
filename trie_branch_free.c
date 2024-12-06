#include <stdlib.h>
#include "trie.h"

void trie_branch_free(struct trie_branch *b)
{
	unsigned long index;
	for (index = 0; index < b->branch_count; index++) {
		trie_branch_free(b->branches[index]);
		free(b->branches[index]);
		b->branches[index] = NULL;
	}
	free(b->branches);
	b->branches = NULL;
	b->key = '\0';
	b->branch_count = 0;
}

