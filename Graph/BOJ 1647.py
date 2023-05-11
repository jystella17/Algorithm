# 백준 G4 도시 분할 계획
# 최소 스패닝 트리 (MST) => 데이터의 특성상 Prim 알고리즘이 더 적합해보이지만, 
# 하나의 마을을 두 개의 집합으로 분리해야 하는 문제이므로 Kruskal 알고리즘을 사용하여 풀이

import sys

n, m = map(int, sys.stdin.readline().split())
parent, town = [i for i in range(n+1)], []

def find_parent(x):
    if x != parent[x]:
        parent[x] = find_parent(parent[x])
        
    return parent[x]


def union(a, b):
    rootA, rootB = find_parent(a), find_parent(b)
    
    if rootA < rootB: parent[rootB] = rootA
    else: parent[rootA] = rootB


for i in range(m):
    a, b, cost = map(int, sys.stdin.readline().split())
    town.append([a, b, cost])

town.sort(key=lambda x: x[2])
answer, div = 0, 0
# 마을 전체를 하나의 집합으로 연결
# Kruskal 알고리즘
for road in town:
    a, b, cost = road
    if find_parent(a) != find_parent(b):
        union(a, b)
        answer += cost
        div = cost

# 유지비가 가장 큰 길 하나를 끊어서 길 유지비 합의 최솟값을 만들 수 있음
# 마을을 2개의 집합으로 분할하는 것을 구현할 필요는 없고, 연결된 길들 중 유지비가 가장 큰 길의 유지비만 빼준다.
print(answer-div)
