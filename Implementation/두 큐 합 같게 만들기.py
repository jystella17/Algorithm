# 프로그래머스 Lv.2 두 큐 합 같게 만들기
# 2022 카카오 인턴십 2번
# Python deque, 입력값 범위에 유의

from collections import deque

def solution(queue1, queue2):
    q1, q2 = deque(queue1), deque(queue2)
    q1_sum, q2_sum = sum(q1), sum(q2)
    
    answer = 0
    while answer < 300000:
        if q1_sum == q2_sum:
            return answer
        
        elif q1_sum > q2_sum:
            elem = q1.popleft()
            q2.append(elem)
            q1_sum -= elem
            q2_sum += elem
            answer += 1
            
        else:
            elem = q2.popleft()
            q1.append(elem)
            q1_sum += elem
            q2_sum -= elem
            answer += 1
            
    return -1
