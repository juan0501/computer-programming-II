#include <stdio.h>
#include <string.h>
#include <iostream>
#include <ctype.h>
using namespace std;

int getWord(char str[])
{
	char* token = strtok(str, " ");
	int cnt = 0;

	while (token != NULL)
	{
		cnt += 1;
		token = strtok(NULL, " ");
	}
	return cnt;
}

int main()
{
	char string[1000005];
	cin.getline(string, 1000005);

	cout << getWord(string);

	return 0;
}
