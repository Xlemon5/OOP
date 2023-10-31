#include "Root.h"
#include <iostream>

using namespace std;


/*void Root::enterCoef()
{
    cout << "Введите значения: " << endl;
    for(int i = 0; i < size; i++)
    {
        cin >> coefficients[i];
    }
}*/



Root::Root(int _size)
{
    size = _size;
    coefficients = new double [size];

    for(int i = 0; i < size; i++)
    {
        coefficients[i] = 0;
    }
}

Root::Root(double a, double b)
{
    size = 2;
    coefficients = new double [size];

    coefficients[0] = a;
    coefficients[1] = b;
}

Root::Root(double a, double b, double c)
{
    size = 3;
    coefficients = new double [size];

    coefficients[0] = a;
    coefficients[1] = b;
    coefficients[2] = c;

}

Root::Root(const Root& other) {
    size = other.size;
    coefficients = new double[size];
    for (int i = 0; i < size; i++) {
        coefficients[i] = other.coefficients[i];
    }
}

Root& Root::operator=(const Root& other) {
    if (this == &other) {
        return *this;
    }

    // Удаляем текущий массив
    delete[] coefficients;
    coefficients = nullptr;

    size = other.size;
    coefficients = new double[size];
    for (int i = 0; i < size; i++) {
        coefficients[i] = other.coefficients[i];
    }

    return *this;
}

Root::~Root()
{
    delete[] coefficients;
    coefficients = nullptr;
}


ostream& operator << (ostream& out, Root& other)
{

    if (other.size == 2)
    {
        out << "y = " << "(" <<other.coefficients[0] << ")" << "x" << " + " <<  "("<< other.coefficients[1] << ")"<< endl;
        //other.calculateRoots();
        return out;
    }
    else if (other.size == 3)
    {
        out << "y = " << "("<<other.coefficients[0] << ")" << "x^2" << " + " << "("<<other.coefficients[1] << ")"<< "x" << " + " << "("<<other.coefficients[2] <<")"<< endl;
        //other.calculateRoots();
        return out;
    }

}

