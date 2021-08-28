#include"iostream"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 递归
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        ListNode* next = head;
        for(int i = 0; i < k - 1; i++){
            next = next->next;
            if(!next) { return head; }
        }

        ListNode* last = head;
        ListNode* prev = head->next;
        head->next = reverseKGroup(next->next, k);
        for(int i = 0; i < k - 1; i++){
            ListNode* temp = prev->next;
            prev->next = last;
            last = prev;
            prev = temp;
        }
        return next;
    }
};


int main(){
    Solution s;
    // ListNode node15 = ListNode(5);
    // ListNode node14 = ListNode(4, &node15);
    // ListNode node13 = ListNode(3, &node14);
    ListNode node12 = ListNode(2);
    ListNode l1 = ListNode(1, &node12);

    ListNode* root = s.reverseKGroup(&l1, 2);
    while (root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}