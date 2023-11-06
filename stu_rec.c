# include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct Student
{
    char firstName[50];
    char lastName[50];
    int rollNumber;
    float cgpa;
    char branch[50];
    struct Student *next;
}Student;
Student *head = NULL;
//Function to add student data to the file
void addStudent()
{
    Student *new_student = (Student*)malloc(sizeof(Student));
    FILE *file = fopen("student_records.txt", "a");
    if (file == NULL)
    {
        printf("Error in opening the file\n");
        return;
    }
    printf("Add the Students Details\n");
    printf("-------------------------\n");
    printf("Enter the first name of student:\n");
    scanf("%s",new_student -> firstName);
    printf("Enter the last name of student:\n");
    scanf("%s",new_student -> lastName);
    printf("Enter the Roll number of student:\n");
    scanf("%d",&new_student -> rollNumber);
    printf("Enter the CGPA of student:\n");
    scanf("%f",&new_student -> cgpa);
    printf("Enter branch:\n");
    scanf("%s",new_student -> branch);

    if(head == NULL || new_student -> rollNumber < head -> rollNumber)
    {
        new_student -> next = head;
        head = new_student;
    }
    else
    {
        Student *temp = head;
        while(temp -> next != NULL || temp->next -> rollNumber < new_student -> rollNumber)
        {
            temp = temp->next;
        }
        new_student -> next = temp -> next;
        temp->next = new_student;
    }
    fprintf(file, "%s %s %d %.2f %s\n", new_student->firstName, new_student->lastName, new_student->rollNumber, new_student->cgpa, new_student->branch);
    fclose(file);
    printf("Student record added successfully.\n");
}
void display()
{
    // FILE *file;
    // file = fopen("student_records.txt", "r");
    // if(file==NULL)
    // {
    //     printf("No records found!\n");
    //     return;
    // }
    // printf("Student Records:\n");
    // Student *temp = head;
    // while (temp != NULL) 
    // {
    //     printf("First Name: %s\nLast Name: %s\nRoll Number: %d\nCGPA: %.2f\nBranch: %s\n\n", temp -> firstName, temp -> lastName, temp -> rollNumber, temp -> cgpa, temp -> branch);
    //     temp = temp -> next;
    // }
    
    

    // fclose(file);
}

int main()
{
     int choice;
     while (1)
      {
        printf("Student Information Management System\n");
        printf("1. Add Student\n2. Display Students\n3. Search Student\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                addStudent();
                break;
            case 2:
                display();
                break;
            case 4:
                printf("Exit\n");
                return 0;
        }
      }
      return 0;

}