#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void bst_init(bst* b, PCOMPARATOR comparator, 
        PRELEASE release_key, PRELEASE release_value)
{
    b -> root = NULL;
    b -> comparator = comparator;
    b -> release_key = release_key;
    b -> release_value = release_value;
}

void bst_add_recursive(bst* b, bstnode** node, void* key, void* value)
{
    if(*node == NULL)
    {
        *node = (bstnode*)malloc(sizeof(bstnode));
        (*node)->key = key;
        (*node)->value = value;
        (*node)->right = (*node)->left = NULL;
        return;
    }
    int c = b->comparator(key, (*node)->key);
    if(c == 0)
        return;
    if(c>0)
        bst_add_recursive(b, &((*node)->right), key, value);
    else
        bst_add_recursive(b, &((*node)->left), key, value);
}


void bst_add(bst* b, void* key, void* value)
{
    bst_add_recursive(b, &(b->root), key, value);
}

