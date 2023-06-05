# 백준 G3 17182번 우주탐사선
# Floyd-Warshall + Backtracking

import sys

n, k = map(int, sys.stdin.readline().split())
planets = [[-1 for j in range(n)] for i in range(n)]
visited, answer = [False for i in range(n)], 100000

def exploration(start, cnt, cost):
    global answer
    
    if cnt == n:
        answer = min(answer, cost)
        return
    
    for next in range(n):
        if not visited[next]:
            visited[next] = True
            exploration(next, cnt+1, cost+planets[start][next])
            visited[next] = False
        

for i in range(n):
    planets[i] = list(map(int, sys.stdin.readline().split()))
    
# Floyd-Warshall로 각 행성 간 이동에 걸리는 시간의 최소값 구하기
for l in range(n):
    for i in range(n):
        for j in range(n):
            planets[i][j] = min(planets[i][j], planets[i][l] + planets[l][j])

# planets 배열에 저장된 시간이 최소값임이 보장되므로, 행성 개수(=n)만큼의 depth로 재귀탐색
visited[k] = True
exploration(k, 1, 0)
print(answer)
