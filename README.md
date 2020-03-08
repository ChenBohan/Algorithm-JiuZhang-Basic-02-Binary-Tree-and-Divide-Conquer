# Algorithm-JiuZhang-Basic-02-Binary-Tree-and-Divide-Conquer
九章算法基础班 - 二叉树和分治法

### 课程大纲

- 用树形分析法计算时间复杂度
- 递归是深度优先搜索算法(DFS)的一种实现形式
  - DFS可以使用非递归的方式实现
- 二叉树上的递归 Recursion in Binary Tree
  - 遍历法 Traverse
  - 分治法 Divide Conquer
- 二叉搜索树
  - 性质：中序遍历是升序序列
  - 功能：O(h)的时间查找，删除，插入
- 二叉树上的宽度优先搜索
  - 使用一个队列的宽度优先搜索算法
    - 在二叉树上无需使用 Hash 判重
  - 如何实现分层遍历
- 必“背”程序：
  - 非递归版本的 Pre Order, In Order
  - 二叉树分层遍历

### 题目

- 深度有限搜索
  - 递归
    - 遍历法
    - 分治法
  - 非递归

- Traverse vs Divide Conquer
  - They are both Recursion Algorithm
  - Result in parameter vs Result in return value （更符合coding style）
  - Top down vs Bottom up
  - 分治法可以并行化运算

- 递归三要素：
  - 定义（状态）
    - 接受什么参数
    - 做了什么事
    - 返回什么值
  - 拆解（方程）
    - 如何将参数变小
  - 出口（初始化）
    - 什么时候可以直接 return

- 思路
  - 碰到二叉树的问题，就想想整棵树在该问题上的结果和左右儿子在该问题上的结果之间的联系是什么
  
- [binary-tree-inorder-traversal](https://www.lintcode.com/problem/binary-tree-inorder-traversal/description)
  - 递归分治法
  - 非递归
    - 挪到下一个点的算法如下:
      - 如果当前点存在右子树，那么就是右子树中“一路向西”最左边的那个点
      - 如果当前点不存在右子树，则是走到当前点的路径中，第一个左拐的点
      
- [binary-tree-postorder-traversal](https://www.lintcode.com/problem/binary-tree-postorder-traversal/description)

- [maximum-depth-of-binary-tree](https://www.lintcode.com/problem/maximum-depth-of-binary-tree/description)
  - 点node为根的树高度，等于高度最大的子树的高度+1

- [minimum-depth-of-binary-tree](https://www.lintcode.com/problem/minimum-depth-of-binary-tree/description)
  - 参考maximum-depth-of-binary-tree

- [balanced-binary-tree](https://www.lintcode.com/problem/balanced-binary-tree/description)
  - 用两个DFS分别得到左子树和右子树的深度，然后进行比较
  
- [lowest-common-ancestor-of-a-binary-tree](https://www.lintcode.com/problem/lowest-common-ancestor-of-a-binary-tree/description)
  - 在root为根的二叉树中找A,B的LCA:
    - 如果找到了就返回这个LCA
    - 如果只碰到A，就返回A
    - 如果只碰到B，就返回B
    - 如果都没有，就返回null
    
- [binary-tree-maximum-path-sum](https://www.lintcode.com/problem/binary-tree-maximum-path-sum/description)
  - 利用分治法 解决问题
    - 需要一个变量`root to any`不断记录带有root点的路径的最大值 curr_max 局部变量
    - 需要另一个变量`any to any`记录当前的最大路径值 max 类变量
    - 最后返回 当前的最大路径值
  - 有4种情况要考虑
    - left + root
    - right + root
    - root
    - left + right + root
    - 不断往上传递的值 只可能是 1， 2， 3中的一种，第四种情况只可能保存在 max里面 而不可能在 curr_max
  - 注意，当root == null,以上2个值都要置为Integer_MIN_VALUE; 因为没有节点可取的时候，是不存在solution的。以免干扰递归的计算

- [validate binary search tree](https://www.lintcode.com/problem/validate-binary-search-tree/description)

- [binary-search-tree-iterator](https://www.lintcode.com/problem/binary-search-tree-iterator/description)
  - 这是一个非常通用的利用 stack 进行 Binary Tree Iterator 的写法。
  - stack 中保存一路走到当前节点的所有节点，stack.peek() 一直指向 iterator 指向的当前节点。
  - 因此判断有没有下一个，只需要判断 stack 是否为空。
  - 获得下一个值，只需要返回 stack.top() 的值，并将 stack 进行相应的变化，挪到下一个点。
    - 如果当前点存在右子树，那么就是右子树中“一路向西”最左边的那个点
    - 如果当前点不存在右子树，则是走到当前点的路径中，第一个左拐的点
  - 访问所有节点用时O(n)，所以均摊下来访问每个节点的时间复杂度时O(1)

- [inorder-successor-in-bst](https://www.lintcode.com/problem/inorder-successor-in-bst/description)
  - 明确标准：比目标节点p要大的节点才可能是结果
    - 每一个比目标节点大的节点都可能是结果，先记录一下
    - 不断逼近最小的那个趋势，反正上面已经记录的最靠近“最小”趋势的那个节点
    - 比目标节点p小，不用想肯定不可能是结果，直接找大的

- [insert-node-in-a-binary-search-tree](https://www.lintcode.com/problem/insert-node-in-a-binary-search-tree/description)
  - 在树上定位要插入节点的位置。
    - 如果它大于当前根节点，则应该在右子树中，如果没有右子树则将该点作为右儿子插入；若存在右子树则在右子树中继续定位。
    - 如果它小于当前根节点，则应该在左子树中，处理同上。

- [binary-tree-level-order-traversal](https://www.lintcode.com/problem/binary-tree-level-order-traversal/description)
  - 二叉树的层次遍历通常实现方式为使用队列不断压入节点遍历,每次取出队列首个元素遍历左右子节点，继续压入子节点即可。
