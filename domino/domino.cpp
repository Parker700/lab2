#include <iostream>
#include "domino.h"
#include <limits>
#include <random>
//#include <ctime>
using namespace std;
namespace domino {//namespace domino opened
    int getvalue(const int a, const int b) {
        int num;
        while (true) {
            cout << "Enter a number between " << a << " and " << b << ": ";
            cin >> num;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }
            if (num <= b && num >= a) {
                return num;
            } else {
                cout << "That is wrong, please, repeat.\n";
            }
        }
    }
    int random(int a, int b){
        random_device rd;   // non-deterministic generator
        mt19937 gen(rd());
        uniform_int_distribution<> dist(a,b);
        return dist(gen);
    }
    Domino::Domino() {
        left = random(0, 6);
        right = random(0, 6);
    }
    Domino::Domino(int v1, int v2) : left(v1), right(v2) {}
    void Domino::print(){
        cout << "[" << left << " : " << right << "]\n";
    }//replaced by out << domino;
    int Domino::getLeft() const{
        return left;
    }
    int Domino::getRight() const{
        return right;
    }
    void Domino::random_change(){
        left = random(0, 6);
        right = random(0, 6);
    }
    void Domino::change(int Left, int Right){
        left = Left;
        right = Right;
    }
    int operator== (const Domino& domino1, const Domino& domino2){
        int first = domino1.getLeft() + domino1.getRight();
        int second = domino2.getLeft() + domino2.getRight();
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











    //class Dominoes
    Dominoes::~Dominoes(){
        delete [] this->arr;
    }
    Dominoes::Dominoes(int zero, int one, int two, int three, int four, int five, int six){
        int len;
        size = zero + one + two + three + four + five + six;
        arr = new Domino[size];
        Domino domino(6, 6);

        for (int i = 0; i < zero; i++) {
            arr[i] = domino;
        }
        len = zero;
        domino.change(5, 5);
        for (int i = len; i < len + one; i++) {
            arr[i] = domino;
        }
        len += one;
        domino.change(4, 4);
        for (int i = len; i < len + two; i++) {
            arr[i] = domino;
        }
        len += two;
        domino.change(3, 3);
        for (int i = len; i < len + three; i++) {
            arr[i] = domino;
        }
        len += three;
        domino.change(2, 2);
        for (int i = len; i < len + four; i++) {
            arr[i] = domino;
        }
        len += four;
        domino.change(1, 1);
        for (int i = len; i < len + five; i++) {
            arr[i] = domino;
        }
        len += five;
        domino.change(0, 0);
        for (int i = len; i < len + six; i++) {
            arr[i] = domino;
        }
    }
    int Dominoes::getsize(){
        return this->size;
    }
    void Dominoes::addDomino(Domino& domino){
        size++;
        Domino *temp = new Domino[size];
        if(size > 1) {
            std::copy(arr, arr + size, temp);
        }
        temp[size - 1] = domino;
        delete [] arr;
        arr = temp;
//        delete [] temp;
    }
    void Dominoes::addRandDomino(){
        Domino domino;
        this->addDomino(domino);
    }
    void Dominoes::delDomino(const int ind){
        this->size--;
        Domino *temp = new Domino[this->size];
        if(ind > this->size || ind < 0){
            throw std::invalid_argument("invalid value");
        }
        if(ind != 0) {
            std::copy(this->arr, this->arr + ind, temp);
        }
        std::copy(this->arr + ind + 1, this->arr + this->size + 1, temp + ind);
        this->arr = temp;
    }
    void Dominoes::deletion(){
        int r = random(0, this->size - 1);
        std::cout << "Deleting " << r << " index of dominoes;\n";
        Dominoes::delDomino(r);
    }
    void Dominoes::sort(){
        if(this->size != 0) {
            Domino temp;
            int comp;
            int ind;
            for(int j = 0; j < this->size; j++) {
                temp = this->arr[j];
                ind = j;
                for (int i = j; i < this->size; i++) {
                    comp = temp == this->arr[i];
                    if (comp == 1) {
                        temp = this->arr[i];
                        ind = i;
                    }
                }
                this->arr[ind] = this->arr[j];
                this->arr[j] = temp;
            }
        }
    }//sort domino

    Dominoes Dominoes::selection(const int num){
        if(num > 6 || num < 0){
            throw std::invalid_argument("invalid value");
        }
        Dominoes Temp;
        int i = 0;
        while(i < this->size){
            if(this->arr[i].getLeft() == num || this->arr[i].getRight() == num){
                Temp.addDomino(this->arr[i]);
                this->delDomino(i);
            }else{
                i++;
            }
        }
        std::cout << "Deleted dominoes:\n";
        std::cout << Temp;
        return Temp;
    }

    Domino& Dominoes::operator[] (const int ind){
        if(ind < 0, ind > this->getsize()){
            throw std::invalid_argument("Incorrect index");
        }
        return this->arr[ind];
    }

    Dominoes& Dominoes::operator= (const Dominoes& domino){
        arr = new Domino[domino.size];
        std::copy(domino.arr, domino.arr + domino.size, arr);
        size = domino.size;
        return *this;
    }

    std::ostream& operator<< (std::ostream& out, const Dominoes& Dominoes){
        out << "Your\n" << Dominoes.size << " dominoes: ";
        for(int i = 0; i < Dominoes.size; i++){
            out << "\n" << Dominoes.arr[i];
        }
        out << "\n";
        return out;
    }
    Dominoes& Dominoes::operator+= (const Domino& domino){
        Domino *temp = new Domino[this->size];
        std::copy(this->arr, this->arr + 1, temp);
        this->size++;
        this->arr[this->size - 1] = domino;
        return *this;
    }
}//namespace domino closed

