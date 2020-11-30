#ifndef BUG_H
#define BUG_H

class Bug {
    public:
        Bug();
        Bug(int pPosition);
        void move();
        void turn();
        void display();

    private:
        int position;
        int dir;
};

#endif