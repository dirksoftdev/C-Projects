#include <stdio.h>
#include <string.h>

const int MAX_TASKS = 100;
const int MAX_LENGTH = 50;

char tasks [MAX_TASKS][MAX_LENGTH]; // 2D array that stores 100 tasks, each 50 characters long
int status[MAX_TASKS] = {0}; // array that keeps track of whether each task is done (1) or not (0)
int task_count = 0;   // Counter to keep track of the number of tasks

int main() {
    printf("\nWelcome to your To-Do List App!\n");
    

    int choice = 0;

    while (choice != 5) { // continue looping until user selects option 5
        printf("\nMain Menu:\n");
        printf("Enter 1 to Add a task.\n");
        printf("Enter 2 to View Tasks.\n");
        printf("Enter 3 to Mark a task as complete.\n");
        printf("Enter 4 to Delete a task.\n");
        printf("Enter 5 to Exit the Program.\n");
        printf("Enter your choice: ");
    

        // Validate input to ensure it's an integer
        if (scanf("%d", &choice) != 1) {
            // If scanf fails (returns 0), it's not a valid integer input
            printf("Invalid input. Please enter a number between 1 and 5.\n");

            // Clear the input buffer
            while (getchar() != '\n'); // Discard invalid input
            choice = 0; // Reset choice to avoid incorrect processing
            continue; // Go back to the start of the loop
        }

        switch (choice) {
            case 1: //new task
                if (task_count < MAX_TASKS) {
                    printf("Enter a new task: ");
                    scanf(" %[^\n]", tasks[task_count]); // Store the new task in tasks[task_count]
                    status[task_count] = 0; // Initialize the task as incomplete
                    task_count++;     // Increment the task count
                } else {
                    printf("Task list is full!\n");
                }
                break;
            case 2: //viewing task
                if(task_count == 0) {
                    printf("No tasks available.\n");
                } else {
                    printf("Your To-Do List:\n");
                    for (int i = 0; i < task_count; i++) {   // Print the task number and description
                        printf("%d %s\n", i + 1, tasks[i]);
                        if (status[i] == 0) {
                            printf("[Incomplete]\n");   // Mark as incomplete if status[i] is 0
                        } else {
                            printf("[Complete]\n"); // Mark as complete if status[i] is 1
                        }
                        
                    }
                }
                break;
            case 3: //completing a task
                if (task_count == 0) { 
                    printf("No tasks available to complete. \n");
                } else {
                    int task_number; //variable to store task number entered by user
                    printf("Enter the task number to mark as complete: ");
                    scanf("%d", &task_number);   // Get the task number from the user

                    if (task_number < 1 || task_number > task_count) {
                        printf("Invalid task number. \n");    // Check if the task number is valid
                    } else {
                        status[task_number - 1] = 1;
                        printf("Task %d marked as complete.\n"); 
                    }
                }
                break;
            case 4: //deleting a task
                if (task_count == 0) {
                    printf("No tasks available to delete. \n");
                } else {
                    int task_number;
                    printf("Enter a task number to delete: ");
                    scanf("%d", &task_number); //Get task number from user

                    if (task_number < 1 || task_number > task_count) {
                        printf("Invalid task number. \n");
                    } else {
                        //shift tasks and statuses up to fill the gap
                        for (int i = task_number - 1; i < task_count -1; i++) {
                            strcpy(tasks[i], tasks[i +1]); // Copy the next task into the current position
                            status[i] = status[i + 1]; // Copy the next status into the current position
                        }
                        
                        //Decrement task count
                        task_count--;

                        //Resetting the memory
                        memset(tasks[task_count], 0, sizeof(tasks[task_count])); // Set all characters in the task string to '\0'
                        status[task_count] = 0;     // Reset the status of the task at the invalid last poistion in the list to 0 (incomplete)
                        printf("Task %d deleted. \n", task_number);
                    }
                    
                }
                break;
            case 5: //exiting the program
                printf("Thank you choosing the to do app!\n");
                break; 
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }


    }

    return 0;
    
    
}