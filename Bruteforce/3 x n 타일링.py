def solution(n):
    answer = 0; previous = 0
    mod = 1000000007
    dp = [0 for i in range(n+1)]
    dp[0] = 1
    
    if(n % 2 == 0):
        for i in range(2, n+1, 2):
            dp[i] = (3 * dp[i-2] + 2 * previous) % mod
            previous += dp[i-2]
    
    answer = dp[n] % mod
    
    return answer
