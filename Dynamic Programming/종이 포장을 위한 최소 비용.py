# Codetree G2 종이 포장을 위한 최소 비용
# Test Case 2부터 수정 필요

import sys

def next_stone(box, m, current):
    for i in range(current, m+1):
        if box[i] == 1: return i
        
    return 0


n, m = map(int, sys.stdin.readline().split())
box = [0 for i in range(0, m+2)] # box[i] = 1이면 해당 박스에 돌이 들어있음
box[m+1] = 1
for i in range(n):
    index = int(sys.stdin.readline())
    box[index] = 1
    
price = [int(sys.stdin.readline()) for i in range(m)]
min_cost = [0 for i in range(m+1)] # 1번부터 각 박스를 탐색할 때 최소 비용 저장
paper_start, answer = 1, 0

for i in range(1, m+1):
    # 종이를 덮을 필요 없는 박스이면 탐색하지 않고 패스
    if box[i] == 0 and (box[i-1] == 0 or box[i+1] == 0):
        spot = next_stone(box, m, i)
        
        if (price[i - paper_start] < min_cost[i-1] + price[0]) and min_cost[i-1] != 0:
            min_cost[i] = price[i - paper_start]
        
        else:
            if (i != m) and (spot != 0):
               if price[spot - i] < price[spot - i - 1]:
                   paper_start = i
                   min_cost[i] = 
            
            else:
                if min_cost[i-1] != 0: answer += min_cost[i-1]
                paper_start = i+1
                continue
    
    # 현재 사용중인 종이로 현재 박스까지 덮을 때의 비용이 더 저렴하면
    if price[i - paper_start] < min_cost[i-1] + price[0]:
        min_cost[i] = price[i - paper_start]
    
    # 이전 박스까지만 현재 사용중인 종이로 덮고, 현재 박스부터 새로운 종이로 덮을 때의 비용이 더 저렴하면   
    else:
        min_cost[i] += min_cost[i-1] + price[0]
        paper_start = i
        
    if i == m: answer += min_cost[i]

print(min_cost)
print(answer)
