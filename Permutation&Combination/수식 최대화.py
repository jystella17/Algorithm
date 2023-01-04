# 프로그래머스 LV.2 수식 최대화
# 2020 카카오 인턴십
# 정규표현식 관련 함수 사용법 공부, del과 remove의 차이에 주의 
# remove를 사용할 경우 해당 값을 갖는 가장 첫 번째 원소가 삭제되므로, 실제로 삭제하려는 원소가 아닌 다른 원소가 삭제될 수 있음

from itertools import permutations
from collections import deque
import re

def solution(expression):
    answer = []
    operators = ['+', '-', '*']
    priority = permutations(operators, 3) # 연산자 우선순위의 모든 조합
    
    for operator in priority:
        exp = deque()
        # 수식에 포함된 모든 연산자 혹은 피연산자를 list의 원소로 변환
        exp = re.split(r'(\D)', expression)
        
        for op in operator:
            while op in exp:
                idx = exp.index(op)   
                exp[idx-1] = str(eval(exp[idx-1] + op + exp[idx+1]))
                
                del exp[idx+1]
                del exp[idx]
            
        answer.append(abs(int(exp[0])))

    return max(answer)
