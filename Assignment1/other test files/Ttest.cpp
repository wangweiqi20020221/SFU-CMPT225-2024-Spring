#include "TVector.h"
#include <iostream>
using namespace std;

int main( )
{
    const int N = 12;

    TVector<int> v ; // Make an int Vector 
    v.display(); // print its contents
    v.ddisplay(); // print its contents
    
    // Store N ints in the Vector
    for( int i = 0 ; i < N; ++i )
    {
        v.push_back( i + 20 );
    }

    // print the contents
    v.display();
    v.ddisplay();

    TVector<float> u ;
    u.display(); // print its contents
    u.ddisplay(); // print its contents
    
    // Store N floats in the Vector
    for( int i = 0 ; i < N; ++i )
    {
        u.push_back( i + 20.3 );
    }

    // print the contents
    u.display();
    u.ddisplay();

    return 0;
}
