#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "player.cpp"
using namespace std;

bool HeadsOrTails(string name, string name2)
{
    char ht;
    cout << name << ", you may select a side of a coin. Guessing the correct side gives you first turn." << endl;
    Sleep(1000);
    cout << endl;
    cout << name << ", would you like to choose heads or tails?" << endl;
    cout << "Press 'h' for heads or 't' for tails." << endl;
    cin >> ht;
    while (ht != 'h' && ht != 'H' && ht != 't' && ht != 'T'){
        cout << "Invalid choice." << endl;
        cout << endl;
        Sleep(1000);
        cout << name << ", would you like to choose heads or tails?" << endl;
        cout << "Press 'h' for heads or 't' for tails." << endl;
        cin >> ht;
    }
    int num = rand() % 2;
    //0 is heads, 1 is tails
    if (num == 0 && (ht == 'h' || ht == 'H') || num == 1 && (ht == 't' || ht == 'T')){
        cout << name << " won the coin flip! ";
        cout << name << " gets the first action." << endl;
        return true; 
    }
    else {
        cout << name << " lost the coin flip. ";
        cout << name2 << " gets the first action." << endl;
        return false; 
    }
}

void PrintBoard(char b[][15]){
    for (int i = 0 ; i < 6; i++){
        for (int j = 0; j < 15; j++){
            cout << b[i][j];
        }
        cout << endl;
    }
}

bool VerticalMatch(Player player, int xInsert, int yInsert, int row, int column)
{
    char dupeArray[row][column];
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            dupeArray[i][j] = player.GetCoordinate(i, j);
        }
    }

    int tileTwo = yInsert + 1;
    int tileThree = yInsert + 2;
    int tileFour = yInsert + 3;
    if (tileTwo < row && tileThree < row && tileFour < row){
        if (dupeArray[tileTwo][xInsert] == 'f' && dupeArray[tileThree][xInsert] == 'f' && dupeArray[tileFour][xInsert] == 'f'){
            return true;
        }
    }
    return false;
}

bool HorizontalMatch(Player player, int xInsert, int yInsert, int row, int column)
{
    char dupeArray[row][column];
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            dupeArray[i][j] = player.GetCoordinate(i, j);
        }
    }
    int leftOne = xInsert - 1;
    int leftTwo = xInsert - 2;
    int leftThree = xInsert - 3;
    int rightOne = xInsert + 1;
    int rightTwo = xInsert + 2;
    int rightThree = xInsert + 3;
    if (rightOne < column && rightTwo < column && rightThree < column){ //insert at slot one wins
        if (dupeArray[yInsert][rightOne] == 'f' && dupeArray[yInsert][rightTwo] == 'f' && dupeArray[yInsert][rightThree] == 'f'){
            return true;
        }
    } 

    if (leftOne >= 0 && rightOne < column && rightTwo < column){ //insert at slot two wins
        if (dupeArray[yInsert][leftOne] == 'f' && dupeArray[yInsert][rightOne] == 'f' && dupeArray[yInsert][rightTwo] == 'f'){
            return true;
        }
    }

    if (leftOne >= 0 && leftTwo >= 0 && rightOne < column){ //insert at slot three wins
        if (dupeArray[yInsert][leftOne] == 'f' && dupeArray[yInsert][leftTwo] == 'f' && dupeArray[yInsert][rightOne] == 'f'){
            return true;
        }
    }

    if (leftOne >= 0 && leftTwo >= 0 && leftThree >= 0){ //insert at slot four wins
        if (dupeArray[yInsert][leftOne] == 'f' && dupeArray[yInsert][leftTwo] == 'f' && dupeArray[yInsert][leftThree] == 'f'){
            return true;
        }
    }

    return false;
}

bool RightDiagonalMatch(Player player, int xInsert, int yInsert, int row, int column)
{
    char dupeArray[row][column];
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            dupeArray[i][j] = player.GetCoordinate(i, j);
        }
    }
    int leftOne = xInsert - 1;
    int leftTwo = xInsert - 2;
    int leftThree = xInsert - 3;
    int rightOne = xInsert + 1;
    int rightTwo = xInsert + 2;
    int rightThree = xInsert + 3;
    int upOne = yInsert - 1;
    int upTwo = yInsert - 2;
    int upThree = yInsert - 3;
    int downOne = yInsert + 1;
    int downTwo = yInsert + 2;
    int downThree = yInsert + 3;
    if (upOne >= 0 && upTwo >= 0 && upThree >= 0 && rightOne < column && rightTwo < column && rightThree < column){ //first element in diagonal
        if (dupeArray[upOne][rightOne] == 'f' && dupeArray[upTwo][rightTwo] == 'f' && dupeArray[upThree][rightThree] == 'f'){
            return true;
        }
    }

    if (downOne < row && upOne >= 0 && upTwo >= 0 && leftOne >= 0 && rightOne < column && rightTwo < column){ //second element in diagonal
        if (dupeArray[downOne][leftOne] == 'f' && dupeArray[upOne][rightOne] == 'f' && dupeArray[upTwo][rightTwo] == 'f'){
            return true;
        }
    }

    if (downOne < row && downTwo < row && upOne >= 0 && leftOne >= 0 && leftTwo >= 0 && rightOne < column){ //third element in diagonal
        if (dupeArray[downOne][leftOne] == 'f' && dupeArray[downTwo][leftTwo] == 'f' && dupeArray[upOne][rightOne] == 'f'){
            return true;
        }
    } 

    if (downOne < row && downTwo < row && downThree < row && leftOne >= 0 && leftTwo >= 0 && leftThree >= 0){ //fourth element in diagonal
        if (dupeArray[downOne][leftOne] == 'f' && dupeArray[downTwo][leftTwo] == 'f' && dupeArray[downThree][leftThree] == 'f'){
            return true;
        }
    } 

    return false;
}

bool LeftDiagonalMatch(Player player, int xInsert, int yInsert, int row, int column)
{
    char dupeArray[row][column];
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            dupeArray[i][j] = player.GetCoordinate(i, j);
        }
    }
    int leftOne = xInsert - 1;
    int leftTwo = xInsert - 2;
    int leftThree = xInsert - 3;
    int rightOne = xInsert + 1;
    int rightTwo = xInsert + 2;
    int rightThree = xInsert + 3;
    int upOne = yInsert - 1;
    int upTwo = yInsert - 2;
    int upThree = yInsert - 3;
    int downOne = yInsert + 1;
    int downTwo = yInsert + 2;
    int downThree = yInsert + 3;
    if (upOne >= 0 && upTwo >= 0 && upThree >= 0 && leftOne <= 0 && leftTwo <= 0 && leftThree <= 0){ //first element in diagonal
        if (dupeArray[upOne][leftOne] == 'f' && dupeArray[upTwo][leftTwo] == 'f' && dupeArray[upThree][leftThree] == 'f'){
            return true;
        }
    }

    if (downOne < row && upOne >= 0 && upTwo >= 0 && leftOne >= 0 && leftTwo < column && rightOne < column){ //second element in diagonal
        if (dupeArray[downOne][rightOne] == 'f' && dupeArray[upOne][leftOne] == 'f' && dupeArray[upTwo][leftTwo] == 'f'){
            return true;
        }
    }

    if (downOne < row && downTwo < row && upOne >= 0 && rightOne >= 0 && rightTwo >= 0 && leftOne < column){ //third element in diagonal
        if (dupeArray[downOne][rightOne] == 'f' && dupeArray[downTwo][rightTwo] == 'f' && dupeArray[upOne][leftOne] == 'f'){
            return true;
        }
    } 

    if (downOne < row && downTwo < row && downThree < row && rightOne >= 0 && rightTwo >= 0 && rightThree >= 0){ //third element in diagonal
        if (dupeArray[downOne][rightOne] == 'f' && dupeArray[downTwo][rightTwo] == 'f' && dupeArray[downThree][rightThree] == 'f'){
            return true;
        }
    } 
    return false;
}

bool Winner(Player player, int xInsert, int yInsert, int row, int column)
{
    if (VerticalMatch(player, xInsert, yInsert, row, column)){
        return true;
    }

    if (HorizontalMatch(player, xInsert, yInsert, row, column)){
        return true;
    }

    if (RightDiagonalMatch(player, xInsert, yInsert, row, column)){
        return true;
    }

    if (LeftDiagonalMatch(player, xInsert, yInsert, row, column)){
        return true;
    }
    return false;
}

void Action(Player &p, char b[][15], int r, int c)
{
    string insertion = "";
    int xIns, yIns = 0;
    bool ex = false;
    while(true){
        cout << "This is the current board." << endl;
        PrintBoard(b);
        cout << p.GetName() << ", what column would you like to insert your chip?" << endl;
        cout << "Input a column 1-7 please. E represents an empty slot on the board." << endl;
        cin >> insertion;
        while (insertion.length() > 1 || !isdigit(insertion[0])){ //if input string length > 1 or not a digit
            cout << "Invalid column." << endl;
            cout << endl;
            Sleep(1000);
            cout << "This is the current board." << endl;
            PrintBoard(b);
            cout << p.GetName() << ", what column would you like to insert your chip?" << endl;
            cout << "Input a column 1-7 please. E represents an empty slot on the board." << endl;
            cin >> insertion;
        }
        if (b[0][stoi(insertion) * 2 - 1] != 'y' && b[0][stoi(insertion) * 2 - 1] != 'r'){ //check if top row is filled
            while (stoi(insertion) * 2 - 1 < 0 || stoi(insertion) * 2 - 1 > 13){
                cout << "Invalid column." << endl;
                cout << endl;
                Sleep(1000);
                cout << "This is the current board." << endl;
                PrintBoard(b);
                cout << p.GetName() << ", what column would you like to insert your chip?" << endl;
                cin >> insertion;
            }
            int j = r-1; //begins at bottom row
            int colInsertion = stoi(insertion) * 2 - 1;
            while (b[j][colInsertion] == 'y' || b[j][colInsertion] == 'r'){
                j--;
            }
            b[j][colInsertion] = p.GetColor();
            xIns = colInsertion/2;
            yIns = j;
            p.SetCoordinate(j, xIns);
            cout << p.GetName() << " placed their chip at column " << xIns + 1 << ", row " << yIns << endl;
            if (Winner(p, xIns, yIns, r, c)){
                cout << "The game is over." << endl;
                cout << p.GetName() << " has won!" << endl;
                exit(0);
            }
            Sleep(1000);
            ex = true;
        }
        else { //restarts turn if column is full
            cout << "Column is full." << endl;
            cout << endl;
            Sleep(1000);
        }
        if (ex){
            break;
        }
    }
}

int main(){
    srand(time(0));
    int rows = 6;
    int columns = 15;
    char board[rows][15]; //6 rows 15 columns

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (j % 2 == 0){
                board[i][j] = ' ';
            }
            else {
                board[i][j] = 'E';
            }
        }
    }

    string name1, name2;
    cout << "Please enter the name for player 1: " << endl;
    cin >> name1;
    cout << "Please enter the name for player 2: " << endl;
    cin >> name2;
    char color1, color2;
    cout << name1 << ", would you like to play as yellow or red? Press 'y' for yellow or 'r' for red." << endl;
    cin >> color1;
    while (color1 != 'y' && color1 != 'r' && color1 != 'Y' && color1 != 'R'){
        cout << "Invalid choice." << endl;
        cout << endl;
        Sleep(1000);
        cout << name1 << ", would you like to play as yellow or red? Press 'y' for yellow or 'r' for red." << endl;
        cin >> color1;
    }
    if (color1 == 'y' || color1 == 'Y'){
        cout << name1 << " has selected yellow." << endl;
        cout << name2 << ", you will be playing as red." << endl;
        color2 = 'r';
    }
    else {
        cout << name1 << " has selected red." << endl;
        cout << name2 << ", you will be playing as yellow." << endl;
        color2 = 'y';
    }
    bool p1FlipChoice = HeadsOrTails(name1, name2);
    Player p1(name1, color1, p1FlipChoice);
    Player p2(name2, color2, !p1FlipChoice);

    if (p2.GetCoinSide()){ //player 2 gets first turn
        while (true){
            Action(p2, board, rows, columns/2);
            Action(p1, board, rows, columns/2); 
        }
    }

    else { //player 1 gets first turn
        while (true){
            Action(p1, board, rows, columns/2);
            Action(p2, board, rows, columns/2);
        }
    }
    return 0;
}
