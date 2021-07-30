#include <stdio.h>

int max(int arr[], int m)  // �ִ밪 ��ȯ �Լ�
{
	int max = arr[0];  // �ִ밪 �ʱ�ȭ

	for (int i = 1; i < m; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}

	return max;
}

void second_max(int arr[], int m)
{
	for (int i = m-1; i >= 1; i--)   // �迭 �������� ���ĵǾ� �����Ƿ� �� ������
	{
		if (arr[i] != arr[i - 1])  // ���� ���� �� �� �ٸ���, ���� ���� �ι����� ū ��
		{
			printf("%d\n", arr[i - 1]);
			return;
		}
		else                       // ���� ���� �� �� ������, i--
			continue;
	}

	printf("�ι�°�� ū ���� �����ϴ�.\n");
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
	for (int i = 0; i < m; i++)      //�������� ����
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
				swap(&arr[i], &arr[j]);
		}
	}
}

void print_arr(int arr[], int m)  // �迭 �� ���
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
			if (num[j][0] == arr[i]) {  // �ߺ��� ������ ���
				num[j][1] += 1;  // �󵵼� ����
				flag = 1;
				break;
			}
		}

		if (flag == 0) {  // �ߺ����� ���� ������ ���
			num[idx][0] = arr[i];  // ���� ���� ���
			num[idx++][1] = 1;     // �󵵼� 1�� �ʱ�ȭ
		}
	}

	for (int i = 0; i < idx; i++)
	{
		if (num[i][1] >= 2)  // 2���̻� ������ ���
			printf("%3d", num[i][0]);
	}
}

int main()
{
	int n;
	int num[100];

	printf("���� �Է� : ");
	scanf("%d", &n);


	printf("�迭 �Է� : ");
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	printf("�ִ밪 : %d\n", max(num, n));
	sort(num, n);
	printf("�ι�°�� ū �� ��� : ");
	second_max(num, n);
	printf("�������� ��� :");
	print_arr(num, n);
	printf("\n�ι� �̻� �Էµ� �� :");
	duplicate_num(num, n);

	return 0;
}