// 25.09.2015
// Input: integer N followed by N strings
// Output: The strings sorted with the first letter capital and no repeats

#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

void getNames(vector <string> &names , int n);
void alphabetical(vector <string> &names , int n);
void printOut(vector <string> &names , int n);

int main()
{
    int n;
    cin >> n;
    vector <string> names;
    getNames(names , n);
    n = names.size();
    alphabetical(names , n);
    printOut(names , n);

    return 0;
}

void getNames(vector <string> &names , int n)
{
    string name;
    int match;

    for (int i = 0; i < n; i++)
    {
        match = 0;
        cin >> name;
        name[0] = toupper(name[0]);

        for (int j = 1; j < name.size(); j++)
            name[j] = tolower(name[j]);

        for (int k = 0; k < names.size(); k++)
        {
            if(name == names[k])
                match = 1;
        }

        if (match == 0)
            names.push_back(name);
    }
}

void alphabetical (vector <string> &names , int n)
{
    string tmp_min;
    int j = 0;

    while (j < n)
    {
        string theMin = names[j];
        int numb = j;
        for (int i = j; i < n; i++)
        {
            if (names[i] < theMin)
            {
                theMin = names[i];
                numb = i;
            }
        }

        tmp_min = names[numb];
        names[numb] = names[j];
        names[j] = tmp_min;
        j++;
    }
}

void printOut(vector <string> &names , int n)
{
    for (int i = 0; i < (n - 1); i++)
        cout << names[i] << ", ";

    cout << names[(n - 1)] << endl;
}
