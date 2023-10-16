#include "Rational.h"
#include <iostream>
using namespace std;


    Rational::Rational():Pair(){}

    Rational::Rational(int x, int y): Pair(x, y){}


    //ОПЕРАЦИЯ СЛОЖЕНИЯ
    Rational Rational::operator +(const Rational &other) const {

        int newA = a * other.b + b * other.a;
        int newB = b * other.b;

        return Rational(newA, newB);
    }

    //ОПЕРАЦИЯ ДЕЛЕНИЯ
    Rational Rational::operator /(const Rational &other) const {
        int newA = a * other.b;
        int newB = b * other.a;

        return Rational(newA, newB);
    }

    Rational Rational::operator -(const Rational &other) const{
        int newA = (a * other.b) - (b * other.a);
        int newB = b * other.b;


        return Rational(newA, newB);
    }

