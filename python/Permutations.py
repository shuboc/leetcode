class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        return self.permuteHelper(nums, [])

    def permuteHelper(self, nums, res):
        if len(nums) == 0:
            return res

        to_ins = nums.pop()
        if len(res) == 0:
            return self.permuteHelper(nums, [[to_ins]])
        else:
            tmp_res = []
            for sub_perm in res:
                for i in range(len(sub_perm) + 1):
                    tmp_perm = list(sub_perm)
                    tmp_perm.insert(i, to_ins)
                    tmp_res.append(tmp_perm)

            return self.permuteHelper(nums, tmp_res)

        