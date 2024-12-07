//함수 포인터의 배열을 사용한 계산기 (덧셈, 뺄셈, 곱셈, 나눗셈)

#include <stdio.h>

float add(float a, float b){
    return a + b;
}

float subtract(float a, float b){
    return a - b;
}

float multifly(float a, float b){
    return a * b;
}

float divide(float a, float b){
    return a / b;
}


int main() {
    float a, b;

    int choice;

    float(*funcptr[4])(float, float) = {add, subtract, multifly, divide};

    // funcptr[0] = add;
    // funcptr[1] = subtract;
    // funcptr[2] = multifly;
    // funcptr[3] = divide;

    printf("Enter two number : \n");
    scanf("%f %f", &a, &b);

    printf("Enter Choice[ 0:add, 1:subtract, 2:multifly, 3:divide 4:all] \n");
    scanf("%d", &choice);

    if (choice == 4) {
        int funcs_len = sizeof(funcptr) / sizeof(float*);

        for (int i = 0; i < funcs_len; i++) {
            printf("result = %f\n", (funcptr[i])(a, b));
        }
    } else {
        printf("result = %f\n", funcptr[choice](a,b));
    }
}