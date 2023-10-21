#include <iostream>
#include "Linear.h"
using namespace std;



	Linear::Linear() : k(0), b(0) {}

	Linear::Linear(double _k, double _b) : k(_k), b(_b) {}


	void Linear::inputCoefficients() {
		std::cout << "Введите коэффициенты линейного уравнения (k и b): ";
		std::cin >> k >> b;
	}

	void Linear::calculateRoots() {

		if (k == 0)
		{
			cout << "Уравнение не линейное!" << endl;
		}
		else
		{
			double root = -b / k;
			cout << "x = " << root << endl;
		}
	}

	void Linear::displayResult() {
		std::cout << "Результат вычисления линейного уравнения: ";
		calculateRoots();
	}


	void Linear::setK(double K)
	{
		k = K;
	}

	void Linear::setB(double B)
	{
		Linear::b = B;
	}

	double Linear::getK()
	{
		return k;
	}

	double Linear::getB()
	{
		return b;
	}


	ostream& operator << (ostream& out, Linear& other)
	{
		out << "y = " << other.k << "x" << " + " << other.b << endl;
		other.calculateRoots();
		return out;
	}

	istream& operator >> (istream& in, Linear& other)
	{
		double temp_k, temp_b;
		in >> temp_k >> temp_b;
		other.k = temp_k;
		other.b = temp_b;
		return in;
	}
