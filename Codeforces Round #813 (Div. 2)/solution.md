## Solutions

### A.

The answer is the number of $i$ such that $1 \leq i \leq k$ and $p_i > k$

### B. 

just implement a brute force solution

### C.

we can enumerate the length of all-zero prefix.

Assume that $a[1],a[2]....a[i]$ is zero
 
* $\{a[i+1]....a[n]\}$ has no intersection with ${a[1],a[2]....a[i]}$
* $a[i+1]\leq....\leq a[n]$
must be satisfied

Another approach is when there exist some $i$ such that $a[i] > a[i+1]$, we can make operation.
We can just maintain the set of bad indices. This is a more explict idea.

### D.

We can make an observation that the diameter is $min(2*min(a_1,....,a_n), Max_{i=1}^{n-1} min(a_i, a_{i+1}))$

### E.

We can consider the number of "bad" triples $lcm(i,j,k) < i+j+k$

since $lcm(i,j,k)<i+j+k<3k$, we can find $lcm(i,j,k)=k\ or\ lcm(i,j,k)=2k$

we can enumerate i, k. since $2k \% i = 0$, count of valid pairs is $O(nlogn)$

we can define the number of $j$ such that $(i,j,k)$ is a bad tripple as the weight of segment $[i,k]$

this can be precaclulated by two-pointer trick. Then we can solve queires offline by segment-Tree
