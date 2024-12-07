//클로버, 하트, 스페이드, 다이아몬드 4가지 무늬와 1~13까지의 숫자를 가진 52장의 플레잉 카드 중 한 벌(7장)을 랜덤하게 출력
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CNT 52

int main() {
    int check[CNT + 1] = { 0 }; //중복 체크용
    int card_order[CNT] = { 0 }; //생성된 랜덤 숫자
    int rand_max = 52;
    int rand_min = 1;
    
    srand(time(0));
    
    for(int i =0; i < 7; i++){
        int x;
        do {
            x = (double)rand() / ((unsigned)RAND_MAX+1) * (rand_max - rand_min + 1) + rand_min;
        } while (check[x] == 1);
        check[x] = 1;
        card_order[i] = x;
    }

        for(int i = 0; i < 7; i++){
        int x = card_order[i];
        
        if(x >= 1 && x <= 13){
            printf("C%2d ", x);
        } else if(x >= 14 && x <= 26){
            printf("H%2d ", x - 13);
        } else if(x >= 27 && x <= 39){
            printf("S%2d ", x - 26);
        } else if(x >= 40 && x <= 52){
            printf("D%2d ", x - 39);
        }
    }
    
    for(int i = 0; i < 7; i++){
    printf("%3d ", card_order[i]);
    printf("\n");
    
    }
}