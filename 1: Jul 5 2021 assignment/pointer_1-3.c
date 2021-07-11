
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double arr[4] = {10.2, -34.45, 27.5, 125.6 };
    double* pd;

    pd = &arr;  // 배열의 첫번째 인덱스의 주소값 저장

    for (int i = 0; i < 4; i++)
    {
        printf("%.2lf\t", *(pd + i)); // i를 1씩 증가시키며 pd가 가리키는 값을 출력
    }

    return 0;
}
