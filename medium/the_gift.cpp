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
    vector<int> budgets;
    int full = 0;
    int C;
    cin >> C; cin.ignore();
    cerr << "C = " << C << endl;
    for (int i = 0; i < N; i++) {
        int B;
        cin >> B; cin.ignore();
        budgets.push_back(B);
        full += B;
        cerr << "B = " << B << endl;
    };
    
    if (full < C) cout << "IMPOSSIBLE" << endl;
    else 
    {
        sort(budgets.begin(), budgets.end());
        int restParticipants = N;
        for (int i=0; i<N; ++i)
        {                    
            int equalPrice = C/restParticipants;
            cerr << "eq = " << equalPrice << endl;
            int price = (budgets[i] > equalPrice )? equalPrice : budgets[i];
            cout << price << endl;
            C -= price;
            restParticipants--;
        };  
    };        
    
}
