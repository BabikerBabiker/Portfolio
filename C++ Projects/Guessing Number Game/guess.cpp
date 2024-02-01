// @author Babiker Babiker
// @date 01/22/2024
// @details Betting Guessing Game
#include "iostream"
#include "ctime" 
using namespace std;

class Game {
private:
    int money;
    int targetNumber;
    int guess[10];
    int numGuesses;
public:
    Game() {
        this->money = 1000;
        srand(time(0));
        this->targetNumber = rand() % 100;
        this->numGuesses = 0;
    }

    int getTarget() const{
        return this->targetNumber;
    }

    void play() {
        for (int i = 0; i < 10; i++) {
            if (this->money == 0) {
                this->losePrompt();
            }

            cout << "\nCurrent Money: " << this->money << endl;
            cout << "Enter random number between 0-100: ";
            cin >> this->guess[i];
            this->numGuesses++;

            if (checkWin(guess[i])) {
                break;
            }
        }
        winPrompt();
    }

    bool checkWin(int guess) {
        if (guess == this->targetNumber) {
            return true;
        }
        this->money -= 100;
        cout << "Invalid guess!" << endl;
        return false;
    }

    void winPrompt() const{
        cout << "You guessed the right number!! You win!!" << endl;
        cout << "\nWould you like to view all your guesses? [Y/N]: ";
        char c;
        cin >> c;

        switch (c) {
        case 'Y':
        case 'y':
            printGuesses();
        default:
            exit(0);
        }
    }

    void losePrompt() const{
        cout << "\nNo more money left to bet." << endl;
        cout << "The number was ";
        cout << this->getTarget();
        exit(0);
    }

    void printGuesses() const {
        cout << "\nGuesses: " << this->numGuesses << "\n----------" << endl;
        for (int i = 0; i < this->numGuesses; i++) {
            cout << this->guess[i] << endl;
        }
    }
};

int main() {
    Game* guess = new Game();
    cout << "Game started!" << endl;
    cout << guess->getTarget();
    guess->play();

    delete guess;
}
