import sys

x, y = map(int, sys.stdin.readline().split())

def duplicated(dictionary):
    tmp = []
    for k, v in dictionary.items(): tmp.append(v)
    
    if tmp[0] > 1 and tmp[1] > 1: return True
    else: return False

def is_interesting(digit, num, idx):
    if num[idx] in digit:
        digit[num[idx]] += 1
    
    else:
        digit[num[idx]] = 1

    length = len(digit)
    if length >= 3 or (length == 2 and duplicated(digit) == True): 
        return False
    
    elif idx == len(num)-1:
        if length == 1: return False
        else: return True
    
    else: 
        return is_interesting(digit, num, idx+1)

answer = 0
for i in range(x, y+1):
    digit = {}
    if is_interesting(digit, str(i), 0): 
        answer += 1
    
print(answer)
