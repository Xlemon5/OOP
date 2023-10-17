#pragma once
#include <iostream>
#include "Pair.h"
using namespace std;


class Rational : public Pair {

public:
	Rational();

	Rational(int x, int y = 1);

	int findNOD(int a, int b);

	void normalize();

	Rational operator +(const Rational& other) const;

	Rational operator -(const Rational& other) const;

	Rational operator /(const Rational& other) const;

	bool operator > (const Rational& other) const;

	bool operator < (const Rational& other) const;



	// не убирать const из const Rational& other!!!
	friend ostream& operator << (ostream& out, const Rational& other);

	friend istream& operator >> (istream& in, Rational& other);

};
