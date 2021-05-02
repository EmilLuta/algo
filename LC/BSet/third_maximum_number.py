class Solution:
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m_inf = float('-inf')
        one = two = three = m_inf
        for n in nums:
            if n > one:
                one, two, three = n, one, two
            elif n > two and n < one:
                two, three = n, two
            elif n > three and n < two:
                three = n
        if three != m_inf:
            return three
        return one
