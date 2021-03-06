#include <stdio.h>
#include <stdlib.h>

#include "../PublicDefine.h"

typedef char ElementType;
typedef struct node {
	ElementType data;
	struct node* left;
	struct node* right;
} BinNode;
Status BinTree_Create(BinNode* root);
Status BinTree_IsEmpty(BinNode* root)
int BinTree_GetDepth(BinNode* root);
void Visit(ElementType e);
void BinTree_PreOrderTraverse(BinNode* root, void(*Visit)(ElementType e));
void BinTree_InOrderTraverse(BinNode* root, void(*Visit)(ElementType e));
void BinTree_PostOrderTraverse(BinNode* root, void(*Visit)(ElementType e));
void BinTree_LevelOrderTraverse(BinNode* root, void(*Visit)(ElementType e));
BinNode* BinTree_FindNode(BinNode* root,ElementType e);
void BinTree_Destroy(BinNode* root);


