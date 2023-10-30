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

Rational* Rational::operator +(Rational& other)
{
    Rational* newRat = (Rational*)Pair::operator+(other);

    int newA = a * other.b + b * other.a;
    int newB = b * other.b;
    newRat->a = newA;
    newRat->b = newB;

    newRat->normalize();

    return newRat;
}

Rational* Rational::operator -(Rational& other)
{
    int newA = (a * other.b) - (b * other.a);
    int newB = b * other.b;


    Rational* newRat = (Rational*)Pair::operator-(other);
    newRat->a = newA;
    newRat->b = newB;

    newRat->normalize();

    return newRat;
}

Rational* Rational::operator /( Rational& other)
{

    Rational* newRat = (Rational*)Pair::operator /(other);

    int newA = a * other.b;
    int newB = b * other.a;

    newRat->a = newA;
    newRat->b = newB;

    //Rational* newRat = new Rational(newA, newB);


    newRat->normalize();
    return newRat;
}

Rational* Rational::operator *( Rational& other)
{

    Rational* newRat = (Rational*)Pair::operator *(other);
    int newA = a * other.a;
    int newB = b * other.b;

    newRat->a = newA;
    newRat->b = newB;

    //Rational* newRat = new Rational(newA, newB);

    newRat->normalize();
    return newRat;
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
