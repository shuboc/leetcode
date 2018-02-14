/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
  nums.sort((a, b) => (a-b)) // Sort by number

  const res = []
  for (let i = 0; i < nums.length - 2; ++i) {
      if (i > 0 && nums[i] === nums[i-1]) continue

      // Calculate sum and adjust j and k accordingly
      let j = i + 1, k = nums.length - 1
      while (j < k) {
          const sum = nums[i] + nums[j] + nums[k]
          if (sum === 0) {
              res.push([nums[i], nums[j], nums[k]])

              // To find unique answers,
              // we have to find the first different numbers other than original nums[j] and nums[k]
              // -2 -1 -1 1 1 2
              //    j       k
              //       j  k
              //    ^^^^^^^^^ these j, k create repeated tuples
              ++j
              while (nums[j] === nums[j-1]) ++j

              --k
              while (nums[k] === nums[k+1]) --k
          } else if (sum < 0) {
              ++j
          } else {
              --k
          }
      }
  }

  return res
};