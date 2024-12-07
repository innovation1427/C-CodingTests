//qsort를 이용한 재귀 이진 탐색(퀵정렬)

#include <stdio.h>
#include <stdlib.h>

int cmp1(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int cmp2(const void* b, const void* a) {
    return *(int*)a - *(int*)b;
}

int main() {
    int arr[5] = {5, 3, 7, 1, 2};

    qsort(arr, 5 , sizeof(*arr), cmp1);
    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    qsort(arr, 5 , sizeof(*arr), cmp2);
    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    

    return 0;
    
}