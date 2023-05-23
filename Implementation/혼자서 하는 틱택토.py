# 프로그래머스 Lv.2 혼자서 하는 틱택토
# 예외 케이스 처리 주의

def solution(board):
    answer, num_o, num_x = 1, 0, 0
    win_o, win_x = 0, 0
    # 규칙에 어긋나는 케이스 (3*3이므로 완전탐색 수행)
    # 1. O가 선공, X가 후공인데 X의 개수가 더 많은 경우 (표기 오류)
    # 2. 가로/세로/대각선으로 O와 X 모두 한줄이 만들어진 경우 (종료 후 게임 진행)
    # 3. 가로/세로/대각선으로 O 혹은 X가 한줄이 만들어진 후에도 게임이 계속된 경우
    
    for i in range(3):
        this_o = board[i].count('O')
        this_x = board[i].count('X')
        num_o += this_o; num_x += this_x
        
        if this_o == 3 or this_x == 3: # 가로로 한줄
            if this_o == 3: win_o += 1
            else: win_x += 1
        
        if board[0][i] == board[1][i] == board[2][i]: # 세로로 한줄
            if board[0][i] == 'O': win_o += 1
            if board[0][i] == 'X': win_x += 1
    
    # 대각선으로 한줄
    if board[0][0] == board[1][1] == board[2][2]:
        if board[0][0] == 'O': win_o += 1
        if board[0][0] == 'X': win_x += 1
    
    if board[0][2] == board[1][1] == board[2][0]:
        if board[0][2] == 'O': win_o += 1
        if board[0][2] == 'X': win_x += 1
    
    if num_o < num_x or num_o > num_x+1: answer = 0
    # 선공, 후공 모두 승리 조건을 달성한 경우
    if win_o and win_x: answer = 0
    # 선공이 승리 조건을 달성했는데도(O 개수가 X보다 1개 많아야 함) 후공이 추가 표기를 한 경우
    if win_o > 0 and win_x == 0 and num_o == num_x: answer = 0
    # 후공이 승리 조건을 달성했는데도 (O와 X의 개수가 같아야 함) 선공이 추가 표기를 한 경우
    if win_x > 0 and win_o == 0 and num_o != num_x: answer = 0
    
    return answer
