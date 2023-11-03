# include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct 
{
     char firstName[50];
     char lastName[50];
     int rollNumber;
     float cgpa;
    char courses[100];
}Student;
void addStudent()
{
    Student student;
    FILE *file = fopen("student_records.txt", "a");
    printf("Add the Students Details\n");
    printf("-------------------------\n");
    printf("Enter the first name of student\n");
    scanf("%s",student.firstName);
    printf("Enter the last name of student\n");
    scanf("%s",student.lastName);
    printf("Enter the Roll number of student\n");
    scanf("%d",&student.rollNumber);
    printf("Enter the CGPA of student\n");
    scanf("%f",&student.cgpa);
    printf("Enter courses (comma-separated)\n");
    scanf("%s",student.courses);
    fprintf(file, "%s %s %d %.2f %s\n", student.firstName, student.lastName, student.rollNumber, student.cgpa, student.courses);
    fclose(file);
    printf("Student record added successfully.\n");
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
        }
      }
      return 0;

}