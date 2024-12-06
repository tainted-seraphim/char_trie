#include "trie.h"
#include <stdio.h>

static void print_char_readable(int c);

static void print_string_n_times(const char *str, long count);

static void trie_branch_depth_print(const struct trie_branch *b, long depth);

void trie_print(const struct trie *t)
{
  unsigned long index;
  if (!t) {
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
  if (!b || b->branch_count == 0) {
    return;
  }
  print_string_n_times("    ", depth);
  print_char_readable(b->key);
  printf("\n");
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

static void print_char_readable(int c)
{
  if (c >= '!' && c <= '~') {
    printf("%c", c);
  }
  if (c == 127) {
    printf("DEL");
  }
  if (c == '\t') {
    printf("TAB");
  }
  if (c == ' ') {
    printf("SPACEBAR");
  }
  if (c == '\0') {
    printf("\\0");
  }
}
