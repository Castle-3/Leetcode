#include"iostream"
#include"vector"
#include"queue"

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
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode* node = NULL;
//         for(int i = 0; i < lists.size(); i++){
//             node = mergeTwo(node, lists[i]);
//         }
//         return node;
//     }

//     ListNode* mergeTwo(ListNode* l1, ListNode* l2){
//         if(!l1) return l2;
//         if(!l2) return l1;
//         ListNode node = ListNode(0);
//         ListNode* prev = &node;
//         while(l1 && l2){
//             if(l1->val < l2->val){
//                 prev->next = l1;
//                 l1 = l1->next;
//             }
//             else{
//                 prev->next = l2;
//                 l2 = l2->next;
//             } 
//             prev = prev->next;
//         }

//         if(l1) prev->next = l1;
//         else if(l2) prev->next = l2;
//         return node.next;
//     }
// };


// // 分治
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if (!lists.size()) return nullptr;
//         ListNode* node = merge(lists, 0, lists.size() - 1);
//         return node;
//     }

//     ListNode* merge(vector<ListNode*>& lists, int start, int end){
//         if(start == end) return lists[start];
//         int mid = (start + end) / 2;
//         return mergeTwo(merge(lists, start, mid), merge(lists, mid + 1, end)); 
//     }

//     ListNode* mergeTwo(ListNode* l1, ListNode* l2){
//         if(!l1) return l2;
//         if(!l2) return l1;
//         ListNode node = ListNode(0);
//         ListNode* prev = &node;
//         while(l1 && l2){
//             if(l1->val < l2->val){
//                 prev->next = l1;
//                 l1 = l1->next;
//             }
//             else{
//                 prev->next = l2;
//                 l2 = l2->next;
//             } 
//             prev = prev->next;
//         }

//         if(l1) prev->next = l1;
//         else if(l2) prev->next = l2;
//         return node.next;
//     }
// };



//优先队列 
class Solution {
public:
    struct Status{
        int val;
        ListNode * ptr;
        bool operator <(const Status &rhs) const {
            return val > rhs.val;
        }
    };


    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }

        ListNode head, *tail = &head;
        while (!q.empty()){
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if(f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};


int main(){
    Solution s;
    ListNode node13 = ListNode(5);
    ListNode node12 = ListNode(4, &node13);
    ListNode l1 = ListNode(1, &node12);
    
    ListNode node23 = ListNode(4);
    ListNode node22 = ListNode(3, &node23);
    ListNode l2 = ListNode(0, &node22);

    ListNode node32 = ListNode(6);
    ListNode l3 = ListNode(2, &node32);

    vector<ListNode*> v;
    v.push_back(&l1);
    v.push_back(&l2);
    v.push_back(&l3);

    ListNode* root = s.mergeKLists(v);
    while (root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}