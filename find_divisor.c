//약수 구하기 (자연수 N과 K, N의 약수 중 K 번째로 작은 수 출력)

#include <stdio.h>
#include <string.h>

int arr[10000];
int count = 0;

void get_divisor(int N){
    for (int i = 1; i <= N; i++){
        if((N % i) == 0){
            arr[count] = i;
            printf("%d\n", arr[count]);
            count++;
        }else{
            continue;
        }
    }
}

int main() {
    int N, K;
    N = 6;
    K = 3;

    get_divisor(N);

    if(K > count){
        printf("0\n");
    } else {
        printf("%d\n", arr[K - 1]);
    }
}