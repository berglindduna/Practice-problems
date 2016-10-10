// 06.09.2015
// Prints a numbers factors
// if numb < 0, print 0

#include <iostream>

using namespace std;

bool isPrime(int numb);


int main()
{
  int numb;

  cin >> numb;

  if(numb < 1)
      cout << "0" << endl;

  if(numb == 1)
      cout << numb << endl;

  if(isPrime(numb))
  {
      cout << numb << endl;
  }

  else
  {
      for (int i = 2; i <= numb; i++)
      {
          if((numb % i) == 0)
          {
              if(numb == i)
                 cout << i << endl;

              else
                  cout << i << ", ";

              numb /= i;
              i--;
          }
      }
  }
    return 0;
}

bool isPrime(int numb)
{
    int n = 2;
    bool match = true;

    while (n < numb)
    {
        if ((numb % n) == 0)
            match = false;

        n++;
    }

    return(match);
}
