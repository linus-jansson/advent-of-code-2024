import sys
grid = [line.strip() for line in sys.stdin if line.strip()]
n_rows = len(grid)
n_cols = len(grid[0]) if grid else 0
total_count = 0
for i in range(1, n_rows - 1):
    for j in range(1, n_cols - 1):
        if grid[i][j] == 'A':
            c1 = grid[i - 1][j - 1]
            c2 = grid[i + 1][j + 1]
            c3 = grid[i - 1][j + 1]
            c4 = grid[i + 1][j - 1]
            match1 = 1 if (c1 == 'M' and c2 == 'S') or (c1 == 'S' and c2 == 'M') else 0
            match2 = 1 if (c3 == 'M' and c4 == 'S') or (c3 == 'S' and c4 == 'M') else 0
            if match1 and match2:
                total_count += 1
print(total_count)
