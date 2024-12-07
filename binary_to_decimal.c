//2진수를 10진수로 변환하기 (bit 연산을 활용)

#include <stdio.h>

int main() {
    int binary[5] = { 1, 0, 1, 1, 0 };
    int decimal = 0;
    int position = 0;

    for (int i = sizeof(binary) / sizeof(int) - 1; i >= 0; i--)
        {
            if(binary[i] == 1){
                decimal += 1 << position;
            }
            position++;
        }
    printf("%d", decimal);


    /*int len = sizeof(binary) / sizeof(int);

    for(int i = len - 1; i >= 0; i--){
        decimal += binary[i] * (1 << (len - i - 1));
    }
    printf("\n%d", decimal);*/
}