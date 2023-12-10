#ifndef LAB2_DOMINO_H
#define LAB2_DOMINO_H

namespace domino {
    int getvalue();
    class Domino {
    private:
        int left;
        int right;
    public:
        Domino();
        int getleft() const;
        int getright() const;
        void reverse();
    };
}
#endif //LAB2_DOMINO_H
