# 프로그래머스 Lv.3 아이템 줍기
# 좌표계 변환 (예외 케이스 찾기 => 각 좌표 * 2)
# 좌표계 전체를 2배 하더라도, 테두리 부분은 중간에 끊기지 않고 단순히 크기만 2배가 됨

from collections import deque

def solution(rectangle, characterX, characterY, itemX, itemY):
    answer = 0
    maximum = (max(map(max, rectangle)) + 1) * 2
    land = [[-1 for _ in range(maximum)] for _ in range(maximum)]
    
    for rec in rectangle:
        lx, ly, rx, ry = map(lambda x: x*2, rec)
        
        for i in range(lx, rx+1):
            for j in range(ly, ry+1):
                if (i == lx or i == rx) or (j == ly or j == ry):
                    if land[i][j] != 0: land[i][j] = 1
                    
                else: land[i][j] = 0
                
    queue = deque([[characterX*2, characterY*2]])
    dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
    visited = [[1 for _ in range(maximum)] for _ in range(maximum)]
    visited[characterX*2][characterY*2] = 0

    while queue:
        cx, cy = queue.popleft()
        
        if cx == itemX*2 and cy == itemY*2:
            answer = visited[cx][cy] // 2
            break
            
        for i in range(4):
            nx, ny = cx + dx[i], cy + dy[i]
            
            # 다음 좌표가 테두리 부분에 해당하고, 아직 방문되지 않았다면
            if land[nx][ny] == 1 and visited[nx][ny] == 1:
                visited[nx][ny] = visited[cx][cy] + 1
                queue.append([nx, ny])
                
    return answer
