#include <stdio.h>
#include <string.h>

#define MAX 50  // Maximum number of students

// Structure to store student information
struct Student {
    int id;
    char name[50];
    float marks[5];
    float average;
    char grade;
};

// Function declarations
void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
float calculateAverage(float marks[]);
char calculateGrade(float average);

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n====== STUDENT RECORD MANAGEMENT SYSTEM ======\n");
        printf("1. Add Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 3);

    return 0;
}

// Function to add a student record
void addStudent(struct Student students[], int *count) {
    int i;

    if(*count >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &students[*count].id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[*count].name);  // reads string with spaces

    for(i = 0; i < 5; i++) {
        printf("Enter mark %d: ", i+1);
        scanf("%f", &students[*count].marks[i]);
    }

    students[*count].average = calculateAverage(students[*count].marks);
    students[*count].grade = calculateGrade(students[*count].average);

    (*count)++;
    printf("Student record added successfully!\n");
}

// Function to display all student records
void displayStudents(struct Student students[], int count) {
    int i, j;

    if(count == 0) {
        printf("No student records available.\n");
        return;
    }

    for(i = 0; i < count; i++) {
        printf("\n----------------------------------\n");
        printf("Student ID   : %d\n", students[i].id);
        printf("Student Name : %s\n", students[i].name);

        printf("Marks        : ");
        for(j = 0; j < 5; j++) {
            printf("%.1f ", students[i].marks[j]);
        }

        printf("\nAverage      : %.2f\n", students[i].average);
        printf("Grade        : %c\n", students[i].grade);
    }
}

// Function to calculate average marks
float calculateAverage(float marks[]) {
    int i;
    float sum = 0;

    for(i = 0; i < 5; i++) {
        sum += marks[i];
    }

    return sum / 5;
}

// Function to assign grade based on average
char calculateGrade(float average) {
    if(average >= 80)
        return 'A';
    else if(average >= 60)
        return 'B';
    else if(average >= 40)
        return 'C';
    else
        return 'F';
}
