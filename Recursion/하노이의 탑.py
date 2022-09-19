def solution(n):
    return hanoi(n, 1, 3, [])

def hanoi(n, a, b, before):
    if n == 0: return
    
    hanoi(n-1, a, 6-(a+b), before)
    before.append([a, b])
    hanoi(n-1, 6-(a+b), b, before)
    
    return before
