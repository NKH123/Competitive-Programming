/*
ID: neerajd3
LANG: C++
TASK: ride
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int calc( string str )
{
    int result = 1;
    for( int i=0 ; i<str.length() ; i++ )
    {
        result *= str[i] - 'A' + 1;
    }
    return result % 47;
}

int main()
{
    ifstream in;
    ofstream out;
    in.open( "ride.in" );
    out.open( "ride.out" );
    string str1,str2;
    in >> str1 >> str2;
    if( calc( str1 ) == calc( str2 ) )
        out << "GO" << endl;
    else
        out << "STAY" << endl;
    in.close();
    out.close();
    return 0;
}