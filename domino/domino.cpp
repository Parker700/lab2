#include <iostream>
#include "domino.h"
#include <limits>
#include <random>
//#include <ctime>
namespace domino {//namespace domino opened
    int getvalue(const int a, const int b) {
        int num;
        while (true) {
            std::cout << "Enter a number between " << a << " and " << b << ": ";
            std::cin >> num;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number.\n";
                continue;
            }
            if (num <= b && num >= a) {
                return num;
            } else {
                std::cout << "That is wrong, please, repeat.\n";
            }
        }
    }
    int random(int a, int b){
        std::random_device rd;   // non-deterministic generator
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(a,b);
        return dist(gen);
    }
    Domino::Domino() {
        left = random(0, 6);
        right = random(0, 6);
    }
    Domino::Domino(int v1, int v2) : left(v1), right(v2) {}
    void Domino::print() const{
        std::cout << "[" << left << " : " << right << "]\n";
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
    int compare(const Domino& domino1, const Domino& domino2){
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
    bool operator== (const Domino& domino1, const Domino& domino2){
        int first = domino1.getLeft() + domino1.getRight();
        int second = domino2.getLeft() + domino2.getRight();
        if(first == second){
            return 1;
        }else{
            return 0;
        }
    }
    std::ostream& operator<<(std::ostream &out,const Domino &domino){
        out << "[" << domino.left << " : " << domino.right << "]";
        return out;
    }
    std::istream& operator>> (std::istream &in, Domino &domino){ //добавить проверку на корректность
        int num1;
        int num2;
        in >> num1;
        in >> num2;
        if(in.fail()){
            return in;
        }else{
            if(num1 < 0 || num1 > 6 || num2 < 0 || num2 > 6){
                in.setstate(std::ios_base::failbit);
                return in;
            }
            domino.left = num1;
            domino.right = num2;
        }
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
    void Domino::printAscii() const{
        std::cout << "Domino in ASCII-Art:\n _ _ _ _ _ _ _ _ _\n";
        std::cout << " | ";//top level starts
        if(left == 0 || left == 1){
            std::cout << " ";
        }else{
            std::cout << "0";
        }
        std::cout << " ";
        if(left == 6){
            std::cout << "0";
        }else{
            std::cout << " ";
        }
        std::cout << " ";
        if (left == 4 || left == 5 || left == 6){
            std::cout << "0";
        }else{
            std::cout << " ";
        }
        std::cout << " | ";//center
        if(right == 0 || right == 1){
            std::cout << " ";
        }else{
            std::cout << "0";
        }
        std::cout << " ";
        if(right == 6){
            std::cout << "0";
        }else{
            std::cout << " ";
        }
        std::cout << " ";
        if (right == 4 || right == 5 || right == 6){
            std::cout << "0";
        }else{
            std::cout << " ";
        }
        std::cout << " |\n";// top level ends
        std::cout << " |   ";//middle level starts
        if(left == 1 || left == 3 || left == 5){
            std::cout << "0";
        }else{
            std::cout << " ";
        }
        std::cout << "   |   ";
        if(right == 1 || right == 3 || right == 5){
            std::cout << "0";
        }else{
            std::cout << " ";
        }
        std::cout << "   |\n";//middle level ends
        std::cout << " | ";//bottom level starts
        if(left == 4 || left == 5 || left == 6){
            std::cout << "0";
        }else{
            std::cout << " ";
        }
        std::cout << " ";
        if(left == 6){
            std::cout << "0";
        }else{
            std::cout << " ";
        }
        std::cout << " ";
        if(left == 0 || left == 1){
            std::cout << " ";
        }else{
            std::cout << "0";
        }
        std::cout << " | ";//center
        if (right == 4 || right == 5 || right == 6){
            std::cout << "0";
        }else{
            std::cout << " ";
        }
        std::cout << " ";
        if(right == 6){
            std::cout << "0";
        }else{
            std::cout << " ";
        }
        std::cout << " ";
        if(right == 0 || right == 1){
            std::cout << " ";
        }else{
            std::cout << "0";
        }
        std::cout << " |\n";//bottom level ends
        std::cout << " - - - - - - - - -\n";
    }//method that prints in ascii art











    //class Dominoes
    Dominoes::~Dominoes(){
        delete [] this->arr;
    }
    Dominoes::Dominoes(Dominoes& Dominoes){//constructor copy
        arr = new Domino[Dominoes.size];
        std::copy(Dominoes.arr, Dominoes.arr + Dominoes.size, arr);
        size = Dominoes.size;
    }
    Dominoes::Dominoes(Dominoes&& domino){//constructor copy
        arr = domino.arr;
        size = domino.size;
        domino.arr = nullptr;
        domino.size = 0;
    }
    Dominoes::Dominoes(int number, int mode){
        int ind = 0;
        size = number * 7;
        arr = new Domino[size];
        Domino domino(0, 0);
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < number; j++){
                arr[ind] = domino;
                ind++;
            }
            domino.change(i + 1, i + 1);
        }
    }
    Dominoes::Dominoes(const Domino& dom){
        arr = new Domino[1];
        arr[0] = dom;
        size = 1;
    }
    int Dominoes::getsize() const{
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
        if(ind > this->size - 1 || ind < 0){
            throw std::invalid_argument("invalid value");
        }
        if(size != 0) {
            this->size--;
            Domino *temp = new Domino[this->size];
            if (ind != 0) {
                std::copy(this->arr, this->arr + ind, temp);
            }
            std::copy(this->arr + ind + 1, this->arr + this->size + 1, temp + ind);
            delete[] this->arr;
            this->arr = temp;// отдельно обработать случай когда удалено все
        }else{
            std::cout << "An array in empty, we couldn't delete!" << std::endl;
        }
    }
    void Dominoes::delRandom(){
        if(size > 0) {
            int r = random(0, this->size - 1);
            std::cout << "Deleting " << r << " index of dominoes;\n";
            Dominoes::delDomino(r);
        }else{
            std::cout << "An array in empty, we couldn't delete!" << std::endl;
        }
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
//                    comp = temp == this->arr[i];
                    comp = compare(temp, this->arr[i]);
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

    Dominoes& Dominoes::selection(const int num){
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

    Domino& Dominoes::operator[] (const int ind) const{
        if(ind < 0, ind > this->getsize()){
            throw std::invalid_argument("Incorrect index");
        }
        return this->arr[ind];
    }

    Dominoes& Dominoes::operator= (const Dominoes& domino) {//проверить что не самоприсванивание и нужно очистить память
        if(this == &domino){
            return *this;
        }
        delete[] arr;
        if(domino.arr == nullptr){
            arr = nullptr;
            size = 0;
            return *this;
        }
        arr = new Domino[domino.size];
        std::copy(domino.arr, domino.arr + domino.size, arr);
        size = domino.size;
        return *this;
    }

    Dominoes& Dominoes::operator= (Dominoes&& domino){
        if(&domino != this){
            delete[] arr;
            arr = domino.arr;
            size = domino.size;
            domino.arr = nullptr;
            domino.size = 0;
        }
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
    Dominoes& Dominoes::operator+= (const Dominoes& dominoes){
        int len = size + dominoes.size;
        Domino* temp = new Domino[len];
        std::copy(arr, arr + size, temp);
        std::copy(dominoes.arr, dominoes.arr + dominoes.size, temp + size);
        delete[] arr;
        arr = temp;
        size = len;
        return *this;
    }
    void Dominoes::set(Domino* arg, int len){
        delete[] arr;
        arr = arg;
        size = len;
    }
    Dominoes mass(Domino& domino){
        Dominoes dom(0);
        Domino* temp = new Domino[1];
        temp[0] = domino;
        dom.set(temp, 1);
        return dom;
    }
/*    Dominoes& Dominoes::operator+= (const Domino& domino){
        Domino *temp = new Domino[this->size];
        std::copy(this->arr, this->arr + 1, temp);
        this->size++;
        temp[this->size - 1] = domino;
        delete[] arr;
        arr = temp;
        return *this;
    }*/
}//namespace domino closed

