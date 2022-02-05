#include <iostream>
using namespace std;

bool check(string input, int length) {
    cout << input << '\n';
    if ((input.length() == 4) && //fix 49 -> 'a'
       (((input[0] == input[2]) && (input[3] - input[1] == length - 1)) || ((input[2] - input[0] == length - 1) && (input[1] == input[3]))) &&
       ((input[1] >= 49) && (input[1] <= 56) && (input[3] >= 49) && (input[3] <= 56) &&
       (input[0] >= 97) && (input[0] <= 104) && (input[2] >= 97) && (input[2] <= 104)))
        return true;
    else return false;
}

void place(char number, char board[8][8]) {
    string input;
    cout << "Player " << number << ".\n";
    for (int i = 4; i > 0; i--) {
        for (int j = 0; j < 5-i; j++) {
            cout << "Input your " << i << " deck ship coordinates: ";
            cin >> input;
            if (check(input, i)) cout << "okay\n"; // check if its not interferring with any other ship
        }
    }
}

int main()
{
    char board_1[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board_1[i][j] = ' ';
        }
    }
    char board_2[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board_2[i][j] = ' ';
        }
    }
    cout << "\nInput format: \"a1a4\" if you wish to place your 4 deck ship in the upper left corner\n\n";
    place('1', board_1); 
    cout << "Player 1, press \"cmd+k\", leave a message for your opponent and press enter.\n";
    string placeholder;
    cin >> placeholder;
    place('2', board_2);
}
    //    1 2 3 4 5 6 7 8
    //  a o o o o x      
    //  b x x x x o x    
    //  c   * *   x      
    //  d   x x x x x    
    //  e     x o o o x  
    //  f       x x x    
    //  g     *       x x
    //  h   x       x o o 