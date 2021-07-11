#include <stdio.h>
#include <stdlib.h>

void input(double weight[], int n);    // �Լ� ���� ����
void sort(double weight[], int n);     // �Լ� ���� ����
void swap(double* a, double* b);    // �Լ� ���� ����
void print(double weight[], int n);    // �Լ� ���� ����

int main()
{
    int n;  // �л� ��

    printf("�л� ��: ");
    scanf("%d", &n);

    double weight[100];  // ������ �Ǽ����迭 ����

    input(weight, n);  // n����ŭ�� ü���� �迭�� �Է��ϴ� �Լ� ȣ��, �迭, �л��� �Ѱ���
    sort(weight, n);   // �迭�� ü�߰��� ������������ �����ϴ� �Լ� ȣ��, �迭, �л��� �Ѱ���
    print(weight, n);  // ���ĵ� ü���� ���ʷ� ����ϴ� �Լ� ȣ��, �迭, �л��� �Ѱ���

    return 0;
}

void input(double weight[], int n)
{
    printf("ü���Է�: ");
    for (int i = 0; i < n; i++)
        scanf("%lf", &weight[i]);   // �л� ����ŭ ü�� �Է�
}

void sort(double weight[], int n)   // �������� ����
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (weight[i] > weight[j])
                swap(&weight[i], &weight[j]);  // swap �Լ� ȣ��, �ּҰ� �Ѱ���
        }
    }
}

void swap(double* a, double* b)
{
    double temp;

    temp = *a;
    *a = *b;
    *b = temp;
}


void print(double weight[], int n)
{
    printf("\n�������� ���İ��: ");
    for (int i = 0; i < n; i++)
        printf("%.1lf ", weight[i]);   // �������� ���� ��, ü�� ���
}