#include <string>
using namespace std;
class Player
{
    private:
        string name;
        char color;
        bool coinside;
        char board[6][7];
    public:
        Player(string, char, bool);
        void SetCoordinate(int, int);
        string GetName();
        char GetColor();
        bool GetCoinSide();
        char GetCoordinate(int, int);
        void PrintPlayerBoard();
};