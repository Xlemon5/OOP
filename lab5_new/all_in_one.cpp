#include <iostream>
#include <cmath>
using namespace std;

class Root {
public:
	virtual void inputCoefficients() = 0;
	virtual void displayResult() = 0;
	virtual void calculateRoots() = 0;
};


class Linear : public Root {

double k, b;
	
public:

	Linear() : k(0), b(0) {}

	Linear(double _k, double _b) : k(_k), b(_b) {}


	void inputCoefficients() override {
		std::cout << "Введите коэффициенты линейного уравнения (k и b): ";
		std::cin >> k >> b;
	}

	void calculateRoots() override {
		
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

	void displayResult() override {
		std::cout << "Результат вычисления линейного уравнения: ";
		calculateRoots();
	}


	friend ostream& operator << (ostream& out, Linear& other)
	{
		out << "y = " << other.k << "x" << " + " << other.b << endl;
		other.calculateRoots();
		return out;
	}

	friend istream& operator >> (istream& in, Linear& other)
	{
		double temp_k, temp_b;
		in >> temp_k >> temp_b;
		other.k = temp_k;
		other.b = temp_b;
		return in;
	}

	void setK(double K) 
	{
		k = K;
	}

	void setB(double B)
	{
		b = B;
	}

	double getK() 
	{
		return k;
	}

	double getB()
	{
		return b;
	}

};


class Square : public Root {

double a, b, c;

public:

	Square() : a(0), b(0), c(0) {}

	Square(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

	void inputCoefficients() override {
		std::cout << "Введите коэффициенты квадратного уравнения (a, b и c): ";
		std::cin >> a >> b >> c;
	}

	void calculateRoots() override{
		double discriminant = b * b - 4 * a * c;

		if (discriminant > 0) {
			double root1 = (-b + sqrt(discriminant)) / (2 * a);
			double root2 = (-b - sqrt(discriminant)) / (2 * a);
			cout << "Корни: x1 = " << root1 << ", x2 = " << root2 << endl;
		}
		else if(discriminant == 0) 
		{
			double root = -b / (2 * a);
			cout << "Корень: x = " << root << endl;
		}
		else 
		{
			cout << "Действительных корней нет!" << endl;
		}
	}

	void displayResult() override {
		std::cout << "Результат вычисления квадратного уравнения: ";
		calculateRoots();
	}

	friend ostream& operator << (ostream& out, Square& other)
	{
		out << "y = " << other.a << "x^2" << " + " << other.b << "x" << " + " << other.c << endl;
		other.calculateRoots();
		return out;
	}

	friend istream& operator >> (istream& in, Square& other)
	{
		double temp_a, temp_b, temp_c;
		in >> temp_a >> temp_b >> temp_c;
		other.a = temp_a;
		other.b = temp_b;
		other.b = temp_c;
		return in;
	}

	void setA(double A) 
	{
		a = A;
	}

	void setB(double B)
	{
		b = B;
	}

	void setC(double C)
	{
		c = C;
	}

	double getA() 
	{
		return a;
	}

	double getB()
	{
		return b;
	}

	double getC()
	{
		return c;
	}

};


void printRoots(Root& equation){
	equation.displayResult();
}

int main() 
{
	setlocale(LC_ALL, "ru");

	Linear linearEquation;
	Square squareEquation;

	linearEquation.inputCoefficients();
	squareEquation.inputCoefficients();

	Root* ptrLinear = &linearEquation;
	Root* ptrSquare = &squareEquation;

	cout << endl;

	ptrLinear->displayResult();
	ptrSquare->displayResult();

	//printRoots(*ptrLinear);
	//printRoots(*ptrSquare);

	//cout << linearEquation << endl;
	//cout << squareEquation << endl;

	return 0;
}
