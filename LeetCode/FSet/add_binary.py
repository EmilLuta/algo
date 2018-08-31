class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        n = len(a)
        m = len(b)
        a = a[::-1]
        b = b[::-1]
        x = max(n, m)
        i = 0
        r = 0
        o = ''
        while i < x:
            f = 0
            s = 0
            if i < n:
                f = int(a[i])
            if i < m:
                s = int(b[i])
            d, mod = divmod(f + s + r, 2)
            o = str(mod) + o
            r = d
            i += 1
        if r == 1:
            o = '1' + o
        return o


print(Solution().addBinary('1010', '1011'))
print(Solution().addBinary('11', '1'))
