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

        } else if (userInput ==2) {
            printf("Enter the first number:\n");
            scanf("%lf", &firstNumber);
            printf("Enter the second number:\n");
            scanf("%lf", &secondNumber);


            // Space after %c tells scanf to skip any leading whitespace or it might mistakenly capture newline character as input
            printf("Enter the operator: Addition(+), Subtraction(-), Multiplication(*), Division(/):\n");
            scanf(" %c", &operator);

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
                
                default:
                    while (operator != '+' && operator != '-' && operator != '*' && operator != '/') {
                        printf("Invalid operator! Please enter a valid operator (+, -, *, /):\n");
                        scanf(" %c", &operator);
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
                    break;
            }
                    
        } else if (userInput == 0){   
            printf("Thank you for using the Calculator App!\n");
            break;
        } else {
            printf("Invalid Input! Please enter '1' or '2' or '0'.\n");
        }
            
        }

    return 0;
}
