#include "trie.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  struct trie t;
  trie_init(&t);
  trie_insert_string(&t, "geek");
  trie_insert_string(&t, "geek");
  trie_insert_string(&t, "geek");
  trie_insert_string(&t, "genius");
  trie_insert_string(&t, "genius");
  trie_insert_string(&t, "genius");
  trie_insert_string(&t, "genius");
  trie_insert_string(&t, "genius");
  trie_insert_string(&t, "genius");
  trie_insert_string(&t, "generic");
  trie_insert_string(&t, "generic");
  trie_insert_string(&t, "generic");
  trie_insert_string(&t, "");
  trie_insert_string(&t, "");
  trie_insert_string(&t, "");
  trie_print(&t);
  trie_free(&t);
  trie_free(&t);
  trie_print(&t);
  return 0;
}
