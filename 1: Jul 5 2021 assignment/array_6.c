#include <stdio.h>

int is_prime(int num)
{
	for(int i = 2; i < num; i++)
		if(num % 2 == 0)
			return 0;
	return 1;
}

int main()
{
	int a, b;
	printf("a, b 입력: "); scanf("%d%d", &a, &b);
	
	int flag = 0;
	for(int i = a; i <= b; i++)
	{
		if(flag == 5)
		{
			printf("\n");
			flag = 0;
		}
		if(is_prime(i))
		{
			printf("%5d", i);
			flag++;
		}
	}
	return 0;
}
