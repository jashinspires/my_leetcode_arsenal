class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        shifted_grid = [[ 0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                new_column = (j + k) % n
                rows_moved = (j + k) / n
                new_row = (i + rows_moved) % m
                shifted_grid[int(new_row)][int(new_column)] = grid[i][j]
        return shifted_grid
