#include"iostream"

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode* dummy01 = new ListNode(0, l1);
//         ListNode* dummy02 = new ListNode(0, l2);
//         ListNode* node01 = dummy01;
//         ListNode* node02 = dummy02;
//         ListNode* head = new ListNode(0);
//         ListNode* root = head;

//         while(node01->next && node02->next){
//             if(node01->next->val <= node02->next->val){
//                 node01 = node01->next;
//                 root->next = new ListNode(node01->val);
//                 root = root->next;
//             }
//             else{
//                 node02 = node02->next;
//                 root->next = new ListNode(node02->val);
//                 root = root->next;
//             }
//         }
//         while(node01->next){
//             node01 = node01->next;
//             root->next = new ListNode(node01->val);
//             root = root->next;
//         }
        
//         while(node02->next){
//             node02 = node02->next;
//             root->next = new ListNode(node02->val);
//             root = root->next;
//         }
        
//         ListNode* node = head->next;
//         delete dummy01;
//         delete dummy02;
//         delete head;
//         return node;
//     }
// };


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode* head = new ListNode(0);
//         ListNode* prev = head;
//         while(l1 && l2){
//             if(l1->val > l2->val){
//                 prev->next = l2;
//                 l2 = l2->next;
//             }
//             else {
//                 prev->next = l1;
//                 l1 = l1->next;
//             }
//             prev = prev->next;
//         }

//         if(l1) { prev->next = l1; }
//         else prev->next = l2;

//         ListNode* root = head->next;
//         delete head;
//         return root;
//     }
// };


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {return l2;}
        else if (!l2) {return l1;}
        else if (l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};


int main(){
    // ListNode node13 = ListNode(4);
    ListNode node12 = ListNode(3);
    ListNode l1 = ListNode(-9, &node12);

    // ListNode node23 = ListNode(4);
    ListNode node22 = ListNode(7);
    ListNode l2 = ListNode(5, &node22);

    Solution s;
    ListNode* node = s.mergeTwoLists(&l1, &l2);
    // while(node){
    //     ListNode* n = node;
    //     cout << node->val << " ";
    //     node = node->next;
    //     delete n;
    // }
    while(node){
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}