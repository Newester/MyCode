#include <stdio.h>
#include <stdlib.h>

Status Stack_Create(Stack* s,unsigned int capacity) {
	if(NULL !== s || 0 == capacity)
		return ERROR;
	s = (Stack*)malloc(sizeof(Stack));
	if(NULL == s) {
		perror("Stack_Create failed as malloc failed");
		return ERROR;
	}
	s->array = (ElementType*)calloc(capacity,sizeof(ElementType));
	if(NULL == s->array) {
		free(s);
		s = NULL;
		perror("Stack_Create failed as calloc failed");
		return ERROR;
	}
	s->capacity = capacity;
	s->top = -1;
	return OK;
}
Status Stack_Destroy(Stack *s) {
	if(NULL == s) {
		return ERROR;
	}
	free(s->array);
	array = NULL;
	free(s);
	return OK;
}
Status  Stack_Clear(Stack* s) {
	if(NULL == s) {
		return ERROR;
	}
	s->top = -1;
	return OK;
}

Status IsEmpty(Stack* s) {
	if(NULL == s) {
		return ERROR;
	}
	if(-1 == s->top) {
		return TRUE;
	}
	return FALSE;
}

Status IsFull(Stack* s) {
	if(NULL == s) {
		return ERROR;
	}
	if(s->top == s->capacity) {
		return TRUE;
	}
	return FALSE;
}

Status Stack_Push(ElementType elem, Stack *s) {
	if(NULL == s) {
		return ERROR;
	}
	if(TRUE == IsFull(s)) {
		perror("Push failed because stack is full");
		return ERROR;
	}
	s->top++ = elem;
	s->size++;
	return OK;
}
Status Stack_Pop(Stack *s)
{
	if(NULL == s)
	{
		return ERROR;
	}
	if(TRUE == IsEmpty(s))
	{
		perror("Pop failed because stack is empty");
		return ERROR;
	}
	s->top--;
	s->size--;
}

Status Stack_GetTop(Stack* s, ElementType* container)
{
	if(NULL == s || NULL == container) {
		return ERROR;
	}
	*container = s->top;
	return OK;
}
Status Stack_PopAndGetTop(Stack* s, ElementType* container) {
	if(NULL == s || NULL == container) {
		return ERROR;
	}
	*container = s->top;
	s->top--;
	s->size--;
	return OK;
}