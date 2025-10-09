# BOJ 5430 AC (G5)
# 배열 뒤집기 연산 = deque + 탐색 방향(boolean) 으로 구현
# 정방향 : reverse = False : deque의 front부터 D(버리기) 연산 수행
# 정방향 : reverse = True : deque의 back부터 D(버리기) 연산 수행

import sys
import ast
from collections import deque

t = int(sys.stdin.readline().strip())
for tc in range(t):
    commands = list(sys.stdin.readline().strip())
    n = int(sys.stdin.readline().strip())
    _input = sys.stdin.readline().strip()
    
    if _input == "[]":
        dq = deque()
        
    else:
        dq = deque(ast.literal_eval(_input))
    
    
    reverse, error = False, False
    for cmd in commands:
        if cmd == 'R':
            reverse = not reverse
        
        elif cmd == 'D':
            if not dq:
                error = True
                break
            
            if not reverse: dq.popleft()
        
            else: dq.pop()
            
    if error:
        print("error")
        continue
    
    if reverse:
        dq = reversed(dq)
    
    answer = "[" + ",".join(map(str, dq)) + "]"
    print(answer)
