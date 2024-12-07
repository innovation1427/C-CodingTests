//문자열의 복사와 문자열의 연결

#include <stdio.h>
#include <string.h>

char * my_strcpy(char *s1, char *s2){
    while(*s2){
        *s1++ = *s2++;      // s2의 값을 s1에 복사한 뒤, s1과 s2 모두 증가
    }
    *s1 = '\0';             // 문자열 끝에 널 문자를 추가
    return s1;
}

char * my_strcat(char *s1, char *s2){
    while(*s1){
        s1++;
    }
    while(*s2){
        *s1++ = *s2++;
    }
    *s1 = '\0';             // 문자열 끝에 널 문자를 추가
    return s1;
}

int main() {
    char s[100] = "Hello World!";
    char t[] = "hello world!";
    char u[] = "C programming language!";

    my_strcpy(s, t);
    printf("my_strcpy() : %s->%s\n", s, t);
    my_strcat(s, u);
    printf("my_strcat() : %s\n", s);



    
}