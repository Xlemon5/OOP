#ifndef LAB5_NEW_SQUARE_H
#define LAB5_NEW_SQUARE_H

#include "Root.h"
#include <iostream>
using namespace std;

class Square : public Root {

public:

    Square(int _size = 3);

    Square(double _a, double _b, double _c);

    Square(const Square& other);

    Square& operator=(const Square& other);

    void inputCoefficients() override;

    void calculateRoots() override;

    void displayResult() override;

    friend ostream& operator << (ostream& out, Square& other);

    friend istream& operator >> (istream& in, Square& other);

    void setA(double A);

    void setB(double B);

    void setC(double C);

    double getA();

    double getB();

    double getC();

};


#endif //LAB5_NEW_SQUARE_H
