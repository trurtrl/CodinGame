#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
float strToRad(string& str)
{
    size_t found = str.find_first_of(",");
    str = str.replace(found, 1, ".");
    return stof(str)*M_PI/180;
};

float distance(float lonA, float latA, float lonB, float latB, int radius)
{
    float x = (lonB - lonA)*cos((latA+latB)/2);
    float y = latB - latA;
    return sqrt(pow(x,2) + pow(y,2));
};
 
int main()
{
    int radius = 6371;
    
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();    
    float lonA = strToRad(LON);
    float latA = strToRad(LAT);

    int N;
    cin >> N; cin.ignore();

    string target;
    float distMin = radius;
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        
        size_t found5 = DEFIB.find_last_of(";");
        size_t found4 = DEFIB.find_last_of(";", found5 - 1);
        string LATB = DEFIB.substr(found5 + 1);
        string LONB = DEFIB.substr(found4 +1, found5-found4-1);
        
        float lonB = strToRad(LONB);
        float latB = strToRad(LATB);
        
        float dist = distance(lonA, latA, lonB, latB, radius);
        if (dist < distMin) 
        {
            target = DEFIB;
            distMin = dist;
        };
    };
    
        size_t found1 = target.find_first_of(";");
        size_t found2 = target.find_first_of(";", found1 + 1);
        
        string toDefib = target.substr(found1 +1, found2 - found1 -1);
        
        cout << toDefib << endl;

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    // cout << "answer" << endl;
}
