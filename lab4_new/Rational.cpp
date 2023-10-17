#include <iostream>
#include "Rational.h"
using namespace std;


	Rational::Rational() : Pair(0, 1) {}

	Rational::Rational(int x, int y) : Pair(x, y) {}

	int Rational::findNOD(int a, int b)
	{
		int nod = 1;
		int d = 2;

		while (d * d <= a * b)
		{
			if (a % d == 0 && b % d == 0)
			{
				nod = d;
			}
			d += 1;
		}
		return nod;
	}

	void Rational::normalize()
	{
		if (a > 0)
		{
			int NOD = findNOD(a, b);
			a = a / NOD;
			b = b / NOD;
		}
		else
		{
			int NOD = findNOD(abs(a), b);

			a = a / NOD;
			b = b / NOD;
		}
	}

	Rational Rational::operator +(const Rational& other) const
	{
		int newA = a * other.b + b * other.a;
		int newB = b * other.b;

		Rational result(newA, newB);
		result.normalize();

		return result;
	}

	Rational Rational::operator -(const Rational& other) const
	{
		int newA = (a * other.b) - (b * other.a);
		int newB = b * other.b;


		Rational result(newA, newB);
		result.normalize();

		return result;
	}

	Rational Rational::operator /(const Rational& other) const
	{
		int newA = a * other.b;
		int newB = b * other.a;


		Rational result(newA, newB);
		result.normalize();


		return result;
	}

	bool Rational::operator > (const Rational& other) const
	{
		double n1 = 0, n2 = 0;
		n1 = static_cast<double>(a) / static_cast<double>(b);
		n2 = static_cast<double>(other.a) / static_cast<double>(other.b);

		return n1 > n2;
	}

	bool Rational::operator < (const Rational& other) const
	{
		double n1 = 0, n2 = 0;
		n1 = static_cast<double>(a) / static_cast<double>(b);
		n2 = static_cast<double>(other.a) / static_cast<double>(other.b);

		return n1 < n2;
	}



	// не убирать const из const Rational& other!!!
	ostream& operator << (ostream& out, const Rational& other)
	{
		out << "(" << other.a << " / " << other.b << ")" << endl;
		return out;
	}

	istream& operator >> (istream& in, Rational& other)
	{
		in >> other.a >> other.b;
		return in;
	}
