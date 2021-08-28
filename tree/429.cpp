#include"iostream"
#include"vector"
#include"queue"

using namespace std;

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

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return{};
        vector<vector<int>> vec;
        queue<Node*> que;
        que.push(root);

        while(!que.empty()){
            vector<int> v;
            int size = que.size();
            for(int i = 0; i < size; i++){
                Node* node = que.front();
                que.pop();
                v.push_back(node->val);
                for(int j = 0; j < node->children.size(); j++){
                    if(node->children[j] != NULL){
                        que.push(node->children[j]);
                    }
                }
            }
            vec.push_back(v);
        }
        return vec;
    }
};