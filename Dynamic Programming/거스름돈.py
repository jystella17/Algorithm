# Programmers Level 3

def solution(n, money):
    answer = 0
    change = [1] + [0 for i in range(n)]
    
    for coin in money:
        for won in range(coin, n+1):
            change[won] += change[won - coin]
    
    answer = change[n] % 1000000007
    return answer
