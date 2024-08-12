#include <stdio.h>

// I use the round function so I have to include this library
#include <math.h>

int main(void) {
    // Declare Variables
    double billAmount,totalBill; //two decimal values for amount
    int tipPercentage; //a percentage 12-15%


    //Prompt User for Input
    printf("\nWelcome to the Tip calculator!\n\n");

    //if user inputs negative value , then it will ask user to input a value greater than 0
    //else if user inputs a value not equal two decimal places then it will promt to enter again
    //it will then loop to ask for the bill amount again until the user meets the conditions

    do {
     
     printf("What is the bill amount?\n");
     scanf("%lf", &billAmount);

     //To make sure the user only inputs a bill amount of two decimal values we will do a comparison
     //Round function will round to the nearest two decimals and if the billAmount does not match roundedAmount it ask to enter a value with two decimals

     double roundedAmount = round(billAmount * 100) / 100;

     if (billAmount <= 0) {
        printf("Please enter a valid bill amount greater than 0.\n");
     } else if (billAmount != roundedAmount){
        printf("Please enter a value with two decimal places. \n");
     }
     
     // I am using two conditions so I seperate it with ||

    } while (billAmount <= 0 || billAmount != round(billAmount * 100) /100);

   
    //if user inputs negative tip percentage, it will prompt user to enter a valid tip amount
    //it will then loop to ask for the tip percentage again until a valid amount is given

    do {

     printf("What percentage are you tipping?\n");
     scanf("%d", &tipPercentage);

     if (tipPercentage<= 0)
     {
        printf("Please enter a valid Tip Amount.\n");
     }
     
    } while (tipPercentage<= 0);

  

    //Calculate total bill
    totalBill = (billAmount * (tipPercentage/100.0)) + billAmount;  
    //I set it to 100.0 (double) because if I left it at 100 then tippercentage (int)/ 100(int) will give me a result of 0 everytime

    //output summary
    printf("\nSummary:\n");
    printf("Bill Amount: $%.2lf\n", billAmount);
    // The two percent signs at the end of d is used to print the % sign - googled it
    printf("Tip Percentage: %d%%\n", tipPercentage);
    printf("Total Bill: $%.2lf\n", totalBill);


    return 0;

}

//Side Notes

//%d is used in scanf to read an integer value from the user and store it in an int variable

//%lf in scanf: Used to read a double value from user input.
//%.2lf in printf: Used to print a double value with exactly two decimal places.

//The do-while loop ensures that the code inside the loop runs at least once, and it will keep running until the user inputs a valid value.
//Using if statements inside the loop, I can check the input values and provide feedback to the user if the input is invalid.