package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func isSafe(levels []int) bool {
	if len(levels) < 2 {
			return false
	}

	// Determine the initial trend based on the first difference
	diff := levels[1] - levels[0]
	if diff == 0 || abs(diff) < 1 || abs(diff) > 3 {
			return false
	}
	trend := diff / abs(diff) // trend is either -1 (decreasing) or 1 (increasing)

	for i := 2; i < len(levels); i++ {
			diff = levels[i] - levels[i-1]
			if diff == 0 || abs(diff) < 1 || abs(diff) > 3 || (diff/abs(diff) != trend) {
					return false
			}
	}

	return true
}

func isSafeWithDampener(levels []int) bool {
	if isSafe(levels) {
			// The report is safe under the original rules.
			return true
	}

	// Try removing each level to see if the report becomes safe.
	for i := 0; i < len(levels); i++ {
			// Create a copy of levels without the ith element.
			levelsWithoutI := append([]int{}, levels[:i]...)
			levelsWithoutI = append(levelsWithoutI, levels[i+1:]...)

			if len(levelsWithoutI) < 2 {
					continue // Need at least two levels to check the rules.
			}

			if isSafe(levelsWithoutI) {
					// The report becomes safe after removing one level.
					return true
			}
	}

	// The report cannot be made safe even after removing one level.
	return false
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	safeCount := 0
	safeWithDampener := 0

	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.Fields(line)
		levels := make([]int, len(parts))

		for i, part := range parts {
			level, err := strconv.Atoi(part)
			if err != nil {
				fmt.Printf("Invalid number in input: %s\n", part)
				return
			}
			levels[i] = level
		}

		if isSafe(levels) {
			safeCount++
		}

		if isSafeWithDampener(levels) {
			safeWithDampener++
		}
	}

	if err := scanner.Err(); err != nil {
		fmt.Printf("Error reading input: %v\n", err)
		return
	}

	fmt.Printf("%d\n", safeCount)
	fmt.Printf("%d\n", safeWithDampener)
}
