//문자열의 길이와 문자열의 비교 함수의 구현 (strlen(), strcmp() 구현)

#include <stdio.h>
#include <string.h>


int my_strlen(char *str){
    int cnt = 0;
    while(*str){
        cnt++;
        str++;
    }
    return cnt;
}

int my_strcmp(char *s1, char *s2){
    while(*s1 != 0 || *s2 != 0){
        if(*s1 != *s2) break;
        s1++;
        s2++;
    }
    if(*s1>*s2){
        return 1;
    } else if(*s1<*s2){
        return -1;
    } else {
        return 0;
    }

}

int main() {
    char s[] = "Hello World!";
    char t[] = "hello world!";
    
    printf("%d ", (int)strlen(s));
    printf("%d \n", my_strlen(s));
    printf("%d ", strcmp(s,t));
    printf("%d ", my_strcmp(s,t));
    return 0;
}