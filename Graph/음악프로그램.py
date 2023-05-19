# 백준 G3 2623번 음악프로그램
# 위상정렬

import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
indegree = [0 for _ in range(n+1)]
singers = [[] for _ in range(n+1)]

for i in range(m):
    pd = list(sys.stdin.readline().split())
    pd = [int(x) for x in pd]
    
    for x in range(1, pd[0]):
        for y in range(x+1, pd[0]+1):
            singers[pd[x]].append(pd[y])
            indegree[pd[y]] += 1


program, queue = [], deque()
for i in range(1, n+1):
    if indegree[i] == 0: queue.append(i)

while queue:
    current = queue.popleft()
    program.append(current)
    
    for singer in singers[current]:
        indegree[singer] -= 1
        if indegree[singer] == 0:
            queue.append(singer)

if len(program) != n: print(0)        
for p in program: print(p)
