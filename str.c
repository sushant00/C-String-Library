#include <ctype.h>
#include <xlocale.h>
#include "str.h"

/* start implementing your functions here */


/* One is done for you */

int strncasecmp(const char *s1, const char *s2, int len)
{
	unsigned char c1, c2;

	if (!len)
		return 0;

	do {
		c1 = *s1++;
		c2 = *s2++;
		if (!c1 || !c2)
			break;
		if (c1 == c2)
			continue;
		c1 = tolower(c1);
		c2 = tolower(c2);
		if (c1 != c2)
			break;
	} while (--len);
	return (int)c1 - (int)c2;
}


char *strcpy(char *dest, const char *src){
	char *final = dest;
	while(*src!='\0'){
		*dest++ = *src++;
	}
	*(dest) = '\0';
	return final;
}


char *strncpy(char *dest, const char *src, int count){
	int length = strlen(src);
	char *result = dest;
	int minimum = 0;
	if (length > count){
		minimum = count;
	}else{
		minimum = length;
	}
	while(minimum-->0){
		*dest++ = *src++;
	}
	count-=minimum;
	while(count-->0){
		*dest++ = '\0';
	}
	return result;
}


char *strcat(char *dest, const char *src){
	/*
	this returns a copy of dest+src

	char result[1000];
	int count = 0;	
	while(*dest!='\0'){
		result[count++] = *dest++;
		}
	while(*src!='\0'){
		result[count++] = *src++;
	}
	result[count] = '\0';
	return result;*/

	char *result = dest;
	while(*dest!='\0'){
		dest++;
	}
	while(*src!='\0'){
		*dest++ = *src++;
	}
	*dest = '\0';
	return result;

}

char *strncat(char *dest, const char *src, int count){
	char *result = dest;
	while(*dest!='\0'){
		dest++;
	}
	while(*src!='\0' && count-->0){
		*dest++ = *src++;
	}
	*dest = '\0';
	return result;
}

int strcmp(const char *cs, const char *ct){
	unsigned char c1 = *cs,c2 = *ct;
	while(c1==c2){
		if(!c1 && !c2)
			return 0;
		c1 = *++cs;
		c2 = *++ct;
	}
	if(!c1)
		return -1;
	if(!c2)
		return 1;
	return (int)c1 - (int)c2;

}

int strncmp(const char *cs, const char *ct, int count){
	unsigned char c1 = *cs,c2 = *ct;
	while(count-->0 && c1==c2){		
		if(!c1 && !c2)
			return 0;
		c1 = *++cs;
		c2 = *++ct;
	}
	if (count<=0)
		return 0;
	if(!c1)
		return -1;
	if(!c2)
		return 1;
	return (int)c1 - (int)c2;
}


char *strchr(const char *s, int c){
	char ch = (char)c;
	unsigned char tmp = *s;
	while(tmp!=ch && tmp!='\0'){
		tmp = *++s;
	}
	if(!tmp && ch!='\0')
		s = 0;// null pointer
	return (char *)s;
}


char *strchrnul(const char *s, int c){
	char ch = (char)c;
	unsigned char tmp = *s;
	while(tmp!=ch && tmp!='\0'){
		tmp = *++s;
	}
	return (char *)s;	
}


char *strrchr(const char *s, int c){
	char ch = (char)c;
	unsigned char tmp = *s;
	char *result = 0;
	while(tmp){
		if(tmp==ch){
			result = (char *)s;
		}
		tmp = *++s;
	}
	return result;
}


char *strnchr(const char *s, int count, int c){
	char ch = (char)c;
	unsigned char tmp = *s;
	char *result = 0;	
	while(tmp && count-->0){
		if(tmp==ch){
			result = (char *)s;
		}
		tmp = *++s;
	}
	return result;
}


char *skip_spaces(const char *str){
	unsigned char c = *str;
	char *tmp = (char *)str;
	while(c==' '){
		c = *++tmp;
	}
	return tmp;
}


char *strim(char *s){
	unsigned char c = *s;
	while(c==' '){
		c = *++s;
	}
	char *result = (char *)s;
	while(c!=' '){
		c = *++s;
	}
	*s = '\0';
	return result;
}


int strlen(const char *s){
	int length = 0;
	unsigned char c = *s;
	while(c){
		length++;
		c = *++s;
	}
	return length;
}

int strnlen(const char *s, int count){
	int length = 0;
	unsigned char c = *s;

	while(c && count-->0){
		length++;
		c = *++s;
	}
	return length;
}

void *memset(void *s, int c, int count){
	unsigned char *tmp = s;
	unsigned char ch = (unsigned char)c;
	while(count-->0){
		*tmp++ = ch;
	}
	return s;
}

