
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double arr[4] = {10.2, -34.45, 27.5, 125.6 };
    double* pd;

    pd = &arr;  // �迭�� ù��° �ε����� �ּҰ� ����

    for (int i = 0; i < 4; i++)
    {
        printf("%.2lf\t", *(pd + i)); // i�� 1�� ������Ű�� pd�� ����Ű�� ���� ���
    }

    return 0;
}
