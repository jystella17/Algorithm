def solution(alp, cop, problems):
    max_alp, max_cop = 0, 0
    
    for i in range(len(problems)):
        max_alp = max(problems[i][0], max_alp)
        max_cop = max(problems[i][1], max_cop)
        
    alp = min(max_alp, alp)
    cop = min(max_cop, cop)
    max_cost = 100 * (max_alp + max_cop)
    
    dp = [[max_cost + 1 for _ in range(max_cop + 1)] for _ in range(max_alp + 1)]
    dp[alp][cop] = 0
    
    for i in range(alp, max_alp + 1):
        for j in range(cop, max_cop + 1):
            if i + 1 <= max_alp:
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1)
                
            if j + 1 <= max_cop:
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1)
            
            for alp_req, cop_req, alp_rwd, cop_rwd, cost in problems:
                if i >= alp_req and j >= cop_req:
                    next_alp = min(max_alp, i + alp_rwd)
                    next_cop = min(max_cop, j + cop_rwd)
                    dp[next_alp][next_cop] = min(dp[next_alp][next_cop], dp[i][j] + cost)
        
                    
    return dp[-1][-1]
