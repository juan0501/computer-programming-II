#include <stdio.h>
#include <string.h>
#include <ctype.h>

void function(char *string)
{
	char numString[100];
	int idx=0; //numString의 index
	int total = 0; //총합 

	for(int i = 0; i < strlen(string); i++)
	{
		if(isdigit(string[i]))
		{
			printf("%c\n", string[i]);
			numString[idx++] = string[i];
			total += string[i] - '0'; //문자 -> 숫자
		}
	}

	numString[idx] = '\0'; //문자열의 끝은 항상 null
	printf("숫자 문자열: %s(길이 %ld)\n", numString, strlen(numString));
	printf("총합: %d\n", total);
}

int main()
{
	char string[100];
	printf("문자열: "); scanf("%s", string);
	function(string);

	return 0;
}
