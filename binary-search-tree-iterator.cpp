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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */


class BSTIterator {
public:
    /*
    * @param root: The root of binary tree.
    */
    TreeNode *current;
    stack<TreeNode *> myStack;
    
    BSTIterator(TreeNode* root) {
        current = root;
        while (!myStack.empty()){
            myStack.pop();
        }
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        return (current != NULL || !myStack.empty());
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        while (current != NULL){
            myStack.push(current);
            current = current->left;
        }
        current = myStack.top();
        myStack.pop();
        TreeNode *result = current;
        current = current->right;
        return result;
    }
};
