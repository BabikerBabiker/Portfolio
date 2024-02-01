#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;

class Sudoku {
public:
    void rules() {
        cout << "Rules for Sudoku Game" << 
        "\n--------------------------------------------------------------------------------------------------------------------------------" <<
        "\n- A 9×9 square must be filled in with numbers from 1-9 with no repeated numbers in each line, horizontally or vertically" << 
        "\n\nPress ENTER when you're ready to play. You can always view the rules later." << endl;
    }

    void play() {

    }

    void buildBoard() {
        
    }
};

int main() {
    Sudoku* game = new Sudoku();
    game->rules();
    cin.ignore();
    system("clear");

    game->play();
    return 0;
}
