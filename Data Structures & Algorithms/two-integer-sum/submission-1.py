class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        mydict = {}
        mydict[nums[0]] = 0

        for n in range(1,len(nums)):
            if target - nums[n] in mydict:
                return [mydict[target-nums[n]],n]
            if nums[n] not in mydict:
                mydict[nums[n]] = n

        return []
        