#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Subject // �л��� ���� ����
{
    char name[20]; // ����
    char num[20];  // �й�
    int credits;   // ����
    char score;    // ����( A, B, ... )
    struct Subject* next;
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
} User;

User* user_head = NULL, * user_tail = NULL;
Subject* subject_head = NULL, *subject_tail = NULL;
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

int compare_duplication(char* ID)
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

int engdig(char* user)
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

void pw_cmp(char PW[])
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

User* search_ID(char *ID)
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
    if (subject_head != NULL)
    {
        subject_tail->next = (Subject*)malloc(sizeof(Subject));
        subject_tail = subject_tail->next;
    }
    else
    {
        subject_head = (Subject*)malloc(sizeof(Subject));
        subject_tail = subject_head;
    }

    subject_information(subject_tail);
    subject_tail->next = NULL;
}

void subject_information(Subject* subject)
{
    printf("\n=======================\n");

    printf("���� �̸� : ");
    scanf(" %[^\n]", subject->name);

    printf("������ ���� :");
    scanf("%d", &subject->credits);

    printf("������ ����� �л��� �й�: ");
    scanf(" %s", subject->num);
    
    printf("���� �Է�(A~Z): ");
    scanf(" %c", &subject->score);

    printf("\n=======================\n");
}

void print_score()
{
    for (Subject* p = subject_head; p != NULL; p = p->next)
    {
        printf("\n=======================\n");

        printf("\n�����: %s\n", p->name);
        printf("\n����: %d\n", p->credits);
        printf("\n�й�: %s\n", p->num);
        printf("\n����: %c\n", p->score);
        printf("\n=======================\n");
    }
}

void print_my_score(User* user)
{
    for (Subject* p = subject_head; p != NULL; p = p->next)
    {
        if (strcmp(user->num, p->num)==0) 
        {
            printf("\n=======================\n");

            printf("\n�����: %s\n", p->name);
            printf("\n����: %d\n", p->credits);
            printf("\n�й�: %s\n", p->num);
            printf("\n����: %c\n", p->score);
            printf("\n=======================\n");
        }
    }
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
    printf("(1)���� ���� ���, (2)�α׾ƿ�");
    printf("\n=> ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        print_my_score(user);
        break;
    case 2:
        printf("\n[�α׾ƿ� �Ǽ̽��ϴ�.]\n");
        system("cls");
        return;
    default:
        printf("\n[�߸��Է��ϼ̽��ϴ�.]\n");
        break;
    }
    window_student(user);
}