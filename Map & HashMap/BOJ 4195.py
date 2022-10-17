import sys


input= sys.stdin.readline
tc = int(input().rstrip())

def init(friend):
    parent[friend] = friend
    number[friend] = 1

def find(target):
    if target==parent[target]:
        return target
    parent[target]=find(parent[target])
    return parent[target]

def union(a,b):
    a=find(a)
    b=find(b)
    
    if a !=b:
        parent[b]=a
        number[a]+=number[b]

for _ in range(tc):
    parent=dict()
    number=dict()
    F = int(input().rstrip())
    
    for _ in range(F):
        f_1,f_2=input().rstrip().split()
        
        if f_1 not in parent:
            init(f_1)
        if f_2 not in parent:
            init(f_2)
            
        union(f_1,f_2)
        print(number[find(f_1)])
