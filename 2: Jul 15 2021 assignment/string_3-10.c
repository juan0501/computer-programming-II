#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_max(char arr[][100], int cnt)
{
    char max_word[100];
    int max = strlen(arr[0]);

    strcpy(max_word, arr[0]);

    for (int i = 1; i < cnt; i++)
    {
        if (max < strlen(arr[i]))
        {
            max = strlen(arr[i]);
            strcpy(max_word, arr[i]);
        }
    }

    printf("가장 긴 문장: %s\n", max_word);
    printf("단어길이: %d", max);
}

int main()
{
    char word[100][100];
    int cnt;

    printf("영어단어 입력:\n");

    cnt = 0;

    while (1)
    {
        gets(word[cnt]);

        if (strlen(word[cnt]) == 0)  // 빈줄 입력한 경우
            break;

        cnt++;  // 영어 단어 입력 개수 셈
    }

    print_max(word, cnt);

    return 0;
}