# LeetCode: 118. Pascal's Triangle
# Difficulty: Easy
# Link: https://leetcode.com/problems/pascals-triangle/?envType=daily-question&envId=2025-08-01

from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        triangle = []

        for i in range(numRows):
            row = [1] * (i + 1) 
            for j in range(1, i):
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
            triangle.append(row)

        return triangle

# Time Complexity: O(n^2)
# Space Complexity: O(n^2)
# Where n = numRows
