#include"iostream"
#include"stack"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 计算链表长度
// class Solution {
// public:
//     int getLength(ListNode* head){
//         int n = 0;
//         while(head){
//             n++;
//             head = head->next;
//         }
//         return n;
//     }

//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* dummyNode = new ListNode(0, head);
//         int length = getLength(head);
//         ListNode* node = dummyNode;
//         for(int i = 1; i < length - n + 1; i++) { node = node->next; }
//         node->next = node->next->next;
//         ListNode* root = dummyNode->next;
//         delete dummyNode;
//         return root;
//     }
// };



// // 栈，全部入栈，弹出n个元素，此时的栈顶为删除元素的前一个元素
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         stack<ListNode*> s;
//         ListNode* dummy = new ListNode(0, head);
//         ListNode* node = dummy;
//         while(node){
//             s.push(node);
//             node = node->next;
//         }

//         // pop元素个数：n个
//         for(int i = 0; i < n; i++){
//             s.pop();
//         }
//         s.top()->next = s.top()->next->next;
//         ListNode* root = dummy->next;
//         delete dummy;
//         return root;
//     }
// };


// 快慢指针
// 由于我们需要找到倒数第 n 个节点，因此我们可以使用两个指针 first 和 second 同时对链表进行遍历
// 并且 first 比 second 超前n 个节点。first 遍历到链表的末尾时，second 就恰好处于倒数第 n 个节点

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy, *second = dummy;
        for(int i = 0; i < n + 1; i++, first = first->next);
        while(first){
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* root = dummy->next;
        delete dummy;
        return root;
    }
};

int main(){
    // ListNode node05 = ListNode(5);
    // ListNode node04 = ListNode(4, &node05);
    // ListNode node03 = ListNode(3, &node04);
    ListNode node02 = ListNode(2);
    
    ListNode root = ListNode(1, &node02);
    Solution s;
    ListNode* head = s.removeNthFromEnd(&root, 1);

    ListNode* n = head;
    while(n){
        cout << n->val << endl;
        n = n->next;
    }
}