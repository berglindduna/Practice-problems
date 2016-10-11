// 28.09.2015
// Input: two integers cmin and cmax
// Output: All even temperatures between cmin and cmax in Celsius, Fahrenheit and Kelvin

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void getVector(vector<int> &vec , int cmax , int cmin);
void changeHeat(int c , double& f , double& k);

int main()
{
    int cmax , cmin , c;
    double f , k;
    f = 0.00;
    k = 0.00;
    vector<int> vec;
    cin >> cmin >> cmax;
    getVector(vec , cmax , cmin);

    cout << "Celsius " << "Fahrenheit " << "Kelvin " << endl;

    for (int i = 0; i < vec.size(); i++)
    {
        c = vec[i];
        cout << c << " ";
        changeHeat(c , f , k);
        cout << setprecision(2) << fixed;
        cout << f << " " << k << endl;
    }

    return 0;
}

void getVector(vector<int> &vec , int cmax , int cmin)
{
    int i = cmin;
    while (i <= cmax) {
        vec.push_back(i);
        i += 2;
    }
}

void changeHeat(int c , double& f , double& k)
{
    f = ((1.8 * c) + 32.00);
    k = c + 273.15;
}
