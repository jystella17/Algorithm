# 프로그래머스 Lv.2 시소 짝꿍
# Counter, set 활용

from collections import Counter

def solution(weights):
    answer, count = 0, Counter(weights)
    weights = set(weights)
    
    for w in weights:
        if count[w] >= 2: answer += count[w] * (count[w]-1) // 2
        if w*2 in weights: answer += count[w] * count[w*2]
        if w*4/3 in weights: answer += count[w] * count[w*4/3]
        if w*3/2 in weights: answer += count[w] * count[w*3/2]
        
    return answer
