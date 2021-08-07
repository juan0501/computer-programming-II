#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	char name[20];
	int age;
	struct  ListNode* link;
} ListNode;

ListNode* head = NULL;
ListNode* insert_first();
ListNode* search_pre_node(ListNode* p);
ListNode* search_name();
ListNode* delete();

ListNode* insert_first()  // 연결리스트의 맨 앞부분에 새로운 노드를 삽입하는 함수
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // 새로운 노드 p 생성

	printf("\n<학생 정보 입력>\n");
	printf("이름 : ");
	scanf(" %s", p->name);
	printf("나이 : ");
	scanf("%d", &p->age);

	p->link = head;   // p의 링크필드가 head가 가리키던 곳을 가리킴
	head = p;         // 헤드 포인터 변경

	return head;   
}

ListNode* search_pre_node(ListNode* p) // p노드의 이전 노드를 반환하는 함수
{
	ListNode* pre;
	for (pre = head; pre->link != p; pre = pre->link) // pre의 링크필드가 p를 가리킬 때까지 반복
	{

	}
	return pre;
}

ListNode* search_name()
{
	char temp[20];

	printf("\n정보를 삭제할 학생이름 입력 : ");
	scanf(" %s", temp);

	for (ListNode* p = head; p != NULL; p = p->link)  // head부터 연결리스트의 끝까지(NULL) 탐색
	{
		if (strcmp(temp, p->name) == 0)  // 위에서 입력한 값과 노드에 저장된 이름이 같은 경우
			return p;                    // 해당 노드 p를 반환
	}

	return NULL;  // 찾으려는 노드가 없는 경우 NULL반환
}

ListNode* delete(ListNode* p)  // p : 삭제하려는 노드
{
	if (p == NULL)
		printf("\n[삭제하려는 학생이 등록되어 있지 않습니다.]\n");

	else if (p == head)  // 삭제하려는 노드가 맨 앞에 있는 경우
	{
		head = p->link;  // 헤드 포인터 변경
		free(p);         // p가 가리키는 동적메모리 반환
	}

	else 
	{
		ListNode* pre = search_pre_node(p);  // pre : 삭제하려는 노드의 전 노드 
		pre->link = p->link;  // pre의 링크필드가 p의 링크필드가 가리키는 곳을 가리킴
		free(p);        // p가 가리키는 동적메모리 반환
	}

	return head;
}

void print_list()
{
	printf("\n");

	for (ListNode* p = head; p != NULL; p = p->link) {  // 연결리스트 전체 출력
		printf("(%s, %d) -> ", p->name, p->age);
	}

	printf("NULL \n");
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		head = insert_first();  // 삽입
		print_list();           // 출력
	}

	for (int i = 0; i < 5; i++)
	{
		head = delete(search_name());  // 삭제
		print_list();
	}

	return 0;
}

