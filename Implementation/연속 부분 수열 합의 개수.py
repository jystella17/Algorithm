# 프로그래머스 Lv.2 연속 부분 수열 합의 개수

def solution(elements):
    answer = set()
    length = len(elements)
    elements += elements
    
    for i in range(1, length+1): # 연속 부분 수열의 길이
        for j in range(length): # 탐색할 수열
            answer.add(sum(elements[j:i+j]))
    
    return len(answer)
