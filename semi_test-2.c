#include <stdio.h>
#include <string.h>

void to_upper(char arr[])
{
	for (int i = 0; i < strlen(arr); i++)
	{
		if (isalpha(arr[i]))  // ���ĺ��̸�
			printf("%c", toupper(arr[i]));  // �빮�ڷ�
		else
			printf("%c", arr[i]);
	}
}

void to_lower(char arr[])
{
	for (int i = 0; i < strlen(arr); i++)
	{
		if (isalpha(arr[i]))  // ���ĺ��̸�
			printf("%c", tolower(arr[i]));  // �ҹ��ڷ�
		else
			printf("%c", arr[i]);
	}
}

void print_3(char arr[])
{
	int i;

	for (i = 0; i < strlen(arr) - 1; i++)
	{
		if ((arr[i] == arr[i + 1]) && (arr[i] == ' '))  // �� �� ���� �����̸�
			continue;   // ��� X
		else
			printf("%c", arr[i]);  // ���� ���� -> ���⼭ �ϳ��� ���鸸 ���
	}

	if (arr[i] == arr[i + 1] && arr[i] == ' ')  // ������ 2�� �� ( for������ ���ϸ� index ���� �ʰ�)
		printf(" ");
	else
		printf("%c", arr[i]);
}

void print_4(char arr[])
{
	for (int i = 0; i < strlen(arr); i++)
	{
		if (isalpha(arr[i]))  // ���ĺ��̸�
			printf("%c", arr[i]);
		else  // ��Ÿ���� ��� X
			continue;
	}
}

void print_5(char arr[])
{
	int sum = 0;

	for (int i = 0; i < strlen(arr); i++)
	{
		if (isdigit(arr[i]))  // �����̸�
			sum += arr[i] - '0';   // ���� ����
		else
			printf("%c", arr[i]);
	}

	printf(" / �� �� : %d\n", sum);
}

int main()
{
	char sentence[100];
	int n;

	printf("���� �Է�: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("\n���� �Է� : ");
		rewind(stdin);
		gets(sentence);

		printf("\n�ҹ��ڸ� �빮�ڷ� ��ȯ : ");
		to_upper(sentence);

		printf("\n�빮�ڸ� �ҹ��ڷ� ��ȯ : ");
		to_lower(sentence);

		printf("\n�������� ��ĭ�� �ϳ��� ��ĭ���� ��� : ");
		print_3(sentence);

		printf("\n��Ÿ���� ���� ��� : ");
		print_4(sentence);

		printf("\n���ڹ��� ���� ��� (���� ���) : ");
		print_5(sentence);
	}

	return 0;
}