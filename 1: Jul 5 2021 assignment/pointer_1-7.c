#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, r_num, seed, mine;
    int cnt[3] = { 0, };

    srand(time(NULL));

    printf("���������� ������ �� �� �ұ��? ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        r_num = rand() % 3 + 1;

        printf("\n=====< ���� %d >=====\n", i + 1);
        printf("����(1), ����(2), ��(3) ? ");
        scanf("%d", &mine);

        if (mine != 1 && mine != 2 && mine != 3) {
            printf("�߸� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���\n");
            i--;
        }

        else
        {
            switch (r_num)
            {
            case 1:
            {
                printf("(��ǻ��)==> ����\t");
                if (mine == 1)
                {
                    printf("(�����)==> ����\n");
                    printf("����� �����ϴ�!\n");
                    cnt[1]++;
                }
                else if (mine == 2)
                {
                    printf("(�����)==> ����\n");
                    printf("����� �̰���ϴ�!\n");
                    cnt[0]++;
                }
                else if (mine == 3)
                {
                    printf("(�����)==> ��\n");
                    printf("����� �����ϴ�!\n");
                    cnt[2]++;
                }
                break;
            }
            case 2:
            {
                printf("(��ǻ��)==> ����\t");
                if (mine == 1)
                {
                    printf("(�����)==> ����\n");
                    printf("����� �����ϴ�!\n");
                    cnt[2]++;
                }
                else if (mine == 2)
                {
                    printf("(�����)==> ����\n");
                    printf("����� �����ϴ�!\n");
                    cnt[1]++;
                }
                else if (mine == 3)
                {
                    printf("(�����)==> ��\n");
                    printf("����� �̰���ϴ�!\n");
                    cnt[0]++;
                }
                break;
            }
            case 3:
            {
                printf("(��ǻ��)==> ��\t");
                if (mine == 1)
                {
                    printf("(�����)==> ����\n");
                    printf("����� �̰���ϴ�!\n");
                    cnt[0]++;
                }
                else if (mine == 2)
                {
                    printf("(�����)==> ����\n");
                    printf("����� �����ϴ�!\n");
                    cnt[2]++;
                }
                else if (mine == 3)
                {
                    printf("(�����)==> ��\n");
                    printf("����� �����ϴ�!\n");
                    cnt[1]++;
                }
                break;
            }
            }
        }
    }

    printf("\n%d�� %d�� %d��", cnt[0], cnt[1], cnt[2]);

    return 0;
}