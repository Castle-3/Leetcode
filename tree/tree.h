#include"iostream"
#include"string"
#include"vector"
#include"string.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct treeNode{
    int val;
    treeNode* left;
    treeNode* right;
    treeNode() : val(0), left(NULL), right(NULL) {}
    treeNode(int x) : val(x), left(NULL), right(NULL) {}
    treeNode(int x, treeNode* l, treeNode* r) : val(x), left(l), right(r) {}
};

/*
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

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


TreeNode* createTree(char* str, int size){
    str[size - 2] = '\0';
    str++;

    vector<TreeNode*> vec;
    char* token = strtok(str, ", ");
    char temp[] = "null";
    if(!strcmp(token, temp)) return NULL;
    TreeNode* root = new TreeNode(atoi(token));
    vec.push_back(root);

    while((token = strtok(NULL, ", ")) != NULL){
        if(!strcmp(token, temp)) vec.push_back(NULL);
        else vec.push_back(new TreeNode(atoi(token)));
    }

    int count = vec.size(), flag = 0;
    for(int i = 0; 2 * (i - flag) < count; i++){
        if(vec[i] != NULL){
            if(2 * (i - flag) + 1 < count) vec[i]->left = vec[2 * (i - flag) + 1];
            if(2 * (i - flag) + 2 < count) vec[i]->right = vec[2 * (i - flag) + 2];
        }
        else{
            while(vec[i] == NULL){
                i++;
                flag++;
            }
            i--;
        }
    }
    return root;
}


void deleteTree(TreeNode* root){
    if(root == NULL) return;
    TreeNode* leftNode = root->left;
    TreeNode* rightNode = root->right;
    delete root;
    root = NULL;
    if(leftNode) deleteTree(leftNode);
    if(rightNode) deleteTree(rightNode);
}