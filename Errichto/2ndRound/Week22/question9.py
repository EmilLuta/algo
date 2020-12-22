'''
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
'''

class Solution:
    def getMoneyAmount(self, n: int) -> int:
        start = 1
        end = n
        s = 0
        while start < end:
            if end - start == 1:
                return start + s
            else:
                middle = (end + start + 1) // 2
            s += middle
            if middle + 1 == n:
                end = middle - 1
            else:
                start = middle + 1
        return s


class Solution:
    def getMoneyAmount(self, n: int) -> int:
        if n % 2 == 0:
            return sum(i for i in range(1, n, 2))
        return sum(i for i in range(2, n, 2))


from functools import lru_cache

@lru_cache(maxsize=None)
def cost(L, R):
    if L >= R:
        return 0
    best = float('inf')
    best_i = -1
    for i in range(L, R + 1):
        maybe = i + max(cost(L, i-1), cost(i+1, R))
        if maybe < best:
            best = maybe
            best_i = i
    if L == 1 or R == 7:
        print(L, R, best_i)
    return best

N = 10
print(cost(1, N))
