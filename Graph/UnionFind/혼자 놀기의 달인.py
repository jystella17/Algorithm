# 프로그래머스 Lv.2 혼자 놀기의 달인
# Union-Find 개념 활용 (Find만 수행) - 같은 집합에 속한 상자들과 그 개수 구하기

boxes = []

def find_group(boxes, x, cnt):
    if boxes[x] != -1:
        next_box, boxes[x] = boxes[x], -1
        cnt = find_group(boxes, next_box, cnt+1)
        
    return cnt

    
def solution(cards):
    answer, groups, boxes = 0, [], cards
    boxes.insert(0, 0)
    
    for i in range(1, len(boxes)):
        groups.append(find_group(boxes, i, 0))
        # 모든 상자가 열렸다면 더이상 탐색하지 않음
        if boxes.count(-1) == len(boxes)-1: break
    
    # 많은 상자가 속해있는 그룹부터 상자 개수 내림차순 정렬
    groups.sort(reverse=True)
    
    # 1번 상자 그룹에 모든 상자가 포함되었다면 점수는 0점
    if len(groups) < 2: answer = 0
    # 상위 2개 그룹의 상자 개수 곱하기
    else: answer = (groups[0] * groups[1])
    
    return answer
