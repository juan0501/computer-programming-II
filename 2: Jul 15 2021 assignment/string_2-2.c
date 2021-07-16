#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int num)
{
	int temp;
	for(int i = 0; i < num; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(arr[i] < arr[j])
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
		}
	}
}

void count_value(int *arr, int num)
{
	int cnt = 0;
	int idx = 0;
	
	while(idx < num)
	{
		cnt = 0;
		for(int i = 0; i < num; i++)
			if(arr[idx] == arr[i])
				cnt++;
		printf("\n%d: %d개", arr[idx], cnt);
		idx += cnt;
	}
}

int main()
{
	int num; 
	printf("입력할 정수의 개수: "); scanf("%d", &num);

	int arr[num];
	for(int i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	bubble_sort(arr, num);
	count_value(arr, num);
	printf("\n");
	return 0;
}
