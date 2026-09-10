# DSA Assignment #1: 概论 & Floyd-Warshall 算法

*Updated: 2026-09-09 17:49 (GMT+8)*  
*完成学生：<mark>同学的姓名、院系</mark>*



>**说明：**
>
>截止日期：前三周作业统一于 9月29日 提交至 Canvas 平台。
>
>内容要求：每个题目包含：**解题思路**（可选）、**源代码**、**Accepted 截图**、**预估耗时**（可选）。



## 1. 题目

### E27653: Fraction类

http://cs101.openjudge.cn/pctbook/E02733/

OOP, http://cs101.openjudge.cn/pctbook/E27653/

> 主要是练习面向对象编程写法，这样力扣题目，笔试都没有问题了。机考时候，不是必须OOP，能AC就可以。




代码

```cpp

#include <iostream>

using namespace std;

class Fraction {
public:
    int s;
    int m;
    Fraction (int a, int b) {
        s = a;
        m = b;
    }
    friend Fraction operator+ (Fraction lef, Fraction rig) {
        Fraction sum = Fraction(lef.s * rig.m + rig.s * lef.m, lef.m * rig.m);
        simple(sum);
        return sum;
    }
    friend ostream& operator<< (ostream& out, Fraction f) {
        out << f.s;
        if (f.m != 1) out << '/' << f.m;
        return out;
    }
private:
    static int gcd (int x, int y) {
        while (y != 0) {
            int tmp = y;
            y = x % y;
            x = tmp;
        }
        return x;
    }
    static void simple(Fraction& f) {
        int g = gcd(abs(f.s), abs(f.m));
        f.s /= g;
        f.m /= g;
    }
};

int main() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    Fraction f1 = Fraction(a1, b1);
    Fraction f2 = Fraction(a2, b2);
    cout << (f1 + f2) << endl;
}

```



代码运行截图 <mark>![alt text](<屏幕截图 2026-09-09 230208.png>)（至少包含有"Accepted"）</mark>





### E190.颠倒二进制位

bit manipulation, https://leetcode.cn/problems/reverse-bits/

思路：



代码

```cpp
class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res |= (n & 1) << (31 - i);
            n = n >> 1;
        }
        return res;
    }
};
```



代码运行截图 <mark>![alt text](image.png)（至少包含有"Accepted"）</mark>





### E1356.根据数字二进制下 1 的数目排序

bit manipulation, https://leetcode.cn/problems/sort-integers-by-the-number-of-1-bits/

思路：



代码

```cpp
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), 
        [](int a, int b){
            int aStore = a;
            int bStore = b;
            int aSum = 0;
            for (int i = 0; i < 32; i++) {
                aSum += (a & 1);
                a = a >> 1;
            }
            int bSum = 0;
            for (int i = 0; i < 32; i++) {
                bSum += (b & 1);
                b = b >> 1;
            }
            if (aSum != bSum) {
                return aSum < bSum;
            } else {
                return aStore < bStore;
            }
        });
        return arr;
    }
};

```



代码运行截图 <mark>![alt text](image-1.png)（至少包含有"Accepted"）</mark>





### M27300: 模型整理

sortings, AI, http://cs101.openjudge.cn/pctbook/M27300/

思路：



代码

```python
def cmp(s : str):
    lis = s.split('-')
    modelName = lis[0]
    num = (float)(lis[1][:-1])
    level = 1 if lis[1][-1] == 'B' else 0
    return (modelName, level, num)


n = (int)(input())
models = []
for i in range(n):
    s = input()
    models.append(s)
models.sort(key=cmp)
lastName = ''
for model in models:
    modelName, paraNum = model.split('-')
    if modelName != lastName:
        if lastName != '':
            print('')
        print(modelName + ': ', end='')
        lastName = modelName
    else:
        print(', ', end='')
    print(paraNum, end='')
```



代码运行截图 <mark>![alt text](image-2.png)（至少包含有"Accepted"）</mark>





### M1536.排布二进制网格的最少交换次数

greedy, matrix, https://leetcode.cn/problems/minimum-swaps-to-arrange-a-binary-grid/

思路：



代码

```cpp
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rightZeros(n);
        for (int i = 0; i < n; i++) {
            for(int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    rightZeros[i] += 1;
                } else {
                    break;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            bool canFind = false;
            for (int j = i; j < n; j++) {
                if (rightZeros[j] >= n - 1 - i) {
                    canFind = true;
                    res += j - i;
                    while (j != i) {
                        swap(rightZeros[j], rightZeros[j - 1]);
                        j -= 1;
                    }
                    break;
                }
            }
            if (!canFind) {
                return -1;
            }
        }
        return res; 
    }
};
```



代码运行截图 <mark>![alt text](image-3.png)（至少包含有"Accepted"）</mark>





### 05443: 兔子与樱花

http://cs101.openjudge.cn/practice/05443/

> 可以使用 **Dijkstra** 算法（或 Floyd-Warshall 算法）来求两点之间的最短路



代码1(Floyd)

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> nameToIndex;
unordered_map<int, string> indexToName;


int main() {

    int p;
    cin >> p;
    vector<vector<int>> dis(p, vector<int>(p, 100000));
    vector<vector<int>> firstNodeOnPath(p, vector<int>(p));
    for (int i = 0; i < p; i++) {
        string name;
        cin >> name;
        nameToIndex[name] = i;
        indexToName[i] = name;
        dis[i][i] = 0;
        firstNodeOnPath[i][i] = -1;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string a, b;
        int w;
        cin >> a >> b >> w;
        int aIndex = nameToIndex[a];
        int bIndex = nameToIndex[b];
        dis[aIndex][bIndex] = w;
        dis[bIndex][aIndex] = w;
        firstNodeOnPath[aIndex][bIndex] = bIndex;
        firstNodeOnPath[bIndex][aIndex] = aIndex;
    }

    for (int k = 0; k < p; k++) {
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                if (dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    firstNodeOnPath[i][j] = firstNodeOnPath[i][k];
                }
            }
        }
    }

    int r;
    cin >> r;
    while (r--) {
        string src, des;
        cin >> src >> des;
        int srcIndex = nameToIndex[src];
        int desIndex = nameToIndex[des];
        int index = srcIndex;
        while (true) {
            cout << indexToName[index];
            int tmp = index;
            index = firstNodeOnPath[index][desIndex];
            if (index == -1) break;
            cout << "->(" << dis[tmp][index] << ")->";
        }
        cout << endl;
    }
}

```

代码2(Dijkstra)

```py
import heapq
def dijkstra(graph: dict, src):
    bestDis = {u : float('inf') for u in graph.keys()}
    bestDis[src] = 0
    parent = {src : None}
    pq = [(0, src)]
    while(pq):
        curDis, curNode = heapq.heappop(pq)
        if (curDis > bestDis[curNode]):
            continue
        for connectNode, weight in graph[curNode]:
            if (curDis + weight < bestDis[connectNode]):
                bestDis[connectNode] = curDis + weight
                parent[connectNode] = curNode
                heapq.heappush(pq, (curDis + weight, connectNode))
    return parent, bestDis
def getPath(parent, bestDis, des):
    res = []
    curNode = des
    while(True):
        res.append(curNode)
        parentNode = parent[curNode]
        if parentNode == None:
            break
        res.append(bestDis[curNode] - bestDis[parentNode])
        curNode = parentNode
    res.reverse()
    return res

p = (int)(input())
graph = {}
for _ in range(p):
    name = input()
    graph[name] = []
q = (int)(input())
for _ in range(q):
    u, v, w = input().split(' ')
    graph[u].append((v, int(w)))
    graph[v].append((u, int(w)))
r = (int)(input())
for _ in range(r):
    src, des = input().split(' ')
    parent, bestDis = dijkstra(graph, src)
    path = getPath(parent, bestDis, des)
    cnt = 0
    for item in path:
        print(item, end='')
        if (item == des):
            break
        if cnt % 2 == 0:
            print("->(", end='')
        else:
            print(")->", end='')
        cnt += 1
    print('')
```


代码运行截图 <mark>![alt text](image-4.png)（至少包含有"Accepted"）</mark>





## 2. 学习总结和收获

<mark>如果作业题目简单，有否额外练习题目，比如：OJ“计概2025fall每日选做”、CF、LeetCode、洛谷等网站题目。</mark>





