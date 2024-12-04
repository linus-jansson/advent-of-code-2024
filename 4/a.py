import sys
def count_word_occurrences(grid, word):
    n_rows = len(grid)
    n_cols = len(grid[0]) if grid else 0
    word_length = len(word)
    directions = [(-1, 0), (-1, 1), (0, 1), (1, 1),
                  (1, 0), (1, -1), (0, -1), (-1, -1)]
    total_count = 0
    for i in range(n_rows):
        for j in range(n_cols):
            if grid[i][j] == word[0]:
                for dx, dy in directions:
                    x, y = i, j
                    for k in range(1, word_length):
                        x += dx
                        y += dy
                        if 0 <= x < n_rows and 0 <= y < n_cols:
                            if grid[x][y] != word[k]:
                                break
                        else:
                            break
                    else:
                        total_count += 1
    return total_count

if __name__ == "__main__":
    grid = [line.strip() for line in sys.stdin if line.strip()]
    word = "XMAS"
    result = count_word_occurrences(grid, word)
    print(result)
