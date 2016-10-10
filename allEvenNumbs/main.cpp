// 04.09.15
// Input: integer n >= 0
// Output: all even number from 0 to n

#include <iostream>

using namespace std;

bool isEven(int numb);
void printEven(int numb);

int main()
{
    int numb;

    cin >> numb;
    printEven(numb);

    return 0;
}

bool isEven(int numb)
{
    if ((numb % 2) == 0)
        return true;

    return false;
}

void printEven(int numb)
{
    for(int i = 0; i <= numb; i++)
    {
        if (isEven(i) == 1)
            cout << i << endl;
    }
}
