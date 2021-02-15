## 40th Petrozavodsk Programming Camp, Day 5: Almost Retired Dandelion Contest ICPC Training Camp: Common Contest 2, Wednesday, February 3, 2021

### Problem A. Assignment Problem

### Problem B. Lockout vs tourist

* $f(S)$ 表示 $S$ 集合的题目，最大得分。 
* 下注了，下注了，下注了，设你在问题 i 上下 $x(i)$ 比例的筹码，tourist 下 $y(i)$ 的筹码。
* 求 $min_y max_x \sum_{i∈S} x_i[y_if(S/\{i\})+(1-y_i)a_i]$，当然有 $\sum_{i∈S}x_i=\sum_{i∈S}y_i=1$
*  根据**极大极小原理**，你的上界是托姥爷的下界。[好好学一学这个玩意]
* 先请托姥爷施展，托姥爷施展完后你应该 all-in 最大的那个，托姥爷会最小化 $max_{i∈S}y_if(S/\{i\})+(1-y_i)a_i$，枚举答案大于几个 $S$ 中题目的分数后然后可以 O(1) 计算。复杂度 $O(2^n * n)$

### Problem C. Multiple?

* 输出 $\phi(n) \binom{n-1}{k-1}$ 即可。组合数分段打表一下。
* 出现次数最多的元素是 $x$ 它出现了 $y$ 次



### Problem D. Output Limit Exceeded

* n 小于 5 打表一下
* 当 $n-k+1 \leq n$
	* 若 $[n-k+1,k]$ 有两个素数，一定完蛋。
	* 否则 hungary 暴力搞一搞
* 我们可以发现 $\binom{n}{k}, \binom{n}{n-k}(k\leq \frac{n}{2})$ 是否有完美匹配结论是相同的。
	* 证明：		
		* 首先 $\binom{n}{k}$ 有完美匹配，$\binom{n}{n-k}$ 一定有。把相等的配一配就好。
		* 另一方面：$\binom{n}{k}$ 完蛋了，那么 $\binom{n}{n-k}$ 也会完蛋，若 $[1,k]$ 和 $[n-k+1,n]$ 不存在完美匹配，假设 $[1,n-k]$ 与 $[k+1,n]$ 存在完美匹配，可以调整出 $[1,k]$ 和 $[n-k+1,n]$ 的完美匹配。
		* `x-y1,y1-y2,y2-z => x-z,y1-y1,y2-y2` 设 `y1,y2` 是 $[1,k],[n-k+1,n]$ 中公有的数字。
	
### Problem E. Smol Vertex Cover

* 最小点覆盖 >= 最大匹配。

### Problem F. Thanks to MikeMirzayanov

### Problem G. Remove the Prime

* 套娃问题
* 1e6 以下的质因子筛掉 
* 大于 1e6 的 miller\_rabin
* pq 分不开的互相求 gcd 拆开

### Problem H. Excluded Min

### Problem I. Trade

* 按 p 从大到小排序，因为按这个顺序买最优。
* `f[i][j]` 表示前 i 个买 j 个，最小代价。
*  推一推式子发现 j 的上界很小。
  
### Problem J. Increasing or Decreasing

### Problem K. Rectangle Painting

### Problem L. Extreme Wealth

### Problem M. Discrete Logarithm is a Joke