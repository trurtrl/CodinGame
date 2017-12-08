#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int getSerialNumber(char ch)
{
    int ascii = (int)ch;
    if (ascii <(int)'A' || ascii > (int)'Z')
    {       
        return (int)'Z' - (int)'A' +1; //  number of last character in an art string
    }
    else return ascii - (int)'A';
};

void printLineForLetter(string& lineHeap, int serialNumber, const int widthLetter)
{
    int num = serialNumber*widthLetter;
    for (int let = num; let < num+widthLetter; ++let) cout << lineHeap[let];        
};

void draw(string& str, vector<string>& heap, const int widthLetter)
{      
    for (int i = 0; i<heap.size(); ++i)
    {
        for (int s=0; s<str.size(); ++s) 
        {
            printLineForLetter(heap[i], getSerialNumber(str[s]), widthLetter);        
        };
        cout << endl;
    };
};

 
int main()
{
    int Lw;
    cin >> Lw; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    vector<string> heap;


    string T;
    getline(cin, T);
    transform(T.begin(), T.end(), T.begin(), ::toupper);
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        heap.push_back(ROW);
    }

    draw(T, heap, Lw);
    

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    //    cout << "answer" << endl;
}
