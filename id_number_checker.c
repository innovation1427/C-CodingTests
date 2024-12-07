//주민등록번호 검사기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*  -앞 6자리 뒤 7자리 총 13자리
    -앞 6자리: 생년월일
    -7번째 자리: 성별 (1, 3: 남자, 2, 4: 여자 (2000년 이후 출생 남녀에게 3, 4부여))
    -8,9,10,11번째 자리: 태어난 지역 코드와 출생 신고 주민센터 고유 번호를 조합한 번호
    -12번째 자리: 해당 지역 출생신고 접수 순서
    -13번쨰 자리: 주민등록번호 오류 검증 숫자(1~12번쨰 숫자에 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5를 곱하여 더 한값을 
    11로 나눈 나머지를 11에서 뺀 숫자, 두자리 숫자인 경우 10으로 나눈 나머지 값)*/


int ssnChecker(char *);

int main() {
    char ssn[14] = "1234567891723";
    int v;

    if((v = ssnChecker(ssn)) == 0)
        printf("유효한 주민등록번호입니다.\n");
    else {
        printf("유효하지 않은 주민등록번호입니다.\n");
    }
}

int ssnChecker(char ssn[]){
    int chk[13] = {2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5};
    int chksum = 0;
    int r;
    
    for (int i = 0; i < 12; i++){
        chksum = chksum + (ssn[i] - '0') * chk[i];
    }

    r = (11 - chksum % 11) % 10;
    if(r == (ssn[12] - '0')) {
        return 0;
    } else return 1;
}