# 2023 카카오 공채 1차 5번
# Disjoint Set 자료구조를 활용한 Union-Find
# 완전탐색 

def find(parent, x):
    if parent[x] == x: # x의 parent가 자기 자신, 즉 x가 root node라면
        return x
    
    return find(parent, parent[x])


def union(parent, x, y):
    x = find(parent, x)
    y = find(parent, y)
    
    if x != y: # 두 셀이 병합되지 않고 각각 독립된 셀이라면
        parent[y] = x # x셀으로 병합 (y셀의 parent를 x셀의 parent로 변경)

        
def solution(commands):
    answer = []
    value = ["" for i in range(2501)]
    parent = [i for i in range(2501)]
    
    for i in range(len(commands)):
        command = commands[i].split(' ', 1)
        
        if command[0] == "UPDATE":
            parameter = command[1].split(' ')
            
            if len(parameter) == 2: # update val1 val2
                original, change = parameter[0], parameter[1]
                for i in range(1, 2501):
                    if original == value[i]:
                        value[find(parent, i)] = change
            
            else: # update r c val
                r, c = int(parameter[0]), int(parameter[1])
                change = parameter[2]
                num = (r-1)*50 + c
                value[find(parent, num)] = change
            
        elif command[0] == "MERGE":
            parameter = command[1].split(' ')
            r1, c1 = int(parameter[0]), int(parameter[1])
            r2, c2 = int(parameter[2]), int(parameter[3])
            
            num1, num2 = (r1-1)*50 + c1, (r2-1)*50 + c2
            root1, root2 = find(parent, num1), find(parent, num2)
            if not value[root1]: # root1 is empty
                change = value[root2]
            else:
                change = value[root1]
            
            value[root1], value[root2] = "", "" # initialize
            union(parent, root1, root2) # merge root2 to root1
            value[root1] = change
            
        elif command[0] == "UNMERGE":
            parameter = command[1].split(' ')
            r, c = int(parameter[0]), int(parameter[1])
            
            num = (r-1)*50 + c
            root = find(parent, num)
            cur_val = value[root]
            value[root], value[num] = "", cur_val
            
            to_unmerge = []
            for i in range(1, 2501):
                if find(parent, i) == root:
                    to_unmerge.append(i) # root 연결을 바로 해제하면 반복문이 계속 진행되며 root를 찾아가는 경로가 사라질 수 있다.
                    
            for node in to_unmerge: # 따라서 병합을 해제할 셀의 번호를 저장한 뒤 해당 셀들에 대해서만 root 연결 해제를 수행해야 한다.
                parent[node] = node
            
        elif command[0] == "PRINT":
            parameter = command[1].split(' ')
            r, c = int(parameter[0]), int(parameter[1])
            
            num = (r-1)*50 + c
            to_print = value[find(parent, num)]
            
            if not to_print:
                answer.append("EMPTY")
            else:
                answer.append(to_print)
    
    return answer
