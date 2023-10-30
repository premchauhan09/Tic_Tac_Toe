#include <iostream>
using namespace std;
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
int digit;
char token = 'X';
bool tie = false;
string n1 = "";
string n2 = "";

void functionOne()
{

    cout << "   |        |   \n";
    cout << " " << space[0][0] << " |    " << space[0][1] << "   | " << space[0][2] << " \n";
    cout << "___|________|___\n";
    cout << "   |        |   \n";
    cout << " " << space[1][0] << " |    " << space[1][1] << "   | " << space[1][2] << " \n";
    cout << "___|________|___\n";
    cout << "   |        |   \n";
    cout << " " << space[2][0] << " |    " << space[2][1] << "   | " << space[2][2] << " \n";
    cout << "   |        |   \n";
}

void functionTwo()
{

    if (token == 'X')
    {
        cout << n1 << " "
             << "Please Enter ";
    }
    if (token == '0')
    {
        cout << n2 << " "
             << "Please Enter ";
    }
    cin >> digit;
    switch (digit)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    default:
        cout << "Invalid Move";
    }
    if (token == 'X' && space[row][column] != 'X' && space[row][column] != '0')
    {
        space[row][column] = 'X';
        token = '0';
    }
    else if (token == '0' && space[row][column] != 'X' && space[row][column] != '0')
    {
        space[row][column] = '0';
        token = 'X';
    }
    else
    {
        cout << "There is no empty Space !" << endl;
        functionTwo();
    }
    functionOne();
}
bool functionThree()
{
    for (int i = 0; i < 3; i++)
    {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
        {
            return true;
        }
        if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0])
        {
            return true;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'X' && space[i][j] != '0')
            {
                return false;
            }
        }
    }
    tie = true;
    return false;
}

int main()
{
    cout << "Enter the name of the first player: \n";
    getline(cin, n1);
    cout << "Enter the name of the Second  player: \n";
    getline(cin, n2);
    cout << n1 << " is player1 so he/she will play first \n";
    cout << n2 << " is player2 so he/she will play first \n";

    while (!functionThree())
    {
        functionOne();
        functionTwo();
        functionThree();
    }
    if (token == '0' && tie == false)
    {
        cout << n1 << " "
             << "wins!!" << endl;
    }
    else if (token == 'X' && tie == false)
    {
        cout << n2 << " "
             << "wins!!" << endl;
    }
    else
    {
        cout << "It's a draw!" << endl;
    }
}