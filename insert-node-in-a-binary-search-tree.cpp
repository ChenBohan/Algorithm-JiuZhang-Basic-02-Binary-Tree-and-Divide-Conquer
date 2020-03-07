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
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode * insertNode(TreeNode * root, TreeNode * node) {
        if (!root){
            return node;
        }
        TreeNode * traverse = root;
        TreeNode * parent = NULL;
        while(traverse){
            parent = traverse;
            if (traverse->val >= node->val){
                traverse = traverse->left;
            }else{
                traverse = traverse->right;
            }
        }
        if (node->val >= parent->val){
            parent->right = node;
        }else{
            parent->left = node;
        }
        return root;
    }
};
