# 프로그래머스 Lv.2 호텔 대실
# 우선순위 큐 & 정렬 활용

import heapq

def convert_time(hour, minute):
    time = 0
    h1, h2 = int(hour[0]), int(hour[1])
    m1, m2 = int(minute[0]), int(minute[1])
    
    if h1 == 0: time += h2 * 60
    else: time += (h1*10 + h2) * 60
    
    if m1 == 0: time += m2
    else: time += (m1*10 + m2)
    
    return time


def solution(book_time):
    answer, booked, pq = 0, [], []
    
    for bt in book_time:
        start_time = convert_time(bt[0][:2], bt[0][3:])
        end_time = convert_time(bt[1][:2], bt[1][3:]) + 10
        booked.append([start_time, end_time])
    
    booked.sort()
    for b in booked:
        # 다른 손님이 사용한 방 중 입실할 수 있는 방이 있다면
        if len(pq) != 0 and pq[0] <= b[0]:
            heapq.heappop(pq)
        
        # 현재 손님이 다른 손님이 사용한 방에 입실했다면 퇴실 시간 업데이트
        # 새로운 방에 입실해야 한다면 퇴실 시간 저장
        heapq.heappush(pq, b[1])
    
    return len(pq)
