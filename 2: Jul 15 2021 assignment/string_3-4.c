#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mystrcat(char* str1, char* str2);

int main()
{
    char str1[100];
    char str2[100];

    printf("���ڿ�1: ");
    scanf(" %s", str1);
    printf("���ڿ�2: ");
    scanf(" %s", str2);

    mystrcat(str1, str2);   // �Լ� ȣ��

    printf("==> %s", str1);

    return 0;
}

void mystrcat(char* str1, char* str2)
{
    int cnt1 = strlen(str1);  // �ε��� ���� ���ڿ� ���̷� �ʱ�ȭ
    int cnt2 = 0;             // �ε����� �ʱ�ȭ

    str1[cnt1++] = ' ';   // ��� ��

    while (1)
    {
        str1[cnt1] = str2[cnt2++];

        if (str2[cnt2] == '\0')   // str2 ���ڰ� ������ ����
            break;

        cnt1++;
    }

    str1[++cnt1] = '\0';
}