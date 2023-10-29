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

// Function to search for a student by name and print their information
void searchStudentByName(struct Student *head, const char *searchName) {
    struct Student *current = head;
    int found = 0; // Flag to indicate if the student is found

    while (current != NULL) {
        if (strcmp(current->name, searchName) == 0) {
            printf("Student found: %d - %s %d %d\n", current->student_number, current->name, current->age, current->student_number + 200);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("Student with name '%s' not found.\n", searchName);
    }
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

    // Search for a student by name
    searchStudentByName(head, "Student3");
    searchStudentByName(head, "Student6"); // This should print "Student not found."

    // Free memory by deallocating the linked list
    current = head;
    while (current != NULL) {
        struct Student *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
