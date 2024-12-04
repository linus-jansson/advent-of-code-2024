#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LIST_SIZE_I_DONT_WANT_TO_REALLOCATE 1000
// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to calculate the total distance
int calculate_total_distance(int *left_list, int *right_list, int size) {
    // Calculate the total distance
    int total_distance = 0;
    for (int i = 0; i < size; i++) {
        total_distance += abs(left_list[i] - right_list[i]);
    }
    
    return total_distance;
}

int calculate_similarity(int *left_list, int *right_list, int size) {
  // for each number in the left_list calculate
  // how many times the number appears in the right_list
  // Add up each number in the left list after multiplying 
  // it by the number of times it appears in the right list
  int similarity = 0;
  for (int i = 0; i < size; i++) {
    int count = 0;
    for (int j = 0; j < size; j++) {
      if (left_list[i] == right_list[j]) {
        count++;
      }
    }
    similarity += left_list[i] * count;
  }
  return similarity;
}

int main() {
    int left_list[LIST_SIZE_I_DONT_WANT_TO_REALLOCATE], right_list[LIST_SIZE_I_DONT_WANT_TO_REALLOCATE]; // Assuming a max of 1000 pairs for simplicity
    int size = 0;

    // Read input pairs until EOF
    while (scanf("%d %d", &left_list[size], &right_list[size]) == 2) {
        size++;
    }

    // Sort both lists
    qsort(left_list, size, sizeof(int), compare);
    qsort(right_list, size, sizeof(int), compare);

    // Calculate and print the total distance
    int total_distance = calculate_total_distance(left_list, right_list, size);
    printf("%d\n", total_distance);
    int similarity = calculate_similarity(left_list, right_list, size);
    printf("%d\n", similarity);

    return 0;
}
