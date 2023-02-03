# 프로그래머스 Lv.2 테이블 해시 함수
# sort 함수 사용법, 비트 연산자 

def solution(data, col, row_begin, row_end):
    answer = 0
    
    data.sort(key=lambda x: (x[col-1], -x[0]))
    for i in range(row_begin, row_end+1):
        S = 0
        for j in data[i-1]:
            S += (j % i)
        
        answer ^= S
    
    return answer
