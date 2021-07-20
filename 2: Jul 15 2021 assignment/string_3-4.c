#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mystrcat(char* str1, char* str2);

int main()
{
    char str1[100];
    char str2[100];

    printf("문자열1: ");
    scanf(" %s", str1);
    printf("문자열2: ");
    scanf(" %s", str2);

    mystrcat(str1, str2);   // 함수 호출

    printf("==> %s", str1);

    return 0;
}

void mystrcat(char* str1, char* str2)
{
    int cnt1 = strlen(str1);  // 인덱스 값을 문자열 길이로 초기화
    int cnt2 = 0;             // 인덱스값 초기화

    str1[cnt1++] = ' ';   // 띄어 씀

    while (1)
    {
        str1[cnt1] = str2[cnt2++];

        if (str2[cnt2] == '\0')   // str2 문자가 끝나면 종료
            break;

        cnt1++;
    }

    str1[++cnt1] = '\0';
}