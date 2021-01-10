## E. No Game No Life

* sg 值小于 $\sqrt n$
* $p(i)$ 表示当前 xor 值为 i，alice 获胜的概率
* Gauss 一下，$O(n^{3/2})$

FWT 做法

* $p(i)$ 表示施展 i 步后的生成函数，$k$ 次项，表示走 i 步后在 $k$ 的概率。
* $p(i)=(\frac{c}{n+1})^i,p(0)=1$，这里乘法定义成异或卷积，$c_i$ 为 sg 值 i 出现次数。
* Alice 失败的概率为 $H = \frac{1}{n+1}\sum_{i=0}^{+}(\frac{c}{n+1})^i$ 常数项。
* $FWT(H)$ 第 $i$ 项为 $\frac{1}{n+1}\sum_{i=0}^{+}(\frac{[x]FWT(c)}{n+1})^i=\frac{1}{n+1}\frac{1}{1-\frac{[x]FWT(c)}{n+1}}$
* $H = IFWT(FWT(H))$ 
* 复杂度为 $O(2^{logn}n) = O(nlogn)$

