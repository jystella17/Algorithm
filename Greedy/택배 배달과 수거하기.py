# 2023 카카오 공채 1차 2번
# 프로그래머스 Lv.2 택배 배달과 수거하기
# Greedy + Implementation

def solution(cap, n, deliveries, pickups):
    answer = 0
    # 최소 이동 거리 => 멀리 떨어진 집에 대한 배달 및 수거를 우선적으로 처리
    # 따라서 deliveries, pickups 배열의 원소를 역순으로 정렬하여 멀리 떨어진 집을 먼저 탐색
    deliveries = deliveries[::-1]
    pickups = pickups[::-1]

    box_deliver, box_pickup = 0, 0 # 배달/수거할 박스 개수
    for i in range(n):
        box_deliver += deliveries[i]
        box_pickup += pickups[i]
        
        # 첫 출발을 포함해 물류 창고에 방문해야 하는 케이스
        # box_deliver 혹은 box_pickup이 cap*2 이상인 경우, 
        # 현재 지점에서 물류 창고를 여러 번 방문해야 하므로 if가 아닌 while문 사용
        while box_deliver > 0 or box_pickup > 0:
            box_deliver -= cap
            box_pickup -= cap
            answer += (n-i) * 2 # 현재 지점~물류창고를 왕복하는 거리

    return answer
