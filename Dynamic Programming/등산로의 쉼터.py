# Codetree G4 등산로의 쉼터
# 정렬 + DP

import sys

n, m = map(int, sys.stdin.readline().split())
height = list(map(int, sys.stdin.readline().split()))
shelter_height = {i+1: height[i] for i in range(n)} # 각 쉼터별 높이 저장
hiking = [[] for i in range(n+1)] # 각 쉽터에 연결된 등산로 정보 (더 높은 곳에 있는 쉼터 x에 낮은 곳에 있는 쉼터 y가 연결됨)

for i in range(m):
    start, end = map(int, sys.stdin.readline().split())
    if shelter_height[start] > shelter_height[end]:
        hiking[start].append(end)
    else:
        hiking[end].append(start)

# 각 쉼터별 높이를 역순으로 정렬
shelter_height = dict(sorted(shelter_height.items(), key=lambda x: x[1], reverse=True))
dp = [1 for i in range(n+1)] # i번째 쉼터에서 출발했을 때 방문할 수 있는 쉼터의 최대 개수

for shelter, height in shelter_height.items():
    # 현재 쉼터에서 출발했을 때 방문할 수 있는 쉼터 탐색
    for road in hiking[shelter]:
        if height != shelter_height[road]:
            dp[road] = max(dp[shelter]+1, dp[road])
        
for i in range(1, len(dp)): print(dp[i])
