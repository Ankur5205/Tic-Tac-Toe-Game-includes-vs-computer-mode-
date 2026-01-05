#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void displayBoard() {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n\n";
}

bool checkWin(char player) {
    int winConditions[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };

    for (auto &cond : winConditions) {
        if (board[cond[0]] == player &&
            board[cond[1]] == player &&
            board[cond[2]] == player)
            return true;
    }
    return false;
}

bool isDraw() {
    for (char c : board)
        if (c == ' ')
            return false;
    return true;
}

void playerMove() {
    int move;
    while (true) {
        cout << "Enter your move (1-9): ";
        cin >> move;
        move--;

        if (move >= 0 && move < 9 && board[move] == ' ') {
            board[move] = 'X';
            break;
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }
}

void computerMove() {
    int move;
    srand(time(0));
    do {
        move = rand() % 9;
    } while (board[move] != ' ');

    board[move] = 'O';
    cout << "Computer chose position " << move + 1 << "\n";
}

int main() {
    cout << "===== Tic Tac Toe (Player vs Computer) =====\n";
    cout << "You are X | Computer is O\n";

    while (true) {
        displayBoard();
        playerMove();

        if (checkWin('X')) {
            displayBoard();
            cout << "🎉 You win!\n";
            break;
        }

        if (isDraw()) {
            displayBoard();
            cout << "🤝 It's a draw!\n";
            break;
        }

        computerMove();

        if (checkWin('O')) {
            displayBoard();
            cout << "💻 Computer wins!\n";
            break;
        }
    }
    return 0;
}
