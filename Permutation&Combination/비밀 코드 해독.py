# 2025 프로그래머스 코드챌린지 1차 예선 - 비밀 코드 해독 (Lv.2)

from itertools import combinations

def solution(n, q, ans):
    answer = 0
    num = [i for i in range(1, n+1)]

    # 입력한 정수 조합 중 ans = 0인 케이스가 존재 = 해당 정수 조합에 포함된 숫자는 모두 비밀 코드에 포함되지 않음
    # 따라서 해당 숫자들을 모두 제외하고 남은 숫자들에 대해서만(차집합) 비밀 코드 후보 생성 => 시간 단축
    for i in range(len(q)):
        if ans[i] == 0:
            num = list(set(num) - set(q[i]))
  
    for comb in combinations(num, 5):
        comb = list(comb)
        
        is_candidate = True
        for i in range(len(q)):
            count = 0

            # 입력한 정수가 이번 비밀 코드 후보에 몇개 포함되는지 확인
            for query in q[i]:
                if query in comb:
                    count += 1
                  
            # 비밀 코드 후보에 포함된 정수 개수 != ans이면 이번 후보는 비밀 코드가 아님
            if count != ans[i]:
                is_candidate = False
                break

        # 입력한 모든 정수 집합에 대해 조건을 만족하면 비밀 코드 후보로 추가
        if is_candidate: 
            answer += 1
    
    return answer
