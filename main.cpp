// OOP, second lab, #8, Domino class
#include <iostream>
#include "domino/domino.h"
//#include "functions.h"
int main()
{
    using namespace domino;
    int command;
    int number;
    Dominoes MyDom;

/*    Dominoes dom1(3);
    std::cout << dom1;
    Domino d(4, 6);
    std::cout << std::endl << d << std::endl;
    dom1 += d;
    std::cout << dom1;*/

    try {
        while(true) {
            std::cout << "1. Create random dominoes\n"
                      << "2. Create custom dominoes\n"
                      << "3. Quit the program" << std::endl;
            command = getvalue(1, 3);
            try {
                switch(command){
                    case 1: {
                        std::cout << "Type number of random dominoes [0; 30]: ";
                        number = getvalue(0, 30);
                        Dominoes Temp(number);
                        MyDom = Temp;
                        break;
                    }
                    case 2: {
                        std::cout << "Let's create our own custom dominoes:\n";
                        Dominoes Temp(getvalue(0, 10), 0);
                        MyDom = Temp;
                        MyDom.sort();
                        break;
                    }
                    default: {
                        return 0;
                    }
                }
                while (true) {
                    std::cout << "DOMINOES\n1. Show your dominoes   "
                              << "2. Add random domino  "
                              << "3. Add custom domino\n"
                              << "4. Select a group of dominoes by a number "
                              << "5. Delete random domino   "
                              << "6. Delete custom domino\n"
                              << "7. Sort dominoes  "
                              << "8. Quit the program\n";
                    command = getvalue(1, 8);
                    switch(command){
                        case 1:// show dominoes
                        {
                            std::cout << MyDom;
                            break;
                        }
                        case 2://add a random
                        {
                            MyDom.addRandDomino();
                            break;
                        }
                        case 3://add custom
                        {
                            Domino temp(getvalue(0, 6), getvalue(0, 6));
                            ~temp;
//                            MyDom.addDomino(temp);
                            MyDom += temp;
                            break;
                        }
                        case 4://select a group of dominoes
                        {
                            number = getvalue(0, 6);
                            MyDom.selection(number);
                            break;
                        }
                        case 5://del random
                        {
                            MyDom.delRandom();
                            break;
                        }
                        case 6:// del custom
                        {
                            number = getvalue(0, MyDom.getsize() - 1);
                            MyDom.delDomino(number);
                            break;
                        }
                        case 7://sort
                        {
                            std::cout << "Sorting Dominoes:  \n";
                            std::cout << MyDom;
                            MyDom.sort();
                            std::cout << MyDom;
                            break;
                        }
                        default://quit
                        {
                            return 0;
                        }
                    }
                }
            }catch (const std::bad_alloc& ex)
            {
                std::cerr << "Not enough memory" << std::endl;
            }catch (const std::invalid_argument)
            {
                std::cout << "Please try again"<<std::endl;
            }
        }
    }catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}