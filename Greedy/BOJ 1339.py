import sys

n = int(sys.stdin.readline())
word = []
alpha_weight = {'A':0, 'B':0, 'C':0, 'D':0, 'E':0, 'F':0, 'G':0, 'H':0, 'I':0, 
                'J':0, 'K':0, 'L':0, 'M':0, 'N':0, 'O':0, 'P':0, 'Q':0, 'R':0, 
                'S':0, 'T':0, 'U':0, 'V':0, 'W':0, 'X':0, 'Y':0, 'Z':0}
alpha_num, ans = [], 0

for i in range(n):
    word.append(sys.stdin.readline().rstrip())

for w in word:
    for i in range(len(w)):
        # 가중치(자릿수)가 큰 순서대로 9부터 숫자를 부여하기 위해 가중치 저장
        alpha_weight[w[i]] += pow(10, len(w)-i-1)

for value in alpha_weight.values():
    if(value > 0): # 입력받은 단어에 한 번 이상 등장한 알파벳이면
        alpha_num.append(value) # 각 알파벳이 등장한 자릿수 저장

        
alpha_num = sorted(alpha_num, reverse=True) 
# 큰 자릿수에 많이 등장하는 알파벳 순서대로 9부터 숫자를 배정하기 위해 내림차순 정배정하기

for i in range(len(alpha_num)):
    ans += alpha_num[i] * (9-i)
    
print(ans)
