# 백준 G4 뱀
# Python Deque + Simulation

import sys
from collections import deque

n = int(sys.stdin.readline())
k = int(sys.stdin.readline())
snake = deque()
command = []

# 동=1, 북=2, 서=3, 남=4
directions = [(0, 1), (-1, 0), (0, -1), (1, 0)]
snake_dir = 1
board = [[0 for j in range(n+1)] for i in range(n+1)]

def change_dir(direction, snake_dir):
    if direction == 'L':
        if snake_dir != 3:
            snake_dir = (snake_dir + 1) % 4
        else:
            snake_dir = 4
    
    else:
        if snake_dir != 1:
            snake_dir = snake_dir - 1
        else:
            snake_dir = 4
            
    return snake_dir

for i in range(k):
    x, y = map(int, sys.stdin.readline().split())
    board[x][y] = 1
    
l = int(sys.stdin.readline())
for i in range(l):
    x, c = sys.stdin.readline().split()
    command.append((int(x), c))

snake.append((1, 1))
clock = 1; stop = False
head_x, head_y = 1, 1

for cmd in command:
    second, direction = cmd[0], cmd[1]
    for _ in range(clock, second+1):
        # 이동해야 하는 위치 좌표
        nx = head_x + directions[snake_dir-1][0]
        ny = head_y + directions[snake_dir-1][1]
        
        # 이동해야 하는 위치가 벽이거나 자신의 몸인 경우
        if nx <= 0 or nx > n or ny <= 0 or ny > n or (nx, ny) in snake:
            stop = True
            break
        
        # 이동해야 하는 위치에 사과가 있는 경우
        if board[nx][ny] == 1:
            board[nx][ny] = 0
            snake.append((nx, ny))
            
        else:
            snake.append((nx, ny))
            snake.popleft()
        
        clock += 1
        head_x, head_y = nx, ny
     
    if stop == True: break
    # 더 이동할 수 있는 경우 방향 전환
    snake_dir = change_dir(direction, snake_dir)

# 마지막 명령어를 수행한 이후에도 뱀이 계속 이동할 수 있는 경우
while stop == False:
    nx = head_x + directions[snake_dir-1][0]
    ny = head_y + directions[snake_dir-1][1]
    
    if nx <= 0 or nx > n or ny <= 0 or ny > n or (nx, ny) in snake: break
    
    if board[nx][ny] == 1:
        board[nx][ny] = 0
        snake.append((nx, ny))
            
    else:
        snake.append((nx, ny))
        snake.popleft()
    
    clock += 1
    head_x, head_y = nx, ny

print(clock)
