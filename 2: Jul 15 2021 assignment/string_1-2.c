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

	printf("����� �ܾ� : %s", str);
	len = strlen(str);
	printf("\n�ܾ��� ���� : %d", len);
	printf("\n�빮�� ��ȯ : ");
	print_upper(str, len);
	printf("\n�ܾ��� ���� : ");
	reverse_order(str, len);

	return 0;
}