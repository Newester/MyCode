#ifdef __QUEUE_H__
#define __QUEUE_H__

#include "../PublicDefine.h"

typedef int ElementType;

typedef struct node {
	ElementType data;
	node* next;
} QueueNode;

typdef struct {
	QueueNode* front;
	QueueNode* rear;
	unsigned int size;
} Queue;

Queue* Queue_Init(void);

void Queue_Destory(Queue* queue);

void Queue_Clear(Queue* queue);

Status Queue_IsEmpty(Queue* queue);

int Queue_GetSize(Queue* queue);

Status Queue_EnQueue(Queue* queue,ElementType elem);

Status Queue_DeQueue(Queue* queue, ElementType* container);

void Queue_Traverse(Queue* queue);



#endif // __QUEUE_H__