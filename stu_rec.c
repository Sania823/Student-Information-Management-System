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