#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input(char sentence[][100])
{
    int cnt = 0;

    printf("�������� ������� �Է��ϼ���.\n");

    while (1)
    {
        gets(sentence[cnt]);

        if (strlen(sentence[cnt]) == 0)  // ���� �Է½� ����
            break;

        cnt++;   // ������ ���� ��
    }

    return cnt;
}

int token_separate(int cnt1, char sentence[][100], char word[][100])
{
    int cnt2 = 0;
    char* token;
    char seps[] = " !?.,\t\n";

    for (int i = 0; i < cnt1; i++)
    {
        token = strtok(sentence[i], seps);

        while (token != NULL)
        {
            strcpy(word[cnt2++], token);  // �и��� �ܾ �迭�� ����
            token = strtok(NULL, seps);
        }
    }

    return cnt2;
}

void to_lower(int cnt, char word[][100])
{
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; word[i][j] != '\0'; j++)
        {
            if (isupper(word[i][j]))
                word[i][j] += 32;    // �ҹ��ڷ� ���� 
        }
    }
}

int overlap_check(int cnt1, char word[][100], char result[][100])
{
    int cnt2 = 0; // �ܾ��� ����
    int flag; // �ߺ� �˻��ϱ� ����

    for (int i = 0; i < cnt1; i++)
    {
        flag = 0;
        for (int j = 0; j < cnt2; j++)
        {
            if (strcmp(word[i], result[j]) == 0) // �ߺ��� ���
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0) // �ߺ� ���� ��� ���
            strcpy(result[cnt2++], word[i]);
    }

    return cnt2;
}

void sort(int cnt, char result[][100])
{
    char temp[100];

    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (strcmp(result[i], result[j]) < 0)  //���ĺ� ������ ����
            {
                strcpy(temp, result[i]);
                strcpy(result[i], result[j]);
                strcpy(result[j], temp);
            }
        }
    }
}

void print_word(int cnt, char result[][100])
{
    printf("���ĺ��� �ܾ���:\n");

    for (int i = 0; i < cnt; i++)
    {
        printf("%s", result[i]);

        if (i != cnt - 1)  // ���������� - ��� X
            printf("-");
    }
}

int main()
{
    char sentence[100][100];
    char word[100][100];
    char result_word[100][100];

    int cnt_sentence; //�Է��� ���ڿ��� ����
    int cnt_word = 0; // �ܾ��� ����

    cnt_sentence = input(sentence);

    cnt_word = token_separate(cnt_sentence, sentence, word);

    to_lower(cnt_word, word);

    cnt_word = overlap_check(cnt_word, word, result_word);

    sort(cnt_word, result_word);

    print_word(cnt_word, result_word);

    return 0;
}