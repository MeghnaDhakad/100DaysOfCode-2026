# Longest Palindrome

class Solution(object):
    def longestPalindrome(self, s):
        freq = {}

        for char in s:
            freq[char] = freq.get(char, 0) + 1

        length = 0
        has_odd = False

        for count in freq.values():
            length += (count // 2) * 2

            if count % 2 == 1:
                has_odd = True

        if has_odd:
            length += 1

        return length