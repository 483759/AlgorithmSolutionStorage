import sys

t=int(sys.stdin.readline())

def binarySearch(n, k, arr):
    left=0
    right=n
    while left+1<right:
        mid=(left+right)//2
        if arr[mid]==k:
            return True
        elif arr[mid]>k:
            right=mid
        else:
            left=mid
    if arr[left]==k: return True
    return False

def solution():
    n=int(sys.stdin.readline())
    arr1=list(map(int,sys.stdin.readline().split()))
    arr1.sort()
    
    m=int(sys.stdin.readline())
    arr2=list(map(int,sys.stdin.readline().split()))
    for a in arr2:
        if binarySearch(n,a,arr1): print(1)
        else: print(0)

for _ in range(t):
    solution()