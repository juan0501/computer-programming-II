#include <stdio.h>
#include <stdlib.h>

void sum_diff(int x, int y, int* sum, int* diff);    // 함수 원형 선언

int main()
{
    int num1, num2, SUM, DIFF;    // 2개의 정수, 합, 차

    printf("2개의 정수 입력: ");
    scanf("%d%d", &num1, &num2);

    sum_diff(num1, num2, &SUM, &DIFF);  // 함수 호출, 주소값 넘겨줌

    printf("합: %d\n", SUM);
    printf("차: %d\n", DIFF);

    return 0;
}

void sum_diff(int x, int y, int* sum, int* diff)
{
    *sum = x + y;    // 합

    *diff = x - y;    // 차

    if (*diff < 0)     // 차는 항상 양수이므로 음수일 경우 –1 곱해줌
        *diff *= -1;
}