//문자열 압축(연속된 문자 몇 번 나왔는지 압축)

#include <stdio.h>
#include <string.h>

int main() {
    int count = 0;
    char s[1000] = "AAABBBBCCCC";

    for(int i = 0; i < strlen(s); i++){
        count++;
        if(s[i] != s[i+1]) {
            if(count == 1) {
                printf("%c", s[i]);
            } else {
                printf("%d%c", count, s[i]);
            }
            count = 0;
        }
    }
    return 0;
}