//압축한 문자열 복구

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int count = 0;
    char s[1000] = "A12BC";

    int cnt = 0;
    while(1) {
        if(!isdigit(s[cnt])) {
            if(count == 0) {
                count++;
            }
            for(int i = 0; i < count; i++) {
                printf("%c", s[cnt]);
            }
            count = 0;
        } else {
            count = count * 10 + (s[cnt] - '0');
        }
        if(cnt++ >= strlen(s)){
            break;
        }
    }
    return 0;
}