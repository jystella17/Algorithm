# 백준 G4 10942번 팰린드롬?
# s번째~e번째 숫자가 팰린드롬 = palindrome[s][e] = True 형태

import sys

n = int(sys.stdin.readline())
palindrome = [[False for _ in range(n+1)] for _ in range(n+1)]
numbers = list(map(int, sys.stdin.readline().split()))

# s == e인 경우 무조건 palindrome
for i in range(n):
    palindrome[i][i] = True
    
# s+1 == e (ex. s=2, e=3)인 경우 두 숫자가 같으면 palindrome
for i in range(n-1):
    if numbers[i] == numbers[i+1]:
        palindrome[i][i+1] = True
        
# 세 개 이상의 숫자가 포함되는 경우
# 처음과 끝의 숫자가 같고 그 사이의 숫자가 팰린드롬이면 palindrome
for length in range(n-2):
    for i in range(n-2-length):
        j = i + length + 2
        if numbers[i] == numbers[j] and palindrome[i+1][j-1] == True:
            palindrome[i][j] = True

m = int(sys.stdin.readline())
for i in range(m):
    s, e = map(int, sys.stdin.readline().split())
    
    if palindrome[s-1][e-1]: print(1)
    else: print(0)
