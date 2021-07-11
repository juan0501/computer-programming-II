#include <stdio.h>
#include <stdlib.h>

void find(int k[], int* max, int* min);   // 함수 원형 선언

int main()
{
    int maxnum, minnum;  // 최대, 최소

    int k[10];  // 일차원 정수형 배열

    printf("정수입력: ");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &k[i]);    // 10개의 정수 입력
    }

    find(k, &maxnum, &minnum);  // 함수 호출, 주소값 넘겨줌

    printf("\nmax : %d", maxnum);
    printf("\nmin : %d", minnum);

    return 0;
}

void find(int k[], int* max, int* min)
{
    *max = *min = k[0];   // 최대, 최소값을 배열의 첫 번째 인덱스 값으로 초기화

    for (int i = 1; i < 10; i++)  // k[1] ~ k[9]
    {
        if (*max < k[i])     // k[i]가 *max 보다 크면
            *max = k[i];   // *max에 값 저장

        if (*min > k[i])     // k[i]가 *min 보다 작으면
            *min = k[i];   // *min에 값 저장
    }
}