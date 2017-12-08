#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    //  In database first key is room's type, second is enter and value is exit
    // that correspond to "LEFT-0, TOP-1, RIGHT-2, BOTTOM-3" rule.
    // Value "5" means inacceptable direction to entrance
    constexpr int database[14][3] = 
    {
        {5},
        {3, 3, 3},
        {2, 5, 0},
        {5, 3, 5},
        {5, 0, 3},
        {3, 2, 5},  // 5-th room
        {2, 5, 0},
        {5, 3, 3},
        {3, 5, 3},
        {3, 3, 5},
        {5, 0, 5},  //10-th room
        {5, 2, 5},
        {5, 5, 3},
        {3, 5, 5}
    };


    enum direct {LEFT, TOP, RIGHT, BOTTOM};


    int W; // number of columns.
    int H; // number of rows.
    cin >> W >> H; cin.ignore();

    int** grid = new int*[H];
    for (int i = 0; i < H; i++) {
        string LINE; // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
        getline(cin, LINE);
        grid[i] = new int[W];
        istringstream is(LINE);
        int room;
        for (int r=0; r<W; ++r)
        {
            is >> room;
            grid[i][r] = room;
        };
    }

    int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> EX; cin.ignore();

    // game loop
    while (1) {
        int XI;
        int YI;

        string POS;
        cin >> XI >> YI >> POS; cin.ignore();

        int position;
        if (POS == "LEFT") position = 0;
        else if (POS == "TOP") position = 1;
        else if (POS == "RIGHT") position = 2;
        else cerr << "wrong position " << POS << endl; 

        int roomType = grid[YI][XI];        
        int entrance = database[roomType][position];
//        cerr << "Room : " << roomType  << "\tpos = "  << POS <<"\tent = " << entrance << endl;        
        switch (entrance)
        {
            case 0 : XI--; break;
            case 2 : XI++; break;
            case 3 : YI++; break;
            case 5 : cerr << "no exit for " << roomType  << " x "  << POS << endl; break;
            default: cerr << "somwthing wrong with data" << endl;
        };

        cout << XI << " " << YI << endl;


    }
}
