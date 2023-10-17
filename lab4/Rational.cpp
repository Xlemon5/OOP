#include "Rational.h"
#include <iostream>
using namespace std;



    Rational::Rational(int x, int y): Pair(x, y){}


    //ОПЕРАЦИЯ СЛОЖЕНИЯ
    Rational Rational::operator +(const Rational &other) const {

        int newA = a * other.b + b * other.a;
        int newB = b * other.b;

        return Rational(newA, newB);
    }

    Rational Rational::operator -(const Rational &other) const{
        int newA = (a * other.b) - (b * other.a);
        int newB = b * other.b;

        return Rational(newA, newB);
    }

    //ОПЕРАЦИЯ ДЕЛЕНИЯ
    Rational Rational::operator /(const Rational &other) const {
        int newA = a * other.b;
        int newB = b * other.a;

        return Rational(newA, newB);
    }


    bool Rational::operator > (const Pair &other) const
    {
        double n1 = 0, n2 = 0;

        n1 = a / b;
        n2 = other.a / other.b;

        return n1 > n2;
    }

    bool Rational::operator < (const Pair &other) const
    {
        double n1 = 0, n2 = 0;

        n1 = a / b;
        n2 = other.a / other.b;

        return n1 < n2;
    }



