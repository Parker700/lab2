// OOP, second lab, #8, Domino class
#include <iostream>
#include "domino/domino.h"
//#include "functions.h"
int main()
{
    using namespace domino;
    Dominoes Dominoes(5);
    std::cout << Dominoes;
    Domino domino1;
    Dominoes += domino1;
    std::cout << Dominoes;
    Dominoes.sort();
    std::cout << Dominoes;
    Dominoes.delDomino(3);
    std::cout << Dominoes;
    return 0;
}