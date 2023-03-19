# 백준 S2 에디터
# Python list에서 method 별 시간복잡도 고려하기
# Python lis를 활용한 연결리스트 구현 + append, pop 활용 (L일 때 기존 list에서 pop & backup stack에 저장 / D일 때 삭제되었던 데이터 append)

import sys

editor = list(sys.stdin.readline().rstrip())
backup = []

for x in range(int(sys.stdin.readline())):
    command = list(sys.stdin.readline().split())
    # P $ 형태의 명령이 입력되는 경우
    if command[0] == "P":
        editor.append(command[1])
    
    # 커서의 위치가 문장의 맨 앞이 아닌 경우    
    elif command[0] == "L" and editor:
        backup.append(editor.pop())
            
    # 커서의 위치가 문장의 맨 뒤가 아닌 경우
    elif command[0] == "D" and backup:
        editor.append(backup.pop())
    
    # 커서의 위치가 문장의 맨 앞이 아닌 경우
    elif command[0] == "B" and editor:
        editor.pop()

editor.extend(reversed(backup))
print(''.join(editor))
