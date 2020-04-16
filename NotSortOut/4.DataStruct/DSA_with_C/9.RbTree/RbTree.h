#include "../PublicDefine.h"

typedef enum {RB_RED = 0, RB_BLACK = 1} color_t;
typedef int ElementType;

typedef struct node {
    struct node *parent, *left, *right;
    color_t color;
    ElementType data;
} RbNode;

typedef struct {
    RbNode* root;
} *RbTree;

RbTree RbTree_Init(void);
RbTree RbTree_Insert(RbTree tree, ElementType data);
RbTree RbTree_Delete(RbTree tree, ElementType data);
RbNode* RbTree_Serach(RbTree tree, ElementType data);
void RbTree_Destory(RbTree tree);