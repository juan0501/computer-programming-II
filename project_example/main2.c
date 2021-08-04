#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Subject // 수강 과목
{
    char name[20]; // 제목
    char num[20];  // 학번
    int credits;   // 학점
    char score;    // 점수( A, B, ... )
    int check;
} Subject;

typedef struct User
{
    int value; // 0 : 교수님, 1 : 학생
    char ID[20];
    char PW[20];
    char name[20];
    char num[20];  // 학번
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
    printf("\n로그인(1) 회원가입(2) : ");
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
        printf("\n[잘못 눌렀습니다.]\n");
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
        printf("ID 입력: ");
        scanf(" %s", ID);

        if (compare_duplication(ID) == 0 || IDPW_length(ID) == 0 || engdig(ID) == 0)
            continue;

        else
            break;
    }

    strcpy(user->ID, ID);
    pw_cmp(user->PW);

    printf("이름: ");
    scanf(" %s", user->name);

    printf("나이: ");
    scanf("%d", &user->age);

    do
    {
        printf("(0)교수님 , (1)학생 : ");
        scanf("%d", &user->value);
    } while (user->value != 0 && user->value != 1); //다른 번호를 입력하는 경우

    if (user->value == 1)
    {
        printf("학번 입력: ");
        scanf("%d", user->num);
    }

    printf("\n=======================\n");
}

int compare_duplication(char* ID)  // 아이디 중복 확인
{
    if (user_head == NULL || user_head == user_tail) //node가 없는 경우
        return 1;
    else
    {
        for (User* p = user_head; p != user_tail; p = p->next)
            if (strcmp(p->ID, ID) == 0)
            {
                printf("\n[중복되었습니다.]\n");
                return 0;
            }
    }
    return 1;
}

//ID,PW 길이제한
int IDPW_length(char* user)
{
    int length = strlen(user);
    int cnt = 0;

    if (length > 10)  // 아이디가 10글자 이상인 경우
    {
        printf("\n[10글자 이하로 다시입력하세요.]\n");

        return 0;
    }

    return 1;
}

int engdig(char* user)  // 영문자, 숫자로만 아이디, 비밀번호 입력
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

    printf("\n[ID/PW는 영문자와 숫자로만 이루어져야 합니다.]\n");
    return 0;
}

void pw_cmp(char PW[])  // 비밀번호 확인
{
    char cmpPW[20];

    while (1)
    {
        printf("PW 입력: ");
        scanf(" %s", user_tail->PW);

        if (compare_duplication(user_tail->PW) == 0 || IDPW_length(user_tail->PW) == 0 || engdig(user_tail->PW) == 0)
            continue;

        else
            break;
    }

    while (1)
    {
        printf("패스워드 확인: ");
        scanf(" %s", cmpPW);
        if (strcmp(PW, cmpPW) == 0)
            break;
        else
            printf("PW가 일치하지 않습니다.\n");
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
            printf("\n[로그인 되었습니다.]\n");
            if (p->value == 0) //교수님인 경우
                window_professor(p);
            else //학생인 경우
                window_student(p);
        }
        else
        {
            printf("\n[비밀번호가 틀렸습니다.]\n");
            window_1(); //초기화면으로 이동
        }
    }
    else
    {
        printf("\n[아이디가 존재하지 않습니다.]\n");
        window_1(); //초기화면으로 이동
    }
}

User* search_ID(char* ID)  // 등록된 아이디인지 확인
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

    printf("성적을 입력할 학생의 학번을 입력하세요: ");
    scanf(" %s", temp);

    for (User* p = user_head; p != NULL; p = p->next)
    {
        if (strcmp(p->num, temp) == 0)  // 원하는 학생의 학번과 동일하면 성적 입력 가능
        {
            printf("\n=======================\n");
            printf("\n과목명: %s\n", p->sub.name);
            printf("\n학점: %d\n", p->sub.credits);
            printf("\n학번: %s\n", p->sub.num);
            printf("\n점수 입력:");
            printf("%c", p->sub.score);
            printf("\n=======================\n");
            p->sub.check = 1;  // 성적이 입력되었음을 의미
        }
    }
}

void print_score()
{
    for (User* p = user_head; p != NULL; p = p->next)
    {
        if (p->sub.check == 1)  // 성적이 입력된 학생의 수강과목 정보 확인
        {
            printf("\n=======================\n");
            printf("\n과목명: %s\n", p->sub.name);
            printf("\n학점: %d\n", p->sub.credits);
            printf("\n학번: %s\n", p->sub.num);
            printf("\n점수: %c\n", p->sub.score);
            printf("\n=======================\n");
        }
    }
}

void insert_subject(User *user)  // 학생이 수강할 과목 하나 저장
{
    printf("\n=======================\n");

    printf("학번: ");
    scanf(" %s", user->sub.num);

    printf("과목 이름 : ");
    scanf(" %[^\n]", user->sub.name);

    printf("과목의 학점 :");
    scanf("%d", &user->sub.credits);

    user->sub.check = 0;  // 성적이 아직 입력되기 전임을 의미

    printf("\n=======================\n");
}

void print_subject(User *user)
{
    printf("\n=======================\n");
    printf("수강 과목명 : %s\n", user->sub.name);
    printf("학점 : %d", user->sub.credits);
    if (user->sub.check == 1)  // 성적 입력 되었을 경우 점수도 출력
        printf("점수 : %c", user->sub.score);
    printf("\n=======================\n");
}

void window_professor(User* user)
{
    int menu;
    printf("(1)학생 성적 등록 (2)학생 성적 정보 출력, (2)로그아웃");
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
        printf("\n[로그아웃 되셨습니다.]\n");
        system("cls");
        return;
    default:
        printf("\n[잘못입력하셨습니다.]\n");
        break;
    }
    window_professor(user);
}

// activity 3 //
void window_student(User* user)
{
    int menu;
    printf("(1) 수강 과목 등록 (2)성적 정보 출력, (3)로그아웃");
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
        printf("\n[로그아웃 되셨습니다.]\n");
        system("cls");
        return;
    default:
        printf("\n[잘못입력하셨습니다.]\n");
        break;
    }
    window_student(user);
}