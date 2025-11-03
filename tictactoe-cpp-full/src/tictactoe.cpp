
// tictactoe.cpp
// Simple, human-style Tic-Tac-Toe with a small AI (easy to read)
// Author: Miracle Nkundabela (replace with your name)
// Purpose: Practice C++ basics: arrays, functions, game loops, simple AI
#include <iostream>
#include <vector>
#include <cstdlib> // rand, srand
#include <ctime>   // time
using namespace std;

// Print the current board
void printBoard(const char b[3][3]) {
    cout << "\\n";
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            cout << " " << b[r][c] << " ";
            if (c < 2) cout << "|";
        }
        cout << "\\n";
        if (r < 2) cout << "---+---+---\\n";
    }
    cout << "\\n";
}

// Convert 1..9 position to row and col (0-based)
void toRC(int pos, int &r, int &c) {
    pos -= 1;
    r = pos / 3;
    c = pos % 3;
}

// Check if player p ('X' or 'O') has won
bool hasWon(const char b[3][3], char p) {
    for (int i = 0; i < 3; ++i) {
        if (b[i][0]==p && b[i][1]==p && b[i][2]==p) return true;
        if (b[0][i]==p && b[1][i]==p && b[2][i]==p) return true;
    }
    if (b[0][0]==p && b[1][1]==p && b[2][2]==p) return true;
    if (b[0][2]==p && b[1][1]==p && b[2][0]==p) return true;
    return false;
}

// Return true if the board has no empty cells
bool boardFull(const char b[3][3]) {
    for (int r=0;r<3;++r)
        for (int c=0;c<3;++c)
            if (b[r][c]==' ') return false;
    return true;
}

// Simple helper to get empty positions 1..9
vector<int> emptyPositions(const char b[3][3]) {
    vector<int> pos;
    for (int i=1;i<=9;++i) {
        int r,c; toRC(i,r,c);
        if (b[r][c]==' ') pos.push_back(i);
    }
    return pos;
}

// Ask human player to make a move (1-9)
void playerMove(char b[3][3], char player) {
    while (true) {
        cout << "Player " << player << " - enter position (1-9): ";
        int pos;
        if (!(cin >> pos)) {
            cin.clear();
            cin.ignore(10000,'\\n');
            cout << "Please enter a number 1 to 9.\\n";
            continue;
        }
        if (pos < 1 || pos > 9) {
            cout << "Pick between 1 and 9.\\n";
            continue;
        }
        int r,c; toRC(pos,r,c);
        if (b[r][c] != ' ') {
            cout << "That spot is taken. Try another.\\n";
            continue;
        }
        b[r][c] = player;
        break;
    }
}

// Try to find a winning move for player p; return position 1..9 or 0 if none
int findWinningMove(char b[3][3], char p) {
    for (int i=1;i<=9;++i) {
        int r,c; toRC(i,r,c);
        if (b[r][c] == ' ') {
            b[r][c] = p; // try
            bool win = hasWon(b,p);
            b[r][c] = ' '; // undo
            if (win) return i;
        }
    }
    return 0;
}

// Simple AI move: 1) win if possible 2) block opponent 3) take center 4) take corner 5) random
void aiMove(char b[3][3], char aiPlayer, char humanPlayer) {
    // 1. Win if possible
    int move = findWinningMove(b, aiPlayer);
    if (move) { int r,c; toRC(move,r,c); b[r][c] = aiPlayer; return; }

    // 2. Block if human can win next
    move = findWinningMove(b, humanPlayer);
    if (move) { int r,c; toRC(move,r,c); b[r][c] = aiPlayer; return; }

    // 3. Take center if free (position 5)
    int r,c;
    toRC(5,r,c);
    if (b[r][c] == ' ') { b[r][c] = aiPlayer; return; }

    // 4. Take a corner if any (1,3,7,9)
    int corners[4] = {1,3,7,9};
    for (int i=0;i<4;++i) {
        toRC(corners[i],r,c);
        if (b[r][c] == ' ') { b[r][c] = aiPlayer; return; }
    }

    // 5. Else take a random empty spot
    vector<int> empties = emptyPositions(b);
    if (!empties.empty()) {
        int pick = empties[rand() % empties.size()];
        toRC(pick,r,c);
        b[r][c] = aiPlayer;
    }
}

// Main game function
int main() {
    srand((unsigned)time(0)); // random seed
    cout << "Tic-Tac-Toe (simple C++ version)\\n";
    cout << "You can choose: 1) Two-player  2) Play vs Computer\\n";
    cout << "Positions:\\n 1 | 2 | 3\\n---+---+---\\n 4 | 5 | 6\\n---+---+---\\n 7 | 8 | 9\\n\\n";

    char board[3][3];
    char playAgain = 'y';

    while (playAgain=='y' || playAgain=='Y') {
        // reset board
        for (int r=0;r<3;++r)
            for (int c=0;c<3;++c)
                board[r][c] = ' ';

        int mode = 1;
        cout << "Choose mode (1=2-player, 2=vs Computer): ";
        if (!(cin >> mode)) { cin.clear(); cin.ignore(10000,'\\n'); mode = 1; }

        char current = 'X';
        char human = 'X';
        char ai = 'O';
        bool vsComputer = (mode == 2);

        // If vs computer, ask who goes first
        if (vsComputer) {
            char first = 'h';
            cout << "Do you want to go first? (y/n): ";
            cin >> first;
            if (first=='n' || first=='N') { human = 'O'; ai = 'X'; current = 'X'; }
            else { human = 'X'; ai = 'O'; current = 'X'; }
        }

        // Game loop
        while (true) {
            printBoard(board);

            if (vsComputer && current == ai) {
                cout << "Computer is thinking...\\n";
                aiMove(board, ai, human);
            } else {
                playerMove(board, current);
            }

            // check win or draw
            if (hasWon(board, current)) {
                printBoard(board);
                if (vsComputer && current == ai) cout << "Computer (" << ai << ") wins. Better luck next time!\\n";
                else cout << "Player " << current << " wins. Congrats!\\n";
                break;
            }
            if (boardFull(board)) {
                printBoard(board);
                cout << "It's a draw.\\n";
                break;
            }

            // switch
            current = (current == 'X') ? 'O' : 'X';
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing! Good luck with your portfolio.\\n";
    return 0;
}
