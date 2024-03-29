# 프로그래머스 성격 유형 검사하기

def solution(survey, choices):
    answer = ''
    type = {"R":0, "T":0, "C":0, "F":0, "J":0, "M":0, "A":0, "N":0}
    
    for i in range(len(survey)):
        left = survey[i][0] # 왼쪽 = 비동의, 1~3점
        right = survey[i][1] # 오른쪽 = 동의, 5~7점
        
        if choices[i] > 4: # 동의 -> 오른쪽에 점수 추가
            type[right] = type[right] + choices[i]%4
            
        else: # 비동의 -> 왼쪽에 점수 추가
            type[left] = type[left] + (4 - choices[i])
    
    answer += 'R' if type['R'] >= type['T'] else 'T'
    answer += 'C' if type['C'] >= type['F'] else 'F'
    answer += 'J' if type['J'] >= type['M'] else 'M'       
    answer += 'A' if type['A'] >= type['N'] else 'N'
    
    return answer
