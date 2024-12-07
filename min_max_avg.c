//10개의 정수를 배열에 저장하고 최솟값, 최대값, 평균값 계산하기
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    int a[10];
    int min, max;
    int sum = 0;

    // 사용자로부터 10개의 정수를 입력받기
    for(int i = 0; i < 10; i++){
        printf("%d번째 숫자를 입력하세요: ", i + 1);
        scanf("%d", &a[i]);
    }
    
    // 입력받은 숫자들을 출력하기
    for (int i = 0; i < 10; i++)
        printf("%6d", a[i]);
    printf("\n");

    // 최소값, 최대값 및 합 초기화
    min = max = a[0];
    sum = a[0];
    
    // 최소값, 최대값 및 합 계산
    for(int i = 1; i < 10; i++){
        sum += a[i];
        if(a[i] < min)
            min = a[i];
        else if(a[i] > max) 
            max = a[i];
    }

    // 중간 결과 출력 제거 및 최종 결과 출력
    printf("min = %d, max = %d, average = %.2f\n", min, max, sum / 10.0);
    
    return 0;
}
