# 2022 카카오 인턴십 5번
# 프로그래머스 Lv.4 행렬과 연산

from collections import deque

def solution(rc, operations):
    answer = []
    n = len(rc)
    # 제일 왼쪽/제일 오른쪽 column에 해당하는 값은 left_col, right_col에서 저장하므로 
    # 같은 데이터를 중복 저장하지 않고 left_col, right_col에 없는 데이터만 rows에 저장
    # ex. rc[0] = [1, 2, 3]이라면,
    # 1과 3은 left_col, right_col에 저장되므로 2만 rows에 저장
    rows = deque(deque(row[1:-1]) for row in rc)
    left_col = deque(row[0] for row in rc)
    right_col = deque(row[len(rc[0])-1] for row in rc)
    
    for op in operations:
        if op == "ShiftRow":
            # left_col, rows, right_col에서 마지막 원소 (= 마지막 행) pop
            # -> 각각 첫 번째 원소로 append (= 첫번째 행)
            left_col.appendleft(left_col.pop())
            rows.appendleft(rows.pop())
            right_col.appendleft(right_col.pop())
        
        else: # Rotate
            # 4개의 모서리에 대한 처리 (예시는 3X3 행렬으로 가정)
            # (1,1)에 위치한 숫자 -> (1,2)로 이동
            rows[0].appendleft(left_col.popleft())
            # (1,2)에 위치한 숫자 -> (1,3)로 이동
            right_col.appendleft(rows[0].pop())
            # (3,3)에 위치한 숫자 -> (3,2)로 이동
            rows[n-1].append(right_col.pop())
            # (3,2)에 위치한 숫자 -> (3,1)로 이동
            left_col.append(rows[n-1].popleft())       
    
    for i in range(n):
        answer.append([left_col[i]]+ list(rows[i]) + [right_col[i]])
        
    return answer
