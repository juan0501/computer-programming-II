#include <stdio.h>

int main()
{
	int num, min, flag, sum;

	flag = sum = 0;
	min = 100;

	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &num);

		if (num % 2 != 0)
		{
			flag = 1;
			sum += num;

			if (min > num)
				min = num;
		}
	}

	if (flag == 0)
		printf("-1");

	else
		printf("%d\n%d", sum, min);

	return 0;
}