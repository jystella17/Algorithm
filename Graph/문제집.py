# 백준 G2 1766 문제집
# 위상정렬 + 우선순위 큐 (Python heapq 사용)

import sys, heapq

n, m = map(int, sys.stdin.readline().split())
indegree = [0 for _ in range(n+1)]
problems = [[] for _ in range(n+1)]

for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    problems[a].append(b)
    indegree[b] += 1
    
answer, priority, queue = '', [], []
for i in range(1, n+1):
    if indegree[i] == 0: queue.append(i)

heapq.heapify(queue)
while queue:
    current = heapq.heappop(queue)
    priority.append(current)
    
    for prob in problems[current]:
        indegree[prob] -= 1
        if indegree[prob] == 0:
            heapq.heappush(queue, prob)
            
for p in priority: answer += (str(p) + ' ')

print(answer)
