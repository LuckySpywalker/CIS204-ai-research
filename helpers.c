#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "helpers.h"

static void readLine(char *buffer, size_t size, const char *prompt)
{
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
}

static bool parseInt(const char *text, int *value)
{
    char *endptr;
    long parsed = strtol(text, &endptr, 10);
    if (endptr == text || *endptr != '\0') {
        return false;
    }
    if (parsed < INT_MIN || parsed > INT_MAX) {
        return false;
    }
    *value = (int)parsed;
    return true;
}

Student *createStudent(void)
{
    // Allocate memory for a new Student structure.
    Student *newStudent = malloc(sizeof(Student));
    if (newStudent == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for new student.\n");
        return NULL;
    }

    // Prompt the user for first name, last name, rank, age, and original GT score.
    readLine(newStudent->firstName, sizeof(newStudent->firstName), "Enter first name: ");
    readLine(newStudent->lastName, sizeof(newStudent->lastName), "Enter last name: ");
    readLine(newStudent->rank, sizeof(newStudent->rank), "Enter rank: ");

    char line[32];
    do {
        readLine(line, sizeof(line), "Enter age: ");
        if (!parseInt(line, &newStudent->age) || newStudent->age <= 0) {
            printf("Please enter a valid whole number for age.\n");
        }
    } while (!parseInt(line, &newStudent->age) || newStudent->age <= 0);

    do {
        readLine(line, sizeof(line), "Enter original GT score: ");
        if (!parseInt(line, &newStudent->origGTScore) || newStudent->origGTScore < 0) {
            printf("Please enter a valid whole number for the GT score.\n");
        }
    } while (!parseInt(line, &newStudent->origGTScore) || newStudent->origGTScore < 0);

    // Set the printed flag to false initially.
    newStudent->printed = false;
    // Return the pointer to the newly allocated Student.
    return newStudent;
}

float averageAge(Student *students, int count)
{
    // Loop through the array of Student records.
    float totalAge = 0.0f;
    for (int i = 0; i < count; i++) {
        totalAge += students[i].age;
    }
    // Add each student's age to a running total.
    // Divide the total age by the number of students.
    // Return the result as a floating-point average.
    return totalAge / count;
}

float averageScore(Student *students, int count)
{
    // Loop through the array of Student records.
    float totalScore = 0.0f;
    for (int i = 0; i < count; i++) {
        totalScore += students[i].origGTScore;
    }
    // Add each student's original GT score to a running total.
    // Divide the total score by the number of students.
    // Return the result as a floating-point average.
    return totalScore / count;
}

void printTable(Student *students, int count)
{
    // Print a header row for the table columns.
    printf("%-15s %-20s %-15s %5s %7s\n", "First Name", "Last Name", "Rank", "Age", "GT Score");
    printf("-----------------------------------------------------------------\n");
    // For each Student in the list:
    for (int i = 0; i < count; i++) {
        // Check if the printed flag is false.
        if (!students[i].printed) {
            // If so, print the student's details in a formatted row.
            printf("%-15s %-20s %-15s %5d %7d\n",
                   students[i].firstName,
                   students[i].lastName,
                   students[i].rank,
                   students[i].age,
                   students[i].origGTScore);
            // Optionally update the printed flag to true if needed.
            students[i].printed = true;
        }
    }
    //   - print the student's name, rank, age, and original GT score.
    //   - optionally update the printed flag to true if needed.    
    // After printing all records, return to the caller.
}
