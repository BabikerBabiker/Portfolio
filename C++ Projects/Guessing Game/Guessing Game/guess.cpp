#include <iostream>
using namespace std;

const int MAXGUESS = 1000;
int feedbackNUM = 0;
int min{};
int max{};
int guess{};

class Player {
public:
    virtual int getGuess() const = 0;
    void feedback(int playGuess) {
        switch (feedbackNUM) {
        case -1:
            ::max = playGuess;
            break;
        case 1:
            ::min = playGuess;
        }
    }
};

class HumanPlayer : public Player {
public:
    int getGuess() const override {
        int guess{};
        cout << "Enter your guess: ";
        cin >> guess;
        return guess;
    }
};

class ComputerPlayer : public Player {
public:
    int getGuess() const override {
        int guess = rand() % (MAXGUESS + 1);
        cout << "The computer's guess was " << guess << endl;
        return guess;
    }
};

class SmartComputerPlayer : public Player {
public:
    int getGuess() const override {
        int guess = (::min + ::max) / 2;
        cout << "The smart computer's guess was " << guess << endl;
        return guess;
    }
};

bool checkForWin(int guess, int answer) {
    if (answer == guess) {
        cout << "You're right! You win!" << endl;
        return true;
    }
    else if (answer < guess) {
        cout << "Your guess is too high." << endl;
        feedbackNUM = -1;
    }
    else {
        cout << "Your guess is too low." << endl;
        feedbackNUM = 1;
    }
    return false;
}

int play(Player& player1, Player& player2) {
    int answer = rand() % (MAXGUESS + 1);
    int guess;
    int numGuesses = 0;
    bool win = false;

    while (!win) {
        cout << "------------------------------------------" << endl;
        cout << "Player 1's turn to guess. [Between 1-1000]" << endl;
        cout << "------------------------------------------" << endl;
        guess = player1.getGuess();
        numGuesses++;
        win = checkForWin(guess, answer);
        if (win) {
            cout << "\n\n[ENTER] to return back to Main Menu";
            break;
        }
        else player1.feedback(guess);

        cout << "\n------------------------------------------" << endl;
        cout << "Player 2's turn to guess. [Between 1-1000]" << endl;
        cout << "------------------------------------------" << endl;
        guess = player2.getGuess();
        numGuesses++;
        win = checkForWin(guess, answer);
        if (win) {
            cout << "\n\n[ENTER] to return back to Main Menu.";
            break;
        }
        else player2.feedback(guess);
    }
    return numGuesses;
}

static void menu() {
    int p1Choice = 0;
    int p2Choice = 0;
    Player* player1;
    Player* player2;

    while (p1Choice != 4 || p2Choice != 4) {
        cout << "--------------------------" << endl;
        cout << "MENU: Player 1" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Human Player" << endl;
        cout << "2. Computer Player" << endl;
        cout << "3. Smart Computer Player" << endl;
        cout << "4. Exit Game" << endl;
        cout << "--------------------------" << endl;
        cin >> p1Choice;

        switch (p1Choice) {
        case 1:
            player1 = new HumanPlayer();
            break;
        case 2:
            player1 = new ComputerPlayer();
            break;
        case 3:
            player1 = new SmartComputerPlayer();
            break;
        case 4:
            exit(0);
        default:
            cout << "\nInvalid choice for Player 1.\n" << endl;
            continue;
        }

        cout << "--------------------------" << endl;
        cout << "MENU: Player 2" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Human Player" << endl;
        cout << "2. Computer Player" << endl;
        cout << "3. Smart Computer Player" << endl;
        cout << "4. Exit Game" << endl;
        cout << "--------------------------" << endl;
        cin >> p2Choice;

        switch (p2Choice) {
        case 1:
            player2 = new HumanPlayer();
            break;
        case 2:
            player2 = new ComputerPlayer();
            break;
        case 3:
            player2 = new SmartComputerPlayer();
            break;
        case 4:
            delete player1;
            exit(0);
        default:
            cout << "\nInvalid choice for Player 2.\n" << endl;
            delete player1;
            continue;
        }

        ::min = 0;
        ::max = MAXGUESS;

        system("cls");

        play(*player1, *player2);
        cin.ignore();
        cin.ignore();
        system("cls");

        delete player1;
        delete player2;
    }

}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    menu();
    return 0;
}