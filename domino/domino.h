#ifndef LAB2_DOMINO_H
#define LAB2_DOMINO_H
#include <iostream>
namespace domino {
    int getvalue();
    class Domino {
    private:
        int left;
        int right;
    public:
        Domino();
        Domino(int v1, int v2);
        void print();
        int getleft() const;
        int getright() const;
        friend int operator== (const Domino& first, const Domino& second);
        Domino& operator~ ();
        void printAscii();
        friend std::ostream& operator<< (std::ostream &out,const Domino &domino);
        friend std::istream& operator>> (std::istream &in,  Domino &domino);
        Domino & operator =(const Domino& domino);
    };
    class Dominos {
    private:
        int size;
        Domino* arr;
    public:
        Dominos(int size);
    };
}
#endif //LAB2_DOMINO_H
