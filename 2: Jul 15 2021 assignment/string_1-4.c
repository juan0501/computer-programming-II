#include <stdio.h>
#include <string.h>

void print_arr(char* arr, int n)
{
    int len = strlen(arr);

    for (int i = len - n; i < len; i++)
        printf("%c", arr[i]);
}

int main()
{
    char str[100] = "interesting"; 
    int num;  

    printf("���ڿ�: %s\n", str);

    printf("��µ� ���ڼ�: ");
    scanf("%d", &num);

    print_arr(str, num);

    return 0;
}