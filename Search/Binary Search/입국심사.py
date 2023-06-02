# 프로그래머스 Lv.3 입국심사
# Binary Search 응용 (어떤 데이터에 대해 이분탐색을 수행해야 하는지 파악해야 함)

def solution(n, times):
    # times를 오름차순으로 정렬 => 최악의 경우 심사 시간이 가장 짧은 심사관에게
    # 모든 사람이 심사를 받음 => right = times[0]*n
    times.sort()
    answer, min_time, max_time = 0, times[0], times[0]*n
    print(min_time, max_time)
    
    while min_time <= max_time:
        mid = (min_time + max_time) // 2
        
        # mid가 모든 대기자의 입국 심사를 완료할 수 있는 시간인지 판단
        # mid까지 0번 심사관이 입국 심사를 할 수 있는 인원 수 + 1번 심사관 + ...
        # 해당 값이 n보다 작으면(입국 심사를 못받는 사람이 있다면) min_time 업데이트
        people = 0
        for time in times:
            people += (mid // time)
            
            if people >= n:
                answer, max_time = mid, mid-1
                break
                
        if people < n: 
            min_time = mid+1
    
    return answer
