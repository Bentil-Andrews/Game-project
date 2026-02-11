#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int getHighScore() {
    ifstream file("highscore.txt");
    int highScore = 0;
    if (file >> highScore) {
        return highScore;
    }
    return 0;
}

void saveHighScore(int score) {
    ofstream file("highscore.txt");
    file << score;
}

void showMenu() {
    cout << "\n===== NUMBER GUESSING GAME PRO =====\n";
    cout << "1. Play Game\n";
    cout << "2. View High Score\n";
    cout << "3. Exit\n";
    cout << "Choose option: ";
}

void playGame() {
    int level;
    cout << "\nSelect Difficulty:\n";
    cout << "1. Easy (1-10, 5 attempts)\n";
    cout << "2. Medium (1-50, 7 attempts)\n";
    cout << "3. Hard (1-100, 10 attempts)\n";
    cout << "Choice: ";
    cin >> level;

    int maxNumber, attempts;

    if (level == 1) {
        maxNumber = 10;
        attempts = 5;
    } else if (level == 2) {
        maxNumber = 50;
        attempts = 7;
    } else {
        maxNumber = 100;
        attempts = 10;
    }

    int secret = rand() % maxNumber + 1;
    int guess;
    int score = 0;

    cout << "\nGuess the number between 1 and " << maxNumber << endl;

    while (attempts > 0) {
        cout << "Attempts left: " << attempts << "\nEnter guess: ";
        cin >> guess;

        if (guess == secret) {
            cout << "?? Correct!\n";
            score = attempts * 10;
            break;
        } else if (guess < secret) {
            cout << "Too low!\n";
        } else {
            cout << "Too high!\n";
        }

        attempts--;
    }

    if (attempts == 0 && guess != secret) {
        cout << "\n?? Game Over! The number was " << secret << endl;
    }

    cout << "Your Score: " << score << endl;

    int highScore = getHighScore();
    if (score > highScore) {
        cout << "?? New High Score!\n";
        saveHighScore(score);
    }
}

int main() {
    srand(time(0));

    int choice;

    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            playGame();
        } 
        else if (choice == 2) {
            cout << "\nCurrent High Score: " << getHighScore() << endl;
        } 
        else if (choice == 3) {
            cout << "Exiting game...\n";
        } 
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}

