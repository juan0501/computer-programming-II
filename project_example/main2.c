#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Subject // ���� ����
{
    char name[20]; // ����
    char num[20];  // �й�
    int credits;   // ����
    char score;    // ����( A, B, ... )
    int check;
} Subject;

typedef struct User
{
    int value; // 0 : ������, 1 : �л�
    char ID[20];
    char PW[20];
    char name[20];
    char num[20];  // �й�
    int age;
    struct User* next;
    struct Subject sub;
} User;

User* user_head = NULL, * user_tail = NULL;
void window_1();
void excution(int n);
void sign_in();
void user_information(User* user);
int compare_duplication(char* ID);
int IDPW_length(char* user);
int engdig(char* user);
void pw_cmp(char PW[]);
void log_in();
User* search_ID(char* ID);
void insert_score();
void subject_information(Subject* subject);
void print_score();
void print_my_score(User* user);
void window_professor(User* user);
void window_student(User* user);

int main()
{
    while (1)
    {
        window_1();
    }
    return 0;
}

void window_1()
{
    int n;
    printf("\n�α���(1) ȸ������(2) : ");
    scanf("%d", &n);

    excution(n);
}

void excution(int n)
{
    switch (n)
    {
    case 1:
        log_in();
        break;
    case 2:
        sign_in();
        break;
    default:
        printf("\n[�߸� �������ϴ�.]\n");
        break;
    }
}

//sign in
void sign_in()
{
    if (user_head != NULL)
    {
        user_tail->next = (User*)malloc(sizeof(User));
        user_tail = user_tail->next;
    }
    else
    {
        user_head = (User*)malloc(sizeof(User));
        user_tail = user_head;
    }

    user_information(user_tail);

    user_tail->next = NULL;
}

//insert user information
void user_information(User* user)
{
    printf("\n=======================\n");
    char* ID = (char*)malloc(sizeof(char) * 20);

    while (1)
    {
        printf("ID �Է�: ");
        scanf(" %s", ID);

        if (compare_duplication(ID) == 0 || IDPW_length(ID) == 0 || engdig(ID) == 0)
            continue;

        else
            break;
    }

    strcpy(user->ID, ID);
    pw_cmp(user->PW);

    printf("�̸�: ");
    scanf(" %s", user->name);

    printf("����: ");
    scanf("%d", &user->age);

    do
    {
        printf("(0)������ , (1)�л� : ");
        scanf("%d", &user->value);
    } while (user->value != 0 && user->value != 1); //�ٸ� ��ȣ�� �Է��ϴ� ���

    if (user->value == 1)
    {
        printf("�й� �Է�: ");
        scanf("%d", user->num);
    }

    printf("\n=======================\n");
}

int compare_duplication(char* ID)  // ���̵� �ߺ� Ȯ��
{
    if (user_head == NULL || user_head == user_tail) //node�� ���� ���
        return 1;
    else
    {
        for (User* p = user_head; p != user_tail; p = p->next)
            if (strcmp(p->ID, ID) == 0)
            {
                printf("\n[�ߺ��Ǿ����ϴ�.]\n");
                return 0;
            }
    }
    return 1;
}

//ID,PW ��������
int IDPW_length(char* user)
{
    int length = strlen(user);
    int cnt = 0;

    if (length > 10)  // ���̵� 10���� �̻��� ���
    {
        printf("\n[10���� ���Ϸ� �ٽ��Է��ϼ���.]\n");

        return 0;
    }

    return 1;
}

int engdig(char* user)  // ������, ���ڷθ� ���̵�, ��й�ȣ �Է�
{
    int length = strlen(user);
    int cnt = 0;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(user[i]))
            cnt++;
        else if (isdigit(user[i]))
            cnt++;
    }

    if (cnt == length)
        return 1;

    printf("\n[ID/PW�� �����ڿ� ���ڷθ� �̷������ �մϴ�.]\n");
    return 0;
}

void pw_cmp(char PW[])  // ��й�ȣ Ȯ��
{
    char cmpPW[20];

    while (1)
    {
        printf("PW �Է�: ");
        scanf(" %s", user_tail->PW);

        if (compare_duplication(user_tail->PW) == 0 || IDPW_length(user_tail->PW) == 0 || engdig(user_tail->PW) == 0)
            continue;

        else
            break;
    }

    while (1)
    {
        printf("�н����� Ȯ��: ");
        scanf(" %s", cmpPW);
        if (strcmp(PW, cmpPW) == 0)
            break;
        else
            printf("PW�� ��ġ���� �ʽ��ϴ�.\n");
    }
}

//log in
void log_in()
{
    char ID[20], PW[20];
    User* p;

    printf("ID : ");
    scanf(" %s", ID);

    p = search_ID(ID);

    if (p)
    {
        printf("PW : ");
        scanf(" %s", PW);

        if (strcmp(PW, p->PW) == 0)
        {
            printf("\n[�α��� �Ǿ����ϴ�.]\n");
            if (p->value == 0) //�������� ���
                window_professor(p);
            else //�л��� ���
                window_student(p);
        }
        else
        {
            printf("\n[��й�ȣ�� Ʋ�Ƚ��ϴ�.]\n");
            window_1(); //�ʱ�ȭ������ �̵�
        }
    }
    else
    {
        printf("\n[���̵� �������� �ʽ��ϴ�.]\n");
        window_1(); //�ʱ�ȭ������ �̵�
    }
}

User* search_ID(char* ID)  // ��ϵ� ���̵����� Ȯ��
{
    for (User* p = user_head; p != NULL; p = p->next)
    {
        if (strcmp(p->ID, ID) == 0)
            return p;
    }
    return NULL;
}

void insert_score()
{
    char temp[20];

    printf("������ �Է��� �л��� �й��� �Է��ϼ���: ");
    scanf(" %s", temp);

    for (User* p = user_head; p != NULL; p = p->next)
    {
        if (strcmp(p->num, temp) == 0)  // ���ϴ� �л��� �й��� �����ϸ� ���� �Է� ����
        {
            printf("\n=======================\n");
            printf("\n�����: %s\n", p->sub.name);
            printf("\n����: %d\n", p->sub.credits);
            printf("\n�й�: %s\n", p->sub.num);
            printf("\n���� �Է�:");
            printf("%c", p->sub.score);
            printf("\n=======================\n");
            p->sub.check = 1;  // ������ �ԷµǾ����� �ǹ�
        }
    }
}

void print_score()
{
    for (User* p = user_head; p != NULL; p = p->next)
    {
        if (p->sub.check == 1)  // ������ �Էµ� �л��� �������� ���� Ȯ��
        {
            printf("\n=======================\n");
            printf("\n�����: %s\n", p->sub.name);
            printf("\n����: %d\n", p->sub.credits);
            printf("\n�й�: %s\n", p->sub.num);
            printf("\n����: %c\n", p->sub.score);
            printf("\n=======================\n");
        }
    }
}

void insert_subject(User *user)  // �л��� ������ ���� �ϳ� ����
{
    printf("\n=======================\n");

    printf("�й�: ");
    scanf(" %s", user->sub.num);

    printf("���� �̸� : ");
    scanf(" %[^\n]", user->sub.name);

    printf("������ ���� :");
    scanf("%d", &user->sub.credits);

    user->sub.check = 0;  // ������ ���� �ԷµǱ� ������ �ǹ�

    printf("\n=======================\n");
}

void print_subject(User *user)
{
    printf("\n=======================\n");
    printf("���� ����� : %s\n", user->sub.name);
    printf("���� : %d", user->sub.credits);
    if (user->sub.check == 1)  // ���� �Է� �Ǿ��� ��� ������ ���
        printf("���� : %c", user->sub.score);
    printf("\n=======================\n");
}

void window_professor(User* user)
{
    int menu;
    printf("(1)�л� ���� ��� (2)�л� ���� ���� ���, (2)�α׾ƿ�");
    printf("\n=> ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        insert_score();
        break;
    case 2:
        print_score();
        break;
    case 3:
        printf("\n[�α׾ƿ� �Ǽ̽��ϴ�.]\n");
        system("cls");
        return;
    default:
        printf("\n[�߸��Է��ϼ̽��ϴ�.]\n");
        break;
    }
    window_professor(user);
}

// activity 3 //
void window_student(User* user)
{
    int menu;
    printf("(1) ���� ���� ��� (2)���� ���� ���, (3)�α׾ƿ�");
    printf("\n=> ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        insert_subject(user);
        break;
    case 2:
        print_subject(user);
        break;
    case 3:
        printf("\n[�α׾ƿ� �Ǽ̽��ϴ�.]\n");
        system("cls");
        return;
    default:
        printf("\n[�߸��Է��ϼ̽��ϴ�.]\n");
        break;
    }
    window_student(user);
}