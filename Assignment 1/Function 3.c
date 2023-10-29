#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a student
struct Student {
    int student_number;
    char name[50];
    int age;
    struct Student *next; // Pointer to the next student in the list
};

// Function to print student information and count students
int printStudentList(struct Student *head) {
    int count = 0;
    struct Student *current = head;

    while (current != NULL) {
        printf("%d - %s %d %d\n", current->student_number, current->name, current->age, current->student_number + 200);
        count++;
        current = current->next;
    }

    return count;
}

int main() {
    // Create a linked list of students
    struct Student *head = NULL;
    struct Student *current = NULL;
    
    // Add student information to the list
    for (int i = 1; i <= 5; i++) {
        struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
        newStudent->student_number = i;
        sprintf(newStudent->name, "Student%d", i);
        newStudent->age = 18 + i;
        newStudent->next = NULL;

        if (head == NULL) {
            head = newStudent;
            current = head;
        } else {
            current->next = newStudent;
            current = newStudent;
        }
    }

    // Call the function to print student information and count students
    int studentCount = printStudentList(head);
    printf("Total students: %d\n", studentCount);

    // Free memory by deallocating the linked list
    current = head;
    while (current != NULL) {
        struct Student *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
