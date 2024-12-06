#include "trie.h"
#include <stdlib.h>
#include <string.h>

static void trie_branch_swap(struct trie_branch **a, struct trie_branch **b);

static long trie_branch_bsearch_key(const struct trie_branch *b, int key);

static void trie_branch_insert_string(struct trie_branch *b, const char *str);

void trie_insert_string(struct trie *t, const char *str)
{
  long index;
  long pos;
  struct trie_branch b;
  b.branches = t->branches;
  b.branch_count = t->branch_count;
  b.key = '\0';
  if (!t || !str) {
    return;
  }
  if (t->branch_count == 0) {
    t->branch_count = 1;
    t->branches = (struct trie_branch **)malloc(sizeof(struct trie_branch *));
    t->branches[0] = (struct trie_branch *)malloc(sizeof(struct trie_branch));
    trie_branch_init(t->branches[0]);
    trie_branch_insert_string(t->branches[0], str);
  } else {
    pos = trie_branch_bsearch_key(&b, *str);
    /* find key logic */
    if (t->branches[pos]->key == *str) {
      if (!*str) {
        return;
      }
      trie_branch_insert_string(t->branches[pos], str + 1);
      return;
    }
    /* insert key logic */
    t->branch_count++;
    t->branches = (struct trie_branch **)realloc(
        t->branches, sizeof(struct trie_branch *) * t->branch_count);
    t->branches[t->branch_count - 1] =
        (struct trie_branch *)malloc(sizeof(struct trie_branch));
    if (t->branches[pos]->key < *str) {
      for (index = t->branch_count - 1; index > pos + 1; index--) {
        trie_branch_swap(&t->branches[index], &t->branches[index - 1]);
      }
      trie_branch_init(t->branches[pos + 1]);
      trie_branch_insert_string(t->branches[pos + 1], str);
    } else {
      for (index = t->branch_count - 1; index > pos; index--) {
        trie_branch_swap(&t->branches[index], &t->branches[index - 1]);
      }
      trie_branch_init(t->branches[pos]);
      trie_branch_insert_string(t->branches[pos], str);
    }
  }
}

static void trie_branch_insert_string(struct trie_branch *b, const char *str)
{
  long index;
  long pos;
  if (!b || !str) {
    return;
  }
  if (b->branch_count == 0) {
    b->branch_count = 1;
    b->branches = (struct trie_branch **)malloc(sizeof(struct trie_branch *));
    b->branches[0] = (struct trie_branch *)malloc(sizeof(struct trie_branch));
    trie_branch_init(b->branches[0]);
    b->key = *str;
    if (*str == '\0') {
      return;
    }
    trie_branch_insert_string(b->branches[0], str + 1);
  } else {
    pos = trie_branch_bsearch_key(b, *str);
    /* find key logic */
    if (b->branches[pos]->key == *str) {
      if (!*str) {
        return;
      }
      trie_branch_insert_string(b->branches[pos], str + 1);
      return;
    }
    /* insert key logic */
    b->branch_count++;
    b->branches = (struct trie_branch **)realloc(
        b->branches, sizeof(struct trie_branch *) * b->branch_count);
    b->branches[b->branch_count - 1] =
        (struct trie_branch *)malloc(sizeof(struct trie_branch));
    if (b->branches[pos]->key < *str) {
      for (index = b->branch_count - 1; index > pos + 1; index--) {
        trie_branch_swap(&b->branches[index], &b->branches[index - 1]);
      }
      trie_branch_init(b->branches[pos + 1]);
      trie_branch_insert_string(b->branches[pos + 1], str);
    } else {
      for (index = b->branch_count - 1; index > pos; index--) {
        trie_branch_swap(&b->branches[index], &b->branches[index - 1]);
      }
      trie_branch_init(b->branches[pos]);
      trie_branch_insert_string(b->branches[pos], str);
    }
  }
}

static long trie_branch_bsearch_key(const struct trie_branch *b, int key)
{
  long left;
  long right;
  long index;
  if (!b) {
    return -1;
  }
  left = 0;
  right = b->branch_count;
  index = (left + right) / 2;
  while (left < right) {
    index = (left + right) / 2;
    if (key < b->branches[index]->key) {
      right /= 2;
    } else if (key > b->branches[index]->key) {
      left = (left + right + 1) / 2;
    } else {
      return index;
    }
  }
  return index;
}

static void trie_branch_swap(struct trie_branch **a, struct trie_branch **b)
{
  struct trie_branch *t;
  if (!a || !b) {
    return;
  }
  t = *a;
  *a = *b;
  *b = t;
}
