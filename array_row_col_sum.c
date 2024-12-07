//2차원 배열 가로, 세로 합과 함께 출력

#include <stdio.h>

int main() {
    int x, y;
    int a[100][100] = { 0, };

    int n = 5;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            a[i][j] = i * n + j;
        }
    }

    for(int i = 0; i < n; i++){
        a[i][n] = 0;
        for(int j = 0; j < n; j++){
            printf("%4d", a[i][j]);
            a[i][n] += a[i][j];
            a[n][j] += a[i][j];
        }
        printf(" ->%4d", a[i][n]);
        printf("\n");
    }
    
    for(int i = 0; i < n; i++){
        printf("%4d", a[n][i]);
    }
}