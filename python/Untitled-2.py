def change_nums(start, cnt):
    global ans, nums
    if cnt == change:
        ans.append(nums)
        return
    else:
        for i in range(start, len(nums)-1):
            for j in range(i+1, len(nums)):
                nums[i], nums[j] = nums[j], nums[i]
                change_nums(start+1, cnt+1)
                nums[i], nums[j] = nums[j], nums[i]

T = int(input())
for tc in range(1, T+1):
    nums_a, change_a = input().split()
    nums, change = list(nums_a), int(change_a)
    change_nums(0, 0)
    print(nums)
    ans = []