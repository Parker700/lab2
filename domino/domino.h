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
        void print() const;// equal to ostream << object
        void printAscii() const;//printing in ASCII code
        int getLeft() const;
        int getRight() const;
        void random_change();
        void change(int Left, int Right);
        Domino& operator~ ();
        friend bool operator== (const Domino& first, const Domino& second);//прототип потом посмотреть, нужно чтобы возвращал булевое значение
        Domino& operator= (const Domino& domino);
        friend std::ostream& operator<< (std::ostream& out,const Domino& domino);
        friend std::istream& operator>> (std::istream& in,  Domino& domino);
    };

    int compare(const Domino& domino1, const Domino& domino2);

    class Dominoes {
    private:
        int size;
        Domino* arr;
    public:
        Dominoes(): size(0), arr(nullptr){}//default constructor
        Dominoes(Dominoes& Dominoes);//copy constr
        Dominoes(Dominoes&& domino);//move constr
        explicit Dominoes(int size){//constructor
            this->size = size;
            arr = new Domino[size];
            Domino domino;
            for(int i = 0; i < size; i++){
                arr[i] = domino;
                domino.random_change();
            }
        }
        Dominoes(int number, int mode);//constructor, еще копирующий и перемещающий конструктор
        Dominoes(const Domino& dom);
        ~Dominoes();//destructor
        int getsize() const;//return size of array
        void set(Domino* arg, int len);
        void addRandDomino();//add random one
        void addDomino(Domino& domino);//add custom one
        void delDomino(const int ind);// delete custom one
        void delRandom();//delete random one -> DelRandom %
        Dominoes& selection(const int num);//selecting and removing a group form dominoes
        void sort();//sort dominoes
        Domino& operator[] (const int ind) const;//return a domino by index Добавить конст перегрузку в добавок
        Dominoes& operator+= (const Dominoes& dominoes);//add one domino, в сохранении семантики изменить перегрузку для а += в += с
        Dominoes& operator= (const Dominoes& domino);//copy operator, еще move operator%
        Dominoes& operator= (Dominoes&& domino);//move operator
        friend std::ostream& operator<< (std::ostream& out, const Dominoes& Dominoes);//output to ostream
    };
    Dominoes mass(Domino& domino);
}
#endif //LAB2_DOMINO_H
