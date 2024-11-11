---
source: https://atcoder.jp/contests/abc352/tasks/abc352_g
---

He is about to choose which socks to wear today by performing the following operation:

-   Continue to randomly draw one sock at a time from the chest, with equal probability, until he can make a pair of socks of the same color from those he has already drawn. Once a sock is drawn, it will not be returned to the chest.

Find the expected value, modulo $998244353$, of the number of times he has to draw a sock from the chest.

What does it mean to find the expected value modulo $998244353$? It can be proved that the sought expected value is always rational. Furthermore, the constraints of this problem guarantee that if the expected value is expressed as an irreducible fraction $\frac{y}{x}$, then $x$ is not divisible by $998244353$. Here, there exists a unique integer $z$ between $0$ and $998244352$, inclusive, such that $xz \equiv y \pmod{998244353}$. Find this $z$.

### Constraints

-   $1\leq N \leq 3\times 10^5$
-   $2\leq A_i \leq 3000$
-   All input values are integers.

___

### Input

The input is given from Standard Input in the following format: <br>
$N$ <br>
$A_1 \ A_2 \ ... \ A_N$ <br>

___

### Sample Input 1

```
2
2 2
```

### Sample Output 1

```
665496238
```

For example, the operation could be performed as follows:

1.  Draw a sock of color $1$ from the chest. There remains one sock of color $1$ and two socks of color $2$ in the chest.
2.  Draw a sock of color $2$ from the chest. There remains one sock each of colors $1$ and $2$ in the chest.
3.  Draw a sock of color $1$ from the chest. The socks drawn so far are two of color $1$ and one of color $2$, allowing a pair of color $1$ socks to be made, thus ending the operation.

In this example, Takahashi draws a sock from the chest three times.

The expected number of times Takahashi draws a sock from the chest is $3$ with probability $\frac{2}{3}$ and $2$ with probability $\frac{1}{3}$, so the expected value is $3\times \frac{2}{3} + 2\times \frac{1}{3} = \frac{8}{3} \equiv 665496238 \pmod {998244353}$.

___

### Sample Input 2

```
1
352
```

___

### Sample Input 3

```
6
1796 905 2768 253 2713 1448
```

### Sample Output 3

```
887165507
```
