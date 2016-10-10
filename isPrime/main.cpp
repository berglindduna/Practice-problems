// 28.08.2015
// Checks if a number is a prime nunmber
#include <iostream>

using namespace std;

bool isNumbPrime(int numb);

int main()
{
    int numb;
    bool prime;

    cin >> numb;
    prime = isNumbPrime(numb);

    if (prime == true)
        cout << numb << " is a prime number!" << endl;
    else
        cout << numb << " is not a prime number!" << endl;

    return 0;
}

bool isNumbPrime(int numb)
{
    int n = 2;
    bool match = true;

    while((n < numb) && (match == true))
    {
        if ((numb % n) == 0)
        {
            match = false;
        }

        n += 1;
    }

    return match;
}
