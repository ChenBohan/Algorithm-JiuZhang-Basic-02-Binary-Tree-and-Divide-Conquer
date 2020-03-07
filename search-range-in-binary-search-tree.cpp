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
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    vector<int> searchRange(TreeNode * root, int k1, int k2) {
        vector<int> result;
        if (!root){
            return result;
        }
        if (k1 < root->val){
            vector<int> left = searchRange(root->left, k1, k2);
            result.insert(result.end(), left.begin(), left.end());
        }
        if (k1 <= root->val && k2 >= root->val){
            result.push_back(root->val);
        }
        if (k2 > root->val){
            vector<int> right = searchRange(root->right, k1, k2);
            result.insert(result.end(), right.begin(), right.end());
        }
        return result;
    }
};
