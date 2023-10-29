#include <stdio.h>
#include <stdlib.h>

int main() {
    int numbers[100];  // Assuming a maximum of 100 numbers, you can adjust the size if needed
    int count = 0;
    int number;

    while (1) {
        printf("Enter a number (-1 to stop): ");
        scanf("%d", &number);

        if (number == -1) {
            break;  // Exit the loop when -1 is entered
        }

        if (number % 2 == 1) {
            // Add odd numbers to the beginning of the list
            for (int i = count; i > 0; i--) {
                numbers[i] = numbers[i - 1];
            }
            numbers[0] = number;
            count++;
        } else {
            // Add even numbers to the end of the list
            numbers[count] = number;
            count++;
        }
    }

    printf("Resulting list: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
