//몬테카를로 시뮬레이션으로 원주율 구하기(정사각형과 내접한 원을 이용하여 10,000,000개의 랜덤으로 찍히는 점이 원 내부와 원 외부에 있는 개수를 카운트하여 구하기)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool isPowerOfTen(int x)
{
    for (int i = 1; i < 10; i++){
        if (x == pow(10, i))
            return true;
        return false;
    }
}

int main() {
    int x, y;
    int iCnt = 0;
    int oCnt = 0;
    int radius = 50;
    double pi;

    for (int i = 1; i <= 10000000; i++){
        x = rand() % 100;
        y = rand() % 100;
        if ((x - radius) * (x - radius) + (y - radius) * (y - radius) <= radius * radius)
            iCnt++;
        else
            oCnt++;
        pi = (double)iCnt / (iCnt + oCnt) * 4;
        if (isPowerOfTen(i))
            printf("i=%d, pi = %f\n", i, pi);
    }
    printf("iCnt=%d, oCnt=%d, pi = %f\n", iCnt, oCnt, pi);
}