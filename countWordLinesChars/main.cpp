// 11.09.2015
// Counts the lines, words and chars in a input file

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

void openFile(ifstream& ins , string name);
int countLines(ifstream& ins);
int countWords(ifstream& ins);
int countChars(ifstream& ins);
void printOut(ostream& outs , int lines , int words , int chars);

int main()
{
    int lines, words , chars;
    string name;
    cin >> name;
    ifstream ins;

    openFile(ins , name);
    lines = countLines(ins);
    ins.close();
    openFile(ins , name);
    words = countWords(ins);
    ins.close();
    openFile(ins , name);
    chars = countChars(ins);
    ins.close();

    printOut(cout , lines , words , chars);
    return 0;
}

void openFile(ifstream& ins , string name)
{
    ins.open(name.c_str());
    if (ins.fail())
    {
        cout << "error" << endl;
        exit(1);
    }
}

void openOutFile(ofstream & outs , string name)
{
    outs.open(name.c_str());

    if (outs.fail())
        cout << "error" << endl;
}

int countLines(ifstream& ins)
{
    string s;
    vector <string> vec;
    while (!ins.eof())
    {
        getline(ins , s);
        vec.push_back(s);
    }
    unsigned int n = vec.size();

    if (vec[(n - 1)] == "")
        n -=1;

    return n;
}

int countWords(ifstream& ins)
{
    string s;
    int counter = 0;

    while (ins >> s)
        counter ++;

    return counter;
}

int countChars(ifstream& ins)
{
    int counter = 0;

    while(!ins.eof())
    {
        ins.get();
        counter += 1;
    }
    return counter;
}

void printOut(ostream& outs , int lines , int words , int chars)
{
    outs << lines << " lines" << endl;
    outs << words << " words" << endl;
    outs << chars << " chars" << endl;
}
