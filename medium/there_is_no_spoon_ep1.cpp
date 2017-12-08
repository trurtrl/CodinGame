#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

class MyArray{
public:

    int height, width;


    MyArray(int height, int width)
    :   height{height},
        width{width}
    {
        array = new bool* [height];
        for (int k=0; k<height; ++k)
        {
            array[k] = new bool [width];
        };
    }
    ~MyArray()
    {
        for (int i=0; i<height; ++i) delete [] array[i];
        delete [] array;
    }
      
    void fitArray(int row, string line)
    {
        for (int x=0; x<width; ++x)
        {
            if (line.at(x) == '.') array[row][x] = false; 
            else { array[row][x] = true; }
        };
    }

    void printNodes()
    {
        for (int y=0; y<height; ++y)
        {
            for (int x=0; x<width; ++x)
            {
                cerr << x <<" "<< y << endl;
                cerr << array[y][x] << endl;
                if (array[y][x])
                {
                    int x2 = defineX2(x,y);
                    int y3 = defineY3(x,y);
                    int y2 = (0 < x2) ? y : -1;
                    int x3 = (0 < y3) ? x : -1;

                    cout << x <<" "<< y <<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
                };
            };
        };
    }

private:
    bool** array;

    int defineX2(int x, int y)
    {
        ++x;
        while(x<width)
        {
            if (array[y][x]) return x;
            ++x;
        };
        return -1; 
    }        

    int defineY3(int x, int y)
    {
        ++y;
        while(y<height)
        {
            if (array[y][x]) return y;
            ++y;
        };
        return -1;
    }
};


int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();

    MyArray arr = MyArray(height, width);

    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);

        arr.fitArray(i, line);
    };

    arr.printNodes();
}
