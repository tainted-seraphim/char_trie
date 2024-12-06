#ifndef CHAR_TRIE_TRIE_H
#define CHAR_TRIE_TRIE_H

struct trie_branch {
  struct trie_branch **branches;
  unsigned long branch_count;
  char key;
};

struct trie {
  struct trie_branch **branches;
  unsigned long branch_count;
};

void trie_init(struct trie *t);

void trie_free(struct trie *t);

void trie_print(const struct trie *t);

void trie_insert_string(struct trie *t, const char *str);

void trie_branch_init(struct trie_branch *b);

void trie_branch_free(struct trie_branch *b);

#endif
