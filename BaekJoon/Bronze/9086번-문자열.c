#include <stdio.h>
#include <string.h>

int main()
{
    int testCase;
    scanf("%d", &testCase);
    char string[1005];
    
    for(int i = 0; i < testCase; i++)
    {
        scanf("%s", string);
        printf("%c%c\n", string[0], string[strlen(string) - 1]);
    }
    
    return 0;
}
