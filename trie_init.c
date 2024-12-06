#include "trie.h"
#include <stdlib.h>

void trie_init(struct trie *t)
{
  t->branch_count = 0;
  t->branches = NULL;
}
