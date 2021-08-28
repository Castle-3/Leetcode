#include"iostream"
#include"queue"

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


// class Solution {
// public:
//     // 获取本层下一个有子树的左边节点
//     Node* getnextNode(Node* root){
//         Node* node = root->next;
//         while(node){
//             if(node->left){ return node->left; }
//             else if(node->right){ return node->right; }
//             node = node->next;
//         }
//         return NULL;
//     }

//     Node* connect(Node* root) {

//         // node指向每层的一个节点
//         Node* node = root;
        
//         // node为空，表示所有层循环结束
//         while(node){

//             // 建立一个哑节点，指向每层的第一个节点
//             Node dummy = Node(0, NULL, NULL, node);

//             // head节点表示当前访问的节点，用于本层间的遍历
//             Node* head = node;

//             // head为空，表示本层循环结束
//             while(head){

//                 // head的左子树指向右子树
//                 if(head->left && head->right){ head->left->next = head->right; }

//                 // 查找本层距离head最近的，有子树的节点，并获取其左边的节点
//                 Node* next = getnextNode(head);

//                 // 如果存在，则建立指向关系
//                 if(next){
//                     if(head->right) head->right->next = next;
//                     else if(head->left) head->left->next = next;
//                 }

//                 // head在本层滑动
//                 head = head->next;
//             }

//             // node指向下一层第一个节点
//             node = getnextNode(&dummy);
//         }

//         // 返回
//         return root;
//     }
// };

// class Solution {
// public:
//     Node* connect(Node* root) {
//         if(root==NULL) return{};
//         queue<Node*> que;
//         que.push(root);
//         while(!que.empty()){
//             int size = que.size();
//             for(int i = 0; i < size; i++){
//                 Node* node = que.front();
//                 que.pop();
//                 if(i != size - 1) node->next = que.front();
//                 if(node->left) que.push(node->left);
//                 if(node->right) que.push(node->right);
//             }
//         }
//         return root;
//     }
// };


// class Solution {
// public:
//     void handle(Node* &last, Node* &nextStart, Node* head){
//         // 如果上一个元素存在，则将其指向当前访问的元素
//         if(last){
//             last->next = head;
//         }

//         // 找到第一个元素，并赋给nextStart，之后保持不变，直到下一层
//         if(!nextStart){
//             nextStart = head;
//         }

//         // 更新last
//         last = head;
//     }

//     Node* connect(Node* root) {
//         Node* start = root;
//         while(start){
//             // last指向上一个元素， nextStart指向下一层第一个元素， head在本层之间滑动
//             Node *last = NULL, *nextStart = NULL, *head = start;
//             while(head){
//                 if(head->left){
//                     handle(last, nextStart, head->left);
//                 }

//                 if(head->right){
//                     handle(last, nextStart, head->right);
//                 }
//                 head = head->next;
//             }
//             start = nextStart;
//         }
//         return root;
//     }
// };


// 递归
class Solution {
public:
    Node* getNextNode(Node* node){
        while(node){
            if(node->left) return node->left;
            if(node->right) return node->right;
            node = node->next;
        }
        return NULL;
    }

    Node* connect(Node* root) {
        if(root==NULL) return NULL;

        if(root->left && root->right){
            root->left->next = root->right;
            root->right->next = getNextNode(root->next);
        }
        else if(root->left){
            root->left->next = getNextNode(root->next);
        }
        else if(root->right){
            root->right->next = getNextNode(root->next);
        }
        else return root;

        root->right = connect(root->right);
        root->left = connect(root->left); 
        return root;
    }
};


/* 
 *[1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5]
 */

int main(){
    Node n52 = Node(5);
    Node n51 = Node(5);
    Node n46 = Node(4);
    Node n45 = Node(4);
    Node n44 = Node(4);
    Node n43 = Node(4);
    Node n42 = Node(4);
    Node n41 = Node(4, &n51, &n52, NULL);
    Node n34 = Node(3);
    Node n33 = Node(3, &n45, &n46, NULL);
    Node n32 = Node(3, &n43, &n44, NULL);
    Node n31 = Node(3, &n41, &n42, NULL);
    Node n22 = Node(2, &n33, &n34, NULL);
    Node n21 = Node(2, &n31, &n32, NULL);
    Node n11 = Node(1, &n21, &n22, NULL);

    Solution s;
    Node* root = s.connect(&n11);

    queue<Node*> que;
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        for(int i = 0; i < size; i++){
            Node* node = que.front();
            cout << node->val;
            if (i == size - 1) cout << "#";
            que.pop();
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
    }
    cout << endl;
}