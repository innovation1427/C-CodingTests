//최대공약수와 최소공배수 (유클리드 호제법 사용 while문 사용)

#include <stdio.h>
#include <string.h>

int gcd(int min, int max){
    int remainder = 1;
    while (remainder != 0) {
        remainder = max % min;
        max = min;
        min = remainder;
    }
    return max;
}

int lcm(int min, int max){
    return min * max / gcd(min, max);
}

int main() {
    int a, b, min, max;
    a = 60;
    b = 24;

    if(a>b) {
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }
    printf("gcd = %d\n lcm = %d", gcd(min, max), lcm(min, max));
}