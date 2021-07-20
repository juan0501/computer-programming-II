#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void partition(char *string, int len, int limit_len)
{
    for(int i = len - limit_len; i < len; i++)
        printf("%c", string[i]);
    printf("\n");
}

int totalOfSum(char *string, int len)
{
    int sum = 0;
    for(int i = 0; i < len; i++)
    {
        if(isdigit(string[i]))
            sum += string[i] - '0';
    }
    return sum;
}

void checkFreq(char *string, int len)
{
    int freq[10][1] = {0, };
    
    for(int i = 0; i < len; i++)
    {
        if(isdigit(string[i]))
        {
            freq[string[i] - '0'][0]++;
        }
    }
    
    for(int i = 0; i < 10; i++)
    {
        if(freq[i][0] > 0)
            printf("(%d): %d", i, freq[i][0]);
    }
    printf("\n");
}

void getNumString(char *string, int len)
{
    char nString[100];
    int idx = 0;
    for(int i = 0; i < len; i++)
    {
        if(isdigit(string[i]))
            nString[idx++] = string[i];
    }
    nString[idx] = '\0';
    printf("숫자 문자열: %s\n", nString);
}

int main(int argc, const char * argv[]) {
    
    char string[100];
    printf("문자열: "); scanf("%[^\n]", string);

    int limit_len;
    printf("출력될 문자 수: "); scanf("%d", &limit_len);
    printf("부분 문자열: ");
    partition(string, strlen(string), limit_len);
    
    printf("숫자 총합: %d\n", totalOfSum(string, strlen(string)));
    
   
    checkFreq(string, strlen(string));
    getNumString(string, strlen(string));
    
    printf("\n");
    return 0;
}
