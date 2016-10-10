// 13.09.2015
// Input: string1, string2 and line
// Changes all string1 in line to string 2 and changes all first letters to upper

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void changeWords (string& text , string w1 , string w2);
void changeToUpper (string& text);

int main()
{
    string w1 , w2 , text;
    cin >> w1 >> w2;
    getline(cin, text);

    changeWords (text , w1 , w2);
    changeToUpper (text);

    cout << text << endl;

    return 0;
}

void changeWords (string& text , string w1 , string w2)
{
    unsigned int p = text.find (w1);
    int length = w1.length ();
    int length2 = w2.length();

    while ( p < text.length() )
    {
            text.erase (p , length);
            text.insert (p , w2 , 0 , length2);
            p = text.find (w1);
    }

    unsigned int p2 = text.find_first_of(" ");

    if (p2 == 0)
        text.erase(0 , 1);
}


void changeToUpper (string& text)
{
    if (isalpha (text[0]))
        text[0] = toupper(text[0]);

    unsigned int p = text.find_first_of (" ");

    while (p < (text.length() - 1))
    {
        if (isalpha (text[p + 1]))
            text [p + 1] = toupper (text [p + 1]);

        p = text.find_first_of (" " , p + 1);
    }
}
