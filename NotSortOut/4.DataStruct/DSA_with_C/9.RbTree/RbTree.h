#ifndef RBTREE_H
#define RBTREE_H

#include "../PublicDefine.h"

#define COLOR_RED 0
#define COLOR_BLACK 1

typedef int ElementType;

typedef struct node {
    struct node *parent, *left, *right;
    int color;
    ElementType data;
} RbNode;

typedef struct {
    RbNode* root;
} *RbTree, RbRoot;

RbTree RbTree_Create(void);
void RbTree_Destory(RbTree tree);
RbTree RbTree_Insert(RbTree tree, ElementType data);
RbTree RbTree_Delete(RbTree tree, ElementType data);
RbNode* RbTree_Serach(RbTree tree, ElementType data);


#endif // RBTREE_H