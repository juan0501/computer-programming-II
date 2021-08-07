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

ListNode* insert_first()  // ���Ḯ��Ʈ�� �� �պκп� ���ο� ��带 �����ϴ� �Լ�
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // ���ο� ��� p ����

	printf("\n<�л� ���� �Է�>\n");
	printf("�̸� : ");
	scanf(" %s", p->name);
	printf("���� : ");
	scanf("%d", &p->age);

	p->link = head;   // p�� ��ũ�ʵ尡 head�� ����Ű�� ���� ����Ŵ
	head = p;         // ��� ������ ����

	return head;   
}

ListNode* search_pre_node(ListNode* p) // p����� ���� ��带 ��ȯ�ϴ� �Լ�
{
	ListNode* pre;
	for (pre = head; pre->link != p; pre = pre->link) // pre�� ��ũ�ʵ尡 p�� ����ų ������ �ݺ�
	{

	}
	return pre;
}

ListNode* search_name()
{
	char temp[20];

	printf("\n������ ������ �л��̸� �Է� : ");
	scanf(" %s", temp);

	for (ListNode* p = head; p != NULL; p = p->link)  // head���� ���Ḯ��Ʈ�� ������(NULL) Ž��
	{
		if (strcmp(temp, p->name) == 0)  // ������ �Է��� ���� ��忡 ����� �̸��� ���� ���
			return p;                    // �ش� ��� p�� ��ȯ
	}

	return NULL;  // ã������ ��尡 ���� ��� NULL��ȯ
}

ListNode* delete(ListNode* p)  // p : �����Ϸ��� ���
{
	if (p == NULL)
		printf("\n[�����Ϸ��� �л��� ��ϵǾ� ���� �ʽ��ϴ�.]\n");

	else if (p == head)  // �����Ϸ��� ��尡 �� �տ� �ִ� ���
	{
		head = p->link;  // ��� ������ ����
		free(p);         // p�� ����Ű�� �����޸� ��ȯ
	}

	else 
	{
		ListNode* pre = search_pre_node(p);  // pre : �����Ϸ��� ����� �� ��� 
		pre->link = p->link;  // pre�� ��ũ�ʵ尡 p�� ��ũ�ʵ尡 ����Ű�� ���� ����Ŵ
		free(p);        // p�� ����Ű�� �����޸� ��ȯ
	}

	return head;
}

void print_list()
{
	printf("\n");

	for (ListNode* p = head; p != NULL; p = p->link) {  // ���Ḯ��Ʈ ��ü ���
		printf("(%s, %d) -> ", p->name, p->age);
	}

	printf("NULL \n");
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		head = insert_first();  // ����
		print_list();           // ���
	}

	for (int i = 0; i < 5; i++)
	{
		head = delete(search_name());  // ����
		print_list();
	}

	return 0;
}

