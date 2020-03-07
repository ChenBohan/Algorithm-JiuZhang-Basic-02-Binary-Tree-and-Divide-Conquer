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
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        vector<vector<int>> result;
        if (!root){
            return result;
        }
        queue<TreeNode *> Q;
        Q.push(root);
        while(!Q.empty()){
            vector<int> level;
            int size = Q.size();
            for (int i = 0; i < size; i++){
                TreeNode * node = Q.front();
                Q.pop();
                level.push_back(node->val);
                if (node->left){
                    Q.push(node->left);
                }
                if (node->right){
                    Q.push(node->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};
