#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, r_num, seed, mine;
    int cnt[3] = { 0, };

    srand(time(NULL));

    printf("가위바위보 게임을 몇 번 할까요? ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        r_num = rand() % 3 + 1;

        printf("\n=====< 게임 %d >=====\n", i + 1);
        printf("가위(1), 바위(2), 보(3) ? ");
        scanf("%d", &mine);

        if (mine != 1 && mine != 2 && mine != 3) {
            printf("잘못 입력하였습니다. 다시 입력하세요\n");
            i--;
        }

        else
        {
            switch (r_num)
            {
            case 1:
            {
                printf("(컴퓨터)==> 가위\t");
                if (mine == 1)
                {
                    printf("(사용자)==> 가위\n");
                    printf("당신이 비겼습니다!\n");
                    cnt[1]++;
                }
                else if (mine == 2)
                {
                    printf("(사용자)==> 바위\n");
                    printf("당신이 이겼습니다!\n");
                    cnt[0]++;
                }
                else if (mine == 3)
                {
                    printf("(사용자)==> 보\n");
                    printf("당신이 졌습니다!\n");
                    cnt[2]++;
                }
                break;
            }
            case 2:
            {
                printf("(컴퓨터)==> 바위\t");
                if (mine == 1)
                {
                    printf("(사용자)==> 가위\n");
                    printf("당신이 졌습니다!\n");
                    cnt[2]++;
                }
                else if (mine == 2)
                {
                    printf("(사용자)==> 바위\n");
                    printf("당신이 비겼습니다!\n");
                    cnt[1]++;
                }
                else if (mine == 3)
                {
                    printf("(사용자)==> 보\n");
                    printf("당신이 이겼습니다!\n");
                    cnt[0]++;
                }
                break;
            }
            case 3:
            {
                printf("(컴퓨터)==> 보\t");
                if (mine == 1)
                {
                    printf("(사용자)==> 가위\n");
                    printf("당신이 이겼습니다!\n");
                    cnt[0]++;
                }
                else if (mine == 2)
                {
                    printf("(사용자)==> 바위\n");
                    printf("당신이 졌습니다!\n");
                    cnt[2]++;
                }
                else if (mine == 3)
                {
                    printf("(사용자)==> 보\n");
                    printf("당신이 비겼습니다!\n");
                    cnt[1]++;
                }
                break;
            }
            }
        }
    }

    printf("\n%d승 %d무 %d패", cnt[0], cnt[1], cnt[2]);

    return 0;
}