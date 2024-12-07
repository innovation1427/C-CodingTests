//스택을 이용한 reverse polish(후위 표현식) 계산기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
#define NUMBER '0'

float stack[MAX];
int sp = 0;

// "3 4 + 5 *" \n

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getchar()) == ' ' || c == '\t');  // 공백, 탭 지우기
    s[1] = '\0';
    if (c == 'q')  // q를 입력하면 종료
        return 'q';
    if (!isdigit(c) && c != '.')  // 문자가 숫자가 아니면 (연산자)
        return c;

    i = 0;
    if (isdigit(c) || c == '.') {  // 숫자나 소수점 처리
        while (isdigit(s[++i] = c = getchar()));
        if (c == '.') {
            while (isdigit(s[++i] = c = getchar()));
        }
        s[i] = '\0';
        if (c != EOF) {
            ungetc(c, stdin);
        }
        return NUMBER;
    }

    return c;  // 연산자 반환
}

void push(float f) {
    if (sp < MAX) {
        stack[sp++] = f;
    }
    else {
        printf("stack full\n");
    }
}

float pop() {
    if (sp > 0) {
        return stack[--sp];
    }
    else {
        printf("error: stack empty\n");
        return 0;
    }
}

int main() {
    int type;
    char s[MAX];

    while (1) {
        printf("계산할 식을 후위 표기식으로 입력하십시오 (종료하려면 q 입력) : ");

        while ((type = getop(s)) != '\n' && type != EOF) {
            if (type == 'q') {
                printf("프로그램을 종료합니다.\n");
                return 0;
            }

            switch (type) {
            case NUMBER:
                push(atof(s));
                break;

            case '+':
                push(pop() + pop());
                break;

            case '-': {
                float op2 = pop();
                push(pop() - op2);
                break;
            }

            case '*':
                push(pop() * pop());
                break;

            case '/': {
                float op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            }

            default:
                printf("Unknown command %s\n", s);
                break;
            }
        }

        if (sp > 0) {
            printf("결과: %.8g\n", pop());
        }

        // 스택을 비웁니다.
        sp = 0;

        if (type == EOF) {
            break;
        }
    }

    return 0;
}
