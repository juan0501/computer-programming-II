#include <stdio.h>

int main()
{
	int row, col;
	printf("배열의 행과 열: "); scanf("%d%d", &row, &col);

	int arr[row + 1][col + 1];

	for(int i = 0; i <= row; i++)
		for(int j = 0; j <= col; j++)
			arr[i][j] = 0;

	int total = 0;
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			scanf("%d", &arr[i][j]);
			total += arr[i][j];
		}
	}

	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			arr[i][col] += arr[i][j];

	for(int j = 0; j < col; j++)
		for(int i = 0; i < row; i++)
			arr[row][j] += arr[i][j];
			
	arr[row][col] = total;	
	printf("\n배열의 결과\n");
	for(int i = 0; i <= row; i++)
	{
		for(int j = 0; j <= col; j++)
			printf("%5d", arr[i][j]);
		printf("\n");
	}

	printf("\n%d는 전체의 합\n", arr[row][col]);

	return 0;
}
