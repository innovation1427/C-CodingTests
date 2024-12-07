//1에서 10까지 겹치지 않는 랜덤 숫자 만들기
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CNT 10

int main() {
    int check[CNT + 1] = { 0 }; //중복 체크용
    int rand_order[CNT] = { 0 }; //생성된 랜덤 숫자
    int rand_max = 10;
    int rand_min = 1;
    
    srand(time(0));
    
    for(int i =0; i < CNT; i++){
        int x;
        do {
            x = (double)rand() / ((unsigned)RAND_MAX+1) * (rand_max - rand_min + 1) + rand_min;
        } while (check[x] == 1);
        check[x] = 1;
        rand_order[i] = x;
    }
    for(int i = 0; i < CNT; i++){
    printf("%3d ", rand_order[i]);
    printf("\n");
    
    }
}