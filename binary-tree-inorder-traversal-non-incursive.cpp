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
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        stack<TreeNode*> mystack;
        vector<int> result;
        while (root){
            mystack.push(root);
            root = root->left;
        }
        while(!mystack.empty()){
            TreeNode* current = mystack.top();
            result.push_back(current->val);
            if (current->right){
                current = current->right;
                while(current){
                    mystack.push(current);
                    current = current->left;
                }
            }
            else{
                mystack.pop();
                while(!mystack.empty() && mystack.top()->right == current){
                    current = mystack.top();
                    mystack.pop();
                }
            }
        }
        return result;
    }
};

