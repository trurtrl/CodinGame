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

    vector<int> temp; 
    int minT;

    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    cerr << " n = " << n << endl;
    if (n <= 0) 
    {
        minT = 0;
    }
    else
    {
        for (int i = 0; i < n; i++) {
            int t; // a temperature expressed as an integer ranging from -273 to 5526
            cin >> t; cin.ignore();
            temp.push_back(t);
            cerr << t << endl;
        };
    
        minT = temp[0];

        for_each(temp.begin(), temp.end(), [&minT](int t){
            int x = (abs(minT) < abs(t)) ? minT : t;
            minT = (abs(t) == abs(minT)) ? max(t, minT) : x;
        });
    };

    
    cout << minT << endl;

    

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

//    cout << "result" << endl;
}
