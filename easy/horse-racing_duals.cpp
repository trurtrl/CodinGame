#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;
    cin >> N; cin.ignore();
    vector<int> horses;
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
    horses.push_back(Pi);
    }
    int min = 100;
    sort(horses.begin(), horses.end());
    for (int i = 1; i< horses.size(); ++i)
    {
        int dif = horses[i] - horses[i-1];
        if (dif < min) min = dif;
    };
    
    cout << min << endl;
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

//    cout << "answer" << endl;
}
