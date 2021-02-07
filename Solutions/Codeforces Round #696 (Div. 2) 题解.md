## Codeforces Round #696 (Div. 2) 题解

### A. Puzzle From the Future

按位决策，每位先考虑填 1，与上位相同则填 0

### B. Different Divisors

* 一定是 $1,p,q,pq$
* 分别求 p,q 的 min

### C. Array Destruction

* 第一步必须拿掉最大的，不然后面就完蛋了。
* 每步操作都要干最大的。
* 枚举 x （x=a[2n]+a[?]），之后模拟即可。

### D. Cleaning

* 不考虑修改，通过高斯消元(......)，列一列可行的条件。
* 枚举修改即可。

### E. What Is It?

* 每个元素必被一个元素吃掉。x 被 y 吃，代价为 $(x-y)^2$
* 转化成最大生成树问题，打打表，挖掘一下最大生成树的 feature 即可。【迷惑行为】
* 观察 $\geq (n-1)^2$ 操作，$\geq (n-2)^2$ 最多几次操作 .........


