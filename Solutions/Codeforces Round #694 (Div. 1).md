## Codeforces Round #694 (Div. 1)

取得了 🐩。

### A. Strange Birthday Party

* 注意到送出去的礼物一定是一个前缀，否则不优。
* 一定把礼物送给人的后缀。
* 枚举送出去的礼物前缀的长度即可。

### B. Strange Definition

* 我们只 care 质因子的奇偶性。
* $f(x)$ 表示 $x$ 中出现次数为奇数次的质因子乘积。
* 一些简单的分类讨论。

### C. Strange Shuffle

* 打表可以发现一些性质。例如🐔的右边会大于 k，🐔的左边的一些人会小于 k。
* 找到一个大于 k 的，往左边二分，可以找到 🐔。

### D. Strange Housing

* 又是考虑BFS生成树，DFS生成树，提出了复杂得死的做法...... 一看过了一万个人，觉得自己一定是写麻烦了，尝试了一打
* 这类问题和 prim，dij 这种不断迭代扩充点集的做法是很类似的，最近见过的一个类似的问题是 [here](https://codeforc.es/gym/102893/problem/K)，好吧其实也不是很类似。
* 点染成黑色表示被选择了，白色表示没被选择，我们需要给每个点决定是黑色还是白色。
* 随便选一个点染成黑色，然后把邻居染成白色，每次在未被染色的点中选出一个与白色点相邻的点，染成黑色，然后把它未被染色的邻居染成白色【防止被别人搞，所以不会有两个黑色的点相邻】
* 联通性可以归纳地证明，

### E. Strange Permutation




## Codeforces Round #695 (Div. 2)
 
A 题先 WA 几发，C 每怎么想明白在乱猜，E 题 case 没想清楚，写歪了，对拍拍死自己好多次才救回来。

### A. Wizard of Orz

一定是 `x+2,x+1,x,x+1,x+2,.....` 的形式

`98901234.......`

### B. Hills And Valleys

* 考虑到改一个位置，至多影响 3 个位置，枚举改哪个位置，以及改成啥。
* 改成啥考虑少数几个关键值即可。

### C. Three Bags

* 合并的过程相当于一颗树。
* 偶数层数的点贡献为负。
* 合法必须满足：
	* 至少有两个包里的有点，在偶数层。
	* 一个包里所有点躺在偶数层。
* 假设不然，一个包里部分点躺在偶数层，那剩下的点，躺在奇数层，那 How is there's daddy ? 

### D. Sum of Paths

* $f[i][x]$ 值为 i，walk x 步方案数。$O(n^2)$
* 考虑位置 i 作为路径第 j 项贡献即可。

### E. Distinctive Roots in a Tree

* 独立考虑每种数字。
* 充要条件：不能有 3 个点共路径。
* 考虑每种数字，枚举每个点，看看有没有作为 3 连🐔的中间的那个点。
* 有如下两种  case
	* 其它两个点都在其子树内。
	* 其它两个点：一内一外	 
* 数子树内有没有点，施展 DFS 序，用 BIT 很好维护。


 

## Atcoder Regular Contest 111

### A - Simple Math 2

$[\frac{a}{b}]\%c$ 的式子，对 $a$ 减去 $b*c$ 不影响结果。

### B - Reversible Cards

考虑每个连通块点边关系。树的话，是点数-1，否则是点数。

### C - Too Heavy

* 答案的下界是 $\sum |环长|-1$
* 如果存在 $i$ 使得 $b[p[i]] \geq a[i]$ 且 $p[i] \neq i$ 完蛋了。
* 否则每个环有个巨大的 $a[i]$ 拿它把环解体了即可。

### D - Orientation

* 权值大的点指向权值小的点，否则矛盾。
* 权值相等的点，给边定向后，这两个点必须处于同一个 SCC 中
* DFS 生成树搞一下，证明没想清楚。

### E - Simple Math 3

* 问的是有多少个 $i$ 使得 $[\frac{a+ci}{d}] = [\frac{a+bi-1}{d}]$
* 当 $(a+ci) - (a+bi-1)\leq d$ 时
	* $[\frac{a+ci}{d}] - [\frac{a+bi-1}{d}] \leq 1$
	* 答案一定在这些 i 里面。
* 类欧即可。
 
### F - Do you like query problems

* 期望可加。
* 一个数字被区间框住后，$\frac{m}{2m+1}$ 的概率，变成 $[0,m)$ 随机数，其它不动。
* 那么动一次和动多次没区别。
* 推一推，非常明确。
* 比赛在推成🐔了 => $\frac{m-1}{2m+1}$ 的概率，变成 $[0,m)$ 中不等于自身的随机数。然后没得彻底。










