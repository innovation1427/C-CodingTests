//주식가격 (큐, 스택)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int get_time(int array[], int arr_len, int index);

// prices_len은 배열 prices의 길이입니다.
int* solution(int prices[], size_t prices_len) {
    int* answer = (int*)malloc(prices_len * sizeof(int)); // 올바른 메모리 할당 크기
    if (answer == NULL) {
        // 메모리 할당 실패 시 처리
        return NULL;
    }
    for(int i = 0; i < prices_len; i++) {
        answer[i] = get_time(prices, prices_len, i);
    }
    return answer;
}

int get_time(int array[], int arr_len, int index) {
    if(index >= arr_len - 1) {
        return 0;
    }
    int result = 0;
    
    for(int i = index + 1; i < arr_len; i++) {
        result = result + 1;
        if(array[index] > array[i]) {
            break;
        }
    }
    return result;
}

int main() {
    int prices[] = {1, 2, 3, 2, 3};
    size_t prices_len = sizeof(prices) / sizeof(prices[0]);
    int* result = solution(prices, prices_len);
    for (int i = 0; i < prices_len; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result); // 할당된 메모리를 해제
    return 0;
}
