#include <stdlib.h>
#include "trie.h"

void trie_branch_init(struct trie_branch *b)
{
	b->branches = NULL;
	b->branch_count = 0;
	b->key = '\0';
}
