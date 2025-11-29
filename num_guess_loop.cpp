// Copyright (c) 2025 Christopher El-Mur
// Number guessing game (C++)
// Generates a random number between 0 and 9 and repeatedly asks
// the user to guess until they get it right. Handles invalid input.

#include <cstdlib>   // for rand() and srand()
#include <iostream>  // for input/output
#include <string>    // for std::string
int main() {
    int correctNumber;
    int numberGuess;

    // Initialize random seed
    srand(static_cast<unsigned>(time(NULL)));

    // Generate a random number between 1 and 9
    correctNumber = rand_r() % 9 + 1;

    std::cout << "Guess a random number between 1 and 9!\n";

    // Keep asking until the user guesses correctly
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> input;

        try {
            // Try converting the string to an integer
            numberGuess = std::stoi(input);

            if (numberGuess == correctNumber) {
                std::cout << "CORRECT! :) The number was " << correctNumber << std::endl;
                // exit loop once correct
                break;
            } else {
                std::cout << "Wrong guess :( Try again\n";
            }
        } catch (const std::invalid_argument) {
            // Happens if input is not a number
            std::cout << "Invalid input: please enter a number between 1 and 9.\n";
        } catch (const std::out_of_range) {
            // Happens if the number is too large
            std::cout << "please enter a small number between 1 and 9.\n";
        }
    }
}
