//마방진 출력

#include <stdio.h>

int main() {
    int x, y;
    int a[100][100] = { 0, };
    int n = 5;

    int col = n / 2;
    int row = 0;

    for(int i = 1; i <= n * n; i++){
        a[row][col] = i;

        //다음 위치 결정
        int t_row = row - 1;
        int t_col = col + 1;

        if(t_row == -1){    //위로 벗어나는경우
            t_row = n - 1;
        }

        if(t_col == n){    //오른쪽으로 벗어나는 경우
            t_col = 0;
        }
        if(a[t_row][t_col] != 0){    //이미 숫자가 있는 경우
            row++;
        } else {
            row = t_row;
            col = t_col;
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