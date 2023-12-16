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
        int getleft() const;
        int getright() const;
        Domino& operator~ ();
        friend int operator== (const Domino& first, const Domino& second);
        Domino& operator= (const Domino& domino);
        friend std::ostream& operator<< (std::ostream &out,const Domino &domino);
        friend std::istream& operator>> (std::istream &in,  Domino &domino);
    };
    class Dominos {
    private:
        int size;
        Domino* arr;
    public:
        Dominos(int size){
            this->size = size;
            arr = new Domino[size];
            Domino domino;
            for(int i = 0; i < size; i++){
                arr[i] = domino;
            }
        }
    };
}
#endif //LAB2_DOMINO_H
