## Petrozavodsk Winter Training Camp 2017 d

### Problem A. The Catcher in the Rye

* 和光按最短路折射的性质有关。
* 一个无脑的做法是三分套三分，但会 TLE，得施展黄金分割才能苟。

### Problem B. Dissertation

* LCS 问题最常见的做法是，$f[i][j]$ 表示第一个串前缀 i，第二个串前缀 j，的 LCS
* 第二个串很短。那么 $g[i][j]$ 表示第二个串的前 i 位，答案为 j，第一个串最短前缀。决策 i+1 是否在 LCS 中即可。

### Problem C. Dominoes

* n 一大就玩不出来了。
* 手画 n=1,2,3,4 即可。

### Problem D. Endgame

有向图博弈问题。

### Problem E. Evacuation

### Problem F. Factory

三分套三分

### Problem G. Grasshoppers

* n 很小的话，矩阵快速幂即可，可惜乘不得。
* 第 i+1 行是第 i 行循环右移一位。
* 矩阵乘法可以 NTT $O(nlogn)$  实现。

### Problem H. Education Nightmare

* 到 m 以后，最坏情况，还需要未访问的点中距离 m 的最远距离步。
* 那就枚举这个东西。按从大到小的顺序。
* 距离 m $> d$ 的点全都扬掉，需要走多少步呢？
* 建虚树，支持动态插点【睡觉吧】
* 把每个点到 m 路径上的点打上 tag 即可。

### Problem I. A Really Odd Sequence

签到。

### Problem J. Spoonerisms

### Problem K. A Text Problem

### Problem L. Waiter’s Problem

抓着最大的那个干。

