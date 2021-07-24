import sys

n,k,p,x=map(int,sys.stdin.readline().split())
num=[0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011, 0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1111011]

arr=[[0 for j in range(10)] for i in range(10)]
for i in range(10):
    for j in range(10):
        xor = num[i]^num[j]
        while xor != 0:
            if xor & 1 == 1: arr[i][j]+=1
            xor = xor >> 1

st=str(x)
while len(str(x))<k: st='0'+st

def func(dep, cnt, s):
    global x, n
    if dep>=len(s):
        if int(s)==x: return 0
        if int(s)>=1 and int(s)<=n: return 1
        return 0
    
    sum=0
    cur=int(s[dep])
    for i in range(10):
        if cur != i and arr[cur][i]<=cnt:
            a=list(map(str,str(s)))
            a[dep]=str(i)
            sum+=func(dep+1,cnt-arr[cur][i],"".join(a))
        if cur==i: sum+=func(dep+1, cnt, s)
    return sum

print(func(0,p,st))