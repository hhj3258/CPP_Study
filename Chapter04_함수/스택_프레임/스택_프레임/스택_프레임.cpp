#include <iostream>

using namespace std;

int MultiplyBy(int a, int b) 
{
    int c = a * b;
    return c;
}

// F5
// F10
// F11
int main()
{
    int a = 3;
    int b = 5;
    int result = MultiplyBy(b, a);
    
    return 0;
}