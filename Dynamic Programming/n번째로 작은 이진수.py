# Codetree G3 n번째로 작은 이진수
# 재귀 활용

# Codetree G3 n번째로 작은 이진수
# 재귀 활용

import sys
from itertools import combinations

n, k = map(int, sys.stdin.readline().split())
answer = "1"

cache = {}
def factorial(n):
    if n in cache: return cache[n]
    
    elif n <= 1: return 1
    
    else: 
        cache[n] = n * factorial(n-1)
        return cache[n]

    return n * factorial(n-1) if n > 1 else 1


def make_binary(k, i, threshold, length):
    global answer
    # 위치를 결정해야 하는 k개의 1이 현재까지 결정된 answer와 이번 턴에 결정될 자릿수를 제외한 위치에서(i-2개) 배치되는 경우의 수
    previous = int(factorial(i-2) / int(factorial(k-1) * factorial(i-k-1)))

    if k == 1 or previous == 1: # 위치를 결정할 k가 하나밖에 남지 않았거나 남은 1이 배치되는 경우의 수가 하나밖에 없는 경우
        arr = [i for i in range(len(answer)+1, length+1)]
        binary = list(combinations(arr, k-1))[::-1][threshold-1] # 1이 몇 번째 자리에 배치되는지 리턴
        return binary

    # previous에 포함되는 케이스들은 자릿수를 하나 늘렸을 때 앞자리가 0인 경우에 모두 포함된다. 
    # ex. previous에 포함된 케이스가 011, 101, 110인 경우 -> 0011, 0101, 0110에 모두 포함
    if threshold <= previous: # 따라서, 길이가 현재 length와 같은 이진수들 중에서 답이 될 숫자의 순서가 previous 범위 내에 들어가는 경우
        answer += "0" # 현재 자리에는 0이 추가되고
        return make_binary(k, i-1, threshold, length) # 이후 자리에 들어갈 숫자를 재귀적으로 결정
    
    else: # 답이 될 숫자의 순서가 위의 조건보다 더 후순위라면
        answer += "1" # 현재 자리에 1을 추가
        return make_binary(k-1, i-1, threshold-previous, length)


count, length = 0, 0
for i in range(k, 10000000):
    if k == 1: 
        length = n; break
    
    cases, length = int(factorial(i-1) / int(factorial(k-1) * factorial(i-k))), i
    
    if count + cases >= n: break # 더이상 자릿수를 늘릴 수 없다면 종료
    else: count += cases

threshold, binary = n - count, [] # threshold = 길이가 현재 length와 같은 이진수들 중에서 답이 될 숫자가 몇 번째인지 저장

if length != 1 and k != 1: # 답이 될 이진수의 길이가 1이 아니면서 포함되는 1의 개수가 1개가 아닌 경우
    binary = make_binary(k, length, threshold, length)

    for i in range(len(answer)+1, length+1): # 현재까지 결정된 answer의 뒷자리 완성
        if i in binary: answer += '1'
        else: answer += '0'

elif k == 1:
    answer += '0'*(n-1)
    
print(answer)
