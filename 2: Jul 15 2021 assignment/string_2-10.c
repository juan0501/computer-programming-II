#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    char* token;
    char lim[10] = " .,!?"; 
    int len, cnt;
    cnt = 0;

    printf("영어 문장을 입력하세요.\n");

    while (1)
    {
        gets(str);
        len = strlen(str); 

        if (len == 0)  
            break; 

        token = strtok(str, lim);  

        printf("[단어]\n");
        while (token != NULL)  // 문자열에 토큰이 있는 동안 반복
        {
            printf("%s\n", token);
            token = strtok(NULL, lim);  // 다음 토큰을 얻으려면 NULL을 인수로 줌
            cnt++;  // 단어 수 셈
        }

        printf("총 단어수: %d\n", cnt);
        cnt = 0;  // 단어 수 초기화
    }

    printf("[종료합니다]");

    return 0;
}


