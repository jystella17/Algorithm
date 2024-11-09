# NCPC 2019 (Nordic Collegiate Programming Contest)
# Problem A (Alphabet Animals)

import sys
 
prev = sys.stdin.readline().strip()
n = int(sys.stdin.readline())
words = [[] for _ in range(26)]
 
for i in range(n):
    tmp = sys.stdin.readline().strip()
    words[ord(tmp[0]) - ord('a')].append(tmp)
 
select = ""
start = ord(prev[len(prev) - 1]) - ord('a')
can_eliminate = False
for i in range(len(words[start])):
    if select == "": select = words[start][0]
    
    length = len(words[start][i])
    next_start = words[start][i][length-1]
    
    if next_start != words[start][i][0]:
        if len(words[ord(next_start) - ord('a')]) == 0:
            select = words[start][i]
            can_eliminate = True
    
    else:
        if len(words[ord(next_start) - ord('a')]) == 1:
            select = words[start][i]
            can_eliminate = True
 
    if can_eliminate == True: break
    
if select == "": print("?")
elif select != "" and can_eliminate == False: print(select)
else: print(select + "!")
