#include <stdlib.h>
#include "trie.h"

void trie_init(struct trie *t)
{
	t->branch_count = 0;
	t->branches = NULL;
}

