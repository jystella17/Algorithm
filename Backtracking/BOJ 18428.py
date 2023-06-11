# BFS + Backtracking

import sys

# 3개의 장애물을 설치하는 모든 경우의 수 => 백트래킹
def obstacle(cnt):
    global flag

    if cnt == 3:
        if bfs():
            flag = True; return
    else:
        # 모든 빈 공간에 장애물을 3개씩 설치
        for x in range(n):
            for y in range(n):
                if corridor[x][y] == "X":
                    corridor[x][y] = "O"
                    obstacle(cnt + 1)
                    corridor[x][y] = "X"

# 감시
def bfs():
    for t in teacher:
        for k in range(4):
            nx, ny = t
            
            while nx >= 0 and nx < n and ny >= 0 and ny < n:
                if corridor[nx][ny] == "O": break

                # 학생이 보이면 실패
                if corridor[nx][ny] == "S": return False

                nx += dx[k]
                ny += dy[k]
                
    return True


n = int(sys.stdin.readline())
flag = False
corridor, teacher = [], []
dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]

# 복도 정보 입력
for i in range(n):
    corridor.append(list(map(str, sys.stdin.readline().split())))
    
    for j in range(n):
        if corridor[i][j] == "T":
            teacher.append([i, j])

obstacle(0)

if flag: print("YES")
else: print("NO")
