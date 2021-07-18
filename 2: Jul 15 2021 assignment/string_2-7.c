#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char * argv[]) {

    char print[4][25] = {"도시", "구", "동", "나머지 상세주소"};
    char str[50], addr[100];
    int idx = 0;
    
    /* Only for English */
    for(int i = 0; i < 4; i ++)
    {
        printf("%s: ", print[i]);
        scanf(" %[^\n]", str);
        strcat(addr, str); //붙여넣기
        idx = strlen(addr);
        addr[idx++] = ' '; //공백 넣기
        addr[idx] = '\0'; //문자열의 끝은 항상 \0
    }

    printf("*주소\n");
    printf("%s\n", addr);
    
    return 0;
}
