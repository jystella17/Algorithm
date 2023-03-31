# 백준 G5 문자열 잘라내기
# Python set 활용

import sys

r, c = map(int, sys.stdin.readline().split())
letters = ['' for i in range(c)] # 처음에 만들 수 있는 모든 문자열
count = 0

for i in range(r):
    string = sys.stdin.readline()
    for j in range(c):
        letters[j] += string[j]

for i in range(r):
    for j in range(c):
        letters[j] = letters[j][1:] # 첫번째 row 문자 제거

    # 남은 문자들 중 중복 존재 -> set(letters)의 길이가 열의 개수 c와 달라짐
    if len(set(letters)) != c: break
    else: count += 1
    
print(count)
