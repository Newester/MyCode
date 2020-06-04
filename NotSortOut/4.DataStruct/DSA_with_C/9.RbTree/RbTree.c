#include <stdio.h>
#include <stdlib.h>

#include "RbTree.h"

#define rb_parent(node) ((RbNode*)(node)->parent)
#define rb_color(node) ((node)->color)
#define rb_is_red(node) ((node)->color == COLOR_RED)
#define rb_is_black(node) ((node)->color == COLOR_BLACK)
#define rb_set_red(node) do { (node)->color = COLOR_RED; } while(0)
#define rb_set_black(node) do { (node)-> color = COLOR_BLACK; } while(0)
#define rb_set_parent(node, p) do { (node)->parent = (p); } while(0)
#define rb_set_color(node, c) do { (node)->color = (c); } while(0)

RbTree RbTree_Create(void) {
    RbTree rb_tree = (RbTree)malloc(sizeof(*rb_tree));
    assert(NULL != rb_tree);
    rb_tree->root = NULL;
    return rb_tree;
}

void RbTree_Clear(RbNode* root) {
    if(NULL == root) {
        return;
    }
    if(NULL != root->left) {
        RbTree_Clear(root->left);
    } 
    else if (NULL != root->right) {
        RbTree_Clear(root->right);
    }
    free(root);
}

void RbTree_Destory(RbTree tree) {
    if(NULL != tree) {
        return;
    }
    RbTree_Clear(tree->root);
    free(tree);
}

RbNode* RbTree_CreateNode(ElementType data) {
    RbNode* node = (RbNode*)malloc(sizeof(RbNode));
    if(NULL == node) {
        perror("RbTree_CreateNode failed as malloc failed.");
        return NULL;
    }
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->color = COLOR_BLACK;
    return node;
}

RbTree RbTree_Insert(RbTree tree, ElementType data) {
    if(NULL == tree) {
        perror("RbTree_Insert failed as tree is null");
        return tree;
    }
    RbNode* node = RbTree_CreateNode(data);
    if(NULL == tree->root) {
        tree->root = node;
        return tree;
    }
    RbNode* pre;
    RbNode* p = tree->root;
    while(NULL != p) {
        pre = p;
        if(data == p->data) {
            perror("RbTree_Insert failed as data already exits.");
            free(node);
            return tree;
        }
        if(data > p->data) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }
    if(data > pre->data) {
        pre->right = node;
    }
    else {
        pre->left = node;
    }
    
    RbNode* grd = pre->parent;
    

    
}

RbNode* RbTree_Serach(RbTree tree, ElementType data) {
    assert(NULL != tree);
    RbNode* p = tree->root;
    while(NULL != p && data != p->data) {
        if (data == p->data) {
            break;
        }
        if(data < p->data) {
            p == p->left;
        }
        else if(data > p->data) {
            p = p->right;
        }
    }
    return p;
}

RbTree RbTree_Delete(RbTree tree, ElementType data) {
    
}