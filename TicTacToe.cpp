#include <iostream>
#include <limits>
#include <random>
#include <time.h>                               // The code uses features in c++11. Compile it using "g++ -std=c++11".

using namespace std;

char grid[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'X';

//The following are prototypes of functions.

void Draw();

void PlayerInput();
void AIinput();
char HowToWin();
void CheckWin(int count);

int main()
{
    int count = 1;
    cout << "Welcome to the Tic Tac Toe Game! Press enter to begin!" << endl; cout << endl;
    cin.get();

    Draw();
    while (1)
    {
        PlayerInput();Draw();
        CheckWin(count);
        ++count;
        AIinput(); Draw();
        CheckWin(count);
        ++count;
    }
}
void Draw()
{
    system("CLS");                                          // clears the screen

    for(int r = 0; r < 3 ; ++r)
    {
       cout << "-----------"<< endl;
       for(int c = 0; c < 3; ++c)
       {
           cout << grid[r][c] << " | ";
       }
       cout << endl;
    }
}
void PlayerInput()
{
    PlayerLOOP: player = 'X';
    cout << endl;

    cout << "Input the number of the field you would like to fill." << endl;

    int n;
    cin >> n;

    while(!cin || n < 1 || n > 9)                                       // disallows inputs that are not integers between 1 and 9.
    {
        cout << "Please enter an integer value between 1 and 9." << endl;
        cin.clear();
        cin.ignore(numeric_limits <streamsize>::max(), '\n');
        cout << "Input the number of the field you would like to fill." << endl;
        cin >> n;
    }
    if(n == 1)
    {
        if(grid[0][0] == '1')
        {
            grid[0][0] = player;
        }
        else
        {
            cout << "This field has already been taken; please try again!" << endl;
            goto PlayerLOOP;
        }
    }
    else if(n == 2)
    {
        if(grid[0][1] == '2')
        {
            grid[0][1] = player;
        }
        else
        {
            cout << "This field has already been taken; please try again!" << endl;
            goto PlayerLOOP;
        }
    }
    else if(n == 3)
    {
        if(grid[0][2] == '3')
        {
            grid[0][2] = player;
        }
        else
        {
            cout << "This field has already been taken; please try again!" << endl;
            goto PlayerLOOP;
        }
    }
    else if(n == 4)
    {
        if(grid[1][0] == '4')
        {
            grid[1][0] = player;
        }
        else
        {
            cout << "This field has already been taken; please try again!" << endl;
            goto PlayerLOOP;
        }
    }
    else if(n == 5)
    {
        if(grid[1][1] == '5')
        {
           grid[1][1] = player;
        }
        else
        {
            cout << "This field has already been taken; please try again!" << endl;
            goto PlayerLOOP;
        }
    }
    else if(n == 6)
    {
        if(grid[1][2] == '6')
        {
            grid[1][2] = player;
        }
        else
        {
            cout << "This field has already been taken; please try again!" << endl;
            goto PlayerLOOP;
        }
    }
    else if(n == 7)
    {
        if(grid[2][0] == '7')
        {
           grid[2][0] = player;
        }
        else
        {
            cout << "This field has already been taken; please try again!" << endl;
            goto PlayerLOOP;
        }
    }
    else if(n == 8)
    {
        if(grid[2][1] == '8')
        {
            grid[2][1] = player;
        }
        else
        {
            cout << "This field has already been taken; please try again!" << endl;
            goto PlayerLOOP;
        }
    }
    else if(n == 9)
    {
        if(grid[2][2] == '9')
        {
            grid[2][2] = player;
        }
        else
        {
            cout << "This field has already been taken; please try again!" << endl;
            goto PlayerLOOP;
        }
    }
}
void AIinput()
{
    AILOOP: player = 'O';

    mt19937 mt_rand(time(0)); // seed the generator
    uniform_int_distribution<> distr(1, 9); // define the range
    int n = (int)distr(mt_rand);

    if(n == 1)
    {
        if(grid[0][0] == '1')
        {
            grid[0][0] = player;
        }
        else
        {
            goto AILOOP;
        }
    }
    else if(n == 2)
    {
        if(grid[0][1] == '2')
        {
            grid[0][1] = player;
        }
        else
        {
            goto AILOOP;
        }
    }
    else if(n == 3)
    {
        if(grid[0][2] == '3')
        {
            grid[0][2] = player;
        }
        else
        {
            goto AILOOP;
        }
    }
    else if(n == 4)
    {
        if(grid[1][0] == '4')
        {
            grid[1][0] = player;
        }
        else
        {
            goto AILOOP;
        }
    }
    else if(n == 5)
    {
        if(grid[1][1] == '5')
        {
            grid[1][1] = player;
        }
        else
        {
            goto AILOOP;
        }
    }
    else if(n == 6)
    {
        if(grid[1][2] == '6')
        {
            grid[1][2] = player;
        }
        else
        {
            goto AILOOP;
        }
    }
    else if(n == 7)
    {
        if(grid[2][0] == '7')
        {
           grid[2][0] = player;
        }
        else
        {
            goto AILOOP;
        }
    }
    else if(n == 8)
    {
        if(grid[2][1] == '8')
        {
            grid[2][1] = player;
        }
        else
        {
            goto AILOOP;
        }
    }
    else if(n == 9)
    {
        if(grid[2][2] == '9')
        {
            grid[2][2] = player;
        }
        else
        {
            goto AILOOP;
        }
    }
}

char HowToWin()
{

/*

Grid Field:

00 | 01 | 02
------------
10 | 11 | 12
------------
20 | 21 | 22

*/
    // Checking to see if we have three 'X's in a row

    if(grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X')
    {
        return 'X';
    }
    if(grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X')
    {
        return 'X';
    }
    if(grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X')
    {
        return 'X';
    }

    //Checking to see if we have three 'X's in a column

    if(grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X')
    {
        return 'X';
    }
    if(grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X')
    {
        return 'X';
    }
    if(grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X')
    {
        return 'X';
    }

    //Checking to see if we have three 'X's in a diagonal

    if(grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X')
    {
        return 'X';
    }
    if(grid[2][0] == 'X' && grid[1][1] == 'X' && grid[0][2] == 'X')
    {
        return 'X';
    }

    //Checking to see if we have three 'O's in a row

    if(grid[0][0] == 'O' && grid[0][1] == 'O' && grid[0][2] == 'O')
    {
        return 'O';
    }
    if(grid[1][0] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O')
    {
        return 'O';
    }
    if(grid[2][0] == 'O' && grid[2][1] == 'O' && grid[2][2] == 'O')
    {
        return 'O';
    }

    //Checking to see if we have three 'O's in a column

    if(grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O')
    {
        return 'O';
    }
    if(grid[0][1] == 'O' && grid[1][1] == 'O' && grid[2][1] == 'O')
    {
        return 'O';
    }
    if(grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O')
    {
        return 'O';
    }

    //Checking to see if we have three 'O's in a diagonal

    if(grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O')
    {
        return 'O';
    }
    if(grid[2][0] == 'O' && grid[1][1] == 'O' && grid[0][2] == 'O')
    {
        return 'O';
    }
    return '+';                     // Oddly, if this line is removed, inputting a '7' makes the player automatically win.
}
void CheckWin(int count)
{
        if(count < 3)               // Obviously, there is no need to check count when less than three turns have elapsed.
        {
            return;
        }

        if (HowToWin() == 'X')
        {
            cout << "You win!" << endl;
            system("PAUSE");
            exit(0);
        }
        else if (HowToWin() == 'O')
        {
            cout << "The computer wins!" << endl;
            system("PAUSE");
            exit(0);
        }
        else if (HowToWin() == '+' && count == 9)
        {
            cout << "It's a draw!" << endl;
            system("PAUSE");
            exit(0);
        }
}

