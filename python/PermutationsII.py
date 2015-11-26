class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        used = [False] * len(nums)
        res = []
        self.permuteRec(nums, used, [], res)
        return res

    def permuteRec(self, nums, used, perm, res):
        if len(perm) == len(nums):
            res.append(list(perm)) # Don't forget to make a copy
            return

        for i in xrange(len(nums)):
            if not used[i] and not (i > 0 and nums[i-1] == nums[i] and used[i-1]): # Omit
                perm.append(nums[i])
                used[i] = True
                self.permuteRec(nums, used, perm, res)
                used[i] = False
                perm.pop()