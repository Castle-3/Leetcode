#include"stdlib.h"
#include"stdio.h"

typedef struct VAL2INDEX{
    int value;
    int index;
} Val2Index;

int compare(const void * a, const void * b){
    Val2Index* x = (Val2Index*) a;
    Val2Index* y = (Val2Index*) b;
    return x->value - y->value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    Val2Index* map = (Val2Index*)malloc(sizeof(Val2Index) * numsSize);
    for (int i = 0; i < numsSize; i++){
        map[i].value = nums[i];
        map[i].index = i;
    }
    
    qsort(map, numsSize, sizeof(Val2Index), compare);
    for(int i = 0; i < numsSize; i++){
        printf("%d ", map[i].value);
    }
    printf("\n");

    int i = 0, j = numsSize - 1;
    while(i < j){
        if(map[i].value + map[j].value > target){ j--; }
        else if(map[i].value + map[j].value < target){ i++; }
        else{ 
            int* result = (int*)malloc(2 * sizeof(int));
            *returnSize = 2;
            result[0] = map[i].index, result[1] = map[j].index;
            free(map);
            return result;
        }
    }
    free(map);
    *returnSize = 0;
    return NULL;
}

int main(){
    int data[] = {3,2,4};
    int target = 6;
    int x = 2;
    int* resultSize = &x;
    int *result = twoSum(data, 3, target, resultSize);
    for(int i = 0; i < 2; i++){
        printf("%d\n", result[i]);
    }
}