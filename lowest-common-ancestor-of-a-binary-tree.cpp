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
    /*
     * @param root: The root of the binary search tree.
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        if (!root){
            return NULL;
        }
        if (root == A || root == B){
            return root;
        }
        TreeNode* leftLCA = lowestCommonAncestor(root->left, A, B);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, A, B);
        if (leftLCA && rightLCA){
            return root;
        }
        if (leftLCA){
            return leftLCA;
        }
        if (rightLCA){
            return rightLCA;
        }
        return NULL;
    }
};
