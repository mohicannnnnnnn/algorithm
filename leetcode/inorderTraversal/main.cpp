#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
  */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;
        TreeNode *node = root;
        stack<TreeNode *> s;

        while(!s.empty() || node){
            if(node){
                    s.push(node);
                    node = node->left;
            }else{
                node = s.top();
                s.pop();
                result.push_back(node->val);
                node = node->right;
            }
        }
        return result;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
