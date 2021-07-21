#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 111
int main()
{
	int N;
	char S[SIZE];
	scanf("%d", &N);
	scanf("%s", S);
	
	int a_list[26][1];
	for(int i = 0; i < 26; i++)
		a_list[i][0] = -1;
	
	for(int i = 0; i < strlen(S); i++)
	{
		if(a_list[S[i] - 'a'][0] > -1)
			continue;
		a_list[S[i] - 'a'][0] = i;
	}
	for(int i = 0; i < 26; i++)
		printf("%d ", a_list[i][0]);

	return 0;
}
