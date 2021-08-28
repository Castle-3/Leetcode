#include"iostream"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// // 迭代法
// // last指向上一个节点，node指向下一个节点
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(!head || !head->next){ return head; }
//         ListNode* dummy = new ListNode(0, head);
//         ListNode* last = dummy;
//         ListNode* node;
//         while(last && head && head->next){
//             node = head->next;
//             head->next = node->next;
//             node->next = head;
//             head = head->next;
//             last->next = node;
//             last = last->next->next;
//         }
//         ListNode* root = dummy->next;
//         delete dummy;
//         return root;
//     }
// };


// 递归
class Solution {
public:
    // 递归的含义是：将两两相邻节点交换，返回交换完成的头节点
    ListNode* swapPairs(ListNode* head) {
        // 终止条件
        if(head == NULL || head->next == NULL) return head;

        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};


int main(){
    Solution s;
    ListNode node14 = ListNode(4);
    ListNode node13 = ListNode(3, &node14);
    ListNode node12 = ListNode(2, &node13);
    ListNode l1 = ListNode(1, &node12);

    ListNode* root = s.swapPairs(&l1);
    while (root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}