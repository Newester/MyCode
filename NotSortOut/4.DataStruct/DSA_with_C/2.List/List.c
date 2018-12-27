#include <stdio.h>
#include <stdlib.h>

#include "List.h"

ListNode* List_Init(void) {
	printf("Please input your data end by '#':\n");
	char c = '\0';
	ListNode* head = NULL;
	ListNode* prev = NULL;
	while (c = getchar()) {
		if( '#' == c)
			break;
		ListNode* p = (ListNode*)malloc(sizeof(*p));
		if(NULL == p) {
			perror("List_Init failed as malloc failed");
			if(NULL != head)
				List_Destroy(head);
			prev = p = NULL;
			exit(OVERFLOW);
		}
		p->data = c;
		p->next = NULL;

		if(NULL == head) {
			head = p;
			prev = head;
		}
		else {
			prev->next = p;
			prev = p;
		}
		p = p->next;
	}

	return head;
}

ListNode* List_ForeInsert(ListNode* head, DataType data) {

	ListNode* p = (ListNode*)malloc(sizeof(*p));
	if(NULL == p) {
		printf("List_ForeInsert fail as malloc fail.\n");
		return head;
	}
	p->data = data;
	p->next = NULL;
    
    if(NULL != head)
		p->next = head;
	head = p;
	
	p = NULL;
	return head;
}

Status List_BackInsert(ListNode* head, DataType data) {

	ListNode* p = (ListNode*)malloc(sizeof(*p));
	if(NULL == p) {
		printf("List_ForeInsert fail as malloc fail.\n");
		return ERROR;
	}
	p->data = data;
	p->next = NULL;

	if(NULL == head)
		head = p;
	else {
		p = head;
		while(NULL != head->next)
			head = head->next;
		head->next = p;
	}

	return OK;
}

Status List_FindElem(ListNode* head, DataType data, DataType* container) {
	if(NULL == container) {
		perror("Container does not exist");
		return ERROR;
	}
	while(NULL != head || data != head->data)
		head = head->next;
	if(NULL == head) {
		container = NULL;
		return FALSE;
	}
	else {
		*container = head->data;
		return TRUE;
	}
}

void List_Traverse(ListNode* head) {
	while(NULL != head) {
		printf("%c\t",head->data);
		head = head->next;
	}
	putchar('\n');
}

Status List_DeleteElem(ListNode* head,DataType data) {
	ListNode* p = head;
	ListNode* prev = NULL;
	while( p != NULL || p->data != data) {
		prev = p;
		p = p->next;
	}

	if(NULL == p)
		return FALSE;
	if(head == p) {
		head = head->next;
		p->next = NULL;
		free(p);
	}
	else {
		prev->next = p->next;
		p->next = NULL;
		free(p);
	}

	return TRUE;
}
ListNode* List_Reverse(ListNode* head) {
	ListNode* p = head;
	if(NULL != p->next)
		List_Reverse(p->next);
	head = head->next;
	head->next = p;
	p = NULL;
}
void List_Destory(ListNode* head) {
	ListNode* next = NULL;
	ListNode* p = head;
	if(NULL != p) {
		next = p->next;
		free(p);
		p = p->next;
	}
}


