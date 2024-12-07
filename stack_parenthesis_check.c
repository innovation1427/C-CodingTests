//스택을 활용한 괄호 검사

#include <stdio.h>
#include <string.h>
#define MAXVAL 100

char stack[MAXVAL];
int sp = 0;
void push(char v){
    if(sp < MAXVAL){
        stack[sp++] = v;
    } else {
        printf("stack full");
    }
}

char pop(){
    if(sp > 0){
        return stack[--sp];
    } else {
        printf("error: stack empty\n");
        return 0;
    }
}

void printStack(){
    printf("Stack : ");
    for (int i = 0; i < sp; i++){
        printf("%c ", stack[i]);
    }
    printf("\n");
}

int main() {
    char stmt[100];
    char r;
    int i = 0;

    strcpy(stmt, "((([(())])))");

    while (stmt[i] != '\0') {  // NULL을 '\0'으로 수정
        switch(stmt[i]) {
            case '(' : case '[' : case '{' :
                push(stmt[i]);
                break;
            case ')' : case ']' : case '}' :

                if(sp == 0) {    //stack empty
                    printf("error-짝이 안맞습니다.");
                    return 0;
                } else {
                    r = pop();
                    //짝이 맞는지 검사
                    if( (r == '(' && stmt[i] != ')') ||
                        (r == '[' && stmt[i] != ']') ||
                        (r == '{' && stmt[i] != '}')) {
                            printf("짝이 맞지 않습니다.");
                            return 0;
                        }
                }
                break;
                }
        i++;
        }
    if (sp > 0) {
        printf("괄호 짝이 안맞습니다\n");
    } else {
        printf("괄호 짝이 맞습니다\n");
    }
}