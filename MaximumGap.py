class Solution:
    # @param num, a list of integer
    # @return an integer
    def maximumGap(self, num):
        
        if len(num) < 2:
            return 0
        
        # Remove duplication
        num_dict = {}
        for n in num:
            num_dict[n] = 1
        num = num_dict.keys()

        # Put n-2 numbers into n-1 buckets (exclude min and max)
        max_num = max(num)
        min_num = min(num)
        gap = (max_num-min_num) / (len(num)-1)
        bucket_size = (max_num - min_num) / gap + 1
        min_bucket = [float("inf") for _ in xrange(bucket_size)]
        max_bucket = [float("-inf") for _ in xrange(bucket_size)]
        
        for n in num:
            if n in (max_num, min_num):
                continue
            idx = (n-min_num) / gap
            max_bucket[idx] = max(n, max_bucket[idx])
            min_bucket[idx] = min(n, min_bucket[idx])
        
        # Calculate gap between buckets (Max gap must be larger than gap)
        max_gap = float("-inf")
        last_max = min_num
        for i in xrange(bucket_size):
            if max_bucket[i] == float("-inf"): # No element in this bucket
                continue
            max_gap = max(max_gap, min_bucket[i] - last_max)
            last_max = max_bucket[i]
        max_gap = max(max_num-last_max, max_gap)
            
        return max_gap
