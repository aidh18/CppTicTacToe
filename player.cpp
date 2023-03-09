class Player
{
    private:
        char _symbol;

    public:
        Player() { }

        char GetSymbol()
        {
            return _symbol;
        }

        void SetSymbol(char symbol)
        {
            _symbol = symbol;
        }
};
