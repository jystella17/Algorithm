# 백준 G5 ABCDE
# DFS + 백트래킹 기본 문제

import sys

sys.setrecursionlimit(10**4)
n, m = map(int, sys.stdin.readline().split())
friends, visited, answer = {i: [] for i in range(n)}, [], 0

def is_connected(start, cnt, val):
    global answer
    if cnt == 5: 
        answer = 1; return
    
    visited[start] = True
    for friend in friends[start]:
        if visited[friend] == False:
            visited[friend] = True
            is_connected(friend, cnt+1, val)
            visited[friend] = False


for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    friends[a].append(b); friends[b].append(a)

empty = 0
for i in range(n):
    if len(friends[i]) == 0: empty += 1

if (n - empty) < 5: answer = 0
else:
    for start in friends:
        visited = [False for i in range(n)]
        is_connected(start, 1, False)
        
        if answer == 1: break

print(answer)
