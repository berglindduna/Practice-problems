// 29.09.2015
// Makes a nx1 array with the max values in each row in a nxm array

#include <iostream>

using namespace std;

void getArray (int **arr , int dalkar , int radir);
void maxInRows (int **arr, int *arr2 , int dalkar, int radir);

int main()
{
    int cols, rows;

    cin >> cols >> rows;

    int **arr;
    arr = new int* [cols];

    for (int i = 0; i < cols; i++)
        arr[i] = new int [rows];

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
            arr[i][j] = 0;
    }

    int *maxes;
    maxes = new int [rows];

    getArray(arr , cols , rows);
    maxInRows (arr , maxes , cols , rows);

    delete [] maxes;

    for (int i = 0; i < cols; i++)
        delete [] arr[i];

    delete [] arr;

    return 0;
}

void getArray (int **arr , int cols , int rows)
{
    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < cols; i++)
            cin >> arr[i][j];
    }
}

void maxInRows ( int **arr, int *arr2 , int cols, int rows)
{
    int maxNumb;

    for(int j = 0; j < rows; j++)
    {
        maxNumb = arr[0][j];

        for(int i = 1; i < cols; i++)
        {
            if (arr[i][j] > maxNumb)
                maxNumb = arr[i][j];
        }

        *(arr2 + j) = maxNumb;
    }

    for ( int i = 0; i < rows; i++ )
        cout << *(arr2 + i) << endl;
}

