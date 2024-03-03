# 프로그래머스 Lv.1
# 2024 카카오 인턴 기출

def solution(friends, gifts):
    answer, users, gift_score, next_gift = 0, {}, {}, {}
    logs = [[0 for _ in range(len(friends))] for _ in range(len(friends))]
    
    members = len(friends)
    
    for i in range(members):
        users[friends[i]] = i
        next_gift[friends[i]] = 0
        
    for g in gifts:
        sender, receiver = g.split()
        logs[users[sender]][users[receiver]] += 1
        
    for i in range(members):
        send, recv = 0, 0
        
        for j in range(members):
            if i == j: continue
            
            send += logs[i][j]
            recv += logs[j][i]
            
        gift_score[friends[i]] = (send - recv)
    
    for i in range(members):
        for j in range(i+1, members):
            if logs[i][j] == 0 and logs[j][i] == 0:
                if gift_score[friends[i]] > gift_score[friends[j]]:
                    next_gift[friends[i]] += 1
                
                elif gift_score[friends[i]] < gift_score[friends[j]]:
                    next_gift[friends[j]] += 1
                
            elif logs[i][j] == logs[j][i]:
                if gift_score[friends[i]] > gift_score[friends[j]]:
                    next_gift[friends[i]] += 1
                
                elif gift_score[friends[i]] < gift_score[friends[j]]:
                    next_gift[friends[j]] += 1
                
            elif logs[i][j] > logs[j][i]:
                next_gift[friends[i]] += 1
                
            else:
                next_gift[friends[j]] += 1
                
    for ng in next_gift:
        answer = max(answer, next_gift[ng])
        
    return answer
