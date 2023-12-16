#include <iostream>
#include "domino.h"
#include <limits>
#include <random>

//#include <ctime>
using namespace std;
namespace domino {//namespace domino opened
    int getvalue() {
        int num;
        while (true) {
            cout << "Enter a number between 0 and 6: ";
            cin >> num;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }
            if (num > -1 && num < 7) {
                return num;
            } else {
                cout << "That is wrong, please, repeat.\n";
            }
        }
    }
    int random(){
        random_device rd;   // non-deterministic generator
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0,7);
        return dist(gen);
    }
    Domino::Domino() {
        left = random();
        right = random();
    }
    Domino::Domino(int v1, int v2) : left(v1), right(v2) {}
    void Domino::print(){
        cout << "[" << left << " : " << right << "]\n";
    }

    int Domino::getleft() const{
        return left;
    }
    int Domino::getright() const{
        return right;
    }
    int operator== (const Domino& domino1, const Domino& domino2){
        int first = domino1.getleft() + domino1.getright();
        int second = domino2.getleft() + domino2.getright();
        if(first > second){
            return 1;
        }else if(first < second){
            return -1;
        }else{
            return 0;
        }
    }
    std::ostream& operator<<(std::ostream &out,const Domino &domino){
        out << "[" << domino.left << " : " << domino.right << "]";
        return out;
    }
    std::istream& operator>> (std::istream &in, Domino &domino){
        in>>domino.left;
        in>>domino.right;
        return in;
    }
    Domino& Domino::operator~ (){
        int temp;
        temp = left;
        left = right;
        right = temp;
        return *this;
    }
    Domino& Domino::operator= (const Domino& domino){
        left = domino.left;
        right = domino.right;
        return *this;
    }
    void Domino::printAscii(){
        cout << "Domino in ASCII-Art:\n _ _ _ _ _ _ _ _ _\n";
        cout << " | ";//top level starts
        if(left == 0 || left == 1){
            cout << " ";
        }else{
            cout << "0";
        }
        cout << " ";
        if(left == 6){
            cout << "0";
        }else{
            cout << " ";
        }
        cout << " ";
        if (left == 4 || left == 5 || left == 6){
            cout << "0";
        }else{
            cout << " ";
        }
        cout << " | ";//center
        if(right == 0 || right == 1){
            cout << " ";
        }else{
            cout << "0";
        }
        cout << " ";
        if(right == 6){
            cout << "0";
        }else{
            cout << " ";
        }
        cout << " ";
        if (right == 4 || right == 5 || right == 6){
            cout << "0";
        }else{
            cout << " ";
        }
        cout << " |\n";// top level ends
        cout << " |   ";//middle level starts
        if(left == 1 || left == 3 || left == 5){
            cout << "0";
        }else{
            cout << " ";
        }
        cout << "   |   ";
        if(right == 1 || right == 3 || right == 5){
            cout << "0";
        }else{
            cout << " ";
        }
        cout << "   |\n";//middle level ends
        cout << " | ";//bottom level starts
        if(left == 4 || left == 5 || left == 6){
            cout << "0";
        }else{
            cout << " ";
        }
        cout << " ";
        if(left == 6){
            cout << "0";
        }else{
            cout << " ";
        }
        cout << " ";
        if(left == 0 || left == 1){
            cout << " ";
        }else{
            cout << "0";
        }
        cout << " | ";//center
        if (right == 4 || right == 5 || right == 6){
            cout << "0";
        }else{
            cout << " ";
        }
        cout << " ";
        if(right == 6){
            cout << "0";
        }else{
            cout << " ";
        }
        cout << " ";
        if(right == 0 || right == 1){
            cout << " ";
        }else{
            cout << "0";
        }
        cout << " |\n";//bottom level ends
        cout << " - - - - - - - - -\n";
    }//method that prints in ascii art
    //class Dominos

}//namespace domino closed

