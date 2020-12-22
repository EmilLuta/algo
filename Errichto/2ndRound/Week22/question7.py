'''
https://leetcode.com/problems/candy/

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.
'''

class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        if n == 0:
            return 0
        if n == 1:
            return 1
        answer = [0] * n
        padded_ratings = [float('inf')] + ratings + [float('inf')]
        i = 1
        give_ratings = []
        while i < n + 2 - 1:
            if padded_ratings[i - 1] > padded_ratings[i] and padded_ratings[i + 1] > padded_ratings[i]:
                give_ratings.append(i - 1)
            if padded_ratings[i - 1] == padded_ratings[i]:
                start = max(i - 2, 0)
                while i < n + 2 - 1 and padded_ratings[i - 1] == padded_ratings[i]:
                    i += 1
                if padded_ratings[start] > padded_ratings[i - 1] and padded_ratings[i] > padded_ratings[i - 1]:
                    give_ratings.append(i - 2)
                continue
            i += 1
        for rating in give_ratings:
            answer[rating] = 1
            i = rating - 1
            while i >= 0 and i < n - 1 and ratings[i] >= ratings[i + 1]:
                if ratings[i] > ratings[i + 1]:
                    answer[i] = max(answer[i], answer[i + 1] + 1)
                if ratings[i] == ratings[i + 1]:
                    answer[i] = max(answer[i], 1)
                i -= 1
            i = rating + 1
            while i < n and i > 0 and ratings[i] >= ratings[i - 1]:
                if ratings[i] == ratings[i - 1]:
                    answer[i] = max(answer[i], 1)
                if ratings[i] > ratings[i - 1]:
                    answer[i] = max(answer[i], answer[i - 1] + 1)
                i += 1
        return sum(answer)
