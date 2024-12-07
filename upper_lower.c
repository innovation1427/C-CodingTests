//대문자와 소문자의 변환

#include <stdio.h>
#include <string.h>

/*소문자가 더 크다('a' - 'A' = 32)*/

char* to_lower(char *str){
    char * s = str;
    while(*s){
        if(*s >= 'A' && *s <= 'Z'){
            *s += 32;     //소문자로 변환
        }
        s++;
    }
    return str;
}
char* to_upper(char *str){
    char * s = str;
    while(*s){
        if(*s >= 'a' && *s <= 'z'){
            *s -= 32;     //소문자로 변환
        }
        s++;
    }
    return str;
}


int main() {
    char s[] = "Hello world!";

    printf("to_upper() : %s\n", to_upper(s));
    printf("to_lower() : %s\n", to_lower(s));
}