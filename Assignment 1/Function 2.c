#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to compare two integers for qsort
int compareIntegers(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int numbers[100];
    int count = 0;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate and add 100 random numbers to the list
    for (int i = 0; i < 100; i++) {
        numbers[count] = rand() % 1000; // Assuming a range of 0 to 999, you can adjust as needed
        count++;
    }

    // Sort the numbers in descending order
    qsort(numbers, count, sizeof(int), compareIntegers);

    // Print the sorted numbers
    printf("Sorted numbers (from largest to smallest):\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
