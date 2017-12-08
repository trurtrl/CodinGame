#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
string strToLower(string& str)
{
//    str.erase(remove(str.begin(), str.end(), '\n'), str.end()); 
    transform( str.begin(), str.end(), str.begin(), [](unsigned char ch){return tolower(ch);});
    return str;
};

string printMIME(string& FNAME, map<string, string>& mime)
{

    size_t found = FNAME.find_last_of(".");
    if (found == string::npos) return "UNKNOWN";
            
    string ext = FNAME.substr(found+1);
    ext = strToLower(ext);
//    cerr << "ext=" << ext << endl;
//    map<string, string>::const_iterator it = 
//        find_if(mime.begin(), mime.end(), [&ext](pair<string,string> p) -> bool {
//        return ext == strToLower(p.first);} );
        
    map<string, string>::const_iterator it = mime.find(ext);
        
    if (it != mime.end()) return (*it).second;
    else return "UNKNOWN" ;     
};    
 
int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    map<string, string> mime;
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        mime.insert(make_pair(strToLower(EXT), MT));
    }
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);

        cout << printMIME(FNAME, mime) << endl;
 
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
//    cout << "UNKNOWN" << endl;
}
