#include "Vector.h"
#include <iostream>
#include <algorithm>
using namespace std;

void printIntVec( const Vector<int> a )
{
    int N = a.size( );
    cout << "size=" << N << endl;
    
    for( int i = 0; i < N; ++i )
    {
        cout << "a[" << i << "]=" << a[i] ;
        cout << endl;
    }
}

int main( )
{
    const int N = 20;

    Vector<int> v ; // Make an int Vector 
    printIntVec( v );
    
    // Store N ints in the Vector
    for( int i = 0 ; i < N; ++i )
    {
        v.push_back( i );
    }

    // print the contents
    printIntVec( v );

    v[0] = 1;
    
    return 0;
}
