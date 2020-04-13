#include <stdio.h>
#include <stdlib.h>

#include "../PublicDefine.h"


typedef char ElementType;

typedef struct node {
    ElementType data;
    struct node* left;
    struct node* right;
} BSTNode;

BSTNode* BST_Create(BSTNode* root);

BSTNode* BST_CreateNode(ElementType data);

Status BST_Insert(BSTNode* root, ElementType data);

Status BST_Insert2(BSTNode* root, ElementType data);

BSTNode* BST_Search(BSTNode* root, ElementType data);

BSTNode* BST_Search2(BSTNode* root, ElementType data);

BSTNode* BST_Delete(BSTNode* root, ElementType data);

BSTNode* BST_Delete2(BSTNode* root, ElementType data);

void BST_Destroy(BSTNode* root);








