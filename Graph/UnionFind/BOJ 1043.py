# 백준 G4 거짓말
# 연결 관계가 명확하지 않은 데이터가 주어졌을 때의 Union-Find

import sys

n, m = map(int, sys.stdin.readline().split())
ground_truth = list(map(int, sys.stdin.readline().split()))[1:] # 진실을 이미 알고 있는 사람들
truth = [i for i in range(n+1)]

def find(truth, x):
    if truth[x] != x:
        truth[x] = find(truth, truth[x])
    
    return truth[x]


def union(truth, x, y, ground_truth):
    x, y = find(truth, x), find(truth, y)
    
    if x in ground_truth and y in ground_truth:
        return # 이미 같은 집합 안에 있는 경우
    
    if x in ground_truth: # x만 진실을 알고 있는 경우
        truth[y] = x
    
    elif y in ground_truth: # y만 진실을 알고 있는 경우
        truth[x] = y
        
    else: # 모두 진실을 모르는 경우
        if x > y:
            truth[x] = y
        else:
            truth[y] = x
       
parties = []
for x in range(m):
    party = list(map(int, sys.stdin.readline().split()))[1:]

    for i in range(len(party)-1):
        union(truth, party[i], party[i+1], ground_truth)
           
    parties.append(party)

answer = 0
for party in parties:
    for i in range(len(party)):
        if find(truth, party[i]) in ground_truth:
            break
        
    else:
        answer += 1

print(answer)
