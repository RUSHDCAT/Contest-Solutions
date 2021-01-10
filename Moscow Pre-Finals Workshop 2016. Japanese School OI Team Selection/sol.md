## Moscow Pre-Finals Workshop 2016. Japanese School OI Team Selection.

### Problem A. Matryoshka

* 迪尔沃思，转成 LIS 问题

### Problem C. Employment

* 连通块个数 = 点数 - 边数
* 点表示 $a[i]\geq x$ 的元素个数，边数表示 $max(a[i],a[i+1]) \geq x$
* [强化一百倍后 => CF 1392I](https://codeforces.com/problemset/problem/1392/I)


### Problem D. Sandwich

* 不妨设我们要扬掉格子 G，不妨设 G 是 N 类型，不妨设我们先扬右上角的 pizza P。
* 那么上面和右边格子的 4 块一定要先扬掉的。考虑上方的格子的两块 pizza，和 P 粘起来的一定是后扬的。为什么呢？因为和 P 沾起来了。
* 根据依赖关系建图求后继/前驱数即可
* TLE ？观察注意到一行横向的边连接有什么特点。

### Problem E. Toilets

* 合法的序列等价于任意后缀，男性 - 女性 <= 1
* 找到被跨越次数最多的女性。

### Problem F. Sushi
w
### Problem G. Telegraph

* 等价于拆成一些链，每个点被至少一条链包含，最大化边权和。
* 考虑树怎么做：每个点贪心选择最多的儿子保留。
* 如果整个环都被留下来，枚举一条环上边切开即可。
* 比赛施展沙雕 dp 去了，跟狗一样


### Problem H. Dangerous Skating

* 4 联通格子连权值为 2 的边。 
* 每个格子向上下左右到达格子连权值为 1 的边。


### Problem I. Worst Reporter 2

* score 小的可以匹配 sore 大的。
* 尽量匹配 type 相同的。
* 把配上的人扬了，剩下的 3h 当 +1， 5h 当 -1，任何前缀和必须非负。
* 匹配 type 相同 score 为 x，y 两人，相当于对 [x,y) 区间 -1
* 存在最优解区间不交，否则可以不断调整。
* 相同 type 的构造括号序列。取出每对匹配上的括号，按右端点升序，左端点降序排序。贪心地拿。



