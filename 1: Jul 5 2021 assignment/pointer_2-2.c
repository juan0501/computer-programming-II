#include <stdio.h>
#include <stdlib.h>

int get_line(double x1, double y1, double x2, double y2, double* slope, double* yint);   // 함수 원형 선언

int main()
{
    double x1, y1, x2, y2;   // 좌표
    double s, y;             // 기울기, y절편

    printf("두개의 좌표를 입력하세요\n");
    printf("(x1, y1): ");
    scanf("%lf%lf", &x1, &y1);
    printf("(x2, y2): ");
    scanf("%lf%lf", &x2, &y2);

    if (get_line(x1, y1, x2, y2, &s, &y) == -1)   // 함수 호출, 변수 s, y의 주소값 넘겨줌
        printf("오류");

    else
        printf("\n기울기: %.1lf\ny절편: %.1lf\n직선방정식: y = %.1lfx + %.1lf", s, y, s, y);

}

int get_line(double x1, double y1, double x2, double y2, double* slope, double* yint)
{
    if (x1 == x2)     // 두 점의 x좌표가 같은 경우 ( 기울기 계산 불가능 ) 
        return –1;

    *slope = (double)(y1 - y2) / (x1 - x2);   // 기울기
    *yint = y1 - (*slope) * x1;           // y절편

    return 0;
}