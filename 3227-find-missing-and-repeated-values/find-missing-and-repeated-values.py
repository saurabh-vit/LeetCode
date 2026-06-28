class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        x = n*n
        freq = {}
        for row in grid:
            for num in row:
                freq[num] = freq.get(num, 0) + 1

        rep, miss = 0, 0 
        for i in range(1, x+1):
            if freq.get(i, 0) == 2:
                rep = i
            elif freq.get(i, 0) == 0:
                miss = i
        return [rep, miss]