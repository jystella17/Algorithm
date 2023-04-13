# Codetree G3 n번째로 작은 수
# 메모리 초과 해결 필요

import sys
import math
from itertools import combinations

n, k = map(int, sys.stdin.readline().split())

# num = n if n<
count = [[1]*(k+1) for _ in range(n)]
# count2 = [[1]*(k+1) for _ in range()]
answer, length, sum_count = "1", 0, 1
# 시작점 전까지 초기화
for i in range(2, n):
    threshold = min(i, k)
    count[i][1] = i
    for j in range(2, threshold+1): 
        count[i][j] = count[i-1][j-1] + count[i-1][j]
    
    if i == threshold: count[i][threshold] = 1

# n번째로 작은 수 찾기
for i in range(k, n*k):
    arr = [i for i in range(2, i+2)]
    length = i+1
    
    if sum_count + count[i][k-1] >= n:
        # count[i][k-1] = count[i-1][k-2] + count[i-1][k-1]
        binary = list(combinations(arr, k-1))[::-1] 
        break

    else: 
        # count[i][k-1] = count[i-1][k-2] + count[i-1][k-1]
        sum_count += count[i][k-1]

for i in range(2, length+1):
    if i in binary[n-sum_count-1]: answer += '1'
    
    else: answer += '0'
 
# 예외 처리   
if k == 1:
    answer = "1"
    for i in range(n-1): answer += "0"
    
print(answer)
