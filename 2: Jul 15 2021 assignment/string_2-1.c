#include <stdio.h>
#include <stdlib.h>

void gcd_lcm(int x, int y, int* gcd, int* lcm)
{
    int num1, num2, num3;

    if (x > y)
    {
        num1 = x;
        num2 = y;
    }

    else if (x < y)
    {
        num1 = y;
        num2 = x;
    }

    else  // �� ���� ���� ���
        printf("�����Դϴ�.");


    while (num2 != 0)    // num2�� 0�� �Ǳ� ������ �ݺ�
    {
        num3 = num1 % num2;
        num1 = num2;
        num2 = num3;
    }

    *gcd = num1;             // num2�� 0�̸� �ִ������� num1�� ����
    *lcm = (x * y) / *gcd;    // �ּҰ����
}

int main()
{
    int num1, num2, max, min;

    printf("2���� �ڿ��� �Է�: ");
    scanf("%d%d", &num1, &num2);

    gcd_lcm(num1, num2, &max, &min);  // �Լ� ȣ��

    printf("�ִ�����: %d\n�ּҰ����: %d", max, min);

    return 0;
}
