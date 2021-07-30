#include <stdio.h>

int max(int arr[], int m)  // 최대값 반환 함수
{
	int max = arr[0];  // 최대값 초기화

	for (int i = 1; i < m; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}

	return max;
}

void second_max(int arr[], int m)
{
	for (int i = m-1; i >= 1; i--)   // 배열 오름차순 정렬되어 있으므로 맨 끝부터
	{
		if (arr[i] != arr[i - 1])  // 왼쪽 값과 비교 후 다르면, 왼쪽 값이 두번로 큰 값
		{
			printf("%d\n", arr[i - 1]);
			return;
		}
		else                       // 왼쪽 값과 비교 후 같으면, i--
			continue;
	}

	printf("두번째로 큰 값이 없습니다.\n");
	return;
}

void swap(int* a, int* b)  
{
	int temp;

	temp = (*b);
	(*b) = (*a);
	(*a) = temp;
}

void sort(int arr[], int m)
{
	for (int i = 0; i < m; i++)      //오름차순 정렬
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
				swap(&arr[i], &arr[j]);
		}
	}
}

void print_arr(int arr[], int m)  // 배열 값 출력
{
	for (int i = 0; i < m; i++)
		printf("%3d", arr[i]);
}

void duplicate_num(int arr[], int m)
{
	int num[100][100];
	int idx = 0;
	int flag;

	for (int i = 0; i < m; i++)
	{
		flag = 0;

		for (int j = 0; j < idx; j++)
		{
			if (num[j][0] == arr[i]) {  // 중복된 숫자인 경우
				num[j][1] += 1;  // 빈도수 증가
				flag = 1;
				break;
			}
		}

		if (flag == 0) {  // 중복되지 않은 숫자인 경우
			num[idx][0] = arr[i];  // 숫자 새로 등록
			num[idx++][1] = 1;     // 빈도수 1로 초기화
		}
	}

	for (int i = 0; i < idx; i++)
	{
		if (num[i][1] >= 2)  // 2번이상 등장한 경우
			printf("%3d", num[i][0]);
	}
}

int main()
{
	int n;
	int num[100];

	printf("정수 입력 : ");
	scanf("%d", &n);


	printf("배열 입력 : ");
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	printf("최대값 : %d\n", max(num, n));
	sort(num, n);
	printf("두번째로 큰 값 출력 : ");
	second_max(num, n);
	printf("오름차순 출력 :");
	print_arr(num, n);
	printf("\n두번 이상 입력된 값 :");
	duplicate_num(num, n);

	return 0;
}
