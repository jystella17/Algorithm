# Codetree G5 일렬로 서있는 소
# 완전탐색 + Two Pointer (투포인터 활용한 풀이 다시 짜보기)

import sys

n = int(sys.stdin.readline())
cow = sorted([int(sys.stdin.readline()) for i in range(n)])
length, answer = len(cow), 0

def is_line(x, y, y_idx):
    global answer
    
    for i in range(y_idx+1, length):
        if (3*y - 2*x) >= cow[i] and (2*y - x) <= cow[i]:
            answer += 1
            
        elif cow[i] < (3*y - 2*x): continue
        else: return # 최대 범위를 넘어가는 경우 함수 종료


for i in range(length-2):
    for j in range(i+1, length-1):
        is_line(cow[i], cow[j], j)

print(answer)
