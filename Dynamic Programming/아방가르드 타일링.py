# 프로그래머스 Lv.3 아방가르드 타일링
# 점화식 응용 공부하기

def solution(n):
    answer, mod = 0, 1000000007
    dp = [1, 1, 3, 10, 23, 62]
    for i in range(6, n+1): 
        dp.append(0)
    
    for i in range(6, n+1):
        dp[i] = (dp[i-1] + 2*dp[i-2] + 6*dp[i-3] + dp[i-4] - dp[i-6] + mod) % mod
    
    return dp[n]
