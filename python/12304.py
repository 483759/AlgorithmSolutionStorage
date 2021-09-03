import sys
sys.stdin = open('input.txt')

T = int(input())
for tc in range(1, T+1):
    N = int(input())
    P = list(map(int, input().split()))
    result = P[:]
    three = []

    for p in P:
        x, y = 0, 0
        a = result.pop(x)
        three.append(a)
        while y < len(result):
            if result[y] == (p//3)*4:
                result.pop(y)
                break
            y += 1
    print('Case #{}:'.format(tc), *three)

# import sys

# sys.stdin=open('python/input.txt','r')
# input=sys.stdin.readline

# tc=int(input())
# for t in range(1, tc+1):
#   n=int(input())
#   arr=list(map(int,input().split()))
#   ans=[]
#   q=[]

#   while len(arr)!=0:
#     if len(q)==0 or q[0]!=arr[0]:
#       ans.append(arr[0])
#       q.append(int((arr[0]/3)*4))
#     else:
#       q.pop(0)
#     arr.pop(0)

#   print('Case #{}:'.format(t), *ans)
