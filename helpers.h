#ifndef HELPERS_H
#define HELPERS_H

#include <stdbool.h>

typedef struct {
    char firstName[20];
    char lastName[30];
    char rank[20];
    int age;
    int origGTScore;
    bool printed;
} Student;

Student *createStudent(void);
float averageAge(Student *students, int count);
float averageScore(Student *students, int count);
void printTable(Student *students, int count);

#endif // HELPERS_H
