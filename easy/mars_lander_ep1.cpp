#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
struct Point{
    int x, y;
    Point(int x, int y)
    :   x{x}, y{y}
    {};
};

class Mars{
public:
    int surfaceN;
    vector<Point*> surface;    
    int X;
    int Y;
    int hSpeed; // the horizontal speed (in m/s), can be negative.
    int vSpeed; // the vertical speed (in m/s), can be negative.
    int fuel; // the quantity of remaining fuel in liters.
    int rotate; // the rotation angle in degrees (-90 to 90).
    int power; // the thrust power (0 to 4).
    
    Mars()
    {
        cin >> surfaceN; cin.ignore();
        for (int i = 0; i < surfaceN; i++) {
            int landX; // X coordinate of a surface point. (0 to 6999)
            int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
            cin >> landX >> landY; cin.ignore();
//            cerr << landX << "x" << landY << endl;
            surface.push_back(new Point(landX, landY));
        };
        defineFlat();        
    }
    ~Mars()
    {
        for (int i=0; i<surfaceN; ++i) delete surface[i];
    }
    
    void setData()
    {
        cin >> X >> Y >> hSpeed >> vSpeed >> fuel >> rotate >> power; cin.ignore();
    }
    
    void move()
    {
        defineRoverPosition();                
        nextPeakIndex = maxAltitude(p2, flat2);

        int vSpeedMod = (0 == vSpeed) ? 1 : vSpeed;                
        int hSpeedMod = (0 == hSpeed) ? 1 : hSpeed;         
        targetX = surface[flat1]->x;
        targetY = surface[flat1]->y;                
        int steps = min(abs((targetX-X)/hSpeedMod), abs((targetY-Y)/vSpeedMod));
        
        if ((X + hSpeed*steps) < targetX)
        {
            rotate = (rotate-15 < -45) ? -45 : rotate-15;
            powerPlus();
            cerr << "Hrot = " << rotate << endl;
        };
        if ((Y + vSpeed*steps) < targetY)
        {
            rotate = (rotate-15 < -45) ? -45 : rotate-15;
            powerPlus();
            cerr << "Vrot = " << rotate << endl;
        };        
        
        if (p1 == flat1)
        {
            if (vSpeed < -30)
            {
                rotate = 0;
                power = 4;
            };
            
            if (hSpeed > 15)
            {
                rotate = 45;
                power = 4;
            };  
            
            if ((Y - surface[flat1]->y < 50))  
            {
                rotate = 0;
                power = 3;
            };
        }         
        
        cout << rotate << " " << power << endl;                 
    }    
    
private:
    const float gravity = 3.711;

    int flat1, flat2;
    int nextPeakIndex;                   //  index of obtacle's peak in the way
    int p1, p2;                 //  indexes between that Points the rover is
    const int hReserve = 100;    //  distance within flat surface next to tilts 
    int targetX;    
    int targetY;
    
    void defineFlat()
    {
        flat1 = 0;
        flat2 = 1;
        while (surface[flat2]->y != surface[flat1]->y) 
        {
            flat1 +=1;
            flat2 +=1;
        }; 
    }    

    void defineRoverPosition()
    {
        p2 = 0;
        while (surface[p2]->x <= X)
        {
            p2 += 1;
        };
        p1 = (surface[p2]->x == X ) ? p2 : p2-1;
        cerr << "FLAT: "<< flat1 << " " << flat2 << "\tP: " << p1 << " " << p2 << endl;
    }

    int maxAltitude(int begin, int end)
    {
        int pMax = begin;
        for (int p = begin; p < end; ++p)
        {
            if (surface[p]->y > surface[pMax]->y) pMax = p;
        };
        return pMax;
    }

    void powerPlus()
    {
        power  = (power+1 > 4) ? 4 : power+1;        
    }
    void powerMinus()
    {
        power  = (power-1 < 0) ? 0 : power-1;    
    }    
}; 
 
 
int main()
{
    Mars rover = Mars();
    
    while(1)
    {
        rover.setData();
        rover.move();
    };    
    
/*    int surfaceN; // the number of points used to draw the surface of Mars.
    cin >> surfaceN; cin.ignore();
    for (int i = 0; i < surfaceN; i++) {
        int landX; // X coordinate of a surface point. (0 to 6999)
        int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> landX >> landY; cin.ignore();
    }

    // game loop
    while (1) {
        int X;
        int Y;
        int hSpeed; // the horizontal speed (in m/s), can be negative.
        int vSpeed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power; // the thrust power (0 to 4).
        cin >> X >> Y >> hSpeed >> vSpeed >> fuel >> rotate >> power; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // 2 integers: rotate power. rotate is the desired rotation angle (should be 0 for level 1), power is the desired thrust power (0 to 4).
        cout << "0 3" << endl;
    }*/
}
