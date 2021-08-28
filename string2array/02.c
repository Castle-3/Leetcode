#include"stdio.h"
#include"stdlib.h"
#include"math.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int flag = 0;
    struct ListNode* root = (struct ListNode*)malloc(sizeof(struct ListNode));
    root->val = 0;
    root->next = NULL;

    struct ListNode* p = root;
    while (l1 != NULL || l2 != NULL || flag != 0){
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(l1 == NULL && l2 != NULL){
            newNode->val = (l2->val + flag) % 10;
            flag = (l2->val + flag) / 10;
            l2 = l2->next;
        }
        else if(l2 == NULL && l1 != NULL){
            newNode->val = (l1->val + flag) % 10;
            flag = (l1->val + flag) / 10;
            l1 = l1->next;
        }
        else if(l1 != NULL && l2 != NULL){
            newNode->val = (l1->val + l2->val + flag) % 10;
            flag = (l1->val + l2->val + flag) / 10;
            l1 = l1->next, l2 = l2->next;
        }
        else {
            newNode->val = flag;
            flag = 0;
        }

        p->next = newNode;
        p = p->next;
    }
    p->next = NULL;
    return root->next;
}

struct ListNode* arr2Node(int temp[], int len){
    struct ListNode* root = (struct ListNode*)malloc(sizeof(struct ListNode));
    root->val = temp[0];
    root->next = NULL;

    for(int j = len - 1; j >= 1; j--){
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = temp[j];
        newNode->next = root->next;
        root->next = newNode;
    }
    return root;
}


int main(){

    int arr1[] = {0};
    int arr2[] = {0};

    struct ListNode* x  = arr2Node(arr1, 1);
    struct ListNode* y  = arr2Node(arr2, 1);
    struct ListNode* res = addTwoNumbers(x, y);

    while (res!= NULL){
        struct ListNode* temp = res;
        printf("%d ", res->val);
        res = res->next;
        free(temp);
    }

    while (x!= NULL){
        struct ListNode* temp = x;
        x = x->next;
        free(temp);
    }

    while (y!= NULL){
        struct ListNode* temp = y;
        y = y->next;
        free(temp);
    }
}