/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        if (!root || !p){
            return NULL;
        }
        TreeNode * successor = NULL;
        TreeNode * node = root;
        while(node){
            if (node->val > p->val){
                successor = node;
                node = node->left;
            }else{
                node = node->right;
            }
        }
        return successor;
    }
};
