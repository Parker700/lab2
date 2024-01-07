#ifndef LAB2_DOMINO_H
#define LAB2_DOMINO_H
#include <iostream>

namespace domino {
    int getvalue();

    int random();
    class Domino {
    private:
        int left;
        int right;
    public:
        Domino();
        Domino(int v1, int v2);
        void print();
        void printAscii();
        int gerLeft() const;
        int gerRight() const;
        void random_change();
        Domino& operator~ ();
        friend int operator== (const Domino& first, const Domino& second);
        Domino& operator= (const Domino& domino);
        friend std::ostream& operator<< (std::ostream& out,const Domino& domino);
        friend std::istream& operator>> (std::istream& in,  Domino& domino);
    };
    class Dominoes {
    private:
        int size;
        Domino* arr;
    public:
        Dominoes(): size(0), arr(nullptr){}
        explicit Dominoes(int size){
            this->size = size;
            arr = new Domino[size];
            Domino domino;
            for(int i = 0; i < size; i++){
                arr[i] = domino;
                domino.random_change();
            }
        }
        void addDomino(Domino& domino);
        void delDomino(int ind);
        void sort();
        Dominoes& operator+= (const Domino& domino);//add one domino
        friend std::ostream& operator<< (std::ostream& out, const Dominoes& Dominoes);//output to ostream
    };
}
#endif //LAB2_DOMINO_H
