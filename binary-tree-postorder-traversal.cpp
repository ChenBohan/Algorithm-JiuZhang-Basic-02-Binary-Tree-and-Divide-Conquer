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

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        vector<int> result;
        if (root == NULL){
            return result;
        }
        vector<int> leftTree = postorderTraversal(root->left);
        vector<int> rightTree = postorderTraversal(root->right);
        result.insert(result.end(), leftTree.begin(), leftTree.end());
        result.insert(result.end(), rightTree.begin(), rightTree.end());
        result.push_back(root->val);
        return result;
    }
};
