# 백준 G3 18808번 스티커 붙이기
# 복잡한 조건의 시뮬레이션, 좌표 회전

import sys

n, m, k = map(int, sys.stdin.readline().split())
laptop = [[0 for _ in range(m)] for _ in range(n)]
stickers = []

def rotate(sticker):
    # 90도 회전 => row는 column으로, column은 row로
    r, c = len(sticker[0]), len(sticker)
    new_sticker = [[0 for _ in range(c)] for _ in range(r)]
    
    for i in range(r):
        for j in range(c):
            new_sticker[i][j] = sticker[c-1-j][i]
            
    return new_sticker


def check(x, y, sticker):
    r, c = len(sticker), len(sticker[0])
    
    for i in range(r):
        for j in range(c):
            # 스티커를 붙이려는 위치 중 하나라도 이미 다른 스티커가 붙어있다면 False 리턴
            if sticker[i][j] == 1 and laptop[x+i][y+j] == 1: 
                return False
                    
    # 모두 빈칸이면 스티커 붙이기
    for i in range(r):
        for j in range(c):
            if sticker[i][j] == 1:
                laptop[x+i][y+j] = 1
    
    return True


for t in range(k):
    r, c = map(int, sys.stdin.readline().split())
    tmp = [list(map(int, input().split())) for _ in range(r)]
    stickers.append(tmp)

for sticker in stickers:
    num_rotation = 0
    
    while num_rotation < 4:
        already_attached = False
        r, c = len(sticker), len(sticker[0])
        
        # 스티커를 붙이기 시작할 수 있는 모든 좌표에서 현재 스티커를 붙일 수 있는지 확인
        for x in range(n-r+1):
            for y in range(m-c+1):
                if check(x, y, sticker) == True:
                    already_attached = True; break
                
            if already_attached: break
        
        # 현재 입력받은 스티커가 부착되었다면 다음 스티커 탐색
        if already_attached: break
        
        sticker = rotate(sticker)
        num_rotation += 1

answer = 0
for i in range(n):
    for j in range(m):
        if laptop[i][j] == 1: answer += 1

print(answer)      
                
