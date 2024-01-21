#ifndef LAB2_DOMINO_H
#define LAB2_DOMINO_H
#include <iostream>

namespace domino {
    int getvalue(const int a, const int b);
    int random(int a, int b);

    class Domino {
    private:
        int left;
        int right;
    public:
        Domino();
        Domino(int v1, int v2);
        void print();// equal to ostream << object
        void printAscii();//printing in ASCII code
        int getLeft() const;
        int getRight() const;
        void random_change();
        void change(int Left, int Right);
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
        Dominoes(): size(0), arr(nullptr){}//default constructor
        explicit Dominoes(int size){//constructor
            this->size = size;
            arr = new Domino[size];
            Domino domino;
            for(int i = 0; i < size; i++){
                arr[i] = domino;
                domino.random_change();
            }
        }
        Dominoes(int zero, int one, int two, int three, int four, int five, int six);//constructor
        ~Dominoes();//destructor
        int getsize();//return size of array
        void addRandDomino();//add random one
        void addDomino(Domino& domino);//add custom one
        void delDomino(const int ind);// delete custom one
        void deletion();//delete random one
        Dominoes selection(const int num);//selecting and removing a group form dominoes
        void sort();//sort dominoes
        Domino& operator[] (const int ind);//return a domino by index
        Dominoes& operator+= (const Domino& domino);//add one domino
        Dominoes& operator= (const Dominoes& domino);//copy operator
        friend std::ostream& operator<< (std::ostream& out, const Dominoes& Dominoes);//output to ostream
    };
}
#endif //LAB2_DOMINO_H
