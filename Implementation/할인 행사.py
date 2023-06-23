# 프로그래머스 Lv.2 할인 행사

from collections import Counter

def solution(want, number, discount):
    answer, items = 0, {}
    for i in range(len(want)):
        items[want[i]] = number[i]
        
    for i in range(len(discount)-9):
        if items == Counter(discount[i:i+10]):
            answer += 1
    
    return answer
