#include <stdio.h>
#include <stdlib.h> // Required for rand(), srand()
#include <time.h>  // Required for time()

// Define Constants
const int MAX_NUMBER = 100;
const int MAX_ATTEMPTS = 10;

// Function Declarations
void display_instructions();
int generate_random_number();

int main() {
    display_instructions(); // Show the game instructions

    int random_number = generate_random_number(); // Generate the random number
    int guess; // store user's guess
    int attempts = 0; // initializing the attempts counter

    // Game Loop
    while (attempts < MAX_ATTEMPTS) {
        printf("Enter your guess (1-%d): ", MAX_NUMBER);

        // Check if the input is a valid integer
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter a number.\n");
            // Clear the input buffer to avoid an infinite loop
            while (getchar() != '\n'); // Discard invalid input
            continue; // Prompt the user again
        }

        // The rest of the game logic
        if (guess == random_number) {
            printf("\nCongratulations! You have guessed the correct number: %d\n", random_number);
            break;
        } else if (guess > random_number) {
            printf("Too high!\n");
        } else {
            printf("Too low!\n");
        }

        attempts++; // Increment the attempts counter

        // Check if the user has run out of attempts
        if (attempts == MAX_ATTEMPTS) {
            printf("\nSorry, you have run out of attempts! The correct number was: %d\n", random_number);
        } else if (attempts == MAX_ATTEMPTS - 1) {
            printf("This is your final attempt! Make it count!\n\n");
        } else {
            printf("\nAttempts Remaining: %d\n", MAX_ATTEMPTS - attempts);
        }
    }

    return 0;
}

// Function Definitions

// Display the game instructions
void display_instructions() {
    printf("\nWelcome to the Number Guesser! \n");
    printf("You will have 10 attempts to guess the correct number from the range of 1 to 100.\n\n");
}

// Generate a random number between 1 and MAX_NUMBER
int generate_random_number() {
    srand(time(0)); // Seed the random number generator with the current time so you can a new number everytime
    return rand() % MAX_NUMBER + 1; // Generate a random number between 1 and MAX_NUMBER
}
