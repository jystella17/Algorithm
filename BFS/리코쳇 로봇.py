# 프로그래머스 Lv.2 리코쳇 로봇
# BFS 변형 (한 칸씩 움직이는 것이 아니라, 장애물이나 벽을 만나기 전까지 이동할 수 있으므로
# 상하좌우를 탐색하는 for문 안에 다시 while문을 사용하여 이동할 수 있는 좌표까지 계속 이동해야 함)

from collections import deque

def solution(board):
    start, n, m = [0, 0], len(board), len(board[0])
    dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
    visited = [[0 for j in range(m)] for i in range(n)]
    
    for i in range(n):
        for j in range(m):
            if board[i][j] == 'R': 
                start, visited[i][j] = [i, j], 1
                break
            
    queue = deque([start])
    while queue:
        cx, cy = queue.popleft()
        if board[cx][cy] == 'G': return visited[cx][cy]-1
        
        for i in range(4):
            nx, ny = cx, cy
            
            while True:
                nx += dx[i]; ny += dy[i]
                
                if nx < 0 or nx >= n or ny < 0 or ny >= m:
                    nx -= dx[i]; ny -= dy[i]
                    break
                    
                else:
                    if board[nx][ny] == 'D':
                        nx -= dx[i]; ny -= dy[i]
                        break
                        
            if visited[nx][ny] == 0:
                visited[nx][ny] = visited[cx][cy] + 1
                queue.append([nx, ny])
            
    return -1
