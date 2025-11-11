102. Binary Tree Level Order Traversal
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root == NULL){
            return result;
        }

        queue <TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector <int> ans(size);

            for(int i = 0; i < size; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                ans[i] = frontNode -> val;

                if(frontNode -> left){
                    q.push(frontNode -> left);
                }

                if(frontNode -> right){
                    q.push(frontNode -> right);
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};