#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

string stringToBin(string& origin)
{
    string result;
    for (int s=0; s< origin.size(); ++s)
    {
        char ch = origin[s];
        for (int i=6; i>=0; --i)
        {
            result += (ch & (1 << i))? '1' : '0';
        };
    };
    return result;
};

string toChuckCode(const string& binStr)
{
    string res ;
    char prevBit = 'a';
    for (int i=0; i< binStr.size(); ++i)
    {
        char bit = binStr[i];
        if (bit != prevBit)
        {
            res += (bit == '1') ? " 0 " : " 00 ";
        };
        res += "0";
        prevBit = bit;
    };
    res.erase(0, 1);
    return res;
};

           
 
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);
    string str;    
//    int bitNum = 7;
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    cout << toChuckCode(stringToBin(MESSAGE)); 

}
