import sys

sys.set_int_max_str_digits(0)


class Solution:
    def largestPalindrome(self, n: int, k: int) -> str:
        if k == 1 or k == 3 or k == 9:
            return '9' * n
        elif k == 2:
            if n <= 2:
                return '8' * n
            return '8' + '9' * (n - 2) + '8'
        elif k == 4:
            if n <= 4:
                return '8' * n
            return '88' + '9' * (n - 4) + '88'
        elif k == 5:
            if n <= 2:
                return '5' * n
            return '5' + '9' * (n - 2) + '5'
        elif k == 6:
            if n <= 2:
                return '6' * n
            v = ['8'] + ['9'] * (n - 2) + ['8']
            if n & 1:
                v[n // 2] = '8'
            else:
                v[n // 2] = v[n // 2 - 1] = '7'
            return ''.join(v)
        elif k == 8:
            if n <= 6:
                return '8' * n
            return '888' + '9' * (n - 6) + '888'
        elif k == 7:
            x = 10 ** n - 1
            mid = 10 ** (n // 2)
            if n & 1:
                while x % k:
                    x -= mid
            else:
                mid1 = 10 ** (n // 2 - 1)
                while x % k:
                    x -= mid + mid1
            return str(x)
