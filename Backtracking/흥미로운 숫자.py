import sys
from itertools import combinations

x, y = map(int, sys.stdin.readline().split())
len_x, len_y = len(str(x)), len(str(y))
num = [i for i in range(10)]
select = list(combinations(num, 2))
start, end, answer = 0, 0, 0

def find_interesting(number, index, length, threshold, count):
    for s in select:
        if s[0] == 0:
            dd
        
        elif s[1] == 0:
            dd
        
        else:
            dd
        
    return 1

for i in range(len_x, len_y+1):
    # 자릿수가 i인 모든 흥미로운 숫자들이 (0이 포함되는 경우를 제외하고) 정답 범위 내에 포함된다면
    # EX. i == 3이면 9C1 * 3P1 + 9C2 * 2 * 3P1 == 9*3 + 36*2*3 == 9*3 + 72*3 == 81*3
    if i > len_x and i < len_y: answer += (81*i)
    
    elif i == len_x and len_x != len_y:
        exclusion = find_interesting(0, i, i, x-1, 0)
        answer += (81*i - exclusion)
    
    elif i == len_y and len_x != len_y:
        answer += find_interesting(0, i, i, y, 0)
    
    else: # len_x == len_y인 경우의 답 구하기
        answer = find_interesting(0, i, i, y, 0) - find_interesting(0, i, i, x-1, 0)

print(answer)
