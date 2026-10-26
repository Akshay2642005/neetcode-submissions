class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res = []

        def backtrack(start, rem, path):
            if rem == 0:
                res.append(path[:])
                return
            for i in range(start, len(nums)):
                if nums[i] > rem:
                    break
                path.append(nums[i])
                backtrack(i, rem - nums[i], path)
                path.pop()
        backtrack(0, target, [])
        return res
        