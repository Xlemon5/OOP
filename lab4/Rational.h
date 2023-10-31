#ifndef LAB4_NEW_RATIONAL_H
#define LAB4_NEW_RATIONAL_H


#include <iostream>
#include "Pair.h"
using namespace std;


class Rational : public Pair {

public:
	Rational();

	Rational(int x, int y = 1);

	int findNOD(int a, int b);

	void normalize();

	Rational* operator +( Rational& other);

	Rational* operator -( Rational& other);

	Rational* operator /( Rational& other);

    Rational* operator *( Rational& other);

	bool operator > (const Rational& other) const;

	bool operator < (const Rational& other) const;


	friend ostream& operator << (ostream& out, const Rational& other);

	friend istream& operator >> (istream& in, Rational& other);

};

#endif //LAB4_NEW_RATIONAL_H
