# 프로그래머스 LV.2 캐시

from collections import deque

def solution(cacheSize, cities):
    answer = 0
    cache = deque() # queue의 첫 번째 원소가 Least Recently Used => pop()으로 삭제될 수 있도록
    cities = [c.upper() for c in cities] # 입력값 중 같은 도시임에도 대소문자가 다른 경우가 있으므로, 일괄적으로 대문자로 변경 
    
    if cacheSize == 0: # cache size가 0이면 항상 cache miss => 실행시간 모두 5
        return len(cities)*5
    
    for i in range(len(cities)):
        if cities[i] in cache: # cache에 존재하는 원소가 다시 참조된 경우
            cache.remove(cities[i]) # 가장 최근에 참조된 원소가 되므로 queue의 맨 뒤로 보냄
            cache.append(cities[i])
            answer += 1
        
        else:
            answer += 5
            
            if len(cache) >= cacheSize: # queue 원소의 교체가 이루어져야 하는 경우
                cache.popleft() # queue 가장 왼쪽의 Least Recently Used 원소를 제거하고 
                cache.append(cities[i]) # 새로운 원소 삽입
            
            else:
                cache.append(cities[i])
    
    return answer
