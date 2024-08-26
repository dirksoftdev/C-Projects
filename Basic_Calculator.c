
#include <stdio.h>
#include <math.h>


// Tip Calculator
void tipCalculator() {
    double billAmount, totalBill, roundedAmount;
    int tipPercentage;

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

//Basic Calculator

//Basic Calculator Mini-Functions

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    while (b == 0) {
        printf("Error: Division by 0 is not allowed. Please enter a non-zero value for the second number:\n");
        scanf("%lf", &b);
    }
    return a / b;
}

//Basic Calculator Function

void basicCalculator() {
    double firstNumber, secondNumber;
    char operator;
    double result;

// Input and validation steps

//Initialize to 0:
// validInput is initialized to 0 because we haven't received valid input yet.

// While not true (which means 0):
// The loop runs as long as validInput is 0. The !validInput means "not valid," so the loop continues to prompt the user for a number.

// If the input is a valid number:
// scanf tries to read the input as a number. If it successfully reads a valid number, scanf returns 1 (indicating success).

// If scanf outputs 1:
// When scanf returns 1, it means the input is valid, so validInput is set to 1.

// Exiting the loop:
// Once validInput is set to 1, the loop condition !validInput becomes false, and the loop exits.

  int validInput = 0; // Declare validInput once

    // Input validation for the first number
    while (!validInput) {
        printf("Enter the first number:\n");
        if (scanf("%lf", &firstNumber) == 1) {
            validInput = 1; // Set to true if input is valid
        } else {
            printf("Invalid input! Please enter a numeric value.\n");
            while (getchar() != '\n');  // Clear the input buffer
        }
    }

    validInput = 0; // Reset validInput for the second number so you can use the same variable for the second number validation.

    // Input validation for the second number
    while (!validInput) {
        printf("Enter the second number:\n");
        if (scanf("%lf", &secondNumber) == 1) {
            validInput = 1; // Set to true if input is valid
        } else {
            printf("Invalid input! Please enter a numeric value.\n");
            while (getchar() != '\n');  // Clear the input buffer
        }
    }

    int validOperator = 0; // Operator validation

    // Space after %c tells scanf to skip any leading whitespace or it might mistakenly capture newline character as input

    while (!validOperator) {
        printf("Enter the operator: Addition(+), Subtraction(-), Multiplication(*), Division(/):\n");
        scanf(" %c", &operator);
        if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
            validOperator = 1; // Set to true if input is valid
        } else {
            printf("Invalid operator! Please enter a valid operator (+, -, *, /).\n");
        }
    }

    // Calculation and output
    switch (operator) {
        case '+':
            result = add(firstNumber, secondNumber);
            break;

        case '-':
            result = subtract(firstNumber, secondNumber);
            break;

        case '*':
            result = multiply(firstNumber, secondNumber);
            break;

        case '/':
            result = divide(firstNumber, secondNumber);
            break;
    }

    printf("Result: %.2lf\n", result);
}

int main() {
    int calculatorInput = -1; // Initialize the loop variable with a non-zero value

    // Prompt User for Input
    printf("\nWelcome to the Calculator App!\n\n");

    while (calculatorInput != 0) { // Loop until the user chooses to quit
        printf("Enter '1' for Tip Calculator, '2' for Basic Calculator, or '0' to quit:\n");

        // Check if scanf successfully reads an integer if user enters "character"
        if (scanf("%d", &calculatorInput) != 1) {
            printf("Invalid Input! Please enter '1', '2', or '0'.\n");

            // Clear the input buffer
            while (getchar() != '\n');  // Remove the leftover characters from the buffer

            continue; // Restart the loop to prompt again
        }

        if (calculatorInput == 1) {
            tipCalculator(); // Call the tipCalculator function
        } else if (calculatorInput == 2) {
            basicCalculator(); // Call the basicCalculator function
        } else if (calculatorInput == 0) {   
            printf("Thank you for using the Calculator App!\n");
        } else {
            printf("Invalid Input! Please enter '1', '2', or '0'.\n");
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