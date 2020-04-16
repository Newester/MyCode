#include <stdio.h>
#include <stdlib.h>

#include "RbTree.h"

RbTree RbTree_Init(void) {
    RbTree rb_tree;

    rb_tree->nil = (RbNode*)malloc(sizeof(RbNode));
    assert(rb_tree != NULL);

    rb_tree->nil->parent = NULL;
    rb_tree->nil->left = NULL;
    rb_tree->nil->right = NULL;
    rb_tree->nil->color = RB_BLACK;

    rb_tree->root = rb_tree->nil;

    return rb_tree;
}