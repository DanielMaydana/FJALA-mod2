#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void bst_init(bst *b, PCOMPARATOR comparator, PRELEASE release_key, PRELEASE release_value)
{
    b->root = NULL;
    b->comparator = comparator;
    b->release_key = release_key;
    b->release_value = release_value;
}

void bst_add_recursive(bst *b, bstnode **node, void *key, void *value)
{
    if (*node == NULL)
    {
        *node = (bstnode *)malloc(sizeof(bstnode));
        (*node)->key = key;
        (*node)->value = value;
        (*node)->right = (*node)->left = NULL;
        return;
    }

    int c = b->comparator(key, (*node)->key);

    if (c == 0)
        return;

    if (c > 0)
        bst_add_recursive(b, &((*node)->right), key, value);
    else
        bst_add_recursive(b, &((*node)->left), key, value);
}

void bst_add(bst *b, void *key, void *value)
{
    bst_add_recursive(b, &(b->root), key, value);
}

void *bst_find_recursive(const bst *b, const bstnode *node, const void *key)
{
    if (node == NULL)
    {
        return NULL;
    }
    int c = b->comparator(key, node->key);
    if (c == 0)
    {
        return node->value;
    }
    if (c > 0)
        return bst_find_recursive(b, node->right, key);
    else
        return bst_find_recursive(b, node->left, key);
}

void *bst_find(const bst *b, const void *key)
{
    return bst_find_recursive(b, b->root, key);
}

void bst_iterate_recursive(const bstnode *node, PITERATE fkey, PITERATE fvalue)
{
    if (node == NULL)
    {
        return;
    }
    bst_iterate_recursive(node->left, fkey, fvalue);
    fkey(node->key);
    fvalue(node->value);
    bst_iterate_recursive(node->right, fkey, fvalue);
}

void bst_iterate(const bst *b, PITERATE fkey, PITERATE fvalue)
{
    bst_iterate_recursive(b->root, fkey, fvalue);
}

void bst_release_recursive(bst *b, bstnode *node)
{
    if (node == NULL)
    {
        return;
    }
    bst_release_recursive(b, node->left);
    bst_release_recursive(b, node->right);
    b->release_key(node->key);
    b->release_value(node->value);
    free(node);
}

void bst_release(bst *b)
{
    bst_release_recursive(b, b->root);
}