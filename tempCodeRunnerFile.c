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