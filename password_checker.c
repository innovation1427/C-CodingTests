//패스워드 검사기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int passwordChecker(char *);

int main() {
    char password[30] = "Abc1*";

    switch (passwordChecker(password)) {
        case 1:
            printf("8글자 이상이어야 함\n");
            break;
        case 2:
            printf("영문 대문자가 하나 이상이어야 함\n");
            break;
        case 3:
            printf("영문 소문자가 하나 이상이어야 함\n");
            break;
        case 4:
            printf("숫자가 하나 이상이어야 함나\n");
            break;
        case 5:
            printf("특수 문자가 하나 이상이어야 함\n");
            break;
        default:
            printf("규칙에 맞는 패스워드 입니다.\n");
            break;
    }
}

int passwordChecker(char password[]){
    int checkLen = 0;
    int checkUpper = 0;
    int checkLower = 0;
    int checkSpecial = 0;
    int checkDigit = 0;

    if(strlen(password) >= 8)
        checkLen = 1;

    for(int i = 0; i < strlen(password); i++){
        if(isupper(password[i])){
            checkUpper = 1;
        } else if (islower(password[i])) {
            checkLower = 1;
        } else if (isdigit(password[i])){
            checkDigit = 1 ;
        } else {
            checkSpecial = 1;
        }
    }
    
    if (checkLen = 0) return 1;
    if (checkUpper = 0) return 2;
    if (checkLower = 0) return 3;
    if (checkSpecial = 0) return 4;
    if (checkDigit = 0) return 5;
    return 0;
}