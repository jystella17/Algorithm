# 백준 G2 1765번 닭싸움 팀 정하기
# 같은 집합이 되는 조건 & 고려하지 않아도 되는 조건 확인

import sys

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
friends, enemies = [i for i in range(n+1)], [[] for _ in range(n+1)]

def find(x):
    if friends[x] != x:
        friends[x] = find(friends[x])
        
    return friends[x]


def union(p, q):
    p, q = find(p), find(q)
    
    if p == q: return # 이미 같은 팀에 속해있는 경우
    friends[q] = p


for i in range(m):
    relation, p, q = map(str, sys.stdin.readline().split())
    p, q = int(p), int(q)
    # 서로 친구 관계이면, 이미 같은 팀에 속해있는지 확인 
    # 다른 팀에 속해있다면 union
    if relation == 'F': union(p, q)
    else:
        enemies[p].append(q); enemies[q].append(p)

# 원수의 원수도 같은 팀이 되므로, 각 학생의 원수의 원수를 friends 배열에서 union
for i in range(1, n+1):
    for enemy in enemies[i]:
        for friend in enemies[enemy]:
            union(i, friend)

answer = 0
for i in range(1, len(friends)):
    if i == friends[i]: answer += 1
    
print(answer)
