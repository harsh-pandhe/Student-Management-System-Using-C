#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int roll;
    char name[100];
    char dept[100];
    char course[100];
    char year[100];
    char semester[100];
    char email[100];
    char phone[100];
};

int display(struct Student *s)
{
    printf("Student Information\n");
    printf("Roll: %d\n", s->roll);
    printf("Name: %s\n", s->name);
    printf("Department: %s\n", s->dept);
    printf("Course: %s\n", s->course);
    printf("Year: %s\n", s->year);
    printf("Semester: %s\n", s->semester);
    printf("Email: %s\n", s->email);
    printf("Phone: %s\n", s->phone);
}

int take_data(struct Student *s)
{
    printf("Enter Student Information\n");
    printf("Enter Roll: ");
    scanf("%d", &s->roll);
    printf("Enter Name: ");
    scanf("%s", s->name);
    printf("Enter Department: ");
    scanf("%s", s->dept);
    printf("Enter Course: ");
    scanf("%s", s->course);
    printf("Enter Year: ");
    scanf("%s", s->year);
    printf("Enter Semester: ");
    scanf("%s", s->semester);
    printf("Enter Email: ");
    scanf("%s", s->email);
    printf("Enter Phone: ");
    scanf("%s", s->phone);
}

int menu()
{
    printf("1. Take Data\n");
    printf("2. Display Data\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    struct Student s;
    int choice = 0;
    while (choice != 3)
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            take_data(&s);
            choice = 0;
            break;
        case 2:
            display(&s);
            choice = 0;
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}