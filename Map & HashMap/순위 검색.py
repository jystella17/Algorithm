# 프로그래머스 Lv.2 순위 검색
# 2021 Kakao Blind Recruitment 기출문제

# 가능한 모든 항목 조합 = 개발언어 4가지 (java, python, cpp, 조건없음) / 지원 직군 3가지 (backend, frontend, 조건없음) / 
# 경력구분 3가지 (junior, senior, 조건없음) / 소울푸드 3가지 (pizza, chicken, 조건없음) = 4 * 3 * 3 * 3 = 108 개
# 검색 조건(= 항목 조합)을 key, 검색 조건을 만족하는 지원자들의 코딩테스트 점수를 value (list 형태)로 하는 dictionary (hashmap) 사용

# 모든 지원자는 16개의 검색 조건을 만족
# ex. java, backend, junior, chicken 선택한 지원자 => (-, -, -, -), (java, -, -, -), (-, backend, -, -), 
# (-, -, junior, -), (-, -, -, chicken), (java, backend, -, -), (java, -, junior, -), (java, -, -, chicken), 
# (-, backend, junior, -), (-, backend, -, chicken), (-, -, junior, chicken),
# (java, backend, junior, -), (java, backend, -, chicken), (java, -, junior, chicken),
# (-, backend, junior, chicken), (java, backend, junior, chicken)

# 따라서, 각 지원자의 코딩테스트 점수를 (지원자가 입력한 정보에 따라) 16개의 검색 조건을 key 값으로 갖는 entry에 value로 append
# 모든 입력을 저장한 후, 각 value list를 오름차순 정렬
# 각 query를 key값으로 변환 => dictionary에서 해당 key값에 대응되는 value list 조회 => lower_bound로 기준 점수 X가 들어갈 위치(인덱스) 찾기
# => 전체 길이 - lower_bound로 찾은 인덱스 = 코딩테스트에서 기준 점수 X 이상의 점수를 받은 지원자 수

import bisect


def solution(info, query):
    answer, recruitments = [], {}
  
    recruitments[("-", "-", "-", "-")] = []
  
    recruitments[("java", "-", "-", "-")] = []
    recruitments[("python", "-", "-", "-")] = []
    recruitments[("cpp", "-", "-", "-")] = []
    recruitments[("-", "backend", "-", "-")] = []
    recruitments[("-", "frontend", "-", "-")] = []
    recruitments[("-", "-", "junior", "-")] = []
    recruitments[("-", "-", "senior", "-")] = []
    recruitments[("-", "-", "-", "pizza")] = []
    recruitments[("-", "-", "-", "chicken")] = []
    
    recruitments[("java", "backend", "-", "-")] = []
    recruitments[("java", "frontend", "-", "-")] = []
    recruitments[("python", "backend", "-", "-")] = []
    recruitments[("python", "frontend", "-", "-")] = []
    recruitments[("cpp", "backend", "-", "-")] = []
    recruitments[("cpp", "frontend", "-", "-")] = []
  
    recruitments[("java", "-", "junior", "-")] = []
    recruitments[("java", "-", "senior", "-")] = []
    recruitments[("python", "-", "junior", "-")] = []
    recruitments[("python", "-", "senior", "-")] = []
    recruitments[("cpp", "-", "junior", "-")] = []
    recruitments[("cpp", "-", "senior", "-")] = []
    
    recruitments[("java", "-", "-", "pizza")] = []
    recruitments[("java", "-", "-", "chicken")] = []
    recruitments[("python", "-", "-", "pizza")] = []
    recruitments[("python", "-", "-", "chicken")] = []
    recruitments[("cpp", "-", "-", "pizza")] = []
    recruitments[("cpp", "-", "-", "chicken")] = []
    
    recruitments[("-", "backend", "junior", "-")] = []
    recruitments[("-", "backend", "senior", "-")] = []
    recruitments[("-", "frontend", "junior", "-")] = []
    recruitments[("-", "frontend", "senior", "-")] = []
    
    recruitments[("-", "backend", "-", "pizza")] = []
    recruitments[("-", "backend", "-", "chicken")] = []
    recruitments[("-", "frontend", "-", "pizza")] = []
    recruitments[("-", "frontend", "-", "chicken")] = []
    
    recruitments[("-", "-", "junior", "pizza")] = []
    recruitments[("-", "-", "junior", "chicken")] = []
    recruitments[("-", "-", "senior", "pizza")] = []
    recruitments[("-", "-", "senior", "chicken")] = []
    
    recruitments[("java", "backend", "junior", "-")] = []
    recruitments[("java", "backend", "senior", "-")] = []
    recruitments[("java", "frontend", "junior", "-")] = []
    recruitments[("java", "frontend", "senior", "-")] = []
    
    recruitments[("python", "backend", "junior", "-")] = []
    recruitments[("python", "backend", "senior", "-")] = []
    recruitments[("python", "frontend", "junior", "-")] = []
    recruitments[("python", "frontend", "senior", "-")] = []
    
    recruitments[("cpp", "backend", "junior", "-")] = []
    recruitments[("cpp", "backend", "senior", "-")] = []
    recruitments[("cpp", "frontend", "junior", "-")] = []
    recruitments[("cpp", "frontend", "senior", "-")] = []
    
    recruitments[("java", "backend", "-", "pizza")] = []
    recruitments[("java", "backend", "-", "chicken")] = []
    recruitments[("java", "frontend", "-", "pizza")] = []
    recruitments[("java", "frontend", "-", "chicken")] = []
    
    recruitments[("python", "backend", "-", "pizza")] = []
    recruitments[("python", "backend", "-", "chicken")] = []
    recruitments[("python", "frontend", "-", "pizza")] = []
    recruitments[("python", "frontend", "-", "chicken")] = []
    
    recruitments[("cpp", "backend", "-", "pizza")] = []
    recruitments[("cpp", "backend", "-", "chicken")] = []
    recruitments[("cpp", "frontend", "-", "pizza")] = []
    recruitments[("cpp", "frontend", "-", "chicken")] = []
    
    recruitments[("java", "-", "junior", "pizza")] = []
    recruitments[("java", "-", "junior", "chicken")] = []
    recruitments[("java", "-", "senior", "pizza")] = []
    recruitments[("java", "-", "senior", "chicken")] = []
    
    recruitments[("python", "-", "junior", "pizza")] = []
    recruitments[("python", "-", "junior", "chicken")] = []
    recruitments[("python", "-", "senior", "pizza")] = []
    recruitments[("python", "-", "senior", "chicken")] = []
    
    recruitments[("cpp", "-", "junior", "pizza")] = []
    recruitments[("cpp", "-", "junior", "chicken")] = []
    recruitments[("cpp", "-", "senior", "pizza")] = []
    recruitments[("cpp", "-", "senior", "chicken")] = []
    
    recruitments[("-", "backend", "junior", "pizza")] = []
    recruitments[("-", "backend", "junior", "chicken")] = []
    recruitments[("-", "backend", "senior", "pizza")] = []
    recruitments[("-", "backend", "senior", "chicken")] = []
    
    recruitments[("-", "frontend", "junior", "pizza")] = []
    recruitments[("-", "frontend", "junior", "chicken")] = []
    recruitments[("-", "frontend", "senior", "pizza")] = []
    recruitments[("-", "frontend", "senior", "chicken")] = []1
    
    recruitments[("java", "backend", "junior", "pizza")] = []
    recruitments[("java", "backend", "junior", "chicken")] = []
    recruitments[("java", "backend", "senior", "pizza")] = []
    recruitments[("java", "backend", "senior", "chicken")] = []
    recruitments[("java", "frontend", "junior", "pizza")] = []
    recruitments[("java", "frontend", "junior", "chicken")] = []
    recruitments[("java", "frontend", "senior", "pizza")] = []
    recruitments[("java", "frontend", "senior", "chicken")] = []
    
    recruitments[("python", "backend", "junior", "pizza")] = []
    recruitments[("python", "backend", "junior", "chicken")] = []
    recruitments[("python", "backend", "senior", "pizza")] = []
    recruitments[("python", "backend", "senior", "chicken")] = []
    recruitments[("python", "frontend", "junior", "pizza")] = []
    recruitments[("python", "frontend", "junior", "chicken")] = []
    recruitments[("python", "frontend", "senior", "pizza")] = []
    recruitments[("python", "frontend", "senior", "chicken")] = []
    
    recruitments[("cpp", "backend", "junior", "pizza")] = []
    recruitments[("cpp", "backend", "junior", "chicken")] = []
    recruitments[("cpp", "backend", "senior", "pizza")] = []
    recruitments[("cpp", "backend", "senior", "chicken")] = []
    recruitments[("cpp", "frontend", "junior", "pizza")] = []
    recruitments[("cpp", "frontend", "junior", "chicken")] = []
    recruitments[("cpp", "frontend", "senior", "pizza")] = []
    recruitments[("cpp", "frontend", "senior", "chicken")] = []
    
    for app in info:
        app = app.split(" ")
        language, position, career, food = app[0], app[1], app[2], app[3]
        score = int(app[4])
        
        recruitments[(language, position, career, food)].append(score)
        
        recruitments[("-", position, career, food)].append(score)
        recruitments[(language, "-", career, food)].append(score)
        recruitments[(language, position, "-", food)].append(score)
        recruitments[(language, position, career, "-")].append(score)
        
        recruitments[("-", "-", career, food)].append(score)
        recruitments[("-", position, "-", food)].append(score)
        recruitments[("-", position, career, "-")].append(score)
        recruitments[(language, "-", "-", food)].append(score)
        recruitments[(language, "-", career, "-")].append(score)
        recruitments[(language, position, "-", "-")].append(score)
        
        recruitments[("-", "-", "-", food)].append(score)
        recruitments[("-", "-", career, "-")].append(score)
        recruitments[("-", position, "-", "-")].append(score)
        recruitments[(language, "-", "-", "-")].append(score)
        
        recruitments[("-", "-", "-", "-")].append(score)
    
    for key in recruitments:
        recruitments[key].sort()
    
    for que in query:
        que = que.split(" ")
        language, position, career, food = que[0], que[2], que[4], que[6]
        score = int(que[7])
        key = (language, position, career, food)
        
        start = bisect.bisect_left(recruitments[key], score)
        answer.append(len(recruitments[key]) - start)
        
    return answer
