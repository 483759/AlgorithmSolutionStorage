import sys

sys.stdin=open("python/input.txt","r")
arr[0]=list(map(int,sys.stdin.readline().split()))

v=[0,0,arr[2]]
visit=[False, False, False]
ans=set()
def func(cur):
    global visit, v
    if visit[cur]: return
    ans.add(v[2])
    
    for i in range(3):
        if i==cur: continue
        if v[i]==arr[i] or visit[i]: continue
        visit[i]=True
        v[i]+=arr[i]-v[cur]
        func(i)
        v[i]-=arr[i]-v[cur]
        visit[i]=False

func(2)

print(ans,end=" ")