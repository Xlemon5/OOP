#ifndef LAB5_NEW_LINEAR_H
#define LAB5_NEW_LINEAR_H


#include "Root.h"
#include <iostream>
using namespace std;

class Linear : public Root {
public:

    Linear(int _size = 2);

    Linear(double _k, double _b);

    Linear(const Linear& other);

    Linear& operator=(const Linear& other);

    void inputCoefficients() override;

    void calculateRoots() override;

    void displayResult() override;


    friend ostream& operator << (ostream& out, Linear& other);

    friend istream& operator >> (istream& in, Linear& other);

    void setK(double K);

    void setB(double B);

    double getK();

    double getB();

};


#endif //LAB5_NEW_LINEAR_H
