# 프로그래머스 Lv.2 주식가격
# list가 아닌 deque에서의 탐색(queue) => 실행시간 단축

from collections import deque

def solution(prices):
    answer, stock = [], deque(prices)
    
    while stock:
        ticker = stock.popleft()
        
        second = 0
        for s in stock:
            second += 1
            if s < ticker: break
        
        answer.append(second)
    
    return answer
