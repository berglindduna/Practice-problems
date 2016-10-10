// 28.08.2015
// Input: integer n
// Output: how many years, days, hours, minutes and seconds n seconds are

#include <iostream>

using namespace std;

int years(int& sek);
int days(int& sek);
int hours(int& sek);
int minutes(int& sek);
void seconds(int& sek);

const int sec_m = 60, sec_h = 60 * 60, sec_d = sec_h * 24, sec_y = sec_d * 365;
int main()
{
   int sec;
   cin >> sec;

   sec = years(sec);
   sec = days(sec);
   sec = hours(sec);
   sec = minutes(sec);
   seconds(sec);

    return 0;
}

int years(int& sec)
{
    int a = sec / sec_y;

    if (a == 1)
        cout << a << " year" << endl;

    else if (a > 1)
        cout << a << " years" << endl;

    sec %= sec_y;

    return sec;
}

int days(int& sec)
{
    int a = sec / sec_d;

    if (a == 1)
        cout << a << " day" << endl;

    if (a > 1)
        cout << a << " days" << endl;

    sec %= sec_d;
    return sec;
}

int hours(int& sec)
{
    int a = sec / sec_h;

    if (a == 1)
        cout << a << " hour" << endl;

    if (a > 1)
        cout << a << " hours" << endl;

    sec %= sec_h;
    return sec;
}

int minutes(int& sec)
{
 int a = sec / sec_m;
    if (a == 1)
        cout << a << " minute" << endl;

    if (a > 1)
        cout << a << " minutes" << endl;

    sec %= sec_m;
    return sec;
}

void seconds(int& sec)
{
    if(sec == 1)
        cout << sec << " second" << endl;

    if(sec > 1)
        cout << sec << " seconds" << endl;
}
