## 贪心算法
采用 ** 贪心的策略 ** ，保证每次操作都是局部最优的，从而使得最终的结果是全局最优的。

- 并不从整体最优考虑。虽然不能对所有的问题得到整体最优解，但许多情况下是可以产生整体最优解的。在一些情况下，即便贪心算法不能得到整体最优解，其结果也是最优解很好的近似

- 一般情况下，需要证明后才可以真正运用到题目的算法中：整个问题的最优解一定由在贪心策略中存在的子问题的最优解得来

- 当一个问题的最优解包含其子问题的最优解时，称此问题具有最优子结构性质

- 贪心算法自顶向下的，通过不断地迭代优化，缩小问题规模。

### 自顶向下和自底向上的区别

	核心：是否存储上一状态的解
	若没有存储上一状态的解，则为递归，否则便是DP