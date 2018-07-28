#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include "../PublicDefine.h"


typedef struct HashTable HashTable;

HashTable* HashTable_Create(void);

void HashTable_Destory(void);

#define HashTable_Put(ht,key,value) HashTable_Put2(ht,key,value,NULL);
int HashTable_Put2(HashTable* ht, char* key, void* value, void(*free_value)(void*));

void* HashTable_Get(HashTable* ht, char* key);

void HashTable_Remove(HashTable* ht, char* key);

#endif // __HASHTABLE_H__
