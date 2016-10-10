// 29.09.2015
// Input: integer n followed by an array of N integers
// Output: the two highest absolute values in the array

#include <iostream>

using namespace std;

void getArray (int *arr , int n);
void changeMinus (int *arr , int n);
void findMax (int *arr , int n);


int main()
{
    int n;
    int *arr;
    cin >> n;
    arr = new int[n];

    for ( int i = 0; i < n; i++)
        cin >> arr[i];

    changeMinus (arr , n);
    findMax (arr , n);

    delete [] arr;

    return 0;
}

void changeMinus (int *arr , int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            arr[i] *= -1;
    }
}

void findMax (int *arr , int n)
{
    int highest = arr[0];
    int nextHighest = arr[1];

    for (int i = 2; i < n; i++) {
        if (highest < nextHighest) {
            int temp = highest;
            highest = nextHighest;
            nextHighest = temp;
        }

        if (arr[i] > nextHighest)
            nextHighest = arr[i];
    }

    cout << highest << " " << nextHighest << endl;
}
