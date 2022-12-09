# 프로그래머스 LV.2 메뉴 리뉴얼
# 2021 카카오 신입공채 1차 2번
# 조합 => itertools의 combination 이용

import itertools

def solution(orders, course):
    answer = []
    
    for cnum in course:
        courses = {}
        course_candidates = []
        
        # 메뉴 개수에 따라 가능한 코스요리 조합 구하기
        # 각 손님이 주문한 메뉴를 기반으로 조합을 구하게 되므로
        # 중복이 있을 수 있음 => 문제 풀이에 활용
        for order in orders:
            tmp = list(itertools.combinations(sorted(order), cnum))
            course_candidates.extend(tmp)
            
        # dictionary에 주문 횟수 저장
        for candidate in course_candidates:
            candidate = ''.join(candidate)
            
            if candidate in courses:
                courses[candidate] += 1
                
            else:
                courses[candidate] = 1
            
        # 2회 이상 & 가장 많이 주문된 단품메뉴 조합을 answer에 저장
        for c in courses:
            max_order = max(courses.values())
            if courses[c] >= 2 and courses[c] == max_order:
                answer.append(c)
    
    return sorted(answer)
