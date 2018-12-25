#ifndef __CSTRFUN_H__
#define __CSTRFUN_H__

#include <assert.h>
#include <stdio.h>
//strcpy
char *strcpy(char *dst,const char *src){
	assert(dst && src);
	char *res = dst;
	while('\0' != (*res++ = *src++));
	return res;
}

//strlen
size_t strlen(const char *str){
	assert(NULL != str);
	size_t len = 0;
	while('\0' != *str)
		len++;
	return len;
}

//strcat
char *strcat(char* dst,const char *src){
	assert(dst && src);
	char *res = dst;
	while('\0' != *dst)
		dst++;
	while(*dst++ = *src++);
	return res;
}

//strcmp
int strcmp(const char* s1,const char* s2){
	assert(s1 && s2);
	while(*s1 == *s2){
		if('\0' == *s1){
			return 0;
		}
		s1++;
		s2++;
	}
	return *s1 - *s2;
}
#endif
