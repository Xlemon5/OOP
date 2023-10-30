#include <iostream>
#include "Linear.h"
using namespace std;



Linear::Linear(int _size) : Root(_size) {}

Linear::Linear(double _k, double _b) : Root(_k, _b) {}


void Linear::inputCoefficients() {
    cout << "Введите коэффициенты линейного уравнения (k и b): ";
    cin >> coefficients[0] >> coefficients[1];
}

void Linear::calculateRoots() {

    if ( coefficients [0] == 0)
    {
        cout << "Уравнение не линейное!" << endl;
    }
    else
    {
        double root = -coefficients[1] / coefficients[0];
        cout << "x = " << root << endl;
    }
}

void Linear::displayResult() {
    std::cout << "Результат вычисления линейного уравнения: ";
    calculateRoots();
}

Linear::Linear(const Linear& other) : Root(other) {
    // Оператор копирования для Linear
}

Linear& Linear::operator=(const Linear& other) {
    if (this == &other) {
        return *this;
    }

    // Оператор присваивания для Linear
    Root::operator=(other);

    return *this;
}

void Linear::setK(double K)
{
    coefficients[0] = K;
}

void Linear::setB(double B)
{
    coefficients[1] = B;
}

double Linear::getK()
{
    return coefficients[0];
}

double Linear::getB()
{
    return coefficients[1];
}


ostream& operator << (ostream& out, Linear& other)
{
    out << "y = " << "(" <<other.coefficients[0] << ")" << "x" << " + " <<  "("<< other.coefficients[1] << ")"<< endl;
    //other.calculateRoots();
    return out;
}

istream& operator >> (istream& in, Linear& other)
{
    double temp_k, temp_b;
    in >> temp_k >> temp_b;
    other.coefficients[0] = temp_k;
    other.coefficients[1] = temp_b;

    //other.inputCoefficients();
    //убрать temp_k, temp_b и оставшийся код
    return in;
}
