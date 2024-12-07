//qsort를 이용한 재귀 이진 탐색(퀵정렬 문자열)

#include <stdio.h>
#include <stdlib.h>

int cmp1(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

int cmp2(const void* b, const void* a) {
    return *(char*)a - *(char*)b;
}

int main() {
    int arr[5] = {'a', 'l', 's', 'h', 'y'};

    qsort(arr, 5 , sizeof(*arr), cmp1);
    for (int i = 0; i < 5; i++){
        printf("%c ", arr[i]);
    }
    printf("\n");

    qsort(arr, 5 , sizeof(*arr), cmp2);
    for (int i = 0; i < 5; i++){
        printf("%c ", arr[i]);
    }
    printf("\n");
    

    return 0;
    
}