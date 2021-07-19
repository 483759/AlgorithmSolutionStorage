n=int(input())
arr=[]
for i in range(n):
    arr.append(list(map(int,input().split())))

dr=[0,1,0,1]
dc=[0,0,1,1]

def divide(r, c, n, arr):
    if n==1:
        return arr[r][c]
    else:
        num=[]
        global dr
        global dc
        for i in range(4):
            num.append(divide(r+(n//2)*dr[i],c+(n//2)*dc[i],n//2,arr))
        return conquer(num)

def conquer(num):
    return sorted(num)[2]
print(divide(0,0,n,arr))