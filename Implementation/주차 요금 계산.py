# 프로그래머스 LV.2 주차 요금 계산
# 2022 카카오 신입공채 1차 3번
# Dictionary 활용, 구현

import math

# HH:MM 형태의 입력을 분으로 환산
def time_to_minutes(time):
    hour, minute = time.split(":")
    return int(hour)*60 + int(minute)
    
# 주차 시간 -> 요금 계산    
def parking_fee(minutes, free_time, base_fee, extra_time, extra_fee):
    if minutes <= free_time:
        return base_fee
    
    else:
        additional = math.ceil((minutes-free_time)/extra_time)
        return base_fee + (additional * extra_fee)

def solution(fees, records):
    answer = []
    free_time = fees[0]
    base_fee = fees[1]
    extra_time = fees[2]
    extra_fee = fees[3]
    
    parking = dict() # 현재 주차된 차량
    exit_cars = dict() # 출차된 차량의 번호와 요금 저장
    
    for record in records:
        timestamp, car_number, in_out = record.split()
        timestamp = time_to_minutes(timestamp)
        
        if in_out == 'IN':
            parking[car_number] = timestamp
            
        else: # 출차 시
            time = timestamp - parking[car_number]
            
            try:
                exit_cars[car_number] += time
                
            except:
                exit_cars[car_number] = time
                
            del parking[car_number]
    
    for car_number, timestamp in parking.items():
        time = 1439 - timestamp # 1439 = 23:59
        try:
            exit_cars[car_number] += time
        
        except:
            exit_cars[car_number] = time
            
    fees = sorted(list(exit_cars.items()), key=lambda x: x[0])
    
    for f in fees:
        answer.append(parking_fee(
            f[1], free_time, base_fee, extra_time, extra_fee
        ))
    
    return answer
