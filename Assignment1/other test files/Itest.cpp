#include "IVector.h"
#include <iostream>
using namespace std;

int main( )
{
    const int N = 12;

    IVector v ; // Make an int Vector 
    v.display(); // print its contents
    v.ddisplay(); // print the array contents
    
    // Store N ints in the Vector
    for( int i = 20 ; i < N+20 ; ++i )
    {
        v.push_back( i );
    }

    // print the contents
    v.display();
    v.ddisplay(); // print the array contents

    v[2] = v[4];
    v.pop_back();
    v.pop_back();
    
    v.display();
    v.ddisplay(); // print the array contents

    return 0;
}
