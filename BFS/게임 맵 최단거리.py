# 프로그래머스 Lv.2 게임 맵 최단거리

from collections import deque

def solution(maps):
    answer, n, m = -1, len(maps), len(maps[0])
    dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
    
    queue = deque([[0, 0]])
    visited = [[0 for _ in range(m)] for _ in range(n)]
    visited[0][0] = 1
    
    while queue:
        cx, cy = queue.popleft()
        if cx == n-1 and cy == m-1:
            return visited[cx][cy]
        
        for i in range(4):
            nx, ny = cx + dx[i], cy + dy[i]
            
            if nx < 0 or nx >= n or ny < 0 or ny >= m: continue
                
            if maps[nx][ny] == 1 and visited[nx][ny] == 0:
                visited[nx][ny] = visited[cx][cy] + 1
                queue.append([nx, ny])
    
    return answer
