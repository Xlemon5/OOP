#include "Square.h"
#include <iostream>
#include <cmath>
using namespace std;


Square::Square(int _size) : Root(_size) {}

Square::Square(double _a, double _b, double _c) : Root(_a, _b, _c) {}


Square::Square(const Square& other) : Root(other) {
    // Оператор копирования для Linear
}

Square& Square::operator=(const Square& other) {
    if (this == &other) {
        return *this;
    }

    // Оператор присваивания для Linear
    Root::operator=(other);

    return *this;
}


void Square::inputCoefficients()  {
    std::cout << "Введите коэффициенты квадратного уравнения (a, b и c): ";
    std::cin >> coefficients[0] >> coefficients[1] >> coefficients[2];
}

void Square::calculateRoots()  {

    double a = coefficients[0];
    double b = coefficients[1];
    double c = coefficients[2];


    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Корни: x1 = " << root1 << ", x2 = " << root2 << endl;
    }
    else if (discriminant == 0)
    {
        double root = -b / (2 * a);
        cout << "Корень: x = " << root << endl;
    }
    else
    {
        cout << "Действительных корней нет!" << endl;
    }
}

void Square::displayResult()  {
    std::cout << "Результат вычисления квадратного уравнения: ";
    calculateRoots();
}

std::ostream& operator << (ostream& out, Square& other)
{
    out << "y = " << "("<<other.coefficients[0] << ")" << "x^2" << " + " << "("<<other.coefficients[1] << ")"<< "x" << " + " << "("<<other.coefficients[2] <<")"<< endl;
    //other.calculateRoots();
    return out;
}

std::istream & operator >> (istream & in, Square & other)
{
    double temp_a, temp_b, temp_c;
    in >> temp_a >> temp_b >> temp_c;
    other.coefficients[0] = temp_a;
    other.coefficients[1] = temp_b;
    other.coefficients[2] = temp_c;


    return in;
}

void Square::setA(double A)
{
    coefficients[0] = A;
}

void Square::setB(double B)
{
    coefficients[1] = B;
}

void Square::setC(double C)
{
    coefficients[2] = C;
}

double Square::getA()
{
    return coefficients[0];
}

double Square::getB()
{
    return coefficients[1];
}

double Square::getC()
{
    return coefficients[2];
}
