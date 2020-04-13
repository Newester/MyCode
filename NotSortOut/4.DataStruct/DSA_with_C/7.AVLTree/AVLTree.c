#include "AVLTree.h"

#define HEIGHT(tree) ((NULL == tree)?0:((AVLNode*)tree->height))

#define MAX(a,b) ((a)>(b) ? (a) : (b))

#define ABS(x) ((x)>0 ? (x) : (0 - (x)))

AVLNode* AVL_CreateNode(ElementType data) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    if(NULL == node) {
        perror("AVL_CreateNode failed as malloc failed.");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    
    return node;
}

AVLNode* AVL_Insert(AVLNode* root, ElementType data) {
    if(NULL == root) {
        root = AVL_CreateNode(data);
        if(NULL == root) {
            perror("AVL_Insert failed as AVL_CreateNode failed.");
        }
        return root;
    }

    else if(data < root->data) {
        root = AVL_Insert(root->left, data);
        // 说明失衡
        if(2 == HEIGHT(root->left) - HEIGHT(root->right)) {
            // 说明是插在了左子树的左边，是左左型
            if(HEIGHT(root->left->left)  >= HEIGHT(root->left->right)) {
                root = AVL_LL(root);
            }
            else { // 左右型
                root = AVL_LR(root);
            }
        }
        return root;
    }
    else if(data > root->data) {
        root = AVL_Insert(root->right, data);
        if(2 == HEIGHT(root->right) - HEIGHT(root->left)) {
            if(HEIGHT(root->right->right)  >= HEIGHT(root->right->left)) {}
                root = AVL_RR(root);
            }
            else {
                root = AVL_RL(root);
            }
        }
        root->height = MAX(HEIGHT(root->left), HEIGHT(root->right)) + 1;
        return root;
    }
    else { // data == root->data
        perror("AVL_Insert failed as data already exists.");
        return root;
    }
}

AVLNode* AVL_FindMax(AVLNode* root) {
    if(NULL == root) {
        perror("AVL_FindMax failed as root is empty.");
        return NULL;
    }
    for(; NULL != root->right; root = root->right);
    return root;
}

AVLNode* AVL_FindMin(AVLNode* root) {
    if(NULL == root) {
        perror("AVL_FindMin failed as root is empty.");
        return NULL;
    }
    for(; NULL != root->left; root = root->left);
    return root;
}

AVLNode* AVL_Delete(AVLNode* root, ElementType data) {
    if(NULL == root) {
        perror("AVL_Delete failed: not found.");
        return NULL;
    }
    if(data != root->data) {
        if(data < root-> data) {
            root->left =  AVL_Delete(root->left, data);
            if(2 == HEIGHT(root->right) - HEIGHT(root->left)) {
                if(HEIGHT(root->right->right) >= HEIGHT(root->right->left)) {
                    root = AVL_RR(root);
                }
                else {
                    root = AVL_RL(root);
                }                
            }
        }
        if(data > root->data) {
            root->right = AVL_Delete(root->right, data);
            if(2 == HEIGHT(root->left) - HEIGHT(root->right)) {
                if(HEIGHT(root->left->left) - HEIGHT(root->left->right)) {
                    root = AVL_LL(root);
                }
                else {
                    root = AVL_LR(root);
                }
            }
        }

    }
    else { // (data == root->data)
        if(NULL != root->left && NULL != root->right) {
            if(HEIGHT(root->left) > HEIGHT(root->right)) {
                AVLNode* min = AVL_FindMin(root->left);
                root->data = min->data;
                root->left = AVL_Delete(root->left, min->data);
            }
            else {
                AVLNode* max = AVL_FindMax(root->right);
                root->data = max->data;
                root->right = AVL_Delete(root->right, max->data);
            }
            root->height = MAX(HEIGHT(root->left), HEIGHT(root->right)) + 1;
        }
        else {
            AVLNode* p = root;
            root = (NULL == root->left) ? root->right : root->left;
            free(p);
        }
    }
    return root;
}


/*
* 左左向右旋
* 什么时候是左左型？失衡节点的左子树比右子树高；失衡节点的左子树的左子树还是比右子树高；
*/
AVLNode* AVL_LL(AVLNode* root) {
    // 左儿子为轴
    AVLNode* pivot = root->left;
    //右旋之前先把左儿子的右子树挪走，免得占位置
    root->left = pivot->right;
    // 然后把根节点拉下来作为左子树的右子树；
    pivot->right = root;
    // 调整高度
    root->height = MAX(HEIGHT(root->left), HEIGHT(root->right)) + 1;
    pivot->height = MAX(HEIGHT(pivot->left), HEIGHT(pivot->right)) + 1;
    return pivot;
}

/*
* 右右向左旋
*/
AVLNode* AVL_RR(AVLNode* root) {
    
    AVLNode* pivot = root->right;
    root->right = pivot->left;
    pivot->left = root;
    root->height = MAX(HEIGHT(root->left), HEIGHT(root->right)) + 1;
    pivot->height = MAX(HEIGHT(pivot->left), HEIGHT(pivot->right)) + 1;
    return pivot;
}

/*
* 左右先左旋孙子再右旋儿子
*/
AVLNode* AVL_LR(AVLNode* root){
    root = AVL_RR(root->left);
    return AVL_LL(root);
}


AVLNode* AVL_RL(AVLNode* root) {
    root = AVL_LL(root->right);
    return AVL_RR(root);
}

