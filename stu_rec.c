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
void saveToFile(struct Student* head) 
{
    FILE* file = fopen("student_records.txt", "w");
    if (file == NULL) {
        printf("File could not be opened for writing.\n");
        return;
    }

    struct Student* current = head;
    while (current != NULL) {
        fprintf(file, "PRN:%d\n\tName:%s %s\n\tBranch:%s\n\tCGPA:%.2f\n", current->rollnumber,current->first_name,current->last_name,current->branch,current->cgpa);
        current = current->next;
    }

    fclose(file);
}
void display(struct Student *head)

{
    //FILE *file;
    // file = fopen("student_records.txt", "r");
    // struct Student * temp = head;
    // while(temp!=NULL){
        
    //     printf("Roll Number: %d\n", temp->rollnumber);
    //     printf("First Name: %s\n", temp->first_name);
    //     printf("Last Name: %s\n", temp->last_name);
    //     printf("Branch: %s\n", temp->branch);
    //     printf("CGPA: %0.4f\n\n", temp->cgpa);
    //     temp = temp->next;
    // }
    // struct Student* current = head;
    // printf("Student List:\n");
    // FILE* file = fopen("student_records.txt", "w");
    // if (file == NULL) {
    //     printf("Error opening file for writing.\n");
    //     return;
    // }

    // while (current != NULL) {
    //     printf("Roll Number: %d, Name: %s %s, Branch: %s, CGPA: %.2f\n", current->rollnumber, current->first_name, current->last_name, current->branch, current -> cgpa);
    //     fprintf(file, "Roll Number: %d, Name: %s %s, Branch: %s, CGPA: %.2f\n", current->rollnumber, current->first_name, current->last_name, current->branch, current->cgpa);
    //     current = current->next;
    // }
    // printf("\n");
    // fclose(file);
    FILE* file = fopen("student_records.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}
struct Student * insert( struct Student *head,int rollnumber, char first_name[100],char last_name[100],char branch[100], float cgpa)
{
    
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    FILE *file = fopen("student_records.txt","a");
    student->rollnumber=rollnumber;
    strcpy(student->first_name,first_name);
    strcpy(student->last_name,last_name);
    strcpy(student->branch,branch);
    student->cgpa=cgpa;
    student->next = NULL;
    if(head==NULL)
    {
        //if head is NULL, set student as the new head
        head = student;
    }
    else{
        //if list is not empty insert student in beginning of head 
        student->next = head;
        head = student;
    }
    fprintf(file, "PRN:%d\n\tName:%s %s\n\tBranch:%s\n\tCGPA:%.2f\n", student->rollnumber,student->first_name,student->last_name,student->branch,student->cgpa);
    fclose(file);
    printf("Student record added successfully.\n");
    return head;  
}
void search(struct Student *head,int rollnumber)
{
    struct Student * temp = head;
    while(temp!=NULL)
    {
        if(temp->rollnumber==rollnumber)
        {
            printf("Roll Number: %d\n", temp->rollnumber);
            printf("First Name: %s\n", temp->first_name);
            printf("Last Name: %s\n", temp->last_name);
            printf("Branch: %s\n", temp->branch);
            printf("CGPA: %f\n", temp->cgpa);
            return;
        }
        temp = temp->next;
    }
    printf("Student with Roll Number %d is not found.\n", rollnumber);
}
void update(struct Student *head,int rollnumber)
{
    // struct Student * temp = head;
    // while(temp!=NULL)
    // {
    // if(temp->rollnumber==rollnumber)
    //     {
    //         printf("Record with Roll Number %d Found.\n", rollnumber);
    //         printf("Enter new First name: ");
    //         scanf("%s", temp->first_name);
    //         printf("Enter new Last name: ");
    //         scanf("%s", temp->last_name);
    //         printf("Enter new Branch: ");
    //         scanf("%s", temp->branch);
    //         printf("Enter new CGPA: ");
    //         scanf("%f",&temp->cgpa);
    //         printf("Updation Successful!\n");
    //         return;
    //     }
    //     temp = temp->next;
    // }
    // printf("Student with Roll Number %d is not found!\n", rollnumber);
    struct Student* current = head;

    while (current != NULL && current->rollnumber != rollnumber) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Student not found.\n");
        return;
    }

    printf("Enter new First name: ");
    scanf("%s", current->first_name);
    printf("Enter new Last name: ");
    scanf("%s", current->last_name);
    printf("Enter new Branch: ");
    scanf("%s", current -> branch);
    printf("Enter new CGPA: ");
    scanf("%f", &current -> cgpa);

    printf("Student with Roll Number %d updated.\n");

    // Update the file
    saveToFile(head);     
}
void delete(struct Student **head,int rollnumber)
{
    // struct Student *current = head;
    // struct Student *prev = NULL;
    // while (current != NULL)
    // {
    //     if (current  -> rollnumber == rollnumber)
    //     {
    //         if(prev == NULL)
    //         {
    //             current -> next = head;
    //         }
    //         else
    //         {
    //             prev -> next = current -> next;
    //         }
    //         free(current);
    //         printf("Student with Roll number %d has been deleted\n", rollnumber);
    //         return;
    //     }
    //     prev = current;
    //     current = current -> next;
    // }
    // printf("No Student record corresponding to %d present.\n",rollnumber);struct Student* current = *head;
    struct Student* current = *head;
    struct Student* prev = NULL;
    while (current != NULL && current-> rollnumber != rollnumber) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student not found.\n");
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Student with Roll Number %d deleted.\n", rollnumber);

    // Update the file
    saveToFile(*head);

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
    // Load student data from the file at the beginning
    FILE* file = fopen("student_records.txt", "r");
    if (file != NULL) 
    {
        int rollNumber;
        char name[50];
        float marks;

        while (fscanf(file, "%d %s %s %s %f", &rollnumber, first_name, last_name, branch, &cgpa) == 5) {
            struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
            newStudent-> rollnumber = rollnumber;
            strcpy(newStudent->first_name, first_name);
            strcpy(newStudent->last_name, last_name);
            strcpy(newStudent->branch, branch);
            newStudent->cgpa = cgpa;
            newStudent->next = NULL;

            if (head == NULL) {
                head = newStudent;
            } else {
                struct Student* current = head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newStudent;
            }
        }

        fclose(file);
     printf("Student Information Management System\n");
     while (flag)
      {
        printf("1. Add Student information\n2. Search Student\n3. Update information of student\n4. Display Students\n5. Delete Student\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                printf("Enter Roll Number: ");
                scanf("%d", &rollnumber);
                printf("Enter First name of student: ");
                scanf("%s",first_name);
                printf("Enter Last name of student: ");
                scanf("%s",last_name);
                printf("Enter Branch: ");
                scanf("%s", branch);
                printf("Enter CGPA: ");
                scanf("%f",&cgpa);
                head = insert(head,rollnumber,first_name,last_name,branch,cgpa);
                break;
            case 2:
                printf("Enter Roll number to search: ");
                scanf("%d", &rollnumber);
                search(head,rollnumber);
                break;
            case 3:
                printf("Enter Roll number to update a information of student: ");
                scanf("%d", &rollnumber);
                update(head,rollnumber);
                break;
            case 4:
                display(head);
                break;
            case 5:
                int rollnumber;
                printf("Enter the Roll number to delete: ");
                scanf("%d",&rollnumber);
                delete(&head,
                rollnumber);
                break;
            case 6:
                printf("Exit");
                flag=0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
     }
    }
}