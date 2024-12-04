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
    // Sort both lists
    qsort(left_list, size, sizeof(int), compare);
    qsort(right_list, size, sizeof(int), compare);
    
    // Calculate the total distance
    int total_distance = 0;
    for (int i = 0; i < size; i++) {
        total_distance += abs(left_list[i] - right_list[i]);
    }
    
    return total_distance;
}

int main() {
    // Example input lists
    int left_list[LIST_SIZE_I_DONT_WANT_TO_REALLOCATE], right_list[LIST_SIZE_I_DONT_WANT_TO_REALLOCATE]; // Assuming a max of 1000 pairs for simplicity
    int size = 0;

    // Read input pairs until EOF
    while (scanf("%d %d", &left_list[size], &right_list[size]) == 2) {
        size++;
    }

    // Calculate and print the total distance
    int total_distance = calculate_total_distance(left_list, right_list, size);
    printf("%d\n", total_distance);

    return 0;
}
