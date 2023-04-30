# 백준 G5 감소하는 수
# 백트래킹 

import sys

n = int(sys.stdin.readline())
answer, count, decreasing = 0, 0, ['0']
visited = [False] * 10

def decrease_number(n, threshold, count, dec): # threshold = 0~9까지의 숫자 중 몇개를 골라야 하는지
    global answer
    if count == threshold:
        answer += 1
        decreasing.append(dec)
        return
    
    for i in range(10):
        if visited[i] == True: continue
        if i == 0 and count == 0: continue
        if answer == n: return
    
        if (len(dec) >= 1 and int(dec[len(dec)-1]) > i) or len(dec) == 0:
            visited[i] = True
            decrease_number(n, threshold, count+1, dec+str(i))
            visited[i] = False

# 가장 큰 감소하는 수: 9876543210
# 9876543210은 1022번째 감소하는 수 => n > 1022이면 -1 출력
for i in range(1, 11):
    if answer < n and n < 1023: 
        decrease_number(n, i, 0, "")
    else: break

if len(decreasing) > 1 or n == 0: 
    print(decreasing[answer])
else: print(-1)
