# 백준 G4 3584번 가장 가까운 공통 조상
# LCA 알고리즘 - 선형 탐색 사용 (이분 탐색을 활용한 풀이도 작성해 볼 것)

import sys

t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    tree = [0 for _ in range(n+1)]
    
    for _ in range(n-1):
        parent, child = map(int, sys.stdin.readline().split())
        tree[child] = parent
        
    a, b = map(int, sys.stdin.readline().split())
    parents = set()
    
    while a > 0: # a에서 root에 도달하기 위해 지나는 모든 parent node 저장
        parents.add(a)
        a = tree[a]
        
    # b에서 root에 도달하기 위해 지나는 모든 parent node 중에서
    while True: # a -> root의 경로와 일치하는 노드 중 가장 먼저 발견되는 노드 출력
        if b in parents:
            print(b); break
        
        b = tree[b]
