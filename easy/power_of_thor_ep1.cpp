
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    int x = initialTX;      // current Thor's position
    int y = initialTY; 
    string direction;
    

    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();


        if (lightY < y) 
        {
            y -= 1;
            direction = "N";
        } else if (lightY == y)
        {
            direction = "";
        } else {
            y += 1;
            direction = "S";
        };
        cerr << "direction=" << direction << "-" << endl;

        if (lightX > x) {
            x += 1;
            direction += "E";
        } else if (lightX < x) {
            x -= 1;
            direction += "W";
        };
        cerr << "x=" << x << "\ty=" << y << endl;         
        
        
//        if (lightX > initialTX)
        
        cout << direction << endl;
//        cout << "SE" << endl;
    };
}