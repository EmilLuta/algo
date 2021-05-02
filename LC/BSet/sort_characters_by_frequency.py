class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        return "".join([char * times for char, times in collections.Counter(s).most_common()])
