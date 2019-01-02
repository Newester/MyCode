#include "HashTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE (1024*1024)

struct kv {
    struct kv* next;
    char* key;
    void* value;
    void (*free_value)(void*);
	
};

struct HashTable {
	struct kv** table;
};

static void kv_init(struct kv* kv) {
	kv->next = NULL;
	kv->key = NULL;
	kv->value = NULL;
	kv->free_value = NULL;
}

static void kv_free(struct kv* kv) {
	if( NULL != kv ) {
		if( NULL != kv->free_value ) {
			kv->free_value(kv->value);
		}
		free(kv->key);
		kv->key = NULL;
		free(kv);
	}
}

static int HashTable_Times33(char* key) {
	unsigned int hash = 0;
	while( '\0' != *key ) {
		hash = (hash << 5) + hash + *(key++);
	}
	return hash;
}

HashTable* HashTable_Create() {
	HashTable* ht = malloc(sizeof(HashTable));
	if( NULL == ht ) {
		HashTable_Destory(ht);
		return NULL;
	}
	ht->table = malloc(sizeof(struct kv*)*TABLE_SIZE);
	if( NULL == ht->table ) {
		HashTable_Destory(ht);
		return NULL;
	}
	memset(ht->table,0,sizeof(struct kv*)*TABLE_SIZE);
	return ht;
}

void HashTable_Destory(HashTable* ht) {
	if( NULL != ht ) {
		if( NULL != ht->table ) {
			int i = 0;
			for(; i < TABLE_SIZE; ++i) {
				struct kv* p = ht->table[i];
				struct kv* q = NULL;
				while( NULL != p) {
					q = p->next;
					kv_free(p);
					p = q;
				}
			}
		}
		free(ht->table);
		ht->table = NULL;
	}
	free(ht);
}

int HashTable_Put2(HashTable* ht, char* key, void* value, void(*free_value)(void*)) {
	int i = HashTable_Times33(key) % TABLE_SIZE;
	struct kv* p = ht->table[i];
	struct kv* pre = p;
	while( NULL != p ) {
		if( 0 == strcmp(p->key,key) ) {
			if( NULL != p->free_value) {
				p->free_value(p->value);
			}
			p->value = value;
			p->free_value = free_value;
			break;
		}
		pre = p;
		p = p->next;
	}

	if( NULL == p ) {
		char* kstr = malloc(strlen(key) +1 );
		if( NULL == kstr ) {
			return -1;
		}
		struct kv* kv = malloc(sizeof(struct kv));
		if( NULL == kv ) {
			free(kstr);
			kstr = NULL;
			return -1;
		}
		kv_init(kv);
		kv->next = NULL;
		strcpy(kstr, key);
		kv->key = kstr;
		kv->value = value;
		kv->free_value = free_value;

		if( NULL == pre ) {
			pre->next = kv;
		}
	}
	return 0; 
}

void* HashTable_Get(HashTable* ht, char* key) {
	int i = HashTable_Times33(key) % TABLE_SIZE;
	struct kv* p = ht->table[i];
	while( NULL != p ) {
		if( 0 == strcmp(key, p->key) ) {
			return p->value;
		}
		p = p->next;
	}
	return NULL;
}

void HashTable_Remove(HashTable* ht, char* key) {
	int i = HashTable_Times33(key) % TABLE_SIZE;
	struct kv* p = ht->table[i];
	struct kv* pre = p;
	while( NULL != p ) {
		if( 0 == strcmp(key, p->key) ) {
			kv_free(p);
			if( p == pre ) {
				ht->table[i] = NULL;
			} 
			else {
				pre->next = p->next;
			}
		}
		pre = p;
		p = p->next;
	}
}