# 프로그래머스 Lv.3 여행경로
# Python defaultdict를 이용한 DFS(재귀)

from collections import defaultdict

answer, cities = [], defaultdict(list)

def dfs(start):        
    while cities[start]: # 탐색하지 않은 항공권이 남아있다면
        dfs(cities[start].pop(0)) # 항공권의 목적지를 새로운 출발지로 설정
        
    if not cities[start]: # 해당 도시에서 출발하는 모든 항공권을 탐색했다면
        answer.append(start) # 현재 방문중인 도시를 answer에 저장
        return
    

def solution(tickets):    
    for a, b in tickets: cities[a].append(b)
    # 도시 A에서 출발하는 항공권이 여러 개 있는 경우, 알파벳 오름차순 정렬
    for c in cities: cities[c].sort()

    dfs("ICN")
    # 도시를 사전 순으로 정렬했으므로, dfs 탐색 과정에서 앞에 있는 도시일수록 나중에 저장
    # 따라서 현재 answer 배열을 거꾸로 출력해야 정답
    return answer[::-1]
