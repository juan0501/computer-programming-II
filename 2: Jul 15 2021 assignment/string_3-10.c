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

    printf("���� �� ����: %s\n", max_word);
    printf("�ܾ����: %d", max);
}

int main()
{
    char word[100][100];
    int cnt;

    printf("����ܾ� �Է�:\n");

    cnt = 0;

    while (1)
    {
        gets(word[cnt]);

        if (strlen(word[cnt]) == 0)  // ���� �Է��� ���
            break;

        cnt++;  // ���� �ܾ� �Է� ���� ��
    }

    print_max(word, cnt);

    return 0;
}