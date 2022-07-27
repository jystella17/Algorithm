def solution(n):
    answer = ''
    notation = ['4', '1', '2']

    while n:
        answer = notation[n%3] + answer 
        n = n//3 - (n%3 == 0)
        
    return answer
