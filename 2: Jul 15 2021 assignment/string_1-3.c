#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*문제 유형 입력으로 변경한 코드*/
int main()
{
	char string[100];
	printf("저장될 문자열: "); scanf("%s", string);
	int start, end;
	printf("시작위치, 마지막위치: "); scanf("%d%d", &start, &end);

	for(int i = start-1; i < end; i++)
		printf("%c", string[i]);
	printf("\n");

	return 0;
}
