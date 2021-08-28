#include"stdio.h"
#include"stdlib.h"
#include"string.h"

char * convert(char * s, int numRows){
    if (numRows == 1){ return s;}

    int len = strlen(s);
    int cyc = 2 * numRows - 2;
    int round = len / cyc;
    int remain = len % cyc;
    char* result = (char*)malloc((len + 1) * sizeof(char));
    char* key = result;

    // 完整的循环
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < round; j++){
            *result++ = *(s + cyc * j + i);
            if(i != 0 && i != numRows - 1){
                *result++ = *(s + cyc * j + i + (numRows - i - 1) * 2);
            }
        }

        // 不完整的循环
        // 填竖线
        if(remain > i){
            *result++ = *(s + cyc * round + i);
        }
        // 填斜线
        if(remain > i && (2 * numRows - remain) - 1 <= i && i != numRows - 1){
            *result++ = *(s + cyc * round + 2 * (numRows - 1) - i);
        }
    }
    *result++ = '\0';
    return key;
}
/*
PAYPALISHIRING

*/

int main(){
    char str[] = "ABCDEFGHIJKLMNO";
    char* s = convert(str, 5);
    printf("%s\n", s);
}