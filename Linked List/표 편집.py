# 2021 카카오 인턴십 3번
# 프로그래머스 Lv.3 표 편집
# Linked List 개념 + dictionary를 활용한 linked list 구현

def solution(n, k, cmd): 
    answer = ["O"] * n
    deleted = [] # 삭제된 행을 저장하는 stack
    table = {i:[i-1, i+1] for i in range(n)} # 모든 데이터가 포함된 표
    table[0][0], table[n-1][1] = None, None
    
    current = k
    for c in cmd:            
        if c == 'C':
            answer[current] = 'X'
            prev, next = table[current]
            deleted.append([prev, current, next])
            
            if next == None: # 삭제할 행이 마지막 행인 경우
                current = table[current][0]
            else:
                current = table[current][1]

            if prev == None: # 삭제된 행이 첫번째 행인 경우
                table[next][0] = None
                
            elif next == None: # 삭제된 행이 마지막 행인 경우
                table[prev][1] = None
                
            else:
                table[prev][1] = next
                table[next][0] = prev
        
        elif c == 'Z':
            prev, restore, next = deleted.pop()
            answer[restore] = 'O'
            
            if prev == None: # 복구된 행이 첫번째 행인 경우
                table[next][0] = restore
            
            elif next == None: # 복구된 행이 마지막 행인 경우
                table[prev][1] = restore    
                
            else:
                table[prev][1] = restore
                table[next][0] = restore
                
        else:
            command, to_move = c.split(' ')
            if command == 'U':
                for _ in range(int(to_move)):
                    current = table[current][0]
            
            elif command == 'D':
                for _ in range(int(to_move)):
                    current = table[current][1] 
    
    return ''.join(answer)
