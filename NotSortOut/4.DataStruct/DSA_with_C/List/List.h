#ifndef __LIST_H__
#define __LIST_H__

#include "../PublicDefine.h"

typedef char DataType;

/**
 *普通链表节点
 *@data 数据域
 *@next 指向下一个节点
 */
typedef struct node {
	DataType data;
	struct node* next;
}ListNode;

/**
 *链表头节点，当前实现的链表没有加入此节点
 *@first 指向链表的第一个节点
 *@length 链表的长度，链表数据节点的个数
 */
typedef struct {
	ListNode* first;
	int length;
}List;

/**
 *双向链表节点
 *@prev 指向前驱节点
 *@next 指向后继节点
 *@data 数据域
 */
typedef struct Node {
	DataType data;
	struct Node* prev;
	struct Node* next;
}

//初始化一个链表,由于数据类型这里定义为char，因此比较方便读取用户输入
ListNode* List_Init(void);

//插入元素，前插法
Status List_ForeInsert(ListNode* head, DataType data);

//插入元素，尾插法
Status List_BackInsert(ListNode* tail, DataType data);

//查找特定的元素
Status List_FindElem(ListNode* head, DataType data);

//遍历链表
void List_Travese(ListNode* head);

//删除特定的元素
void List_DeleteElem(ListNode* head,DataType data);

//链表反转，面试常考
Status List_Reverse(ListNode* head);
#endif // __LIST_H__