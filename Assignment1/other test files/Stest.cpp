#include "Stack.h"
#include <iostream>
using namespace std;


int main( )
{
    const int N = 20;

    Stack<int> v ; // Make an int stack 
    v.display(); // print its contents
    v.ddisplay(); // print its contents
    
    // Push N ints onto the stack 
    for( int i = 0 ; i < N; ++i )
    {
        v.push( i+5 );
    }

    v.display(); // print the contents
    v.ddisplay(); // print its contents

    // pop twice and push a new element
    cout << "first pop: " << v.pop() << endl ;
    cout << "second pop: " << v.pop() << endl ;
    v.push(99);

    v.display(); // print the contents
    v.ddisplay(); // print its contents
    
    return 0;
}
