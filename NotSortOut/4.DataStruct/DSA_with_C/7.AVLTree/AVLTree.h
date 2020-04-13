#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

#include <stdio.h>
#include <stdlib.h>

#include "../PublicDefine.h"

typedef char ElementType;
typedef struct node {
	ElementType data;
	struct node* left;
	struct node* right;
	int height;
} AVLNode;

AVLNode* AVL_CreateNode(ElementType data);

AVLNode* AVL_Insert(AVLNode* root, ElementType data);


AVLNode* AVL_Delete(AVLNode* root, ElementType data);

AVLNode* AVL_LL(AVLNode* root);

AVLNode* AVL_RR(AVLNode* root);

AVLNode* AVL_LR(AVLNode* root);

AVLNode* AVL_RL(AVLNode* root);

#endif // __AVL_TREE_H__
