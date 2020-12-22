'''
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
'''

# V1 - Wrong - [1,2,3,4,5,6,7]

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        nums.sort()
        pref = [0]
        for i in range(n):
            pref.append(pref[-1] + nums[i])
        for i in range(n + 1):
            if pref[n] - pref[i] == pref[i] - pref[0]:
                return True
        return False

# V2 - Wrong - [23,13,11,7,6,5,5]

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        s = sum(nums)
        if s % 2 != 0:
            return False
        target = s // 2
        while target != 0:
            good = 0
            index = -1
            for i in range(n):
                if nums[i] <= target and nums[i] > good:
                    good = nums[i]
                    index = i
            if good == 0:
                return False
            target -= good
            nums[index] = 0
        return True
