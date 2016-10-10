// 16.10.2015

#include <iostream>

using namespace std;

class Food
{
private:
    string name;
    int price;

public:
    Food();
    friend bool operator > (const Food& f1 , const Food& f2);
    friend istream& operator >> (istream& ins , Food& f);
    friend ostream& operator << (ostream& outs , Food& f);
};

Food:: Food()
{
    name = "";
    price = 0;
}

bool operator > (const Food& f1 , const Food& f2)
{
    return (f1.price > f2.price);
}

istream& operator >> (istream& ins , Food& f)
{
    ins >> f.name >> f.price;
    return ins;
}

ostream& operator << (ostream& outs , Food& f)
{
    outs << f.name << " " << f.price;
    return outs;
}

// tests
int main()
{
    Food f1, f2;
    cin >> f1 >> f2;

    if (f1 > f2)
        cout << f1 << endl;

    else
        cout << f2 << endl;

    return 0;
}
