#include <stdlib.h>
#include "trie.h"

void trie_free(struct trie *t)
{
	unsigned long index;
	for (index = 0; index < t->branch_count; index++) {
		trie_branch_free(t->branches[index]);
		t->branches[index] = NULL;
	}
	free(t->branches);
	t->branches = NULL;
	t->branch_count = 0;
}

