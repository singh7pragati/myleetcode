110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true

class Solution {
    pair <bool, int> balanced(TreeNode* root){
        if(root == NULL){
            pair <bool, int> p = make_pair(true, 0);
            return p;
        }

        pair<bool, int> left = balanced(root -> left);

        pair<bool, int> right = balanced(root -> right);

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;

        if(left.first && right.first && diff){
            ans.first = true;
        }
        else ans.first = false;

        ans.second = max(left.second , right.second) + 1;

        return ans;

    }
public:
    bool isBalanced(TreeNode* root) {
        return balanced(root).first;
        
    }
};