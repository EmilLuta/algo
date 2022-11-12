- https://codingcompetitions.withgoogle.com/codejam/round/0000000000877b42/0000000000afdf76
    Didn't manage to solve the problem. There's a math property that I need to look at: https://en.wikipedia.org/wiki/Multinomial_theorem

- https://atcoder.jp/contests/abc251
    Not sure how to tackle this problem -- tried to decompose it but I see no direct way out.

- https://codeforces.com/contest/1680/problem/C
    Got a working idea -- what if I try to compute the data and look backwards for my 1s.
    If I know I have x ones used already, I know I need to be left with at most x 0s. I can look backwards what needs to be done and see if it's possible.
    Approach.
        Compute from front what's the best case scenario (already got code for that).
        Go from behind, look at where I am and if I can match from front.
        Store answer as I go.

- https://codeforces.com/contest/1668/problem/D
    Looks like approachable problem, I need to put my head through it
