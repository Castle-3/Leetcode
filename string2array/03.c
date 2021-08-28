#include"stdlib.h"
#include"stdio.h"
#include"string.h"


// int xinY(char x, char* y){
//     int len = strlen(y);
//     for(int i = 0; i < len; i++){
//         if(x == *(y + i)){return 1;}
//     }
//     return 0;
// }

// int findPlace(char* s, char x, int len){
//     for(int i = len - 1; i >= 0; i--){
//         if(x == s[i]){return i + 1;}
//     }
//     return -1;
// }

// int lengthOfLongestSubstring(char * s){
//     int flag = 0;
//     int place = 0;
//     int count = 0;
//     int len = strlen(s);
//     char* window = (char*)malloc(len * sizeof(char) + 1);
//     memset(window, 0, len + 1);

//     for(int i = 0; i < len; i++){
//         flag = xinY(s[i], window);
//         if(flag != 0){
//             place = findPlace(s, s[i], i);
//             memset(window, 0, len + 1);
//             i = place;
//         }

//         *(window + strlen(window)) = s[i];
//         int temp = strlen(window);
//         if(count < temp){count = temp;}
//     }

//     free(window);
//     return count;
// }


// // 建立一个表，出现过的字符为 1， 没有出现的字符为 0
// int lengthOfLongestSubstring(char * s){
//     int start = 0, end = 0, maxsize = 0;
//     char map[256] = {0};

//     while (*(s + end) != '\0'){
//         // 如果出现重复元素，从start位置开始清空元素
//         if(map[(int)*(s + end)] == 1){
//             map[(int)*(s + start)] = 0;
//             start++;
//         }

//         else {
//             map[(int)*(s + end)] = 1;
//             end++;
//             maxsize = maxsize > (end - start) ? maxsize : (end - start);
//         }
//     }
//     return maxsize;
// }


// 滑动窗口
int lengthOfLongestSubstring(char * s){
    int i;
    int start = 0, end = 0;
    int size = strlen(s);
    int maxsize = 0;

    for(; end < size; end++){
        for(i = start; i < end; i++){
            if (s[i] == s[end]){
                maxsize = maxsize >= (end - start) ? maxsize : (end - start);
                start = i + 1;
                break;
            }
        }
    }
    return maxsize >= (end - start) ? maxsize : (end - start);
}


int main(){
    char* str = "abac";
    int x = lengthOfLongestSubstring(str);
    printf("%d\n", x);
}