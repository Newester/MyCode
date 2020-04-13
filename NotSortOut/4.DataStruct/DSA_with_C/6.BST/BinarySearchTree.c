#include "BinarySearchTree.h"

BSTNode* BST_Create() {
    BSTNode* root = NULL;
    Status status;
    ElementType data;
    do {
        scanf("%c", &data);
        if (NULL == root) {
            root = BST_CreateNode(data);
            if(NULL  == root) {
                perror("BST create failed as BST create root failed.");
            }
        }
        else {
            status = BST_Insert(root, data);
            if (OK != status) {
                perror("BST create failed as BST insert failed");
                return ERROR;
            }
            else {
                BST_Destroy(root);
                return NULL;
            }
        }
    } while('#' != data);

    return root;

}

BSTNode* BST_CreateNode(ElementType data) {
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    if (NULL == node) {
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Status BST_Insert(BSTNode* root, ElementType data) {
     
    if (NULL == root) {
        perror("BST insert failed as BST does not exist.");
        return ERROR;
    }

    if (data == root->data) {
        perror("BST insert failed as element already exists.");
        return ERROR;
    }

    if (NULL == root->left && data < root->data) {
        BSTNode* node = BST_CreateNode(data);
        if (NULL == node) {
            perror("BST insert failed as BST create node failed.");
            return ERROR;
        }
        root->left = node;
        return OK;
    }
    if(NULL == root->right && data > root->data) {
        BSTNode* node = BST_CreateNode(data);
        if (NULL == node) {
            perror("BST insert failed as BST create node failed.");
            return ERROR;
        }
        root->right = node;
        return OK;
    }
    
    if (data < root->data) {
        return BST_Insert(root->left, data);
    }
    if (data > root->data) {
        return BST_Insert(root->right, data);
    }

}

Status BST_Insert2(BSTNode* root, ElementType data) {
    BSTNode* pre = NULL;
    if (NULL == root) {
        perror("BST insert failed as BST does not exist.");
        return ERROR;
    }
    while (NULL != root) {
        pre = root;
        if (data < root->data) {
            root = root->left;
        }
        else if (data > root->data) {
            root = root->right;
        }
        else {
            perror("BST insert failed as data already exits.");
            return ERROR;
        }

    }
    BSTNode* node = BST_CreateNode(data);
    if (NULL == node) {
        perror("BST insert failed as BST create node failed.");
        return ERROR;
    }
    else {
        if( data < root->data) {
            pre->left = node;
        }
        else {
            pre->right = node;
        }        
    }
    return OK;
    
}

BSTNode* BST_Search(BSTNode* root, ElementType data) {
    if (NULL == root) {
        return NULL;
    }
    if (root->data == data) {
        return root;
    }
    if (root->data > data) {
        return BST_Search(root->left, data);
    }
    else {
        return BST_Search(root->right, data);
    }
}


BSTNode* BST_Search2(BSTNode* root, ElementType data) {
    while( NULL != root && data != root->data) {
        if (data > root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return root;
}

BSTNode* BST_Delete(BSTNode* root, ElementType data) {
    BSTNode* node = NULL;
    if(NULL == root) {
        perror("BST delete failed as data doesn't exists.");
        return root;
    }
    else if(data > root->data) {
        root->left = BST_Delete(root->left, data);
    }
    else if(data < root->data) {
        root->right = BST_Delete(root->right, data);
    }
    else {
        if(NULL != root->left && NULL != root->right) {
            node = root->right;
            while(NULL != node->left) {
                node = node->left;
            }
            root->data = node->data;
            root->right = BST_Delete(root->right, node->data);
        }
        else {
            node = root;
            if(NULL == root->left) {
                root = root->right;
            }
            else if(NULL == root->right) {
                root = root->right;
            }
            free(node);
        }
    }
    return root;
}


BSTNode* BST_Delete2(BSTNode* root, ElementType data) {
{
    BSTNode* cur = root;
    BSTNode* parent = NULL;
    BSTNode* del = NULL;
    while (cur) {
        if (cur->data < data) {
            parent = cur;
            cur = cur->right;
        }
        else if (cur->data > data) {
            parent = cur;
            cur = cur->left;
        }
        else {
            del = cur;
            if (NULL == cur->left) {//左为空or叶子结点
                if(cur == root) { //parent==NULL删除根节点

                    root = cur->right;
                }
                else if(parent->left == cur) {
                    parent->right = cur->right;
                }
                else {
                    parent->right = cur->right;
                }
            }
            else if (cur->right == NULL) {//右为空
                del = cur;
                if (cur == root) {//删除根节点
                    root = cur->left;
                }
                else if (parent->left == cur) {
                    parent->left = cur->left;
                } else {
                    parent->right = cur->left;
                }
            }
            else { //左右都不为空
                //找右孩子的最左节点替换该节点
                BSTNode * subLeft = cur->right;
                while (subLeft->left) {
                    parent = subLeft;
                    subLeft = subLeft->left;
                }
                del = subLeft;
                cur->data = subLeft->data;
                if (subLeft == cur->right) { //cur->right无左孩子
                    cur->right = subLeft->right;
                }
                else {
                    parent->left = subLeft->right;
                }
            }
            free(del);
            del = NULL;
            return root;
        }
    }
    return root;
}

