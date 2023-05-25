# 백준 G4 2665번 미로만들기
# Python deque를 활용한 0-1 BFS

import sys
from collections import deque

n, rooms = int(sys.stdin.readline()), list()
change = [[10000 for j in range(n)] for i in range(n)]
dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]

for i in range(n):
    row = list(sys.stdin.readline()[:n])
    row = [eval(i) for i in row]
    rooms.append(row)

queue, change[0][0] = deque([(0, 0)]), 0
while queue:
    cx, cy = queue.popleft()
    if cx == n and cy == n: break
    
    for i in range(4):
        nx, ny = cx+dx[i], cy+dy[i]
        
        if nx < 0 or nx >= n or ny < 0 or ny >= n: continue
        
        # 다음 방이 흰 방인 경우 queue의 앞쪽에 다음 방 추가, 방 변경 횟수는 그대로
        elif rooms[nx][ny] == 1 and change[nx][ny] == 10000: 
            queue.appendleft((nx, ny))
            change[nx][ny] = change[cx][cy]
        
        # 다음 방이 검은 방인 경우, 방의 색을 바꿔야 하는지 판정
        # 방의 색을 바꿔야 하는 경우, queue의 뒤쪽에 다음 방을 추가
        elif rooms[nx][ny] == 0:
            # 방을 더 적게 변경하는 방법이 있는 경우
            if change[nx][ny] > change[cx][cy] + 1: 
                queue.append((nx, ny))
                change[nx][ny] = change[cx][cy] + 1
                
print(change[n-1][n-1])
