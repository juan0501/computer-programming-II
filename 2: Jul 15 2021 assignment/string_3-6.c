#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void palindrome(char *arr, int len)
{
    int cnt = 0;

    for (int i = 0; i < (len / 2); i++)
    {
        if (arr[i] == arr[len - 1 - i])
            cnt++;  // 같은 문자인 경우 셈
    }

    if (cnt == (len / 2))   // 회문인 경우
        printf("palindrome: Yes\n");
    else                      // 회문이 아닌 경우
        printf("palindrome: No\n");
}

int main()
{
    char word[20];
    printf("단어를 입력하세요: ");
    scanf("%s", word);

    int length = strlen(word);  

    printf("단어의 길이: %d\n", length);

    palindrome(word, length);

    return 0;
}