#include <stdio.h>
#include <stdlib.h>

int int_part(double* m);       // 함수 원형 선언
double frac_part(double* m);  // 함수 원형 선언

int main()
{
    double num;

    printf("실수: ");
    scanf("%lf", &num);

    printf("\n정수부분: %d", int_part(&num));    // 함수 호출, num의 주소값을 넘겨줌
    printf("\n소수부분: %.3lf", frac_part(&num));  // 함수 호출, num의 주소값을 넘겨줌, 소수점 셋째자리까지 출력

    return 0;
}

int int_part(double* m)
{
    int result = (int)(*m);  // 정수부분
    return result;
}

double frac_part(double* m)
{
    double result = *m - (int)(*m);  // 소수부분
    return result;
}