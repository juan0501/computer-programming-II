#include <stdio.h>
#include <stdlib.h>

int int_part(double* m);       // �Լ� ���� ����
double frac_part(double* m);  // �Լ� ���� ����

int main()
{
    double num;

    printf("�Ǽ�: ");
    scanf("%lf", &num);

    printf("\n�����κ�: %d", int_part(&num));    // �Լ� ȣ��, num�� �ּҰ��� �Ѱ���
    printf("\n�Ҽ��κ�: %.3lf", frac_part(&num));  // �Լ� ȣ��, num�� �ּҰ��� �Ѱ���, �Ҽ��� ��°�ڸ����� ���

    return 0;
}

int int_part(double* m)
{
    int result = (int)(*m);  // �����κ�
    return result;
}

double frac_part(double* m)
{
    double result = *m - (int)(*m);  // �Ҽ��κ�
    return result;
}