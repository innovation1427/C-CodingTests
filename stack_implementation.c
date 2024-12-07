//스택의 구현 (push(), pop(), printStack() 함수 구현)

#include <stdio.h>
#define MAXVAL 100
int stack[MAXVAL];
int sp = 0;

void push(int v) {
    if(sp < MAXVAL){
        stack[sp++] = v;
    } else {
        printf("stack full");
    }
}

int pop() {
    if(sp > 0) {
        //sp = sp - 1;
        //return (stack[sp]);
        
        return stack[--sp];    /*위에 두 줄과 똑같음*/
    } else {
        printf("error: stack empty\n");
        return 0;
    }
}

void printStack() {
    printf("Stack : ");
    for (int i = 0; i < sp; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int v;
    char c;
    while(1){
        printf("Operation : i(insert), d(delete), q(quit) :");
        scanf("%c", &c);
        switch(c){
            case 'i' :
                printf("Enter a number : ");
                scanf("%d", &v);
                push(v);
                break;
            case 'd' :
                printf("%d removed\n", pop());
                break;
            case 'q' :
                return 0;
        }
        printStack();
    }
}