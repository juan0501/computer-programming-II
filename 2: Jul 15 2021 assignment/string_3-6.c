#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void palindrome(char *arr, int len)
{
    int cnt = 0;

    for (int i = 0; i < (len / 2); i++)
    {
        if (arr[i] == arr[len - 1 - i])
            cnt++;  // ���� ������ ��� ��
    }

    if (cnt == (len / 2))   // ȸ���� ���
        printf("palindrome: Yes\n");
    else                      // ȸ���� �ƴ� ���
        printf("palindrome: No\n");
}

int main()
{
    char word[20];
    printf("�ܾ �Է��ϼ���: ");
    scanf("%s", word);

    int length = strlen(word);  

    printf("�ܾ��� ����: %d\n", length);

    palindrome(word, length);

    return 0;
}