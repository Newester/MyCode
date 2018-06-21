
#ifndef __STACK_H__
#define __STACK_H__

#include "../PublicDefine.h"

typedef int ElementType;
typedef struct 
{
	unsigned int capacity;
	int top;
	ElementType* array;
}Stack;

Status Stack_Create(Stack* s, unsigned int capacity);
void Stack_Destroy(Stack *s);
void Stack_Clear(Stack* s);
Status IsEmpty(Stack* s);
Status IsFull(Stack* s);

void Stack_Push(ElementType elem, Stack *s);
void Stack_Pop(Stack *s);
ElementType Stack_GetTop(Stack* s);
ElementType Stack_PopAndGetTop(Stack* s);

#endif // __STACK_H__