#include"stdio.h"
#include"stdlib.h"

int isMatch(char * s, char * p){
    int count;
    char* x = s;
    
    // 替换连续重复字符为*,仅保留第一个字符
    while(*x != '\0'){
        for(count = 1; *(x + count) != '\0' && *(x + count) == *x; count++);
        if(count == 2){*(x + 1) = '*';}
        if(count > 2){
            *(x + 1) = '*';
            for(int i = 2; *(x + i) != '\0'; i++){
                 *(x + i) = *(x + count + i - 2);
            }
        }
        x++;
    }

    int firstMatch = *s && (*s == *p || *p == '.');



}

int main(){
    char s[] = "aamisssmiss";
    char p[] = "";
    isMatch(s, p);
}