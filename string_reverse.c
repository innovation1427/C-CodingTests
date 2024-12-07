//문자열 뒤집기 (반대로 ex) abc -> cba)

#include <stdio.h>
#include <string.h>

char * my_reverse(char *str){
    char *s = str;
    char *e = str + strlen(str) - 1;
    char temp;
    
    while(e > s){
        temp = *s;
        *s = *e;
        *e = temp;

        s++;
        e--;
    }
    return str;
}

int main() {
    char s[] = "Hello World!";

    printf("%s \n", s);
    //printf("_strrev() : %s\n", _strrev(s));
    printf("my_reverse() : %s\n", my_reverse(s));
    return 0;
}