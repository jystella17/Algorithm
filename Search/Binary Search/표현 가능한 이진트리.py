# 프로그래머스 Lv.3 표현 가능한 이진트리
# 2023 카카오 공채 1차 4번
# 포화 이진 트리 + Binary Search(Recursion)

import math

# 입력 받은 10진수를 2진수로 변환
def dec_to_bin(decimal): 
    binary = ""
    while(decimal > 0):
        binary = str(decimal%2) + binary
        decimal = decimal // 2
        
    return binary
    
# 변환된 2진수를 기반으로 포화 이진 트리 생성
def full_binary_tree(dec, binary):
    binary_len = math.floor(math.log2(dec)) + 1 # 2진수의 길이
    height = math.floor(math.log2(binary_len)) + 1 # 포화 이진 트리의 높이
    num_nodes = 2**height - 1 # 포화 이진 트리에 포함된 노드의 총 개수
    
    # 포화 이진 트리 중 2진수를 저장하고 남은 자리는 0으로 padding
    return "0" * (num_nodes - binary_len) + binary

# 포화 이진 트리로 해당 수를 표현할 수 있는지 체크
def is_full_bt(start, end, binary_tree):
    if start >= end: # False 조건에 걸리지 않고 root까지 탐색 완료한 경우
        return binary_tree[start] # 최상위 root가 0일 수 있으므로 True가 아닌 저장된 값 return
    
    root = (start + end) // 2 # root 노드의 index 찾기
    left = is_full_bt(start, root-1, binary_tree) # 왼쪽 자식
    right = is_full_bt(root+1, end, binary_tree) # 오른쪽 자식
    
    if left is False or right is False:
        return False # 하나 이상의 자식 노드에서 False가 리턴된 경우 탐색 중단
    
    if binary_tree[root] == "0" and (left == "1" or right == "1"):
        return False # 부모 노드에 더미 값이 저장되었는데 자식 노드에는 유효한 값이 저장된 경우
    
    # 자식 노드에 저장된 값을 리턴해주기 위한 if else문
    if binary_tree[root] == "1":
        return "1"
    
    else:
        return "0"


def solution(numbers):
    answer = []
    
    for i in range(len(numbers)):
        binary = dec_to_bin(numbers[i])
        tree = full_binary_tree(numbers[i], binary)
        
        if is_full_bt(0, len(tree)-1, tree):
            answer.append(1)
        else:
            answer.append(0)
    
    return answer
