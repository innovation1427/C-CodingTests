//10진수를 16진수로 변환하기(sprintf()를 사용하지 않고, 10진수 정수를 입력받아 16진수 '문자열'로 출력)

#include <stdio.h>

int main() {
    int decimal = 300;
    char hexadecimal[20] = { 0, };
    int position = 0;

    while(1){
        int mod = decimal % 16;    //나머지지
        decimal = decimal /16;     //몫

        //나머지 정수를 문자로 변환(0~9, A~F)하여 변수 배열 hexadecimal[]에 저장
        if(mod < 10) {
            hexadecimal[position] = mod + '0';
        } else {
            hexadecimal[position] = (mod - 10) + 'A';
        }
        position++;


        if (decimal == 0){
            break;
        }
    }
    for (int i = position - 1; i >= 0; i--) {
        printf("%c", hexadecimal[i]);
    }
    printf("\n");
    return 0;

}