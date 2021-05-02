class codec:

    def encode(self, strs):
        """encodes a list of strings to a single string.

        :type strs: list[str]
        :rtype: str
        """
        o = '{}|pijamasx|'.format(len(strs))
        return o + '|pijamasx|'.join(strs)

    def decode(self, s):
        """decodes a single string to a list of strings.

        :type s: str
        :rtype: list[str]
        """
        contents = s.split('|pijamasx|')
        n = int(contents[0])
        contents = contents[1:]
        if n == 0:
            return []
        return contents[:n]

strs = []
strs1 = ['']
strs2 = ['asd', 'plm']
strs3 = ["4|t","f%@"]
strs4 = ['', 'PJ|', 'Q.12 awD']
# Your Codec object will be instantiated and called as such:
codec = Codec()
assert codec.decode(codec.encode(strs)) == strs
assert codec.decode(codec.encode(strs1)) == strs1
assert codec.decode(codec.encode(strs2)) == strs2
assert codec.decode(codec.encode(strs3)) == strs3
assert codec.decode(codec.encode(strs4)) == strs4
