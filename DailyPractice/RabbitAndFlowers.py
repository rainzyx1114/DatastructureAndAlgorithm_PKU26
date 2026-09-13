import heapq
def dijkstra(graph:dict, src):
    bestDis = {u : float('inf') for u in graph.keys()}
    bestDis[src] = 0
    pq = [(0, src)]
    parent = {src : None}
    while (pq):
        curDis, curNode = heapq.heappop(pq)
        if (curDis > bestDis[curNode]):
            continue
        for nextNode, weight in graph[curNode]:
            dis = curDis + weight
            if (dis < bestDis[nextNode]):
                bestDis[nextNode] = dis
                heapq.heappush(pq, (dis, nextNode))
                parent[nextNode] = curNode
    return parent, bestDis

def getPath(parent, bestDis, des):
    res = []
    curNode = des
    while (True):
        res.append(curNode)
        curNode = parent[curNode]
        if (curNode == None):
            break
        res.append(bestDis[res[-1]] - bestDis[curNode])
    res.reverse()
    return res

graph = {}
p = (int)(input())
for _ in range(p):
    graph[input()] = []
q = (int)(input())
for _ in range(q):
    u, v, weight = input().split()
    graph[u].append((v, int(weight)))
    graph[v].append((u, int(weight)))
r = (int)(input())
for _ in range(r):
    src, des = input().split()
    parent, bestDis = dijkstra(graph, src)
    path = getPath(parent, bestDis, des)
    for item in path:
        if isinstance(item, int):
            print("->(" + str(item) + ")->", end='')
        else:
            print(item, end='')
    print('')
            
        