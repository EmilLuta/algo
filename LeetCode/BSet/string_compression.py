class Solution:
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        n = len(chars)
        count = 0
        prev = chars[0]
        start = 0
        for i in range(n):
            if prev == chars[i]:
                count += 1
            else:
                if count == 1:
                    chars[start] = prev
                    prev = chars[i]
                    start += 1
                    count = 1
                else:
                    chars[start] = prev
                    start += 1
                    x = str(count)
                    for j in range(len(x)):
                        chars[start] = x[j]
                        start += 1
                    count = 1
                    prev = chars[i]
        # import code
        # code.interact(local=locals())
        chars[start] = prev
        start += 1
        print(chars)
        if count == 1:
            return start
        x = str(count)
        for j in range(len(x)):
            chars[start] = x[j]
            start += 1
        print(chars)
        return start

print(Solution().compress(['a', 'a', 'a', 'a', 'b', 'a']))
