class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        tried = False
        for i in range(0, len(nums) - 1):
            if i == 0:
                if nums[i] <= nums[i+1]:
                    i += 1
                    continue
                tried = True
                nums[i+1] = min(nums[i+1], nums[i])
                nums[i] = nums[i+1]
            else:
                if nums[i+1] < nums[i-1]:
                    if nums[i] >= nums[i-1]:
                        if tried:
                            return False
                        tried = True
                        nums[i+1] = nums[i]
                    
                elif nums[i-1] <= nums[i+1]:
                    if nums[i-1] <= nums[i] <= nums[i+1]:
                        i += 1
                        continue
                    if tried:
                        return False
                    tried = True
                    nums[i] = nums[i-1]
            i += 1
        return True