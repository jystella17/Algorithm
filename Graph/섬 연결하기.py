# 프로그래머스 Lv.3 섬 연결하기
# n log n & 모든 정점을 연결하는 최단 경로(= 최소 비용) => Kruskal
def find(x, parent):
    if parent[x] != x:
        parent[x] = find(parent[x], parent)
    
    return parent[x]


def union(x, y, parent):
    x, y = find(x, parent), find(y, parent)
    
    if x < y:
        parent[y] = x
    else:
        parent[x] = y


def solution(n, costs):
    answer, parent = 0, [0] * (n+1)
    for i in range(1, n+1):
        parent[i] = i;
    
    # 건설 비용이 적은 다리부터 정렬
    costs.sort(key = lambda x: x[2])
    
    # 다리 정보 (연결된 다리와 비용)을 하나씩 확인하면서 MST를 구성하는지 확인
    for c in costs:
        x, y, cost = c
        
        # 부모 노드가 다르다면 두 섬을 연결했을 때 사이클이 발생하지 않음
        if find(x, parent) != find(y, parent):
            union(x, y, parent) # 두 섬 연결
            answer += cost # 건설 비용 합산
    
    return answer
