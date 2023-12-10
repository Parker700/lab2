#include "domino.h"
#include <iostream>
#include <cmath>
using namespace std;
namespace domino {//namespace domino opened
    int getvalue() {
        int num;
        cin >> num;
        while (true) {
            if (num > -1 && num < 7) {
                return num;
            } else {
                cout << "That is wrong, please, repeat.\n";
                cin >> num;
            }
        }
    }
    Domino::Domino(){
        cout << "We are creating a new domino. Say us the first value of the domino: \n";
        left = getvalue();
        cout << "And now the second one: \n";
        right = getvalue();
    }
    int Domino::getleft() const{
        return left;
    }
    int Domino::getright() const{
        return right;
    }
    void Domino::reverse(){
        int temp;
        temp = left;
        left = right;
        right = temp;
    }
}//namespace domino closed
