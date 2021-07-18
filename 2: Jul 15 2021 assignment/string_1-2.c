#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void reverse_order(char* arr, int length)
{
	for (int i = length -1; i >= 0; i--)
		printf("%c", arr[i]);
}

void print_upper(char* arr, int length)
{
	for (int i = 0; i < length; i++)
		printf("%c", toupper(arr[i]));
}

int main()
{
	char str[100] = "interesting";
	int len;

	printf("저장된 단어 : %s", str);
	len = strlen(str);
	printf("\n단어의 길이 : %d", len);
	printf("\n대문자 변환 : ");
	print_upper(str, len);
	printf("\n단어의 역순 : ");
	reverse_order(str, len);

	return 0;
}