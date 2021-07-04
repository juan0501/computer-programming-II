#include <stdio.h>

int main()
{
	int M, N;
	char board[50][51];
	int cnt1, cnt2, flag, min, temp;

	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%s", board[i]);

	min = 65;

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			cnt1 = cnt2 = 0;

			for (int l = i; l < i + 8; l++) {
				for (int k = j; k < j + 8; k++)
				{
					if ((board[l][k] == 'B' && ((l - i) + (k - j)) % 2 != 0) || (board[l][k] == 'W' && ((l - i) + (k - j)) % 2 == 0))
						cnt1++;

					if ((board[l][k] == 'B' && ((l - i) + (k - j)) % 2 == 0) || (board[l][k] == 'W' && ((l - i) + (k - j)) % 2 != 0))
						cnt2++;
				}
			}

			if (cnt1 >= cnt2)
				temp = cnt2;
			else
				temp = cnt1;

			if (min > temp)
				min = temp;
		}
	}

	printf("%d", min);
}