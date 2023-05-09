# 프로그래머스 Lv.2 모음사전
# itertools의 combinations, permutations, product 함수 사용법 숙지

from itertools import product

def solution(word):
    dictionary = []
    
    for i in range(1, 6):
        for w in list(product(['A', 'E', 'I', 'O', 'U'], repeat=i)):
            dictionary.append(''.join(w))
    
    dictionary.sort()
    return dictionary.index(word)+1
