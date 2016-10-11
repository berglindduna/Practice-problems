// 09.10.2015
// Game table simulation
// Input: 5 integers (lines, rows, x, y, k) and 1 string line (letters)
//      (x,y) is the initial position on the linesxrows table
//      letters has k orders of movement (U,D,L,R)
// Output: the game table (showed as points) exept:
//      The initial position (is "X")
//      Points that the player moves to (is "o")
//      If the player goes outside of the table (is "!")

#include <iostream>
#include <string>

using namespace std;

void init(string** arr , int lines , int rows , int &x , int y);
void moves(string **arr , int lines , int rows , int x , int y , int k , string letters);
void printArray(string **arr , int lines , int rows);
void deleteArray(string **arr , int lines , int rows);

int main()
{
    int lines , rows , x , y , k;
    string letters;

    cin >> lines >> rows >> x >> y >> k;
    getline(cin, letters);

    string **arr = new string * [lines];

    for (int i = 0; i < lines; i++)
        arr[i] = new string [rows];

    init(arr , lines , rows , x , y);
    moves(arr , lines , rows , x , y , k , letters);
    printArray(arr , lines , rows);
    deleteArray(arr , lines , rows);

    return 0;
}

void init(string **arr , int lines , int rows , int& x , int y)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < rows; j++)
            arr[i][j] = ".";
    }

    x = (lines - 1 - x);
    arr[x][y] = "X";
}

void moves(string **arr , int lines , int rows , int x , int y , int k , string letters)
{
    string theMove;
    for (int i = 0; i < k; i++)
    {
        theMove = letters[i];
        if (theMove == "U")
        {
            x --;
            if (x < 0)
            {
                arr[0][y] = "!";
                break;
            }

            else
                arr[x][y] = "o";
        }

        else if (theMove == "D")
        {
            x ++;
            if (x > (lines - 1))
            {
                arr[(lines - 1)][y] = "!";
                break;
            }

            else
                arr[x][y] = "o";
        }

        else if (theMove == "L")
        {
            y --;
            if (y < 0)
            {
                arr[x][0] = "!";
                break;
            }

            else
                arr[x][y] = "o";
        }

        else if (theMove == "R")
        {
            y ++;
            if (y < 0)
            {
                arr[x][(rows - 1)] = "!";
                break;
            }

            else
                arr[x][y] = "o";
        }
    }
}

void printArray(string **arr , int lines , int rows)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < rows; j++)
            cout << arr[i][j];

        cout << endl;
    }
}

void deleteArray(string **arr , int lines , int rows)
{
    for (int i = 0; i < rows; i++)
        delete [] arr[i];

    delete [] arr;
}
