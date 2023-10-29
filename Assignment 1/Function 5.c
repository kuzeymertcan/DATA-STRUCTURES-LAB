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

// Function to search for a student by name and delete the next node
void deleteNextStudent(struct Student *head, const char *searchName) {
    struct Student *current = head;

    while (current != NULL) {
        if (strcmp(current->name, searchName) == 0 && current->next != NULL) {
            // Found the student with the matching name and there is a next student
            struct Student *temp = current->next; // Temporarily store the next student
            current->next = temp->next; // Update the pointer to skip the next student
            free(temp); // Free the memory of the deleted student
            printf("Deleted the next student after %s.\n", searchName);
            return;
        }
        current = current->next;
    }

    printf("No student found with name '%s' or there is no next student to delete.\n", searchName);
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

    // Delete the next student after a specific student by name
    deleteNextStudent(head, "Student3");
    deleteNextStudent(head, "Student5"); // This should indicate that there is no next student after Student5.

    // Free memory by deallocating the linked list
    current = head;
    while (current != NULL) {
        struct Student *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
