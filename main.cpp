// OOP, second lab, #8, Domino class
#include <iostream>
#include "domino/domino.h"

int main()
{
    using namespace std;
    using namespace domino;
    Domino first;
    cout << first.getleft() << " : " << first.getright() << "\n";
    first.reverse();
    cout << first.getleft() << " : " << first.getright() << "\n";
    return 0;
}