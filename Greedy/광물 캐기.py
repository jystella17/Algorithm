# 프로그래머스 Lv.2 광물 캐기
# 문제 조건 유의

from collections import Counter

def solution(picks, minerals):
    answer, section, num_picks = 0, [], sum(picks)
    
    for i in range(0, len(minerals), 5):
        if num_picks == 0: break
        # count[0] = diamond, count[1] = iron, count[2] = stone
        counter, count = Counter(minerals[i:i+5]), [0, 0, 0]
        
        for c in counter.items():
            if c[0] == "diamond": count[0] = c[1]
            elif c[0] == "iron": count[1] = c[1]
            else: count[2] = c[1]
        
        num_picks -= 1
        section.append(count)

    # diamond가 많이 포함된 섹션부터 내림차순, diamond 개수가 같다면 iron 개수 내림차순
    section.sort(key=lambda x: (-x[0], -x[1]))
    for s in section:
        if picks[0] > 0:
            picks[0] -= 1
            answer += sum(s)
        
        elif picks[1] > 0:
            picks[1] -= 1
            answer += (5*s[0] + s[1] + s[2])
        
        elif picks[2] > 0:
            picks[2] -= 1
            answer += (25*s[0] + 5*s[1] + s[2])
            
        else: break
    
    return answer
