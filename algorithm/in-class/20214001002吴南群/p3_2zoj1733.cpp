#include<iostream>
#include<cstdlib>

using namespace std;

string a,b;
int common[ 201 ][ 201 ];

int main()
{
    while ( cin >> a >> b )
    {
        int len1 = a.length();
        int len2 = b.length();
        for ( int i = 0 ; i <= len1 ; ++ i )
            common[ i ][ 0 ] = 0;
        for ( int i = 0 ; i <= len2 ; ++ i )
            common[ 0 ][ i ] = 0;
        for ( int i = 1 ; i <= len1 ; ++ i )
        for ( int j = 1 ; j <= len2 ; ++ j )
        if  ( a[ i-1 ] == b[ j-1 ] )
            common[ i ][ j ] = common[ i-1 ][ j-1 ] + 1;
        else
            common[ i ][ j ] = max( common[ i-1 ][ j ] , common[ i ][ j-1 ] );  
        cout << common[ len1 ][ len2 ] << endl;
    }
    return 0; 
}