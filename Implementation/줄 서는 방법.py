# 프로그래머스 Lv.2 줄 서는 방법
# factorial의 성질 이용

def factorial(n):
    if n < 1: return 1
    
    return factorial(n-1)*n

def solution(n, k):
    # numbers = 줄을 서려는 모든 사람들
    answer, numbers = [], [i for i in range(1, n+1)]

    while(n > 0):
        num_cases = factorial(n-1)
        seq = k // num_cases # 현재 위치에 오는 사람의 번호가 1~n 중 몇 번인지
        k = k % num_cases # 찾아야 하는 답이 현재 사람의 번호가 seq인 방법들 중에서 몇 번째인지
        
        if k == 0: # 0번째 = 현재 사람의 번호가 seq인 방법들 중에는 답이 존재하지 않음
            # 따라서 번호가 1이 더 작은 사람이 현재 위치에 오게 됨
            answer.append(numbers.pop(seq-1))
        else:
            answer.append(numbers.pop(seq))
            
        n -= 1
    
    return answer
