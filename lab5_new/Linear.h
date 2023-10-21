#pragma once
#include "Root.h"
using namespace std;

class Linear : public Root {

	double k, b;

public:

	Linear();

	Linear(double _k, double _b);


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
