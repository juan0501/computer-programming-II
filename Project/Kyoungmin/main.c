#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User {
	char ID[20];
	char PW[20];
	char name[20];
	char Addr[50];
	char birth[10];
	int status;
	struct User *link;
} User;

typedef struct Order {
	char ID[20];
	int ordnum;
	int product;
	char size[20];
	int quantity;
	int price;
	int amount; 
	struct Order *link;
} Order;

int order_num;		//주문번호증가 
User *head1 = NULL;
User *join();
User *insert_first();
int duplicate(char *id);
User *loginID();
int loginPW(User *p);

Order *head2 = NULL;
void *order_list(User *p);
void print_order_list(User *m);
void payment();

void printUser();

User *search_pre_node(User *p);
User *delete_search_ID();
User *delete();

void search_ID();
void search_PW();
void ID_change();
void PW_change();
void menager_order_list();

void sortByID();

void select();
int select1(User *p);
int select1_1();
int select1_2();
int select2(User *p);
int select2_1();
int select3();

int main(void)
{
	select();
	return 0;
}

User *join()		//회원가입 함수 
{
	User *p = (User*)malloc(sizeof(User));
	char check_pw[20];
	printf("\n<회원가입>\n");
	while(1)
	{
		printf("\n아이디: ");
		scanf("%s", p->ID);
		if(duplicate(p->ID) == 1)
			break;
	}
	while(1)
	{
		printf("비밀번호: ");
		scanf("%s", p->PW);
		printf("비밀번호확인: ");
		scanf("%s", check_pw);
		if(strcmp(p->PW, check_pw) == 0)
		{
			printf(">>비밀번호가 확인되었습니다.\n");
			break;
		}
		else
			printf("\n>>비밀번호를 다시 입력해 주세요.\n\n");
	}
	
	printf("이름: ");
	scanf("%s", p->name);
	printf("생년월일(6자리): ");
	scanf("%s", p->birth);
	printf("주소: ");
	scanf("%s", p->Addr);
	printf("\n\n>>>>>회원가입 성공<<<<<");
	Sleep(2000);
	p->status = 2;
	
	p->link = head1;
	head1 = p;
	
	return head1;
}

User *insert_first()	//연결리스트의 맨 앞부분에 새로운 노드를 삽입하는 함수 
{
	User *p = (User*)malloc(sizeof(User));
	strcpy(p->ID, "mkm");
	strcpy(p->PW, "gloria");
	strcpy(p->name, "mkm");
	strcpy(p->birth, "020630");
	strcpy(p->Addr, "rkawjd");
	p->status = 1;
	
	p->link = head1; 
	head1 = p;
	
	return head1;
}

int duplicate(char *id)		//중복검사 함수 
{
	User *p;
	for(p = head1; p != NULL; p = p->link)
	{
		if(strcmp(id, p->ID) == 0)
		{
			printf("\n>>이미 존재하는 아이디입니다.\n");
			Sleep(1000);
			printf(">>아이디를 다시 입력해 주세요.\n");
			Sleep(2000);
			system("cls");
			printf("\n<회원가입>\n");
			return 0;
		}
	}
	return 1;
}

User *loginID()		//로그인id 
{
	char id[20];
	User *p; 
	printf("\n<로그인>\n");
	printf("아이디: ");
	scanf("%s", id);
	for(p = head1; p != NULL; p = p->link)
	{
		if(strcmp(id, p->ID) == 0)
			return p;
	}
//	return NULL;
}

int loginPW(User *p)		//로그인pw 
{
	char pw[20];
	
	if(p == NULL)
	{
		printf("\n>>존재하지 않는 아이디입니다.\n\n");
		Sleep(2000);
	}

	else
	{
		printf("비밀번호: ");
		scanf("%s", pw);
		if(strcmp(pw, p->PW) == 0)
		{
			printf("\n로그인 되었습니다.\n");
			Sleep(2000);
			system("cls");
			return 1;
		}
		else
		{
			printf("\n>>존재하지 않는 비밀번호입니다.\n");
			Sleep(2000);
			return 0;
		}
	}
}

void *order_list(User *p)		//주문받기 
{
	int num;
	order_num++;
	while(1)
	{
		system("cls");
		printf("\n<상품 주문>\n");
		printf("=>10,000원 이상 구매 시 배송비 무료\n");
		printf("\n1.티셔츠(1,000원) 2.바지(2,000원) 3.자켓(3,000원) 0.주문완료: ");
		scanf("%d", &num);
		if(num == 0)
		{
			system("cls");
			break;
		}
		else if(num == 1 || num == 2 || num == 3)
		{
			Order *ord = (Order*)malloc(sizeof(Order));	
			strcpy(ord->ID, p->ID);
			ord->ordnum = order_num;
			ord->product = num;	
			printf("사이즈(S,M,L): ");
			scanf("%s", ord->size);
			printf("상품 수량: ");
			scanf("%d", &ord->quantity);
			switch(ord->product)
			{
				case 1:
					ord->price = 1000;
					ord->amount = ord->price * ord->quantity;
					break;
				case 2:
					ord->price = 2000;
					ord->amount = ord->price * ord->quantity;
					break;
				case 3:
					ord->price = 3000;
					ord->amount = ord->price * ord->quantity;
					break;
			}
			ord->link = head2;
			head2 = ord;
		}
		else
			printf(">>존재하지 않는 상품입니다.\n");
	}
	
	Order *o;
	int amount;
	printf("\n<주문내역>");
	printf("\n========================================================================\n");
	printf("\n주문번호\t주문자ID\t 상품\t 사이즈\t 단가\t 수량\t 금액\n"); 
	for(o = head2; o != NULL; o = o->link) 
	{
		if((order_num == o->ordnum) && strcmp(p->ID, o->ID) == 0)
		{
			printf("   %d\t", o->ordnum);
			printf("\t %s\t\t", o->ID);
			switch(o->product)
			{
				case 1:
					printf("티셔츠\t");
					break;
				case 2:
					printf(" 바지\t");
					break;
				case 3:
					printf(" 자켓\t");
					break;
			}
			printf("  %s\t", o->size);
			printf(" %d\t", o->price); 
			printf("  %d\t", o->quantity);
			printf(" %d\n", o->amount);
			
			amount += o->amount;
		}
	}
	if(amount < 10000)
	{
		amount += 2500;
		printf("\n총 주문금액: %d(배송비 2,500원 포함)\n", amount);
	}
	else
		printf("\n총 주문금액: %d(배송비 무료)\n", amount);
	printf("\n========================================================================\n");
}

void print_order_list(User *m)		//주문내역출력 
{
	printf("\n");
	
	Order *p;
	int amount;
	printf("<주문내역>");
	printf("\n========================================================================\n");
	printf("\n주문번호\t주문자ID\t 상품\t 사이즈\t 단가\t 수량\t 금액\n"); 
	for(p = head2; p != NULL; p = p->link) 
	{
		if(strcmp(p->ID, m->ID) == 0)
		{
			printf("   %d\t", p->ordnum);
			printf("\t %s\t\t", p->ID);
			switch(p->product)
			{
				case 1:
					printf("티셔츠\t");
					break;
				case 2:
					printf(" 바지\t");
					break;
				case 3:
					printf(" 자켓\t");
					break;
			}
			printf("  %s\t", p->size);
			printf(" %d\t", p->price); 
			printf("  %d\t", p->quantity);
			printf(" %d\n", p->amount);
			
			amount += p->amount;
		}
	}
	if(amount < 10000)
	{
		amount += 2500;
		printf("\n총 주문금액: %d(배송비 2,500원 포함)\n", amount);
	}
	else
		printf("\n총 주문금액: %d(배송비 무료)\n", amount);
	printf("\n========================================================================\n");
}

void payment()		//입금 
{
	int bank;
	printf("\n<입금할 은행 선택>\n");
	printf("1.우리은행 2.국민은행 3.농협은행: ");
	scanf("%d", &bank);
	
	switch(bank)
	{
		case 1:
			printf("\n<무통장입금>\n입금은행: 우리은행(0000000)\n예금주: 목경민\n");
			break; 
		case 2:
			printf("\n<무통장입금>\n입금은행: 국민은행(1111111)\n예금주: 목경민\n");
			break;
		case 3:
			printf("\n<무통장입금>\n입금은행: 농협은행(2222222)\n예금주: 목경민\n");
			break;
		default:
			printf("\n>>존재하지 않는 은행입니다.\n");
			break;
	}
}

void printUser()	//회원정보출력 
{
	User *p;
	printf("\n<회원정보 출력>");
	printf("\n==============================\n");
	for(p = head1; p != NULL; p = p->link)
	{
		printf("\n아이디: %s\n", p->ID);
		printf("비밀번호: %s\n", p->PW);
		printf("이름: %s\n", p->name);
		printf("생년월일: %s\n", p->birth);
		printf("주소: %s\n", p->Addr);
		printf("\n==============================\n");
	}
}

User *search_pre_node(User *p)	//p노드의 이전 노드를 반환하는 함수
{
	User *pre;
	for(pre = head1; pre->link != p; pre = pre->link)
	{

	}
	return pre; 
}

User *delete_search_ID()	//회원찾기 
{
	char id[20];
	char pw[20];
	User *p;
	for(p = head1; p != NULL; p = p->link)
	{
		printf("\n정보를 삭제할 회원의 아이디 입력: ");
		scanf("%s", id);
		if(strcmp(id, p->ID) == 0)
		{
			printf("비밀번호 입력: ");
			scanf("%s", pw);
			if(strcmp(pw, p->PW) == 0)
				return p;
			else
			{
				printf("\n존재하지 않는 회원입니다.\n");
				Sleep(2000);
				system("cls");
				break;
			}
		}
		else
		{
			printf("\n존재하지 않는 회원입니다.\n");
			Sleep(2000);
			system("cls");
			break;
		}
	}
	return NULL;
}

User *delete(User *p)	//회원삭제 - p : 삭제하려는 노드 
{
	if(p == NULL)
		printf("\n아이디나 비밀번호를 다시 확인해 주세요.\n");
		 
	else if(p == head1)	//삭제하려는 노드가 맨 앞에 있는 경우 
	{
		head1 = p->link;		//헤드 포인터 변경 
		free(p);			//p가 가리키는 동적메모리 반환
		printf("\n회원정보가 삭제(탈퇴)되었습니다.\n");
	}
	
	else
	{
		User *pre = search_pre_node(p);		//pre : 삭제하려는 노드의 전 노드 
		pre->link = p->link; 	//pre의 링크필드가 p의 링크필드가 가리키는 곳을 가리킴
		free(p); 	//p가 가리키는 동적메모리 반환 
		printf("\n회원정보가 삭제(탈퇴)되었습니다.\n");
	}
	return head1;
}

void search_ID()		//id찾기 
{
	User *p;
	int i;
	char birth[10];
	char name[20];
	for(p = head1; p != NULL; p = p->link)
	{
		printf("\n회원이름입력: ");
		scanf("%s", name);
		if(strcmp(name, p->name) == 0)
		{
			printf("생년월일입력: ");
			scanf("%s", birth);
			if(strcmp(birth, p->birth) == 0)
			{
				system("cls");
				printf("\n%s님의 아이디는 ", p->name);
				for(i=0; i<strlen(p->ID)/2; i++)
					printf("%c", p->ID[i]);
				for(i=strlen(p->ID)/2; i<strlen(p->ID); i++)
					printf("*");
				printf("입니다.\n");
				break;
			}
			else
			{
				printf("\n존재하지 않는 회원입니다.\n");
				Sleep(3000);
				system("cls"); 
				break;
			}
				
		}
		else
		{
			printf("\n존재하지 않는 회원입니다.\n");
			Sleep(3000);
			system("cls"); 
			break;
		}
	}
}

void search_PW()		//pw찾기 
{
	User *p;
	int i;
	char birth[10];
	char id[20];
	char name[20];
	for(p = head1; p != NULL; p = p->link)
	{
		printf("\n아이디입력: ");
		scanf("%s", id);
		if(strcmp(id, p->ID) == 0)
		{
			printf("회원이름입력: ");
			scanf("%s", name);
			if(strcmp(name, p->name) == 0)
			{
				printf("생년월일입력: ");
				scanf("%s", birth);
				if(strcmp(birth, p->birth) == 0)
				{
					system("cls");
					printf("\n%s님의 비밀번호는 ", p->name);
					for(i=0; i<strlen(p->PW)/2; i++)
						printf("%c", p->PW[i]);
					for(i=strlen(p->PW)/2; i<strlen(p->PW); i++)
						printf("*");
					printf("입니다.\n");
					break;
				}
				else
				{
					printf("\n존재하지 않는 회원입니다.\n");
					Sleep(3000);
					system("cls"); 
					break;
				}	
					
			}
			else
			{
				printf("\n존재하지 않는 회원입니다.\n");
				Sleep(3000);
				system("cls"); 
				break;
			}	
		}
		else
		{
			printf("\n존재하지 않는 회원입니다.\n");
			Sleep(3000);
			system("cls"); 
			break;
		}	
	}
}

void ID_change()		//id바꾸기 
{
	User *p;
	char id[20];
	char pw[20];
	char change_id[20];
	for(p = head1; p != NULL; p = p->link)
	{
		printf("\n아이디입력: ");
		scanf("%s", id);
		if(strcmp(id, p->ID) == 0)
		{
			printf("비밀번호입력: ");
			scanf("%s", pw);
			if(strcmp(pw, p->PW) == 0)
			{
				system("cls");
				printf("\n변경할 아이디입력: ");
				scanf("%s", change_id);
				strcpy(p->ID, change_id);
				printf("\n%s님의 아이디가 %s로 변경되었습니다.\n", p->name, p->ID);
				Sleep(3000);
				system("cls"); 
				break;
			}
			else
			{
				printf("\n존재하지 않는 회원입니다.\n");
				Sleep(3000);
				system("cls"); 
				break;
			}	
		}
		else
		{
			printf("\n존재하지 않는 회원입니다.\n");
			Sleep(3000);
			system("cls"); 
			break;
		}	
	}
}

void PW_change()		//pw바꾸기 
{
	User *p;
	char id[20];
	char pw[20];
	char change_pw[20];
	for(p = head1; p != NULL; p = p->link)
	{
		printf("\n기존 아이디입력: ");
		scanf("%s", id);
		if(strcmp(id, p->ID) == 0)
		{
			printf("비밀번호입력: ");
			scanf("%s", pw);
			if(strcmp(pw, p->PW) == 0)
			{
				system("cls");
				printf("\n변경할 비밀번호입력: ");
				scanf("%s", change_pw);
				strcpy(p->PW, change_pw);
				printf("\n%s님의 비밀번호가 %s로 변경되었습니다.\n", p->name, p->PW);
				Sleep(3000);
				system("cls"); 
				break;
			}
			else
			{
				printf("\n존재하지 않는 회원입니다.\n");
				Sleep(3000);
				system("cls"); 
				break;
			}	
		}
		else
		{
			printf("\n존재하지 않는 회원입니다.\n");
			Sleep(3000);
			system("cls"); 
			break;
		}	
	}
}

void menager_order_list()		//주문내역 조회 
{
	Order *p;
	int amount;
	char id[20];
	printf("\n주문내역을 조회할 회원의 아이디를 입력하세요: ");
	scanf("%s", id);
	for(p = head2; p != NULL; p = p->link) 
	{
		if(strcmp(id, p->ID) != 0)
		{
			printf("\n존재하지 않는 회원입니다.\n");
			Sleep(3000);
			system("cls");
			break;
		}
		else
		{
			printf("\n<%s님의 주문내역>\n", id);
			printf("\n=================================================\n");
			printf("\n주문번호\t 상품\t 사이즈\t 단가\t 수량\n");
			for(p = head2; p != NULL; p = p->link) 
			{
				if(strcmp(id, p->ID) == 0)
				{ 
					printf("   %d\t", p->ordnum);
					switch(p->product)
					{
						case 1:
							printf("\t티셔츠\t");
							break;
						case 2:
							printf(" \t 바지\t");
							break;
						case 3:
							printf(" \t 자켓\t");
							break;
					}
					printf("  %s\t", p->size);
					printf(" %d\t", p->price); 
					printf("  %d\n", p->quantity);
					
					amount += p->amount;
				}
			}
			if(amount < 10000)
			{
				amount += 2500;
				printf("\n총 주문금액: %d(배송비 2,500원 포함)\n", amount);
			}
			else
				printf("\n총 주문금액: %d(배송비 무료)\n", amount);
			printf("\n=================================================\n");
			break;
		}
	}
}

void select()		//첫화면 
{
	int num;
	User *member; 
	head1 = insert_first();
	while(1)
	{	
		system("cls");
		printf("\n1.로그인 2.회원가입 3.아이디/비밀번호 찾기 0.종료: ");
		scanf("%d", &num);
		if(num == 1)		//로그인 
		{
			system("cls");
			member = loginID();
			if(loginPW(member) == 1)
			{
				if(member->status == 1)	//관리자 
				{
					//system("cls");
					while(1)
					{
						if(select1(member) == 1)
							break;
					}
				}
				else if(member->status == 2)	//사용자 
				{
					//system("cls");
					while(1)
					{
						if(select2(member) == 1)
							break;
					}
				}
			}
		}
			
			else if(num == 2)		//회원가입 
			{
				system("cls");
				head1 = join();
			}
			
			else if(num == 3)		//아이디,비밀번호 찾기 
			{
				select3();
			}
			
			else if(num == 0)		//종료 
			{
				system("cls");
				break;
			}
	}
}

int select1(User *p)		//관리자로 로그인한 뒤 나오는 화면 
{
	int num;
	while(1)
	{	
		printf("\n1.회원정보 2.아이디/비밀번호 변경 3.회원삭제 0.로그아웃: ");
		scanf("%d", &num);
		system("cls");
		while(1)
		{
			if(num == 1)	//회원정보 
			{
				if(select1_1(p) == 1)
					break;
			}
			else if(num == 2)	//아이디,비밀번호 변경 
			{
				if(select1_2(p) == 1)
					break;
			}
			else if(num == 3)	  //회원삭제 
			{
				system("cls");
				head1 = delete(delete_search_ID());
				Sleep(3000);
				select();
			}
			else if(num == 0)	//로그아웃 
			{
				system("cls");
				return 1;
			}
		}	
	}
}

int select1_1()		//회원정보 
{
	int num1;
	while(1)
	{
		printf("\n1.회원정보 보기 2.회원주문정보 보기 0.이전: ");
		scanf("%d", &num1);
		if(num1 == 1)	//회원정보 보기 
		{
			system("cls");
			printUser();
		}
		else if(num1 == 2)	//회원주문정보 보기 
		{
			system("cls");
			menager_order_list();
		}
		else if(num1 == 0)	//이전 
		{
			system("cls");
			return 1;
		}
	}
}

int select1_2()	//아이디,비밀번호 변경 
{
	int num1;
	while(1)
	{
		printf("\n1.아이디 변경 2.비밀번호 변경 0.이전: ");
		scanf("%d", &num1);		
		if(num1 == 1)		//아이디 변경 
		{
			system("cls");
			ID_change(head1);
		}
		else if(num1 == 2)	//비밀번호 변경 
		{
			system("cls");
			PW_change(head1);
		}
		else if(num1 == 0)	//이전 
		{
			system("cls");
			return 1;
		}
	}
}

int select2(User *p)	//사용자로 로그인한 뒤 나오는 화면 
{
	int num;
	while(1)
	{
		printf("\n1.상품주문 2.회원정보수정/탈퇴 3.주문내역조회 0.로그아웃: ");
		scanf("%d", &num);
		while(1)
		{
			if(num == 1)	//상품주문 
			{
				system("cls");
				order_list(p);
				payment();
				Sleep(3000);
				system("cls");
				break;
			}
			else if(num == 2) 	//회원정보수정,탈퇴 
			{
				if(select2_1(p) == 1)
					break;
			}
			else if(num == 3)	//주문내역조회 
			{
				system("cls");
				print_order_list(p);
				break;
			}
			else if(num == 0)	//로그아웃 
			{
				system("cls");
				return 1;
			}
		}
	}
}

int select2_1()		//회원정보 수정,탈퇴 
{
	int num1;
	User *p;
	system("cls");
	while(1)
	{
		printf("\n1.아이디변경 2.비밀번호변경 3.회원탈퇴 0.이전: ");
		scanf("%d", &num1);
		if(num1 == 1)	//아이디변경
		{
			system("cls");
			ID_change();
			Sleep(3000); 
			select();
		}
		else if(num1 == 2)	 //비밀번호변경
		{
			system("cls");
			PW_change();
			Sleep(3000);
			select();
		}
		else if(num1 == 3)  	//회원탈퇴 
		{
			system("cls");
			head1 = delete(delete_search_ID());
			Sleep(3000);
			select();
		}
		else if(num1 == 0)		//이전 
		{
			system("cls");
			return 1;
		}
	}
}

int select3()		//아이디,비밀번호 찾기 
{
	int num;
	system("cls");
	while(1)
	{
		printf("\n1.아이디 찾기 2.비밀번호 찾기 0.이전: ");
		scanf("%d", &num);
		if(num == 1)	//아이디찾기 
		{
			system("cls");
			search_ID();
		}
		else if(num == 2)	//비밀번호찾기 
		{
			system("cls");
			search_PW();
		}
		else if(num == 0)	//이전 
		{
			system("cls");
			break;
		}
	}
}
