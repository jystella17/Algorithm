# 프로그래머스 Lv.2 스킬트리
# deque 활용 => 매 loop 시작 시 deque 초기화 후 선행 스킬부터 배우는지 확인
# (선행 스킬 순서대로 배우지 않으면 원소가 deque에서 제거되지 않음)

from collections import deque

def solution(skill, skill_trees):
    answer = 0
    
    for skills in skill_trees:
        count = 0
        priority = deque(skill)
        
        for s in skill:
            if s in skills: 
                count += 1
        
        for sk in skills:
            if len(priority) > 0 and priority[0] == sk:
                priority.popleft()

        if len(priority) == len(skill)-count:
            answer += 1
    
    return answer
