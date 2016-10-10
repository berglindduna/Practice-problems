// 20.09.2015
// Input: integer N followed by N integers that form an array
// Output: the array and the array reversed

#include <iostream>

using namespace std;

void reverseArray(int *arr, int N);
void printArray(int *arr, int N);

int main()
{
    int N;
    int *arr;

    cin >> N;
    arr = new int[N];

    for (int i = 0; i < N; i++ )
        cin >> arr[i];

    cout<< "Your array: "<< endl;
    printArray(arr, N);

    reverseArray(arr, N);
    cout<< "Your array reversed: "<< endl;
    printArray(arr, N);

    delete[] arr;

    return 0;
}

void reverseArray(int *arr, int N)
{
    int reversed[N];

    for(int i = 0; i < N; i++)
        reversed[i] = arr[N-1-i];

    for(int i = 0; i < N; i++)
        arr[i] = reversed[i];
}

void printArray(int *arr, int N)
{
    for(int i = 0; i < (N - 1); i++)
        cout << arr[i] << " ";

    cout << arr[N - 1] << endl;
}
