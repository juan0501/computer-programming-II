#include <stdio.h>

void input_arr(int m, int n, int p[][100])
{
    for (int i = 0; i < m; i++)  
    {
        for (int j = 0; j < n; j++)  
            scanf("%d", &p[i][j]); 
    }
}

int find_max(int m, int n, int p[][100])
{
    int max = p[0][0];  

    for (int i = 0; i < m; i++)  
    {
        for (int j = 0; j < n; j++)  
        {
            if (p[i][j] > max)
                max = p[i][j];
        }
    }

    return max;
}


int find_min(int m, int n, int p[][100])
{
    int min = p[0][0]; 

    for (int i = 0; i < m; i++)  
    {
        for (int j = 0; j < n; j++)  
        {
            if (p[i][j] < min)
                min = p[i][j];
        }
    }

    return min;
}

int main()
{
    int rows, cols;
    int arr[100][100];

    printf("�迭�� ��� ��: ");
    scanf("%d%d", &rows, &cols);

    printf("��İ�:\n");

    input_arr(rows, cols, arr);

    printf("\n�ִ밪: %d", find_max(rows, cols, arr));  
    printf("\n�ּҰ�: %d", find_min(rows, cols, arr)); 

    return 0;
}