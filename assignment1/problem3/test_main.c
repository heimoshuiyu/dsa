#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "uncompress.h"

int main() {
	int cnt = 0;
	char* str = NULL;
	char* res = NULL;

	printf("input: %s\n", str);
	res = Uncompress(str);
	printf("output: %s\n", res);
	printf("judge: %s\n\n", res==NULL?"True":"False");
	if(res==NULL)++cnt;

	str = "";
	printf("input: %s\n", str);
	res = Uncompress(str);
	printf("output: %s\n", res);
	printf("judge: %s\n\n", strcmp(res, "")==0?"True":"False");
	if(strcmp(res, "")==0)++cnt;

	str = "abc";
	printf("input: %s\n", str);
	res = Uncompress(str);
	printf("output: %s\n", res);
	printf("judge: %s\n\n", strcmp(res, "abc")==0?"True":"False");
	if(strcmp(res, "abc")==0)++cnt;

	str = "a1(b)c";
	printf("input: %s\n", str);
	res = Uncompress(str);
	printf("output: %s\n", res);
	printf("judge: %s\n\n", strcmp(res, "abc")==0?"True":"False");
	if(strcmp(res, "abc")==0)++cnt;

	str = "a11(c)d";
	printf("input: %s\n", str);
	res = Uncompress(str);
	printf("output: %s\n", res);
	printf("judge: %s\n\n", strcmp(res, "acccccccccccd")==0?"True":"False");
	if(strcmp(res, "acccccccccccd")==0)++cnt;

	str = "3(a)2(bc)";
	printf("input: %s\n", str);
	res = Uncompress(str);
	printf("output: %s\n", res);
	printf("judge: %s\n\n", strcmp(res, "aaabcbc")==0?"True":"False");
	if(strcmp(res, "aaabcbc")==0)++cnt;

	str = "3(a2(c))";
	printf("input: %s\n", str);
	res = Uncompress(str);
	printf("output: %s\n", res);
	printf("judge: %s\n\n", strcmp(res, "accaccacc")==0?"True":"False");
	if(strcmp(res, "accaccacc")==0)++cnt;

	str = "2(abb3(cd))ef";
	printf("input: %s\n", str);
	res = Uncompress(str);
	printf("output: %s\n", res);
	printf("judge: %s\n\n", strcmp(res, "abbcdcdcdabbcdcdcdef")==0?"True":"False");
	if(strcmp(res, "abbcdcdcdabbcdcdcdef")==0)++cnt;

	switch(cnt){
		case 8:printf("A\n");break;
		case 7:
		case 6:printf("B\n");break;
		case 5:printf("C\n");break;
		case 4:
		case 3:
		case 2:
		case 1:printf("D\n");break;
		default:printf("F\n");
	}

}
