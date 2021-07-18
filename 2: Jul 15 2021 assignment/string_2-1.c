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

    else  // 두 수가 같은 경우
        printf("오류입니다.");


    while (num2 != 0)    // num2가 0이 되기 전까지 반복
    {
        num3 = num1 % num2;
        num1 = num2;
        num2 = num3;
    }

    *gcd = num1;             // num2가 0이면 최대공약수는 num1과 같음
    *lcm = (x * y) / *gcd;    // 최소공배수
}

int main()
{
    int num1, num2, max, min;

    printf("2개의 자연수 입력: ");
    scanf("%d%d", &num1, &num2);

    gcd_lcm(num1, num2, &max, &min);  // 함수 호출

    printf("최대공약수: %d\n최소공배수: %d", max, min);

    return 0;
}
