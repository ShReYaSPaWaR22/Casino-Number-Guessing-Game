#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time

using namespace std;

class NumberGuessingGame {
private:
    int secretNumber;
    int maxAttempts;
    int difficulty;

public:
    void setDifficulty(int level) {
        difficulty = level;
        switch (difficulty) {
            case 1: // Easy
                secretNumber = rand() % 10 + 1; // Range 1-10
                maxAttempts = 5;
                break;
            case 2: // Medium
                secretNumber = rand() % 50 + 1; // Range 1-50
                maxAttempts = 7;
                break;
            case 3: // Hard
                secretNumber = rand() % 100 + 1; // Range 1-100
                maxAttempts = 10;
                break;
            default:
                cout << "Invalid difficulty level. Setting to Easy." << endl;
                setDifficulty(1);
        }
    }

    void playGame() {
        int guess;
        int attempts = 0;

        cout << "Guess the number (between 1 and " << (difficulty == 1 ? 10 : (difficulty == 2 ? 50 : 100)) << "): " << endl;

        while (attempts < maxAttempts) {
            cout << "Attempt " << (attempts + 1) << ": ";
            cin >> guess;

            if (guess < 1 || (difficulty == 1 && guess > 10) || (difficulty == 2 && guess > 50) || (difficulty == 3 && guess > 100)) {
                cout << "Please enter a valid guess." << endl;
                continue;
            }

            attempts++;

            if (guess == secretNumber) {
                cout << "Congratulations! You've guessed the correct number!" << endl;
                return;
            } else if (guess < secretNumber) {
                cout << "Too low! Try again." << endl;
            } else {
                cout << "Too high! Try again." << endl;
            }
        }

        cout << "Sorry! You've used all your attempts. The correct number was: " << secretNumber << endl;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    NumberGuessingGame game;
    int difficulty;

    cout << "Welcome to the Casino Number Guessing Game!" << endl;
    cout << "Choose your difficulty level (1-Easy, 2-Medium, 3-Hard): ";
    cin >> difficulty;

    game.setDifficulty(difficulty);
    game.playGame();

    return 0;
}
