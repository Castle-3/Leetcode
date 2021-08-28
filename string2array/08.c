#include"stdio.h"
#include"stdlib.h"

int myAtoi(char * s){
    int flag = 1;
    int result = 0;

    // 去除前导空格
    while(*s != '\0' && *s == ' '){ s++; }

    // 判断符号
    if(*s == '-'){
        flag = -1;
        s++;
    }
    else if(*s == '+'){ s++; }

    // 前置字符
    if(*s < '0' || *s > '9'){ return 0; }

    // 
    while(*s != '\0'){
        if(*s >= '0' && *s <= '9'){
            if(flag == 1 && (result > INT_MAX / 10 || result == INT_MAX / 10 && *s >= '7')){
                return INT_MAX;
            }
            if(flag == -1 && (result > INT_MAX / 10 || result == INT_MAX / 10 && *s >= '8')){
                return INT_MIN;
            }
            result = result * 10 + (*s - '0');
        }
        else { break; }
        s++;
    }
    return flag * result;
}
/*
"3.14159"
"-+12"
"-2147483648"
*/

int main(){
    char s[] = "2147483647";
    int y = myAtoi(s);
    printf("%d\n", y);
}
