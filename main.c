#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student
{
    int roll;
    char name[MAX];
    char dept[MAX];
    char course[MAX];
    char year[MAX];
    char semester[MAX];
    char email[MAX];
    char phone[MAX];
    struct Student *next;
};

void display(struct Student *head)
{
    struct Student *temp = head;
    while (temp != NULL)
    {
        printf("Student Details: \n");
        printf("Roll: %d\n", temp->roll);
        printf("Name: %s\n", temp->name);
        printf("Department: %s\n", temp->dept);
        printf("Course: %s\n", temp->course);
        printf("Year: %s\n", temp->year);
        printf("Semester: %s\n", temp->semester);
        printf("Email: %s\n", temp->email);
        printf("Phone: %s\n", temp->phone);
        temp = temp->next;
    }
}

struct Student *create(int roll, char *name, char *dept, char *course, char *year, char *semester, char *email, char *phone)
{
    struct Student *s = (struct Student *)malloc(sizeof(struct Student));
    s->roll = roll;
    strcpy(s->name, name);
    strcpy(s->dept, dept);
    strcpy(s->course, course);
    strcpy(s->year, year);
    strcpy(s->semester, semester);
    strcpy(s->email, email);
    strcpy(s->phone, phone);
    s->next = NULL;
    return s;
}

void add_student(struct Student **head, struct Student *new_student)
{
    new_student->next = *head;
    *head = new_student;
}

void delete_student(struct Student **head, int roll)
{
    struct Student *temp = *head;
    struct Student *prev = NULL;
    if (temp != NULL && temp->roll == roll)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->roll != roll)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Student not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void update_student(struct Student *head, int roll)
{
    struct Student *temp = head;
    while (temp != NULL && temp->roll != roll)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Student with roll number %d not found.\n", roll);
        return;
    }
    printf("Updating student with roll number %d\n", roll);
    printf("Enter new name: ");
    scanf("%s", temp->name);
    printf("Enter new department: ");
    scanf("%s", temp->dept);
    printf("Enter new course: ");
    scanf("%s", temp->course);
    printf("Enter new year: ");
    scanf("%s", temp->year);
    printf("Enter new semester: ");
    scanf("%s", temp->semester);
    printf("Enter new email: ");
    scanf("%s", temp->email);
    printf("Enter new phone: ");
    scanf("%s", temp->phone);
}

int main()
{
    struct Student *head = NULL;
    int choice, roll;
    char name[MAX];
    char dept[MAX];
    char course[MAX];
    char year[MAX];
    char semester[MAX];
    char email[MAX];
    char phone[MAX];

    while (1)
    {
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Delete Student\n");
        printf("4. Update Student\n");
        printf("5. Search Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Student Information\n");
            printf("Enter Roll: ");
            scanf("%d", &roll);
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Department: ");
            scanf("%s", dept);
            printf("Enter Course: ");
            scanf("%s", course);
            printf("Enter Year: ");
            scanf("%s", year);
            printf("Enter Semester: ");
            scanf("%s", semester);
            printf("Enter Email: ");
            scanf("%s", email);
            printf("Enter Phone: ");
            scanf("%s", phone);
            struct Student *new_student = create(roll, name, dept, course, year, semester, email, phone);
            add_student(&head, new_student);
            break;
        case 2:
            display(head);
            choice = 0;
            break;
        case 3:
            printf("Enter Roll to delete: ");
            scanf("%d", &roll);
            delete_student(&head, roll);
            break;
        case 4:
            printf("Enter roll number to update: ");
            scanf("%d", &roll);
            update_student(head, roll);
            break;
        case 5:
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}