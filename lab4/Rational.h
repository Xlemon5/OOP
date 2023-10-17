#ifndef LAB4_RATIONAL_H
#define LAB4_RATIONAL_H

//#include <iostream>
#include "Pair.h"
using namespace std;




class Rational:public Pair{
public:

    //КОНСТРУКТОРЫ

    Rational(int x = 0, int y = 1);


    //ОПЕРАЦИЯ СЛОЖЕНИЯ
    Rational operator +(const Rational &other) const;

    Rational operator -(const Rational &other) const;

    //ОПЕРАЦИЯ ДЕЛЕНИЯ
    Rational operator /(const Rational &other) const;


    bool operator > (const Pair &other) const;

    bool operator < (const Pair &other) const;


    //перегрузка вывода



};



#endif //LAB4_RATIONAL_H
