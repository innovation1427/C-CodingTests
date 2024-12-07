//두 수의 차

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
    return num1 - num2;
}

int main() {
    int num1[] = {2, 100};
    int num2[] = {3, 2};
    int results[2];
    int num_cases = 2;

    for (int i = 0; i < num_cases; i++) {
        results[i] = solution(num1[i], num2[i]);
    }

    printf("num1\tnum2\tresult\n");
    for (int i = 0; i < num_cases; i++) {
        printf("%d\t%d\t%d\n", num1[i], num2[i], results[i]);
    }

    return 0;
}