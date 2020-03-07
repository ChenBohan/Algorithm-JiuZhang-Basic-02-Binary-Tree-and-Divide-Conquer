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
 
class ReturnType {
public:
    int m_any2Any;
    int m_root2Any;
    ReturnType(int any2Any, int root2Any){
        m_any2Any = any2Any;
        m_root2Any = root2Any;
    }
};

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode * root) {
        ReturnType result = helper(root);
        return result.m_any2Any;
    }
    ReturnType helper(TreeNode * node){
        if (!node){
            return ReturnType(INT_MIN, INT_MIN);
        }
        ReturnType left = helper(node->left);
        ReturnType right = helper(node->right);
        int root2Any = max(max(left.m_root2Any, right.m_root2Any), 0) + node->val;
        int any2Any = max(left.m_any2Any, right.m_any2Any);
        any2Any = max(any2Any, max(0, left.m_root2Any) + max(0, right.m_root2Any) + node->val);
        return ReturnType(any2Any, root2Any);
    }
};
