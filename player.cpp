#include "player.h"

Player::Player(string n, char c, bool cs)
{
    name = n;
    color = c;
    coinside = cs;
    
    for (int i = 0 ; i < 6; i++){
        for (int j = 0; j < 7; j++){
            board[i][j] = 'e';
        }
    }
}

void Player::SetCoordinate(int x, int y)
{
    board[x][y] = 'f';
}

string Player::GetName()
{
    return name;
}
        
char Player::GetColor()
{
    return color;
}

bool Player::GetCoinSide()
{
    return coinside;
}

char Player::GetCoordinate(int x, int y)
{
    return board[x][y];
}

void Player::PrintPlayerBoard()
{
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}
