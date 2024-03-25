from typing import List

from sortedcontainers import SortedList


class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        s1, s2 = SortedList([nums[0]]), SortedList([nums[1]])
        arr1, arr2 = [nums[0]], [nums[1]]

        def greater_count(s: SortedList, x: int):
            return len(s) - s.bisect_right(x)

        for i in range(2, len(nums)):
            x, y = greater_count(s1, nums[i]), greater_count(s2, nums[i])
            if x > y:
                arr1.append(nums[i])
                s1.add(nums[i])
            elif x < y:
                arr2.append(nums[i])
                s2.add(nums[i])
            else:
                if len(arr1) <= len(arr2):
                    arr1.append(nums[i])
                    s1.add(nums[i])
                else:
                    arr2.append(nums[i])
                    s2.add(nums[i])
        return arr1 + arr2
