def findMiddleIndex(nums) -> int:
    leftSum=0
    rightSum=sum(nums)-nums[0]
    
    middleIndex=0
    while middleIndex < len(nums):
        if leftSum==rightSum: return middleIndex
        leftSum+=nums[middleIndex]
        middleIndex+=1
        if middleIndex < len(nums): rightSum-=nums[middleIndex]
    return -1
    

print(findMiddleIndex([2,3,-1,8,4]))