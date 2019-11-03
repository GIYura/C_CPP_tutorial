#include <iostream>
#include <fstream>
#include <exception>

using namespace std;
ifstream fin;

string path = "text1.txt";

int main()
{
    fin.exceptions(ifstream::badbit | ifstream::failbit);
    try{
        cout << "Try to open file" << endl;
        fin.open(path);
        cout << "File successfully open" << endl;
    }
    catch(const ifstream::failure& ex){
        cout << ex.what() << endl;
        cout << ex.code() << endl;
    }

    return 0;
}
