#include <cstring>
using namespace std;

class Board
{
    private:
        char* _board = new char[50];
    
    public:
        Board() { }

    void ResetBoard()
    {
        string board = "1 | 2 | 3\n---------\n4 | 5 | 6\n---------\n7 | 8 | 9\n";
        strcpy(_board, board.c_str());
    }

    void DisplayBoard()
    {
        system("CLS");
        for(int i = 0 ; i < 50 ; i ++)
        {
            cout << _board[i] ;
        }
    }

    bool CheckIfHasSymbol(char position)
    {
        for (int i = 0; i < sizeof(_board) / sizeof(char); i++)
        {
            if (_board[i] == position)
            {
                return false;
            }
        }
        return true;
    }

    void AddSymbol(char symbol, char position)
    {
        for (int i = 0; i < sizeof(_board) / sizeof(char); i++)
        {
            if (_board[i] == position)
            {
                _board[i] = symbol;
            }
        }
    }

    bool CheckIfWon(char symbol)
    {
        if (_board[0] == symbol && _board[4] == symbol && _board[8] == symbol)
            return true;
        if (_board[20] == symbol && _board[24] == symbol && _board[28] == symbol)
            return true;
        if (_board[40] == symbol && _board[44] == symbol && _board[48] == symbol)
            return true;
        if (_board[0] == symbol && _board[20] == symbol && _board[40] == symbol)
            return true;
        if (_board[4] == symbol && _board[24] == symbol && _board[44] == symbol)
            return true;
        if (_board[8] == symbol && _board[28] == symbol && _board[48] == symbol)
            return true;
        if (_board[0] == symbol && _board[24] == symbol && _board[48] == symbol)
            return true;
        if (_board[40] == symbol && _board[24] == symbol && _board[8] == symbol)
            return true;

        return false;
    }
};