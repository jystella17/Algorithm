import sys

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    phone_num = [str(sys.stdin.readline().strip()) for _ in range(n)]
    phone_num.sort() 
    chek = "yes" 
    
    for i in range(len(phone_num) - 1):
        if phone_num[i] == phone_num[i + 1][0:len(phone_num[i])]:
            chek = "no"

    if chek == "no":
        print("NO")
    else:
        print("YES")
