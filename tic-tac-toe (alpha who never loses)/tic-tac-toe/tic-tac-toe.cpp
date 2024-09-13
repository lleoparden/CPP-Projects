#include <iostream>
using namespace std;

    const int SIZE = 3;
    char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    char player = 'X'; // Human is 'X', alpha is 'O'
    int plays = 0;
    int it = 0;
    int wins = 0;
    void printBoard() {
        cout << "-------------\n";
        for (int i = 0; i < SIZE; i++) {
            cout << "| ";
            for (int j = 0; j < SIZE; j++) {
                cout << board[i][j] << " | ";
            }
            cout << "\n-------------\n";
        }
    }

    bool isWinner(char c) {
        // Check rows and columns
        for (int i = 0; i < SIZE; i++) {
            if ((board[i][0] == c && board[i][1] == c && board[i][2] == c) ||
                (board[0][i] == c && board[1][i] == c && board[2][i] == c)) {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == c && board[1][1] == c && board[2][2] == c) ||
            (board[0][2] == c && board[1][1] == c && board[2][0] == c)) {
            return true;
        }
        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    return false;
                }
            }
        }
        return true;
    }

    bool canWin(char c, int& row, int& col) {
        // Check rows and columns
        wins = 0;
        for (int i = 0; i < SIZE; i++) {
            if ((board[i][0] == c && board[i][1] == c && board[i][2] != 'X' && board[i][2] != 'O')) {
                row = i;
                col = 2;
                wins++;
            }
            if ((board[i][0] == c && board[i][2] == c && board[i][1] != 'X' && board[i][1] != 'O')) {
                row = i;
                col = 1;
                wins++;
            }
            if ((board[i][1] == c && board[i][2] == c && board[i][0] != 'X' && board[i][0] != 'O')) {
                row = i;
                col = 0;
                wins++;
            }
            if ((board[0][i] == c && board[1][i] == c && board[2][i] != 'X' && board[2][i] != 'O')) {
                row = 2;
                col = i;
                wins++;
            }
            if ((board[0][i] == c && board[2][i] == c && board[1][i] != 'X' && board[1][i] != 'O')) {
                row = 1;
                col = i;
                wins++;
            }
            if ((board[1][i] == c && board[2][i] == c && board[0][i] != 'X' && board[0][i] != 'O')) {
                row = 0;
                col = i;
                wins++;
            }
        }
        // Check diagonals
        if (board[0][0] == c && board[1][1] == c && board[2][2] != 'X' && board[2][2] != 'O') {
            row = 2;
            col = 2;
            wins++;
        }
        if (board[0][0] == c && board[2][2] == c && board[1][1] != 'X' && board[1][1] != 'O') {
            row = 1;
            col = 1;
            wins++;
        }
        if (board[1][1] == c && board[2][2] == c && board[0][0] != 'X' && board[0][0] != 'O') {
            row = 0;
            col = 0;
            wins++;
        }
        if (board[0][2] == c && board[1][1] == c && board[2][0] != 'X' && board[2][0] != 'O') {
            row = 2;
            col = 0;
            wins++;
        }
        if (board[0][2] == c && board[2][0] == c && board[1][1] != 'X' && board[1][1] != 'O') {
            row = 1;
            col = 1;
            wins++;
        }
        if (board[1][1] == c && board[2][0] == c && board[0][2] != 'X' && board[0][2] != 'O') {
            row = 0;
            col = 2;
            wins++;
        }
        if (wins >= 1) {
            return true;
        }

        return false;
    }

    bool canwinnextround(char c,char d) 
    {
        int row, col,_2,_1;
        char holder;
        char holder2;
        int i = 0;
        if (it == 1) {
            i = 1;
        }
        
        for (i ; i < SIZE;i++) 
        {
            for (int j = 0;j<SIZE;j++) 
            {
                if(board[i][j] != 'X' && board[i][j] != 'O')
                {
                    holder = board[i][j];
                    board[i][j] = c;
                    
                    if (canWin(c, row, col))
                    {
                        if (c == 'O')
                        {
                            holder2 = board[row][col];

                            board[i][j] = 'X';
                            bool first = canWin('X', _1, _2);
                            int wins1 = wins;
                            board[i][j] = holder;

                            board[row][col] = 'X';
                            bool second = canWin('X', _1, _2);
                            int wins2 = wins;
                            if (first && second) 
                            {
                                if (wins1 > wins2) {
                                    board[i][j] = d;
                                    board[row][col] = holder2;
                                    return true;
                                }
                                else {
                                    board[row][col] = d;
                                    board[i][j] = holder;
                                    return true;
                                }
                            }
                            else if (first) 
                            {
                                board[i][j] = d;
                                board[row][col] = holder2;
                                return true;
                            }
                            else if (second)
                            {
                                board[row][col] = d;
                                board[i][j] = holder;
                                return true;
                            }
                            else 
                            {
                                board[row][col] = holder2;
                                board[i][j] = holder;
                                continue;
                            }
                            
                        }
                        else 
                        {
                            board[i][j] = d;
                            return true;
                        }

                    }
                    else 
                    {
                        board[i][j] = holder;
                    }
                }
            }
        }
        
        return false;
    }

    void humanMove() {
        int move;
        while (true) {
            cout << "Enter your move (1-9): ";
            cin >> move;
            move--; // Adjust for 0-based indexing
            int row = move / SIZE;
            int col = move % SIZE;

            if (move >= 0 && move < SIZE * SIZE && board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = 'X';
                break;
            }
            else {
                cout << "Invalid move, try again.\n";
            }
        }
    }

    void alphaMove()
    {
        int row, col;
        cout << "alpha is making its move...\n";

        // alpha tries to win
        if (canWin('O', row, col)) {
            board[row][col] = 'O';
            return;
        }
        
        // alpha tries to block the human from winning
        if (canWin('X', row, col)) {
            board[row][col] = 'O';
            return;
        }
        
        //alpha tries possibilities
        if (plays == 2) {
            if (board[0][0] == 'X' || board[0][2] == 'X' || board[2][0] == 'X' || board[2][2] == 'X') {
                board[1][1] = 'O';
                it = 1;
                return;
            }
            for (int i = 0; i < SIZE;i++) {
                for (int j = 0;j < SIZE;j++) {
                    if (board[i][j] == 'X' ) {
                        if(i != 1 || j != 1)
                        {
                            if (i == 2) {
                                board[i - 1][j] = 'O';
                                return;
                            }
                            else {
                                board[i + 1][j] = 'O';
                                return;
                            }
                        }
                    }
                }
            }
        }
       
        // Otherwise, the alpha takes the first available spot
        if (canwinnextround('O','O')) {
            return;
            
        }         
        else if(canwinnextround('X', 'O')) {
            return;
        }
        // alpha checks the center square
        if (board[1][1] != 'X' && board[1][1] != 'O') {
            board[1][1] = 'O';
            return;
        }
        //very last option
        for (int i=0; i < SIZE;i++)
        {
            for (int j = 0;j < SIZE;j++)
            {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    board[i][j] = 'O';
                    return;
                }
            }
        }
    }
    int main() 
    {
        cout << "Welcome to Tic-Tac-Toe!\n";
        printBoard();

        while (true) {
            
            plays++;
 
            if (player == 'X') {
                humanMove();
            }
            else {
                alphaMove();
            }

            printBoard();

            if (isWinner(player)) {
                
                cout << "alpha" << " wins!\n";
               
                break;
            }
            else if (isBoardFull()) {
                cout << "It's a draw!\n";
                break;
            }

            player = (player == 'X') ? 'O' : 'X'; // Switch player
        }
        system("pause");
        return 0;
    }
