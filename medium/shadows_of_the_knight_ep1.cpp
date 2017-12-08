#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

class Building
{
public:

    int W; // width of the building.
    int H; // height of the building.
    int N; // maximum number of turns before game over.
    int X0;
    int Y0;
    string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
    

    Building()
    {
        U = 0;
        L = 0;
        cin >> W >> H; cin.ignore();
        R = W;
        D = H;
        cin >> N; cin.ignore();
        cin >> X0 >> Y0; cin.ignore();
    }
    
    void setDirection()
    {
        cin >> bombDir; cin.ignore();
    }
    
    void move()
    {
        changeOrigin();
        X0 = (L+R)/2;
        Y0 = (U+D)/2;
        cout << X0 << " " << Y0 << endl;
    }
    
private:

    int L, R, U, D; // limits of origin rectangular

    void changeOrigin()
    {
        if (bombDir == "U")
        {
            L = X0;
            R = X0;
            D = Y0 - 1;
        }
        else if (bombDir == "R")
        {
            L = X0 + 1;
            D = Y0;
            U = Y0;
        }
        else if (bombDir == "D")
        {
            L = X0;
            R = X0;
            U = Y0 + 1;
        }
        else if (bombDir == "L")
        {
            R = X0 + 1;
            D = Y0;
            U = Y0;
        }
        else if (bombDir == "UR")
        {
            L = X0 + 1;
            D = Y0 - 1;
        }
        else if (bombDir == "DR")
        {
            L = X0 + 1;
            U = Y0 + 1;
        }
        else if (bombDir == "DL")
        {
            U = Y0 + 1;
            R = X0 - 1;
        }
        else if (bombDir == "UL")
        {
            R = X0 - 1;
            D = Y0 - 1;
        };
    }
};

int main()
{
    Building batman = Building();

    while(1)
    {
        batman.setDirection();
        batman.move();

    };
}