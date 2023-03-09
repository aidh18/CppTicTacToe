#include <iostream>
#include "board.cpp"
#include "player.cpp"
using namespace std;

class Game
{
    private:
    Board _board;
    Player _playerX;
    Player _playerO;
    Player _currPlayer;
    bool _firstInput;

    void AddSymbol()
    {
        _firstInput = true;
        char choice = GetUserChoice();

        while(_board.CheckIfHasSymbol(choice))
        {
            choice = GetUserChoice();
        }
        
        _board.AddSymbol(_currPlayer.GetSymbol(), choice);
    }

    bool CheckIfGameOver(int turns)
    {
        if (_board.CheckIfWon(_currPlayer.GetSymbol()))
        {
            cout << "Congrats! {_currPlayer.GetSymbol()} won!";
            return true;
        }
        else if (turns == 9)
        {
            cout << "The board is full. Game over.";
            return true;
        }

        return false;
    }

    bool CheckIfPlayAgain()
    {
        string input = "";
        char choice = ' ';
        
        while (choice != 'y' && choice != 'n')
        {
            cout << "Would you like to play again(y or n)? ";
            cin >> input;
            choice = tolower(input[0]);
        }

        if (choice == 'y')
            return true;
        else 
            return false;
    }

    void DisplayCurrentPlayer()
    {
        cout << "Current Player : " << _currPlayer.GetSymbol() << "\n";
    }

    char GetUserChoice()
    {
        string choice;

        if (!_firstInput)
        {
            cout << "Invalid input. Where would you like to go? ";
            cin >> choice;
        }

        _firstInput = false;

        while (choice.length() != 1)
        {
            
            cout << "\33[2K\rInvalid input. Where would you like to go? ";
            
            cin >> choice;
        }

        return choice[0];

    }

    void SwitchPlayer()
    {
        if (_currPlayer.GetSymbol() == _playerX.GetSymbol())
            _currPlayer = _playerO;
        else
            _currPlayer = _playerX;
    }

    public:
    Game()
    {
        _playerX.SetSymbol('X');
        _playerO.SetSymbol('O');
    }

    void Run()
    {
        do
        {
            _board.ResetBoard();
            int turns = 0;
            bool isGameOver = false;

            do
            {
                SwitchPlayer();
                DisplayCurrentPlayer();
                _board.DisplayBoard();
                AddSymbol();

                turns++;
                isGameOver = CheckIfGameOver(turns);
            } while (isGameOver == false);

        } while (CheckIfPlayAgain());
    }  
};