# 프로그래머스 Lv.3 스타 수열
# Counter 클래스 사용법 알아보기

from collections import Counter

def solution(a):
    answer = -1
    # 수열 a에 등장하는 각 원소의 등장 횟수 저장
    numbers = Counter(a)
    
    for k in numbers.keys(): # 각 숫자가 교집합의 원소인 경우를 탐색
        # 수열 a에서 숫자 k의 등장 횟수가 현재까지 가장 긴 스타 수열의 길이보다 작거나 같으면
        # 탐색하지 않고 다음 숫자로 넘어감
        if numbers[k] <= answer:
            continue
        
        cnt, i = 0, 0
        while i < len(a)-1:
            # 연속된 두 원소에 공통 원소가 모두 포함되지 않거나
            # 연속된 두 원소의 값이 같은 경우
            if (a[i] != k and a[i+1] != k) or (a[i] == a[i+1]):
                i += 1 # 바로 다음 인덱스로 이동
                continue
                
            # 현재 탐색중인 원소가 스타 수열에 포함되는 경우
            cnt += 1 # 스타 수열에 현재 원소를 포함시킴
            i += 2 # 다음 탐색 대상으로 이동 (2칸)
                
        answer = max(cnt, answer)
             
    if answer == -1:
        return 0
    
    else:
        return answer*2 # i+1은 탐색 과정에서 스타 수열에 포함시키지 않았으므로 2를 곱함
