#include "Pair.h"
using namespace std;

Pair::Pair() : a(0), b(0) {}
Pair::Pair(int x, int y) : a(x), b(y) {}

int Pair::getA()
{
    return a;
}

int Pair::getB()
{
    return b;
}

void Pair::setA(int A)
{
    a = A;
}

void Pair::setB(int B)
{
    b = B;
}

Pair& Pair::operator =(const Pair& other)
{
    a = other.a;
    b = other.b;

    return *this;
}

Pair::Pair(const Pair& other)
{
    a = other.a;
    b = other.b;
}

bool Pair::operator ==(const Pair& other)
{
    return a == other.a && b == other.b;
}

bool Pair::operator !=(const Pair& other)
{
    return (a != other.a) || (b != other.b);
}

Pair* Pair::operator +(Pair& other)
{
    Pair* newPair = new Pair(a + other.a, b + other.b);

    return newPair;
}

Pair* Pair::operator -(Pair& other)
{
    Pair* newPair = new Pair(a - other.a, b - other.b);

    return newPair;
}

Pair* Pair::operator /(Pair& other)
{
    Pair* newPair = new Pair(a / other.a, b / other.b);

    return newPair;
}

Pair* Pair::operator *(Pair& other)
{
    Pair* newPair = new Pair(a * other.a, b * other.b);

    return newPair;
}

ostream& operator << (ostream& out, const Pair& other)
{
    out << "(" << other.a << ", " << other.b << ")" << endl;
    return out;
}

istream& operator >> (istream& in, Pair& other)
{
    in >> other.a >> other.b;
    return in;
}
