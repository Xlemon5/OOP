#include "Square.h"
#include <iostream>
#include <cmath>
using namespace std;


	Square::Square() : a(0), b(0), c(0) {}

	Square::Square(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

	void Square::inputCoefficients()  {
		std::cout << "Введите коэффициенты квадратного уравнения (a, b и c): ";
		std::cin >> a >> b >> c;
	}

	void Square::calculateRoots()  {
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
		out << "y = " << other.a << "x^2" << " + " << other.b << "x" << " + " << other.c << endl;
		other.calculateRoots();
		return out;
	}

	std::istream & operator >> (istream & in, Square & other)
	{
		double temp_a, temp_b, temp_c;
		in >> temp_a >> temp_b >> temp_c;
		other.a = temp_a;
		other.b = temp_b;
		other.b = temp_c;


		return in;
	}

	void Square::setA(double A)
	{
		a = A;
	}

	void Square::setB(double B)
	{
		b = B;
	}

	void Square::setC(double C)
	{
		c = C;
	}

	double Square::getA()
	{
		return a;
	}

	double Square::getB()
	{
		return b;
	}

	double Square::getC()
	{
		return c;
	}
