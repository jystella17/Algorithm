# 프로그래머스 Lv.3 기둥과 보 설치
# 2020 카카오 신입공채 1차 5번

map = [[[0 for k in range(2)] for j in range(101)] for i in range(101)]

def frame_build(x, y, frameType, n):
    if frameType == 0: # 기둥 설치
        if y == 0: # 바닥 위에 있을 때
            return True
        
        if y<n and map[x][y][1]: # 설치할 기둥의 왼쪽 아래에 보가 있을 때
            return True
        
        if x>0 and map[x-1][y][1]: # 설치할 기둥의 오른쪽 아래에 보가 있을 때
            return True
        
        if y>0 and map[x][y-1][0]: # 설치할 기둥의 아래에 다른 기둥이 있을 때
            return True
    
    else: # 보 설치
        if y>0 and map[x][y-1][0]: # 설치할 보의 왼쪽 아래에 기둥이 있을 때
            return True
        
        if x<n and y>0 and map[x+1][y-1][0]: # 설치할 보의 오른쪽 아래에 기둥이 있을 때
            return True
        
        if x>0 and x<n and map[x-1][y][1] and map[x+1][y][1]: # 설치할 보의 양쪽에 모두 보가 있을 때
            return True
    
    return False


def frame_remove(x, y, frameType, n):
    map[x][y][frameType] = 0
    
    if frameType == 0: # 기둥 삭제
        # 삭제할 기둥의 위에 다른 기둥이 있고 & 위에 보가 없는 경우
        if y<n and map[x][y+1][0] and frame_build(x, y+1, 0, n) == False: 
            return False
        
        # 삭제할 기둥의 위에 보의 왼쪽이 있고 & 해당 보의 아래에 기둥이 없는 경우
        if y<n and map[x][y+1][1] and frame_build(x, y+1, 1, n) == False:
            return False
        
        # 삭제할 기둥의 위에 보의 오른쪽이 있고 & 해당 보의 아래에 기둥이 없는 경우
        if x>0 and y<n and map[x-1][y+1][1] and frame_build(x-1, y+1, 1, n) == False:
            return False
        
    else: # 보 삭제        
        # 삭제할 보의 왼쪽 위에 기둥이 있고 & 해당 기둥 아래에 다른 기둥이 없는 경우
        if map[x][y][0] and frame_build(x, y, 0, n) == False:
            return False
        
        # 삭제할 보의 오른쪽 위에 기둥이 있고 & 해당 기둥 아래에 다른 기둥이 없는 경우
        if x<n and map[x+1][y][0] and frame_build(x+1, y, 0, n) == False:
            return False
        
        # 삭제할 보의 왼쪽에 다른 보가 있고 & 해당 보의 아래에 기둥이 없고 다른 보와도 연결되지 않은 경우
        if x>0 and map[x-1][y][1] and frame_build(x-1, y, 1, n) == False:
            return False
        
        # 삭제할 보의 오른쪽에 다른 보가 있고 & 해당 보의 아래에 기둥이 없고 다른 보와도 연결되지 않은 경우
        if x<n and map[x+1][y][1] and frame_build(x+1, y, 1, n) == False:
            return False
    
    return True


def solution(n, build_frame):
    answer = []
    
    for frame in build_frame:
        x = frame[0];
        y = frame[1];
        a = frame[2];
        b = frame[3];
        
        if b == 1: # 구조물 설치
            if frame_build(x, y, a, n): # 해당 구조물을 설치할 수 있다면
                map[x][y][a] = 1
                answer.append([x, y, a])

        else: # b == 0, 구조물 삭제
            if frame_remove(x, y, a, n): # 해당 구조물을 삭제할 수 있다면
                answer.remove([x, y, a])
            
            else: # 해당 구조물을 삭제할 수 없다면
                map[x][y][a] = 1 # 원상복구
    
    answer.sort()
    return answer
