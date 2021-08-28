#include <stdio.h>

int main(int argc, char *argv[]) {
	int arr[]={100,200,300};
	int *p =NULL;
	p = arr;
	
	//printf("주소 값은 %p\t 데이터 값은 %d\n",p+1,*p+1);
	//printf("주소 값은 %p\t 데이터 값은 %d\n",(p+1),*(p+1));
	printf("주소 값은 %p\t 데이터 값은 %d\n",p++,*p++);
	//printf("주소 값은 %p\t 데이터 값은 %d\n",(p)++,(*p)++);
	//printf("주소 값은 %p\t 데이터 값은 %d\n",++p,*++p);
	//printf("주소 값은 %p\t 데이터 값은 %d\n",++p,++*p);
	return 0;
}
