#include <stdio.h>
#include <stdlib.h>

void input(double weight[], int n);    // 함수 원형 선언
void sort(double weight[], int n);     // 함수 원형 선언
void swap(double* a, double* b);    // 함수 원형 선언
void print(double weight[], int n);    // 함수 원형 선언

int main()
{
    int n;  // 학생 수

    printf("학생 수: ");
    scanf("%d", &n);

    double weight[100];  // 일차원 실수형배열 선언

    input(weight, n);  // n개만큼의 체중을 배열에 입력하는 함수 호출, 배열, 학생수 넘겨줌
    sort(weight, n);   // 배열의 체중값을 내림차순으로 정렬하는 함수 호출, 배열, 학생수 넘겨줌
    print(weight, n);  // 정렬된 체중을 차례로 출력하는 함수 호출, 배열, 학생수 넘겨줌

    return 0;
}

void input(double weight[], int n)
{
    printf("체중입력: ");
    for (int i = 0; i < n; i++)
        scanf("%lf", &weight[i]);   // 학생 수만큼 체중 입력
}

void sort(double weight[], int n)   // 내림차순 정렬
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (weight[i] > weight[j])
                swap(&weight[i], &weight[j]);  // swap 함수 호출, 주소값 넘겨줌
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
    printf("\n내림차순 정렬결과: ");
    for (int i = 0; i < n; i++)
        printf("%.1lf ", weight[i]);   // 내림차순 정렬 후, 체중 출력
}