#include <stdio.h>
#include <math.h>

int main(void) {
    int userInput;

    //tip calculator initilisations 
    double billAmount, totalBill;
    double roundedAmount; 
    int tipPercentage;

    //basic calculator initialisations
    double firstNumber, secondNumber;
    char operator;


    // Prompt User for Input
    printf("\nWelcome to the Calculator App!\n\n");

    while (1) {
        printf("Enter '1' for Tip Calculator or Enter '2' for Basic Calculator or '0' to quit:\n");
        scanf("%d", &userInput);

        if (userInput == 1){
        
            printf("What is the bill amount?\n");
            scanf("%lf", &billAmount);
            roundedAmount = round(billAmount * 100) / 100;

            while (billAmount <= 0 || billAmount != roundedAmount) {
                if (billAmount <= 0) {
                    printf("Please enter a valid bill amount greater than 0.\n");
                } else if (billAmount != roundedAmount) {
                    printf("Please enter a value with two decimal places. \n");
                }
                // prompt the user again
                printf("What is the bill amount?\n");
                scanf("%lf", &billAmount);
                roundedAmount = round(billAmount * 100) / 100;
            }

            // Validate tip percentage with a while loop
            printf("What percentage are you tipping?\n");
            scanf("%d", &tipPercentage);

            while (tipPercentage <= 0) {
                printf("Please enter a valid Tip Amount.\n");
                
                // Prompt the user again
                printf("What percentage are you tipping?\n");
                scanf("%d", &tipPercentage);
            }

            // Calculate total bill
            totalBill = (billAmount * (tipPercentage / 100.0)) + billAmount;  

            // Output summary
            printf("\nSummary:\n");
            printf("Bill Amount: $%.2lf\n", billAmount);
            printf("Tip Percentage: %d%%\n", tipPercentage);
            printf("Total Bill: $%.2lf\n", totalBill);
        }
        else if (userInput ==2) {

            //validating userinput for numeric value

            while (1){
                printf("Enter the first number:\n");
                if (scanf("%lf", &firstNumber) == 1){
                    break;
                } else{
                    printf("Invalid input! Please enter a numeric value.\n");
                    // Clear the input buffer to remove any leftover characters, 
                    // especially after invalid input, ensuring fresh input on next scanf.
                    while (getchar() != '\n');  // Clear the input buffer
                }
            }

            while (1) {
                printf("Enter the second number:\n");
                if (scanf("%lf", &secondNumber) == 1){
                    break;
                } else{
                    printf("Invalid input! Please enter a numeric value.\n");
                    // Clear the input buffer to remove any leftover characters, 
                    // especially after invalid input, ensuring fresh input on next scanf.
                    while (getchar() != '\n');  
                }
            }


            // Space after %c tells scanf to skip any leading whitespace or it might mistakenly capture newline character as input
            while (1){
                printf("Enter the operator: Addition(+), Subtraction(-), Multiplication(*), Division(/):\n");
                scanf(" %c", &operator);

                if (operator == '+' || operator == '-' || operator == '*' || operator == '/'){
                    break;
                } else{
                    printf("Invalid operator! Please enter a valid operator (+, -, *, /).\n");
                }
                
            }
            
            switch (operator) {
                case '+':
                    printf("Result: %.2lf\n", firstNumber + secondNumber);
                    break;
        
                case '-':
                    printf("Result: %.2lf\n", firstNumber - secondNumber);
                    break;
        
                case '*':
                    printf("Result: %.2lf\n", firstNumber * secondNumber);
                    break;
        
                case '/':
                    while (secondNumber == 0) {  
                        printf("Error: Division by 0 is not allowed. Please enter a non-zero value for the second number:\n");
                        scanf("%lf", &secondNumber);
                    }
                    printf("Result: %.2lf\n", firstNumber / secondNumber);
                    break;
                    
            }
        } 
        
        else if (userInput == 0){   
            printf("Thank you for using the Calculator App!\n");
            break;

        } 
        
        else {
            printf("Invalid Input! Please enter '1' or '2' or '0'.\n");
        }
            
    }

    return 0;
}



//Extra Comments 

//%d for an integer (a whole number like 5, 42).
//%lf for a double (a decimal number like 3.14, 2.718).
//%c for a character (a single letter like 'a', 'B').


//scanf Processes Input: scanf reads what the user types and checks if it matches the expected format.
//Return Value:
//1: If the input is a number and matches the format (e.g., %d for an integer), scanf stores it in memory and returns 1.
//0: If the input doesn't match (e.g., the user enters a letter when a number is expected), scanf returns 0 and doesn't change the variable's value in memory.


//Input Buffer
//When you type something in the console (e.g., 123\n), your input goes into a temporary storage area in memory called the input buffer.
//The \n at the end represents the Enter key you press after typing your input. It also gets stored in the input buffer.

//getchar() is a function that reads a single character from the input buffer.
//Each time you call getchar(), it removes one character from the buffer and returns it.

//The loop while (getchar() != '\n'); keeps calling getchar() until it reads and discards the newline character \n.
//This effectively clears out any remaining characters in the input buffer, leaving it empty for the next input.