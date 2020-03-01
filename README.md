# Algorithm-02-JiuZhang-Binary-Tree-and-Divide-Conquer
九章算法基础班 - 二叉树和分治法

- DFS
  - 递归
    - 遍历法
    - 分治法
  - 非递归

- Traverse vs Divide Conquer
  - They are both Recursion Algorithm
  - Result in parameter vs Result in return value （更符合coding style）
  - Top down vs Bottom up
  - 分治法可以并行化运算
  
- 思路
  - 碰到二叉树的问题，就想想整棵树在该问题上的结果和左右儿子在该问题上的结果之间的联系是什么

- [validate binary search tree](https://www.lintcode.com/problem/validate-binary-search-tree/description)

- [binary-search-tree-iterator](https://www.lintcode.com/problem/binary-search-tree-iterator/description)
  - 这是一个非常通用的利用 stack 进行 Binary Tree Iterator 的写法。
  - stack 中保存一路走到当前节点的所有节点，stack.peek() 一直指向 iterator 指向的当前节点。
  - 因此判断有没有下一个，只需要判断 stack 是否为空。
  - 获得下一个值，只需要返回 stack.top() 的值，并将 stack 进行相应的变化，挪到下一个点。
    - 如果当前点存在右子树，那么就是右子树中“一路向西”最左边的那个点
    - 如果当前点不存在右子树，则是走到当前点的路径中，第一个左拐的点
  - 访问所有节点用时O(n)，所以均摊下来访问每个节点的时间复杂度时O(1)
