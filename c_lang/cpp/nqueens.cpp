#include <iostream>
#include <vector>
#define vectorBoard std::vector<std::vector<bool>>

bool placeQueen(vectorBoard&, int chessBoardSize, int row);
bool checkIsSafe(vectorBoard&, int chessBoardSize, int row, int col);
void printBoard(vectorBoard&, int);

int main()
{
    std::cout << "Enter the chess board size (M x M): ";
    int chessBoardSize = 0, i = 0, j = 0;
    std::cin >> chessBoardSize;
    std::vector<bool> col(chessBoardSize, false);
    vectorBoard chessBoard(chessBoardSize, col);

    placeQueen(chessBoard, chessBoardSize, 0);
    printBoard(chessBoard, chessBoardSize);

    return 0;
}

bool placeQueen(vectorBoard& chessBoard, int chessBoardSize, int row)
{
    //printBoard(chessBoard, chessBoardSize);

    bool success = false;

    if(row == chessBoardSize)
        return true;

    int j = 0;

    for(j = 0; j < chessBoardSize; j++)
    {
        if(checkIsSafe(chessBoard, chessBoardSize, row, j))
        {
            chessBoard[row][j] = true;

            if(placeQueen(chessBoard, chessBoardSize, row+1))
            {
                success = true;
                break;
            }
        }

        chessBoard[row][j] = false;
    }

    return success;
}

bool checkIsSafe(vectorBoard& chessBoard, int chessBoardSize, int row, int col)
{
    int i = row, j = col;

    //check right diagonal
    while(i > -1 && j < chessBoardSize)
    {
        if(chessBoard[i][j] == true)
        {
            return false;
        }
        
        i--, j++;
    }

    //check down stright
    i = row, j = col;
    
    while(i > -1)
    {
        if(chessBoard[i][j] == true)
        {
            return false;
        }

        i--;
    }

    //check left diagonal
    i = row;

    while(i > -1 && j > -1)
    {
        if(chessBoard[i][j] == true)
        {
            return false;
        }

        i--, j--;
    }

    return true;   
}

void printBoard(vectorBoard& chessBoard, int chessBoardSize)
{
    int i = 0, j = 0;

    for(i = 0; i < chessBoardSize; i++)
    {
        for(j = 0; j < chessBoardSize; j++)
        {
            if(chessBoard[i][j] == true)
            {
                std::cout << "Q|";
            }
            else
            {
                std::cout << " |";
            }
        }
        
        std::cout << std::endl;
    }
    std::cout << std::endl;
}