543. Diameter of Binary Tree
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1


class Solution {
    pair<int, int> fastDiameter(TreeNode* root){
        if(root == NULL){
            pair <int, int> p = make_pair(0,0);
            return p;
        }

        pair <int,int> left = fastDiameter(root -> left);
        pair <int,int> right = fastDiameter(root -> right);

        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second + 1;

        pair <int, int> ans;
        //first == diameter
        ans.first = max(opt1, max(opt2, opt3));
        //second == height
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        return fastDiameter(root).first - 1;
    }
};