// 06.09.2014
// Checks if the number is a palindrome number

#include <iostream>

using namespace std;

int reverseNumber(int number);

int main()
{
    int numb, revNumb;
    bool palindrome;

    cin >> numb;
    revNumb = reverseNumber(numb);

    if (numb == revNumb)
        cout << numb << " is a palindrome number" << endl;

    else
        cout << numb << " is not a palindrome number" << endl;

    return 0;
}

int reverseNumber(int numb)
{
    int revNumb = 0;
    int rem = 0;

    while(numb != 0)
    {
        rem = numb % 10;
        revNumb = (revNumb * 10) + rem;
        numb /= 10;
    }

    return revNumb;
}
