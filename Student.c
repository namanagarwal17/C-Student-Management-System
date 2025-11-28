#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks[5];
    float total;
    float percentage;
};

void addStudent(struct Student *s) {
    printf("\nEnter Roll Number: ");
    scanf("%d", &s->roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s->name);   // safe alternative of gets

    printf("Enter marks in 5 subjects: ");
    scanf("%f %f %f %f %f", &s->marks[0], &s->marks[1], &s->marks[2], &s->marks[3], &s->marks[4]);

    s->total = s->marks[0] + s->marks[1] + s->marks[2] + s->marks[3] + s->marks[4];
    s->percentage = s->total / 5;
}

void displayStudent(struct Student s) {
    printf("\n----- STUDENT REPORT -----\n");
    printf("Name: %s\n", s.name);
    printf("Roll No: %d\n", s.roll);
    printf("Marks: %.2f, %.2f, %.2f, %.2f, %.2f\n",
           s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.marks[4]);
    printf("Total: %.2f\n", s.total);
    printf("Percentage: %.2f%%\n", s.percentage);

    if (s.percentage >= 75)
        printf("Grade: A\n");
    else if (s.percentage >= 60)
        printf("Grade: B\n");
    else if (s.percentage >= 50)
        printf("Grade: C\n");
    else
        printf("Grade: FAIL\n");
}

int main() {
    struct Student students[100];
    int count = 0;
    int choice, i;

    while (1) {
        printf("\n====== STUDENT MANAGEMENT MENU ======\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&students[count]);
                count++;
                break;

            case 2:
                if (count == 0) {
                    printf("\nNo students added yet.\n");
                } else {
                    for (i = 0; i < count; i++) {
                        displayStudent(students[i]);
                    }
                }
                break;

            case 3:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
