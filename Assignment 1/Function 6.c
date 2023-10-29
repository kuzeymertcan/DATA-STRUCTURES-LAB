#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a student
struct Student {
    int student_number;
    char name[50];
    int age;
    struct Student *next; // Pointer to the next student in the list
};

// Function to find and print the student with the longest name
void printStudentWithLongestName(struct Student *head) {
    struct Student *current = head;
    char longestName[50];
    int maxLength = 0;

    while (current != NULL) {
        int currentLength = strlen(current->name);
        if (currentLength > maxLength) {
            maxLength = currentLength;
            strcpy(longestName, current->name);
        }
        current = current->next;
    }

    if (maxLength > 0) {
        printf("The longest name in the list: %s\n", longestName);
        printf("Length: %d\n", maxLength);
    } else {
        printf("No students in the list.\n");
    }
}

int main() {
    // Create a linked list of students
    struct Student *head = NULL;
    struct Student *current = NULL;
    
    // Add student information to the list
    struct Student student1 = {1, "John", 20, NULL};
    struct Student student2 = {2, "Alice", 22, NULL};
    struct Student student3 = {3, "Abdurrahmangazi", 25, NULL};
    struct Student student4 = {4, "Eleanor", 21, NULL};
    struct Student student5 = {5, "Michael", 19, NULL};

    head = &student1;
    student1.next = &student2;
    student2.next = &student3;
    student3.next = &student4;
    student4.next = &student5;

    // Call the function to find and print the student with the longest name
    printStudentWithLongestName(head);

    return 0;
}
