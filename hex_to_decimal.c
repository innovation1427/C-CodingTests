#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char hexadecimal[20] = "12C";
    int decimal = 0;
    int position = 0;
    
    for (int i = strlen(hexadecimal) - 1; i >= 0; i--) {
        char ch = hexadecimal[i];
        if (ch >= '0' && ch <= '9') {
            decimal += (ch - '0') * (int)pow(16, position);
        } else if (ch >= 'A' && ch <= 'F') {
            decimal += (ch - 'A' + 10) * (int)pow(16, position);
        } else if (ch >= 'a' && ch <= 'f') {
            decimal += (ch - 'a' + 10) * (int)pow(16, position);
        }
        position++;
    }
    printf("%d", decimal);
}