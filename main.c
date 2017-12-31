#include<stdio.h>

#include "str.h"

int main(int argc, char *argv[])
{
	const char str1[20] = "Hello";
	const char str2[20] = "World";
	char str3[20];
	const char str4[20] = "Hello!!World";
	char str5[20];
	const char str6[20] = "    spacesgone   ";
	char str7[20] = "    spacesgone   ";
	char str8[20] = "Hello!!";


	
	printf("strcpy: %s, expected:Hello\n", strcpy(str3, str1));

	printf("strncpy: %s, expected:Hello!!\n", strncpy(str5, str4,7));

	
	printf("strcat: %s, expected:HelloWorld\n", strcat(str3,str2));

	printf("strncat: %s, expected:Hello!!Wo\n", strncat(str8,str2,2));

	printf("strcmp: %d, expected:-1\n", strcmp(str1,str4));

	printf("strncmp: %d, expected:0\n", strncmp(str1,str4,5));

	printf("strchr: %s, expected:!!World\n", strchr(str4,(int)'!'));

	printf("strchrnul: %s, expected:\n", strchrnul(str4,(int)'q'));

	printf("strrchr: %s, expected:ld\n", strrchr(str4,(int)'l'));

	printf("strnchr: %s, expected:llo\n", strnchr(str1,3,(int)'l'));

	printf("skip_spaces: %s, expected:spacesgone   \n", skip_spaces(str6) );

	printf("strim: %s, expected:spacesgone\n", strim(str7) );
	
	printf("strlen: %d, expected:5\n", strlen(str1) );

	printf("strnlen: %d, expected:3\n", strnlen(str1,3) );
	
	char ptr[10];
	printf("memset: %s, expected:aaaa\n",memset(ptr,(int)'a', 4) );


}
