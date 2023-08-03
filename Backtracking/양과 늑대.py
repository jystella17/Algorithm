# 프로그래머스 Lv.3 양과 늑대

def solution(info, edges):
    def dfs(sheeps, wolves):
        if sheeps <= wolves: return
        
        answer.append(sheeps)
        for start, end in edges:
            if visited[start] == False or visited[end] == True: continue
            
            print(start, end, sheeps)
            visited[end] = True
            if info[end] == 0:
                dfs(sheeps+1, wolves)
                    
            else:
                dfs(sheeps, wolves+1)
                
            visited[end] = False
    
    answer, visited = [], [False for _ in range(len(info))]

    visited[0] = True
    dfs(1, 0)
    return max(answer)
