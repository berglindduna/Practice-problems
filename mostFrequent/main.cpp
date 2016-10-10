// 13.09.2015
// Input: number n and array with n integers
// Output: most frequent value in the array

#include <iostream>

using namespace std;

int getMaxNumber ( int *arr , int n );

int main()
{
    int n, maxNumb;
    int *arr;

    cin >> n;
    arr = new int [n];

    for ( int i = 0; i < n; i++ )
        cin >> *( arr + i ) ;

    maxNumb = getMaxNumber ( arr , n );

    cout << maxNumb << endl;

    delete [] arr;

    return 0;
}

int getMaxNumber ( int *arr , int n )
{
    int maxNumb = 0 ;
    int maxCount = 0;
    int counter = 0 ;

    for ( int i = 0; i < n; i++ )
    {
        counter = 0;

        for ( int j = 0 ; j < n; j++)
        {
            if ( *( arr + i ) == *( arr + j ))
            {
                counter += 1;
            }
        }

        if ( counter > maxCount)
        {
            maxCount = counter;
            maxNumb = *( arr+i );
        }
    }

    return maxNumb;
}
