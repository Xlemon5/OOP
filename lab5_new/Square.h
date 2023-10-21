#pragma once
#include "Root.h"
#include <iostream>
using namespace std;

class Square : public Root {

	double a, b, c;

public:

	Square();

	Square(double _a, double _b, double _c);

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
