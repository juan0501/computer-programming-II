#include <stdio.h>

int main(int argc, char *argv[]) {
	int arr[]={100,200,300};
	int *p =NULL;
	p = arr;
	
	//printf("�ּ� ���� %p\t ������ ���� %d\n",p+1,*p+1);
	//printf("�ּ� ���� %p\t ������ ���� %d\n",(p+1),*(p+1));
	printf("�ּ� ���� %p\t ������ ���� %d\n",p++,*p++);
	//printf("�ּ� ���� %p\t ������ ���� %d\n",(p)++,(*p)++);
	//printf("�ּ� ���� %p\t ������ ���� %d\n",++p,*++p);
	//printf("�ּ� ���� %p\t ������ ���� %d\n",++p,++*p);
	return 0;
}
