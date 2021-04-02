// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        
        int depth = 1;
        for (int i = 0; i < root->children.size(); ++i) {
            depth = max(depth, 1 + maxDepth(root->children[i]));
        }
        
        return depth;
    }
    
    /*
    // Second possible solution
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        
        stack<int> depths; 
        for (int i = 0; i < root->children.size(); ++i) {
            depths.emplace(maxDepth(root->children[i]));
        }
        
        int largest = 0;
        while (!depths.empty()) {
            if (depths.top() > largest) {
                largest = depths.top();
            } 
            depths.pop();
        }
        return largest + 1;
    }
    */
};
