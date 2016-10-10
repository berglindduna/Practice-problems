// 28.08.2015

#include <iostream>

using namespace std;

int getNumber();
void printout(int number1, int number2);

int main()
{
    int numb1, numb2, numb3;
    bool switcher = true;

    cin >> numb1 >> numb2 >> numb3;

    if (numb1 + numb2 == numb3) {
        cout << numb1 << " + " << numb2 << " = " << numb3 << endl;
        switcher = false;
    }

    if (numb1 - numb2 == numb3) {
        cout << numb1 << " - " << numb2 << " = " << numb3 << endl;
        switcher = false;
    }

    if (numb1 * numb3 == numb3) {
        cout << numb1 << " * " << numb2 << " = " << numb3 << endl;
        switcher = false;
    }

    if (numb2 != 0) {
        if (numb1 / numb2 == numb3) {
            cout << numb1 << " / " << numb2 << " = " << numb3 << endl;
            switcher = false;
        }

        if (numb1 % numb2 == numb3) {
            cout << numb1 << " % " << numb2 << " = " << numb3 << endl;
            switcher = false;
        }
    }

    if (switcher)
        cout << "no match" << endl;

    return 0;
}
