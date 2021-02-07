## XVIII Open Cup named after E.V. Pankratiev. Grand Prix of Gomel

### Problem A. Aftermath

注意到 $\sum_{d|n} \frac{n}{d} = \sum_{d|n} d$，发现输出 a * b 即可。

### Problem B. Believer

* 每次贪心选择代价增量最小的方式，让答案 +1。
* 二分最优解最大代价增量。

很经典的 idea

* 由若干个栈，栈顶到栈底单增，拿 k 个元素，使得总和最小。

### Problem D. Do I Wanna Know?

* 注意到 size 为 $k$ 的支配集，有且仅有一个，因此答案等于每个 size 为 k 的集合，win 掉其它人的概率之和。
* $f_{ij}$ 表示 i 个人，选 j 个人，这 j 个人 win 掉其它人概率之和。于是可以得到一个 $O(n^2)$ 的 dp。
* 转移时枚举进来的人是编号最大的，还是编号最小的。
* $f_{i+1,j} = f_{i,j} * p^j + f_{i,j-1} * (1-p)^{i-j+1}$
* $f_{i+1,j} = f_{i,j} * (1-p)^j + f_{i,j-1} * p^{i-j+1}$
* 当 $p \neq \frac{1}{2}$ 找到了 $f_{i,j}$ 与 $f_{i,j-1}$ 的线性递推关系。
* 否则每个集合是等价的，根据概率可加性，加一加即可。

### Problem J. Joke

* Joker 打不出去。aha!

### Problem K. Kids Aren’t Alright

* 分解质因数，求每个质因子幂次
* 对于质因子 p，必须有数字出现 0 次，必须有数字出现  $p$ 在 $m$ 中出现次数次。
* 对这些限制条件容斥，枚举违反哪些限制条件，列一下式子发现可以 dp 优化
* $f[i][j][0/1]$ 表示考虑前 $i$ 个质因子，$\prod$ 为 $j$，违反了奇数 / 偶数个限制条件的方案数。
* 另外也可以观察到观察到每种质因子本质只有 3 种方案，于是可以 $O(3^{w(n)})$ 容斥


