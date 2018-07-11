#include "BinaryTree.h"

Status BinTree_Create(BinNode* root) {
	ElementType ch;
	scanf("%c",&ch);
	if(' ' == ch) {
		root = NULL;
	}
	else {
		root = (BinNode*)malloc(sizeof(BinNode));
		if(NULL == root) {
			perror("BinaryTree create failed as malloc failed");
			exit(OVERFLOW);
		}
		root->data = ch;
		BinTree_Create(root->left);
		BinTree_Create(root->right);
	}
	return OK;
}

Status BinTree_IsEmpty(BinNode* root) {
	if(NULL == root) {
		return TRUE;
	}
	return FALSE;
}

int BinTree_GetDepth(BinNode* root) {
	int l = 0, r = 0;
	if(NULL == root) {
		return 0;
	}

	if(NULL == root->left) {
		l = 0;
	}
	else {
		l = BinTree_GetDepth(root->left);
	}
	if(NULL == root->right) {
		r = 0;
	}
	else {
		r = BinTree_GetDepth(root->right);
	}
	return l > r ? (l+1) : (r+1);

}

void Visit(ElementType e) {
	print("%c\t",e);
}

void BinNode_PreOrderTraverse(BinNode* root, void(*Visit)(ElementType e)) {
	if(NULL != root) {
		Visit(root->data);
		BinNode_PreOrderTraverse(root->left,Visit);
		BinNode_PreOrderTraverse(root->right,Visit);
    }
}

void BinNode_InOrderTraverse(BinNode* root, void(*Visit)(ElementType e)) {
	if(NULL !== root) {
		BinNode_InOrderTraverse(root->left,Visit);
		Visit(root->data);
		BinNode_InOrderTraverse(root->right,Visit);
	}
}

void BinNode_PostOrderTraverse(BinNode* root, void(*Visit)(ElementType e)) {
	if(NULL != root) {
		BinNode_PostOrderTraverse(root->left,Visit);
		BinNode_PostOrderTraverse(root->right,Visit);
		Visit(root->data);
	}
}

BinNode* BinTree_FindNode(BinNode* root,ElementType e) {
	if(NULL == root) {
		return NULL;
	}
	if(e == root->data) {
		return root;
	}
	BinNode* node = BinTree_FindNode(root->left,e);
	if(node ! = NULL) {
		return node;
	}
	else
	{
		node = BinTree_FindNode(root->right,e);
		if(node != NULL)
		{
			return node;
		}
	}
	return NULL;

}