//1000까지의 소수를 출력하고 몇 개인지 출력하기 (2 ~ 1000 중에서 소수가 되는 수를 판별하여 출력)

#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) return false; // 1 이하의 숫자는 소수가 아님
    if (num == 2) return true;  // 2는 소수
    if (num % 2 == 0) return false; // 짝수는 소수가 아님

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false; // 나누어 떨어지면 소수가 아님
    }

    return true; // 위 조건에 걸리지 않으면 소수
}

int main() {

    int lower = 2;
    int upper = 1000;
    int prime_count = 0;

    printf("%d와 %d 사이의 소수:\n", lower, upper);
    for (int i = lower; i <= upper; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            prime_count++;
        }
    }
    printf("\n2부터 1000사이의 소수의 갯수: %d\n", prime_count);

    return 0;
}