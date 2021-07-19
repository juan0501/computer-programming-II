#include <stdio.h>
#include <string.h>


void sort_list(char name_list[100][100], int idx)
{
	char temp[100];
	for(int i = 0; i < idx; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(strcmp(name_list[i], name_list[j]) < 0)
			{
				strcpy(temp, name_list[i]);
				strcpy(name_list[i], name_list[j]);
				strcpy(name_list[j], temp);
			}
		}
	}
}

int main()
{
	char name_list[100][100];
	int idx = -1;

	printf("회원이름 입력\n");
	do
	{
		fgets(name_list[++idx], 100, stdin);
		printf("%ld\n", strlen(name_list[idx]));
		
	}while(strlen(name_list[idx]) != 1);

	printf("(가나다 순 정렬)\n");
	sort_list(name_list, idx);
	for(int i = 0; i < idx; i++)
	{
		printf("%s\n", name_list[i]);
	}

	return 0;
}
