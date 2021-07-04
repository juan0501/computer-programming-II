#include <stdio.h>

int max(int *arr, int n)
{
	int m = arr[0];
	
	for(int i = 1; i < n; i++)
		if(m < arr[i])
			m = arr[i];
	return m;
}

int min(int arr[], int n)
{
	int m = arr[0];

	for(int i = 1; i < n; i++)
		if(m > arr[i])
			m = arr[i];
	return m;
}

int main()
{
	int n;
	printf("입력할 정수의 개수: "); scanf("%d", &n);

	int arr[n];

	printf("정수 %d개를 입력하세요\n=>", n);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("\n입력한 정수: ");
	for(int i = 0; i < n; i++)
		printf(" %d", arr[i]);
	
	printf("\n역순: ");
	for(int i = n - 1; i >=0; i--)
		printf(" %d", arr[i]);
	
	printf("\n가장 큰 정수: %d", max(arr, n));
	printf("\n가장 작은 정수: %d", min(arr, n));
  
	return 0;
}
