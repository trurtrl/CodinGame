#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/
 
int findKeyMax(vector<int>& vec)
{
    if (vec.empty()) 
    {
        cerr << "Vector is empty" << endl;
        return -1;
    };    
    int max = 0;
    
    for (int m=0; m< vec.size(); ++m)
    {
        if (vec[m] > vec[max]) max = m;
        
    };
    return max;
};

 
int main()
{
    vector<int> vecMountains(8);
    // game loop
    while (1) {
        for (int i = 0; i < 8; i++) {
            int mountainH; // represents the height of one mountain.
            cin >> mountainH; cin.ignore();
            vecMountains[i] = mountainH;
        };

        int kill = findKeyMax(vecMountains);
        cout << kill << endl;
        vecMountains[kill] = 0;  

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
    };
}
