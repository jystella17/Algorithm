# 프로그래머스 Lv.3 등대

import sys
sys.setrecursionlimit(10**6)

answer = 0
def turn_on(node, prev, road, light):
    global answer
    # leaf 노드가 아닌 경우, 부모(이미 방문한 노드) 를 제외하고 dfs 탐색
    # leaf 노드의 경우 부모 노드를 제외하면 길이가 0이므로, 탐색되지 않음
    for n in road[node]:
        if n == prev: continue
        turn_on(n, node, road, light)
        
        # dfs 탐색 이후 양쪽 끝 등대가 모두 켜지지 않은 경우 => 부모 노드 on 처리
        if light[n] == -1 and light[node] == -1:
            light[node] = 1
            answer += 1
            

def solution(n, lighthouse):
    road = [[] for _ in range(n+1)]
    light = [-1 for _ in range(n+1)] # 1 = on, -1 = off
    
    for s, e in lighthouse:
        road[s].append(e); road[e].append(s)

    # 1 ~ N번까지 각 등대를 켜야 하는지 판단
    turn_on(1, 1, road, light)
    return answer
