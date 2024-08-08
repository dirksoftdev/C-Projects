#include <stdio.h>

int main(void) {
    // Declare Variables
    double billamount,totalbill; //two decimal values for amount
    int tippercentage; //a percentage 12-15%


    //Prompt User for Input
    printf("\nWelcome to the Tip calculator!\n\n");
    printf("What is the bill amount?\n");
    scanf("%lg", &billamount);
    printf("What percentage are you tipping?\n");
    scanf("%d", &tippercentage);

    //Calculate total bill
    totalbill = (billamount * ((double)tippercentage/100)) + billamount;  
    //I set tipperpercentage as double because when I kept it at int it gave me a 0 value and also for an accurate calculation

    //output total bill
    printf("You owe the amount:$%.2lf\n", totalbill);

    return 0;

}