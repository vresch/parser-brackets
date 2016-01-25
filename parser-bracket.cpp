/* Parsing of open&close brackets in file */

#include <fstream>
#include <iostream>

using namespace std;

string filename = "file-bracket";

int main(int argc, char *argv[])
{
    if (argc > 1) filename = argv[1];

    ifstream file(filename);
    if ( !file.good() )
    {
        cout << "Error opening file" << endl;
        return 0;
    }
    string data;
    int bracket_open = 0, bracket_close = 0;
    while ( !file.eof() )
    {
        getline(file, data);
        for ( string::iterator it = data.begin(); it != data.end(); ++it )
        {
            if ( *it == '/' && *(it+1) == '/')
                break;
            else if ( *it == '(' )
            ++bracket_open;
            else if ( *it == ')' )
            ++bracket_close;
        }
    }
    if (bracket_open != bracket_close)
        cout << "Brackets: Mismatched!" << endl;
    else
        cout << "Brackets: OK!" << endl;

    return 0;
}
