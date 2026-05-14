# CIS204-ai-research

# Program Purpose
## What will a user use your program to do?

The user of my program will be a BSEP student. These students are military personnel seeking to raise their GT score above a 110. To determine the efficacy of my class, I will be tracking their original scores vs. their final scores. This program will allow me to collect my student's identification data as well as their original GT score. I will use the program to average their age and scores. 

## What problem does your program solve for users?

As an instructor and a researcher, I need a way to collect and organize data. This program is the first step in that process. 

## What does your program do? Again, use your creativity here.

My program collects student identification data and original GT scores. 

# 2. Input, Output, and Memory Management

## What input will a user need to provide?

The user(myself) will need to enter all identification data (Name, Rank, Age, etc.) and the original GT scores. 

## What output is the program expected to generate?

The program will output the average age and original GT scores of my cohort. 

## What variables will your program need to define?

int numStudents;
int averageAge;
int averageGT;
Student *students;


## How much memory will your program require to operate?
This is a simple program that will not need much memory to operate. I will need roughly 471 bytes of memory for my program. 

# 3. Functions Needed

## List 3–6 functions your program will require.

1. Create a student record and prompt for struct info
    - Student* createStudent(); 
3. Calculate average (of age or GT score)
    - float averageAge(Student*);
    - float averageScore(Student*);
4. Print results as a table with 1 student per row sets bool to true
    - void printTable(Student*)


# 4. Data Structures
## Define a simple struct to use in your program.
    typdef struct{
        char firstName[20];
        char lastName[30];
        char rank[20];
        int age; 
        int origGTScore;
        bool printed;
    } Student;

# 5. File Responsibilities - The following files are required in your project submission.
Describe the purpose and contents of each file.
## main.c
    I will use main to call my functions and allocate memory. 
## helpers.h
    I will use helpers h. to house my struct definition and my function prototypes. 
## Helpers.c
    This is where I will write my programs

# 6. Research Plan - Write a 250 words describing your strategy for using AI to help you
to write the code for this project.

First, I will ask AI to look over this project proposal and point out any gaps in my thinking. Based on its response, I will make edits/changes. Next, I will ask AI to explain how I should use malloc and pointers as I create my student records. Because these are the most recent tools in C that I have learned, I am less familiar with them and less confident in my usage of them. I will have AI thoroughly explain the topic and how it thinks I should use them in my project. 

Next, I will use AI to research my program and any information that is already out there. I'm genuinely curious to see if this information is captured and reported on by anyone else. During this conversation with AI, I will ask it if there are any key metrics it thinks I should add to my program for collection. Perhaps there is an industry standard I am unaware of, or perhaps it will know how I could average soldier ranks. 

When it is time to code with AI, I would like to go line by line so that I understand what it is doing. I also plan to question its methods. I have my own style in coding, and I'm curious to see if I can get AI to simulate my style. AI is a far more advanced coder than myself, and I think that at times, when advanced logic comes easy, we skip to the most complicated of methods rather than the most simple. 

## o Include 3–5 prompts you will give the AI to generate code.
    1. Please look over my project plan. Do not rewrite it. Give me 10 small critiques, but only if they have to do with clarity or accuracy. 
    2. Please explain how a pointer struct works and how I would use malloc with a pointer struct. 
    2. In looking over my program parameters, are there any additional metrics from the students that you think would be important to include?