#ifndef _BST_H
#define _BST_H

typedef int (*PCOMPARATOR)(const void*, const void*);
typedef void (*PRELEASE)(void*);
typedef void (*PITERATE)(const void*);

typedef struct bstnodet
{
    struct bstnodet* left;
    struct bstnodet* right;
    void* key;
    void* value;
}bstnode;

typedef struct
{
    bstnode* root;
    PCOMPARATOR comparator;
    PRELEASE release_key;
    PRELEASE release_value;
}bst;

void bst_init(bst* b, PCOMPARATOR comparator, PRELEASE release_key, PRELEASE release_value);
void bst_add(bst* b, void* key, void* value);

void* bst_find(const bst* b, const void* key);
void bst_iterate(const bst* b, PITERATE fkey, PITERATE fvalue);
void bst_release(bst* b); 

#endif