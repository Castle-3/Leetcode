#include"stdio.h"
#include"string.h"
#include"stdlib.h"


char * longestPalindrome(char * s){
    int op = 0, ed = 0;
    int start = 0, len = strlen(s);
    int left, right;

    for(; start < len; start++){
        left = start;
        right = start;

        while(left >= 0 && right <= len - 1 && s[left] == s[right]){
            if((right - left) > (ed - op)) { op = left, ed = right; }
            left--, right++;
        }
    }

    for(start = 0; start < len; start++){
        left = start;
        right = start + 1;

         while(left >= 0 && right <= len - 1 && s[left] == s[right]){
            if((right - left) > (ed - op)) { op = left, ed = right; }
            left--, right++;
        }
    }

    int size = ed - op + 1;
    char* result = (char*)malloc((size + 1) * sizeof(char));
    while (op <= ed){
        *result++ = *(s + op++);
    }
    *result = '\0';
    return result - size;
}

/*
"babad"
"cbbd"
"a"
"ac"
"aacabdkacaa"
"abb"
"aab"
"acbb"
"adam"
*/

int main(){
    char s[] = "ccc";
    char* re = longestPalindrome(s);
    printf("%s\n", re);
    free(re);
}