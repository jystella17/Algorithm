# 프로그래머스 Lv.2 점 찍기
# 수식 변형으로 시간 복잡도를 줄일 수 있는 규칙 찾기

def solution(k, d):
    answer = 0
    for i in range(0, d+1, k):
        bound = int((pow(d, 2) - pow(i, 2)) ** (1/2))
        answer += (bound//k) + 1
    
    return answer
