#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum Choice { ROCK, PAPER, SCISSORS };

// Function to convert choice from character to Choice enum
Choice charToChoice(char choice) {
    switch(tolower(choice)) {
        case 'r':
            return ROCK;
        case 'p':
            return PAPER;
        case 's':
            return SCISSORS;
        default:
            throw invalid_argument("Invalid choice.");
    }
}

// Function to convert choice from Choice enum to string
string choiceToString(Choice c) {
    switch(c) {
        case ROCK:
            return "Rock";
        case PAPER:
            return "Paper";
        case SCISSORS:
            return "Scissors";
        default:
            return "Invalid";
    }
}

// Function to determine the winner
string determineWinner(Choice userChoice, Choice computerChoice) {
    if (userChoice == computerChoice) {
        return "It's a tie!";
    } else if ((userChoice == ROCK && computerChoice == SCISSORS) ||
               (userChoice == SCISSORS && computerChoice == PAPER) ||
               (userChoice == PAPER && computerChoice == ROCK)) {
        return "You win!";
    } else {
        return "Computer wins!";
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    int numRounds;
    cout << "Welcome to Rock Paper Scissors!" << endl;
    cout << "Enter the number of rounds you want to play: ";
    cin >> numRounds;

    int userWins = 0, computerWins = 0;

    for (int i = 0; i < numRounds; ++i) {
        char userChoiceChar;
        cout << "\nRound " << i+1 << "/" << numRounds << endl;
        cout << "Enter your choice (r for Rock, p for Paper, s for Scissors): ";
        cin >> userChoiceChar;

        try {
            Choice userChoice = charToChoice(userChoiceChar);

            Choice computerChoice = static_cast<Choice>(rand() % 3); // Generate random choice for computer

            cout << "Your choice: " << choiceToString(userChoice) << endl;
            cout << "Computer's choice: " << choiceToString(computerChoice) << endl;

            string result = determineWinner(userChoice, computerChoice);
            cout << result << endl;

            if (result == "You win!") {
                userWins++;
            } else if (result == "Computer wins!") {
                computerWins++;
            }
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }

    cout << "\nFinal Score:" << endl;
    cout << "You: " << userWins << " Computer: " << computerWins << endl;

    if (userWins > computerWins) {
        cout << "Congratulations! You win the game!" << endl;
    } else if (userWins < computerWins) {
        cout << "Computer wins the game!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
