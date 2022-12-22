# 프로그래머스 Lv.3 보석 쇼핑
# 2020 카카오 인턴십 3번
# 투포인터 응용

def solution(gems):
    answer = []
    gem_candidates = {} # 진열대를 탐색하며 구매할 보석 저장
    num_gems = len(set(gems))
    shortest = len(gems) + 1
    
    start, end = 0, 0
    while end < len(gems): # 탐색 가능한 최대 index => len(gems)
        # 현재 마지막 포인터가 가리키는 보석이 아직 구매하지 않은 보석이면
        if gems[end] not in gem_candidates:
            gem_candidates[gems[end]] = 1 # 새로운 보석 종류 추가
        
        # 이미 구매한 보석이면
        else:
            gem_candidates[gems[end]] += 1 # 해당 보석의 개수만 추가
            
        end += 1 # 마지막 포인터를 다음 index로 이동
            
        # dictionary에 모든 종류의 보석이 포함된 경우
        if len(gem_candidates) == num_gems:
        # 후보에서 보석이 제거되지 않고
        # (시작 포인터에 해당하는 보석이 dictionary 내에 2개 이상 포함)
        # 두 개의 포인터가 교차하지 않는 범위 내에서 시작 포인터를 뒤로 이동
            while start < end:
                if gem_candidates[gems[start]] > 1:
                    gem_candidates[gems[start]] -= 1
                    start += 1
                    
                elif shortest > end - start:
                    shortest = end - start
                    answer = [start+1, end]
                    break
                    
                else:
                    break
    
    return answer
