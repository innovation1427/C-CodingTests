//문자열 안에서 다른 문자열 찾기

#include <stdio.h>
#include <string.h>

//함수 쓰는 이유: 협업가능, 재사용가능, 복잡한 코드 단순화 가능 c언어는 포인트와 함수의 활용이 중요
int is_equal(char *str, char *sub){
    while(*sub){
        if(*str++ != *sub++)
            return 0;
    }
    return 1;
}

char* my_strstr(char *str, char *sub){
    while(*str){
        if(is_equal(str, sub)) 
            return str;
            str++;
    }
    return(char *)0;
}

int main() {
    char *str = "Hello student!";
    char *substr = "student";
    char *ret;

    ret = my_strstr(str, substr);
    printf("부분 문자열 '%s'은 '%s'의 %d번째 문자부터\n", substr, str, (int)(ret-str));

    return 0;
}