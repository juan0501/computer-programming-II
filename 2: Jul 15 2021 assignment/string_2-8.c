#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void count_alpha(char *sentence)
{
    int len = strlen(sentence);
    int cnt[3] = {0, 0, 0}; //(영문자, 대문자, 소문자)
    int n_cnt, s_cnt, other; //숫자, 공백, 기타 문자의 수
    n_cnt = s_cnt = other = 0; //init

    for(int i = 0; i < len; i++)
    {
        if(isalpha(sentence[i])) //영문자인가?
        {
            cnt[0]++;
            if(isupper(sentence[i])) //대문자인가?
                cnt[1]++; 
            else //소문자이다.
                cnt[2]++;
        }
        else if(isdigit(sentence[i])) //아니면 숫자인가?
            n_cnt++;
        else if(isspace(sentence[i])) //아니면 공백인가?
            s_cnt++;
        else //기타문자이다.
            other++;
    }

    printf("\n영문자 수: %d", cnt[0]);
    printf("\n대문자 수: %d", cnt[1]);
    printf("\n소문자 수: %d", cnt[2]);
    printf("\n숫자 수: %d", n_cnt);
    printf("\n공백 수: %d", s_cnt);
    printf("\n기타문자 수: %d", other);
}

int main()
{
    char sentence[100];
    printf("영어 문장을 입력하세요.\n");
    scanf("%[^\n]", sentence);

    count_alpha(sentence);
    return 0;
}
