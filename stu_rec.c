#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct Student
{
    int rollnumber;
    char first_name[100];
    char last_name[100];
    char branch[100];
    float cgpa;
    struct Student *next;
};
void display(struct Student *head)
{
    FILE *file;
    file = fopen("student_records.txt", "r");
    struct Student * temp = head;
    while(temp!=NULL){
        
        printf("Roll Number: %d\n", temp->rollnumber);
        printf("First Name: %s\n", temp->first_name);
        printf("last Name: %s\n", temp->last_name);
        printf("branch: %s\n", temp->branch);
        printf("CGPA: %0.4f\n\n", temp->cgpa);
        temp = temp->next;
    }
    printf("\n");
    fclose(file);
}
struct Student * insert(struct Student *head, int rollnumber, char first_name[100],char last_name[100],char branch[100], float cgpa)
{
    
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    FILE *file = fopen("student_records.txt","w");
    student->rollnumber=rollnumber;
    strcpy(student->first_name,first_name);
    strcpy(student->last_name,last_name);
    strcpy(student->branch,branch);
    student->cgpa=cgpa;
    student->next = NULL;
    if(head==NULL)
    {
        /* if head is NULL, set student as the new head */
        head = student;
    }
    else{
        /* if list is not empty
         insert student in beginning of head */
        student->next = head;
        head = student;
    }
    fprintf(file, "%d  %s %s %s %.2f \n", student->rollnumber,student->first_name,student->last_name,student->branch,student->cgpa);
    fclose(file);
    printf("Student record added successfully.\n");
    return head;  
}
void search(struct Student *head, int rollnumber)
{
    struct Student * temp = head;
    while(temp!=NULL)
    {
        if(temp->rollnumber==rollnumber)
        {
            printf("Roll Number: %d\n", temp->rollnumber);
            printf(" first Name: %s\n", temp->first_name);
            printf("last Name: %s\n", temp->last_name);
            printf("branch: %s\n", temp->branch);
            printf("CGPA: %f\n", temp->cgpa);
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}
void update(struct Student *head ,int rollnumber)
{
    struct Student * temp = head;
    while(temp!=NULL)
    {
    if(temp->rollnumber==rollnumber)
        {
            printf("Record with roll number %d Found !!!\n", rollnumber);
            printf("Enter new  first name: ");
            scanf("%s", temp->first_name);
            printf("Enter new  Last name: ");
            scanf("%s", temp->last_name);
            printf("Enter new branch name: ");
            scanf("%s", temp->branch);
            printf("Enter new CGPA: ");
            scanf("%f",&temp->cgpa);
            printf("Updation Successful!!!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);     
}

int main()
{
     struct Student *head = NULL;
     char first_name[100];
     char last_name[100];
     char branch[100];
     int rollnumber;
     float cgpa;
     int choice;
     int flag=1;
     printf("Student Information Management System\n");
     while (flag)
      {
        printf("1. Add Student information\n2. Search Student\n3. Update information of student\n4. Display Students\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &rollnumber);
                printf("Enter  first name of student: ");
                scanf("%s",first_name);
                printf("Enter  last name of student: ");
                scanf("%s",last_name);
                printf("Enter branch name: ");
                scanf("%s", branch);
                printf("Enter cgpa: ");
                scanf("%f",&cgpa);
                head = insert(head,rollnumber,first_name,last_name,branch,cgpa);
                break;
            case 2:
                printf("Enter roll number to search: ");
                scanf("%d", &rollnumber);
                search(head,rollnumber);
                break;
            case 3:
                printf("enter roll number to update a information of student: ");
                scanf("%d", &rollnumber);
                update(head,rollnumber);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exit");
                flag=0;
        }
     }
}