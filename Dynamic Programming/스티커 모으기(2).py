# 프로그래머스 Lv.3 스티커 모으기(2)
# 기본 dp 문제 (케이스 구분 필요, 인덱스 주의)

def solution(sticker):
    # 첫 번째 스티커를 뜯는 경우 / 뜯지 않는 경우
    answer, dp_first, dp_second = 0, [0]*len(sticker), [0]*len(sticker)
    if len(sticker) == 1:
        return sticker[0]
    
    if len(sticker) == 2:
        return max(sticker[0], sticker[1])
    
    dp_first[0] = sticker[0]; dp_first[1] = dp_first[0]
    for i in range(2, len(sticker)-1):
        dp_first[i] = max(sticker[i] + dp_first[i-2], dp_first[i-1])
    
    for i in range(1, len(sticker)):
        dp_second[i] = max(sticker[i] + dp_second[i-2], dp_second[i-1])
    
    return max(dp_first[-2], dp_second[-1])
