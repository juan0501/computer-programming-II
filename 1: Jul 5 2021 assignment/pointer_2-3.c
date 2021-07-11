#include <stdio.h>
#include <stdlib.h>

void find(int k[], int* max, int* min);   // �Լ� ���� ����

int main()
{
    int maxnum, minnum;  // �ִ�, �ּ�

    int k[10];  // ������ ������ �迭

    printf("�����Է�: ");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &k[i]);    // 10���� ���� �Է�
    }

    find(k, &maxnum, &minnum);  // �Լ� ȣ��, �ּҰ� �Ѱ���

    printf("\nmax : %d", maxnum);
    printf("\nmin : %d", minnum);

    return 0;
}

void find(int k[], int* max, int* min)
{
    *max = *min = k[0];   // �ִ�, �ּҰ��� �迭�� ù ��° �ε��� ������ �ʱ�ȭ

    for (int i = 1; i < 10; i++)  // k[1] ~ k[9]
    {
        if (*max < k[i])     // k[i]�� *max ���� ũ��
            *max = k[i];   // *max�� �� ����

        if (*min > k[i])     // k[i]�� *min ���� ������
            *min = k[i];   // *min�� �� ����
    }
}