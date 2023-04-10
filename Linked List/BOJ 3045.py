from bisect import bisect_left
input = __import__('sys').stdin.readline

n,m = map(int,input().split())
prev = [i-1 for i in range(n+1)]
next = [i+1 for i in range(n+1)]


for i in range(m):
    a,b,c = input().split()
    b=int(b)
    c=int(c)
    if next[b] != n + 1: prev[next[b]] = prev[b]
    if prev[b] != -1: next[prev[b]] = next[b]
    if a=='A':
        if prev[c]!=-1: next[prev[c]]=b
        next[b]=c
        prev[b]=prev[c]
        prev[c]=b
    else:
        if next[c]!=n+1: prev[next[c]]=b
        next[b]=next[c]
        prev[b]=c
        next[c]=b

l, p = [], 0
while True:
    p=next[p]
    if p==n+1: break
    l.append(p)

S = [-1]
SS = []
idx = [0]*n
for i,ll in enumerate(l):
    if S[-1]<ll:
        S.append(ll)
        idx[i]=len(S)-2
    else:
        j = bisect_left(S,ll)
        S[j]=ll
        idx[i]=j-1

print(n-len(S)+1)

a = len(S)-2
lis = []
lis_set = set()
for i in range(n-1,-1,-1):
    if idx[i]==a:
        lis.append(l[i])
        lis_set.add(l[i])
        a-=1
        
lis.reverse()

for i in lis:
    j=i-1
    while 0<j and j not in lis_set: print(f'A {j} {j+1}'); j-=1
      
i, j = lis[-1], i+1
while j<n+1: 
  print(f'B {j} {j-1}'); j+=1
