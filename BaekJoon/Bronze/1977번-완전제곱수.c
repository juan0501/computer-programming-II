#include <stdio.h>
#include <math.h>

int main()
{
	int M, N, sum, flag, min;

	scanf("%d", &M);
	scanf("%d", &N);

	flag = sum = 0;
	min = 10001;

	for (int i = M; i <= N; i++)
	{
		if ( (int)sqrt(i) * (int)sqrt(i) == i)
		{
			flag = 1;
			sum += i;

			if (min > i)
				min = i;
		}
	}

	if (flag == 0)
		printf("-1");

	else
		printf("%d\n%d", sum, min);
	return 0;
}