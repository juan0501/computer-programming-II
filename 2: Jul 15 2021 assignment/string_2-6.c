#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int print(char *string)
{
	int cnt = 0;
	for(int i = 0; i < strlen(string); i++)
		if(isalpha(string[i])) //알파벳인지 판단하는 함수 -> ctype.h
		{
			printf("%c", string[i]);
			cnt++; //알파벳의 개수
		}
	return cnt;
}
int main()
{
	char string[100]; //문자열
	
	printf("문자열: "); scanf("%s", string); //문자열 입력 
	int cnt = print(string); 
	printf("(%d)\n", cnt);

	return 0;
}

