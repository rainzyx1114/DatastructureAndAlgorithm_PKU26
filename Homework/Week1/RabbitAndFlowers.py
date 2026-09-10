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
