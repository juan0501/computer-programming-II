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

    printf("���� ������ �Է��ϼ���.\n");

    while (1)
    {
        gets(str);
        len = strlen(str); 

        if (len == 0)  
            break; 

        token = strtok(str, lim);  

        printf("[�ܾ�]\n");
        while (token != NULL)  // ���ڿ��� ��ū�� �ִ� ���� �ݺ�
        {
            printf("%s\n", token);
            token = strtok(NULL, lim);  // ���� ��ū�� �������� NULL�� �μ��� ��
            cnt++;  // �ܾ� �� ��
        }

        printf("�� �ܾ��: %d\n", cnt);
        cnt = 0;  // �ܾ� �� �ʱ�ȭ
    }

    printf("[�����մϴ�]");

    return 0;
}


