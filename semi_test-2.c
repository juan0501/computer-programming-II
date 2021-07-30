#include <stdio.h>
#include <string.h>

void to_upper(char arr[])
{
	for (int i = 0; i < strlen(arr); i++)
	{
		if (isalpha(arr[i]))  // 알파벳이면
			printf("%c", toupper(arr[i]));  // 대문자로
		else
			printf("%c", arr[i]);
	}
}

void to_lower(char arr[])
{
	for (int i = 0; i < strlen(arr); i++)
	{
		if (isalpha(arr[i]))  // 알파벳이면
			printf("%c", tolower(arr[i]));  // 소문자로
		else
			printf("%c", arr[i]);
	}
}

void print_3(char arr[])
{
	int i;

	for (i = 0; i < strlen(arr) - 1; i++)
	{
		if ((arr[i] == arr[i + 1]) && (arr[i] == ' '))  // 두 개 연속 공백이면
			continue;   // 출력 X
		else
			printf("%c", arr[i]);  // 연속 공백 -> 여기서 하나의 공백만 출력
	}

	if (arr[i] == arr[i + 1] && arr[i] == ' ')  // 마지막 2개 비교 ( for문에서 비교하면 index 범위 초과)
		printf(" ");
	else
		printf("%c", arr[i]);
}

void print_4(char arr[])
{
	for (int i = 0; i < strlen(arr); i++)
	{
		if (isalpha(arr[i]))  // 알파벳이면
			printf("%c", arr[i]);
		else  // 기타문자 출력 X
			continue;
	}
}

void print_5(char arr[])
{
	int sum = 0;

	for (int i = 0; i < strlen(arr); i++)
	{
		if (isdigit(arr[i]))  // 숫자이면
			sum += arr[i] - '0';   // 총합 저장
		else
			printf("%c", arr[i]);
	}

	printf(" / 총 합 : %d\n", sum);
}

int main()
{
	char sentence[100];
	int n;

	printf("정수 입력: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("\n문장 입력 : ");
		rewind(stdin);
		gets(sentence);

		printf("\n소문자를 대문자로 변환 : ");
		to_upper(sentence);

		printf("\n대문자를 소문자로 변환 : ");
		to_lower(sentence);

		printf("\n여러개의 빈칸을 하나의 빈칸으로 출력 : ");
		print_3(sentence);

		printf("\n기타문자 제외 출력 : ");
		print_4(sentence);

		printf("\n숫자문자 제외 출력 (총합 계산) : ");
		print_5(sentence);
	}

	return 0;
}