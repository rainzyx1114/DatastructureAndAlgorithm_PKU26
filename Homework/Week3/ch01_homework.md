# 第一章作业

## 1

填空题：

1. $\sum_{i=1}^{n} \frac{1}{i} = \Theta(\underline{\log n})$。
2. $\log(n!) = \Theta(\underline{n \log n})$。
3. $f(n) = \Omega(g(n))$ 且 $f(n) = O(g(n))$ 等价于 $f(n) = \underline{\Theta}(g(n))$。
4. $2026^n = \underline{\Omega}(2025^n)$。（填写 $O$, $\Omega$ 或 $\Theta$）

## 2

```cpp
int cnt = 0;
int i = 1;
while (i <= n) {
    int j = i;
    while (j <= n) {
        cnt++;
        j *= 2;
    }
    i++;
}
```

分析程序，求出程序的时间复杂度（大 $O$ 表示，**给出推导过程**）。

解：只考虑最主要的操作cnt++，总的操作次数为$\sum_{i=1}^{n} (\lfloor \log(\frac{n}{i}) \rfloor + 1) = \sum_{k=1}^{\lfloor \log n \rfloor} \lfloor \frac{n}{2^k} \rfloor + n \le \frac{n}{2} + \frac{n}{4} + ... + n = 2n$，所以时间复杂度为$O(n)$


## 3

求解下列递推式的 $\Theta$ 表示。

1. $T(n) = n^5 \times 3^n + 4^n$。
2. $T(n) = T(n - 1) + \Theta(n)$。
3. $T(n) = T(\lfloor n/2 \rfloor) + \Theta(1)$。
4. $T(n) = T(n - 1) + \Theta(\log n)$。

解：
1. 注意到 $4^n \le T(n) \le 2 \cdot 4^n$ （当n充分大时），从而$T(n) = \Theta(4^n)$
2. 只考虑一边，反复展开就得到 $T(n) \le T(0) + c \sum_{i=1}^{n} i \implies T(n) = O(n^2)$；另一侧同理有：$T(n) = \Omega(n^2)$。综上得到$T(n) = \Theta(n^2)$
3. 展开不难得到 $T(n) = \Theta(\lfloor \log n \rfloor)$，这等价于说$T(n) = \Theta(\log n)$
4. 同2/3反复展开：$T(n) = \Theta(\sum_{i=1}^{n} \log i) \iff T(n) = \Theta(n \log n)$

## 4

1. 证明对任意正实数 $a$ 和 $b$，$a^n = O(b^n)$ 当且仅当 $a \le b$。
2. 给定 $T(1) = 1$ 和 $T(n) = 2T(\lfloor n/2 \rfloor) + n$，证明 $T(n) = O(n \log n)$。（提示：考虑数学归纳法）

证明：
1. $a^n = O(b^n) \iff a^n \le c \cdot b^n$（$c$为常数）
注意a, b都是正实数，从而 $a^n \le c \cdot b^n \iff (\frac{a}{b})^n \le c$
而$(\frac{a}{b})^n \le c$对任意n成立当且仅当$\frac{a}{b} \le 1$，这等价于$a \le b$
故命题得证
2. 使用数学归纳法
取一个充分大的常数c，得到$T(2) = 4 \le c \cdot 2 \log 2$，$T(3) = 5 \le c \cdot 3 \log 3$，base case成立
下面假设命题对 $\le k - 1$的情况都成立，下面证$k$情况也成立 （ $k \ge 4$）：
$T(k) = 2T(\lfloor \frac{k}{2} \rfloor) + k \le 2 \cdot c \lfloor \frac{k}{2} \rfloor \log \lfloor \frac{k}{2} \rfloor + k = c \cdot k \log k + k \le c'k \log k \implies T(k) = O(k \log k)$
故命题得证
