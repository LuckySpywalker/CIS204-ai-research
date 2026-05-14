#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int main(void)
{
    // Ask the user how many student records they want to enter.
    int numStudents;
    printf("How many student records do you want to enter? ");
    if (scanf("%d", &numStudents) != 1 || numStudents <= 0) {
        fprintf(stderr, "Invalid number of students.\n");
        return 1;
    }

    // Clear any leftover newline from the integer input.
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        ;
    }

    // Allocate an array of Student objects using malloc.
    Student *students = malloc(numStudents * sizeof(Student));
    if (students == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for students array.\n");
        return 1;
    }

    // For each student index:
    for (int i = 0; i < numStudents; i++) {
        if (i > 0) {
            printf("\n");
        }

        const char *label;
        if (i == 0) {
            label = "First Student";
        } else if (i == 1) {
            label = "Second Student";
        } else if (i == 2) {
            label = "Third Student";
        } else if (i == 3) {
            label = "Fourth Student";
        } else if (i == 4) {
            label = "Fifth Student";
        } else {
            label = "Next Student";
        }

        printf("%s\n", label);

        //   - call createStudent() to build a single Student record.
        //   - store the returned Student pointer in the array.
        Student *newStudent = createStudent();
        if (newStudent == NULL) {
            free(students);
            return 1;
        }
        students[i] = *newStudent;
        free(newStudent);
    }

    // Calculate the average age using averageAge(). 
    double avgAge = averageAge(students, numStudents);
    // Calculate the average GT score using averageScore().
    double avgScore = averageScore(students, numStudents);

    // Print the student table using printTable().
    printTable(students, numStudents);
    // Print the average age and average GT score in a clear format.
    printf("Average Age: %.2f\n", avgAge);
    printf("Average Original GT Score: %.2f\n", avgScore);

    // Free any allocated memory for the student records.
    free(students);
    // Return 0 to indicate successful program execution.
    return 0;
}
