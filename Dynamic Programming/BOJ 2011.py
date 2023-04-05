# 백준 G5 암호코드
# 복잡한 예외 처리(구현)에 주의

import sys

answer = 0
cipher = sys.stdin.readline().rstrip()
cipher = [int(i) for i in cipher]

decryption = [0 for i in range(len(cipher)+1)]
decryption[0] = 1; decryption[1] = 1

# 입력받은 암호가 한자리 자연수인 경우
if len(cipher) == 1 and cipher[0] >= 1:
    answer = decryption[1]

for i in range(1, len(cipher)):
    # 0이 2번 이상 연속되거나, 30 이상의 10의 배수가 만들어지는 경우 (비정상 입력)
    if (cipher[i-1] == 0 and cipher[i] == 0) or (cipher[i-1] > 2 and cipher[i] == 0) or (cipher[0] == 0):
        answer = 0; break
    
    # 바로 앞이나 현재 위치에 0이 있으면서 정상적인 입력인 경우
    elif cipher[i] == 0 or cipher[i-1] == 0:
        if cipher[i] == 0: 
            decryption[i+1] = decryption[i-1] % 1000000
            
        else: # cipher[i-1] == 0
            decryption[i+1] = decryption[i] % 1000000
            
    # 앞의 숫자와 합쳤을 때 알파벳으로 변경 가능한 경우
    elif cipher[i-1]*10 + cipher[i] <= 26:
        decryption[i+1] = (decryption[i] + decryption[i-1]) % 1000000
    
    # 앞의 숫자와 합쳤을 때 알파벳으로 변경할 수 없는 경우
    else:
        decryption[i+1] = decryption[i] % 1000000
        
    answer = decryption[i+1]

print(answer%1000000)
