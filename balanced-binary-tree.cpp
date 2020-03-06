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
class TreeInfo {
public:
    bool m_isBalanced;
    int m_maxDepth;
    TreeInfo(bool isBalanced, int maxDepth){
        m_isBalanced = isBalanced;
        m_maxDepth = maxDepth;
    }
};

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) {
        return helper(root).m_isBalanced;
    }
    TreeInfo helper(TreeNode * node) {
        if (!node){
            return TreeInfo(true, 0);
        }
        TreeInfo leftInfo = helper(node->left);
        TreeInfo rightInfo = helper(node->right);
        
        if (abs(leftInfo.m_maxDepth - rightInfo.m_maxDepth) <= 1 && leftInfo.m_isBalanced && rightInfo.m_isBalanced){
            return TreeInfo(true, max(leftInfo.m_maxDepth, rightInfo.m_maxDepth) + 1);
        }else{
            return TreeInfo(false, max(leftInfo.m_maxDepth, rightInfo.m_maxDepth) + 1);
        }
    }
};
