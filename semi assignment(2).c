#include <stdio.h>

int main()
{
    int num;
    int i, j, k, l;

    printf("줄(line) 수 : ");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < i; j++)
            printf(" ");

        for (k = 1; k < num-i; k++)
            printf("%d", k);

        for (l = k; l < k+num-i; l++)
            printf("%d", l);

        printf("\n");
    }

    return 0;
}
