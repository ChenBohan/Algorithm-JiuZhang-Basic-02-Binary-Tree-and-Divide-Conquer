/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
#include <limits>

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    
private:
    bool helper(TreeNode * root, long min, long max){
        if (root == NULL){
            return true;
        }
        if (root->val <= min || root->val >= max){
            return false;
        }
        bool leftResult = helper(root->left, min, root->val);
        bool rightResult = helper(root->right, root->val, max);
        return leftResult && rightResult;
    }
};
