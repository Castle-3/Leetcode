#include"stdio.h"
#include"stdlib.h"

void mySwap(char* x, char* y){
    char temp = *y;
    *y = *x;
    *x = temp;
}

int reverse(int x){
    char temp;
    int y = x, len = 0, flag = 1;
    while(y != 0){
        len++;
        y /= 10;
    }
    char* start, *end, *result = (char*)malloc((len + 1)*sizeof(char));
    if(x < 0){ flag = -1; }
    itoa(flag * x, result, 10);
    start = result;
    end = result + len - 1;
    while(start < end){
        mySwap(start, end);
        start++, end--;
    }
    
    int re = atoi(result);
    return re;
} 

int main(){
    int x = 123;
    int y = reverse(x);
    printf("%d\n", y);
}