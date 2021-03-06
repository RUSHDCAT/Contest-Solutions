## Educational Codeforces Round 67 (Rated for Div. 2)

### A. Stickers and Toys

**做法** 鸽巢原理咕咕咕。

### B. Letters Shop

**做法** 对串 $s$ 预处理，字母 $c$，第 $i$ 次出现的位置。



### C. Vasya And Array

**做法** 以如下方式进行构造

令 $a=\{n,n-1,.....,2,1\}$

不降的有交的区间可以取并，取并后我们得到了若干个不交的不降区间，对 a 序列中的这些区间排序。

若一个长度为 2 的区间，不是以上某个区间的子区间，那么肯定不降。

### D. Subarray Sorting

**做法** 若 $a[i]>a[i+1]$ 那么可以交换 $a[i],a[i+1]$

类似于冒泡排序，第 i 趟冒泡，使得 $a[i] = b[i]$，贪心地在 $a[i]~a[n]$ 中选出位置最靠前的值等于 $b[i]$ 的元素，设它的位置为 $pos$，若 $a[pos]$ 小于 $a[i]$~$a[pos-1]$ 中的所有元素，那么这一趟可以成功，否则不合法。 

### E. Tree Painting

**做法** 确定下第一个被染色的点 $rt$ 后，无论接下来染色方案如何，$u$ 点会被统计 $dis(rt,u)+1$ 次。

因此 $max_{i=1}^{n} \sum_{j}^{n} dis(i,j)+1$ 即为答案。

经典的两次 DFS（父亲更新儿子，儿子更新父亲） 可求。

### F. Expected Square Beauty

**做法**

*$E(X)$ 怎么求？*

```
for each {a}:
	for i from 1 to n:
		if a[i] != a[i-1]:
			ans++
```

交换求和次序，我们可以考虑每个位置作为一个区间的右端点对答案的贡献。

设 $P(i)$ 表示 $i$ 作为右端点的概率，即 $P(i)=P(a[i]\neq a[i-1])$,有 $E(X)=\sum_{i=1}^{n} P(i)$ 

*$E(X^2)$ 怎么求？*

定义 $P(i,j)$ 表示，$P(a[i] \neq a[i-1] 且 a[j]\neq a[j-1])$

$E(X^2)=\sum_{i=1}^{n}\sum_{j=1}^{n}P(i,j)$

当 $|i-j|>1$ 因为 $P(i),P(j)$ 无关，有$P(i,j)=P(i)P(j)$

因此 

$E(X^2) = [\sum_{i=1}^{n}P(i)]^2+[\sum_{i=1}^{n}P(i,i)+ \sum_{i=1}^{n-1}P(i,i+1)]-[\sum_{i=1}^{n}P(i)^2+2\sum_{i=1}^{n-1}P(i)P(i+1)]$

上式中 $P(i),P(i,i),P(i,i+1)$ 都可以 $O(1)$ 计算。


### G. Gang Up

口胡：本质上，相当于人的编号 向 有序对 $(t,e)$ 的一个匹配。

其中 $t$ 表示，到达 1 的时间，$e$ 表示，经过的最后一条边。

开始画魔法阵。

* 源点向每个人连流量为 1，费用为 0 的边。
* 每个人向 $(t,e)$ 连，流量为 1，费用为 $ct$ 的边。
* 每个 $(t,e)$，向汇点，连 $n$ 条边，第 $i$  条边，流量为 1，费用为 $2i-1$。

之后，吟唱最大费用最大流。

然后....... 读错题了。

**做法** 用有序对 $(u,t)$ 表示一个节点。表示第 $t$ 秒在点 $u$ 的状态。

考虑建图

* 源点 S，向 $(a_i,0)$ 连，流量为 1，费用为 0 的边。
* $(u,t)$ 向 $(u,t+1)$ 连流量为 $k$，费用为 0 的边。
* 对于原图的边 $u,v$，$(u,t)$ 向 $(v,t+1)$ 连 $k$ 条边，第 $i$ 条流量为 $1$，费用为 $(2i-1)d$。（$\sum_{i=1}^{x} (2i-1) = x^2$）
* $(1,t)$ 向汇点 T 连，流量为 $k$，费用为 $tc$ 的边。

最小费用最大流即可。















