# 2023 카카오 공채 1차 7번
# Tree + Implementation

from collections import defaultdict
import sys
sys.setrecursionlimit(100000000)

def solution(edges, target):
    answer = []
    
    tree = []
    direction = [-1 for i in range(len(target)+1)]
    for i in range(len(target)+1):
        tree.append([])
    
    for i in range(len(edges)):
        tree[edges[i][0]].append(edges[i][1])
        if direction[edges[i][0]] == -1:
            direction[edges[i][0]] = 0
    
    for i in range(len(target)+1):
        tree[i].sort()
    
    leaf = []
    for i in range(1, len(target)+1):
        if len(tree[i]) == 0:
            leaf.append(i)

    leaf_num = {key : 0 for key in leaf} # 각 leaf node에 도달한 숫자 개수
    # 각 leaf node에 도달한 숫자들의 합이 target과 같아질 가능성이 있는지 저장
    is_succeeded = {key : False if target[key-1] > 0 else True for key in leaf} 
    num_sequence = [] # n번째 숫자가 몇 번 node에 도달하는지
    
    def find_leaf(node):
        if len(tree[node]) == 0: # leaf node에 도달한 경우
            return node
        
        road = direction[node] # 현재 설정된 길
        direction[node] = (road+1) % len(tree[node]) # 다음 간선을 길로 설정

        return find_leaf(tree[node][road])
    
    # 각 leaf node에 도달하는 숫자 개수의 최소값 구하기
    while False in is_succeeded.values():
        current = find_leaf(1)
        leaf_num[current] += 1
        
        if leaf_num[current] > target[current-1]:
            return [-1]
        
        if target[current-1] <= 3*leaf_num[current] and leaf_num[current] <= target[current-1]:
            is_succeeded[current] = True
            
        num_sequence.append(current)

    # 각 leaf node에 도달하는 실제 숫자 구하기
    answer = [0]*len(num_sequence)
    for key in leaf:
        result = list()
        sur_cap = target[key-1] - leaf_num[key]
        result = [1]*(leaf_num[key] - sur_cap % 2 - sur_cap // 2) + [2]*(sur_cap % 2) + [3]*(sur_cap // 2)
        
        for idx, node in enumerate(num_sequence):
            if node == key :
                answer[idx] = result.pop(0)
    
    return answer
