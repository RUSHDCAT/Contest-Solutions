### D.

For each prefix a[0]....a[i], we can use dp[i] to represent the longest subsequence end with a[i].

Consider a valid transition from j to i, $(j < i)$, we have `a[i] ^ j > a[j] ^ i`

Assume that the k th bit is the highest different bit. in k+1 th bit to the 30 th bit (0-indexed), a key observation is that `a[i] ^ i = a[j] ^ j` must be satisfied, which inspires us to use trie to insert `a[i] ^ i` for each i.

as for speed up the transition from j, we can enumerate the highest different bit k, and the k th bit of a[i] ^ j must be 1 to ensure a[i] ^ j > a[j] ^ i.

what we should query can be described as 

* a[j]^j have the same prefix with a[i]^i from 30 th bit to k+1 th
* the k th bit in a[j] must be 0 or 1, decided by the k th bit of i is 0 or 1.

So we can use trie to keep max dp value in each subtree.

### E.

If k exceed the number of distinct elements in a, it's easy to solve.

Otherwise, the answer <= 2.

What remains to learn is check whether the answer is 1

we can enumerate the dialog, and use two pointer to move left-up, and right-down corner and maintain the occurence of each elements and the number of elements that all appeareances are covered by the current square.

the complexity is $O(n^3)$

Another approach is enumerate the length of the square, and consider each kind of element use 2-d prefix sum to check the valid position of the square.









