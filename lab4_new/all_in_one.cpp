#include <iostream>
 
using namespace std;
 
 
class Pair {
 
public:
	int a;
	int b;
 
	Pair() : a(0), b(0) {}
	Pair(int x, int y) : a(x), b(y) {}
 
	int getA()
	{
		return a;
	}
 
	int getB()
	{
		return b;
	}
	void setA(int A)
	{
		a = A;
	}
	void setB(int B)
	{
		b = B;
	}
	Pair& operator =(const Pair& other)
	{
		a = other.a;
		b = other.b;
 
		return *this;
	}
	Pair(const Pair& other)
	{
		a = other.a;
		b = other.b;
	}
	bool operator ==(const Pair& other)
	{
		return a == other.a && b == other.b;
	}
	bool operator !=(const Pair& other)
	{
		return (a != other.a) || (b != other.b);
	}
	Pair operator *(const Pair& other) const
	{
		return Pair(a * other.a, b * other.b);
	}
	Pair operator +(const Pair& other) const
	{
		return Pair(a + other.a, b + other.b);
	}
	Pair operator -(const Pair& other) const
	{
		return Pair(a - other.a, b - other.b);
	}
	friend ostream& operator << (ostream& out, const Pair& other)
	{
		out << "(" << other.a << ", " << other.b << ")" << endl;
		return out;
	}
 
	friend istream& operator >> (istream& in, Pair& other)
	{
		in >> other.a >> other.b;
		return in;
	}
};
 
 
class Rational: public Pair {
 
public:
	Rational() : Pair(0, 1) {}
 
	Rational(int x, int y = 1) : Pair(x, y) {}
 
	int findNOD(int a, int b)
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
 
	void normalize()
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
 
	Rational operator +(const Rational& other) const 
	{
		int newA = a * other.b + b * other.a;
		int newB = b * other.b;
 
		Rational result(newA, newB);
		result.normalize();
 
		return result;
	}
 
	Rational operator -(const Rational& other) const
	{
		int newA = (a * other.b) - (b * other.a);
		int newB = b * other.b;
 
 
		Rational result(newA, newB);
		result.normalize();
 
		return result;
	}
 
	Rational operator /(const Rational& other) const
	{
		int newA = a * other.b;
		int newB = b * other.a;
 
 
		Rational result(newA, newB);
		result.normalize();
 
 
		return result;
	}
 
	bool operator > (const Rational& other) const
	{
		double n1 = 0, n2 = 0;
		n1 = static_cast<double>(a) / static_cast<double>(b);
		n2 = static_cast<double>(other.a) / static_cast<double>(other.b);
 
		return n1 > n2;
	}
 
	bool operator < (const Rational& other) const
	{
		double n1 = 0, n2 = 0;
		n1 = static_cast<double>(a) / static_cast<double>(b);
		n2 = static_cast<double>(other.a) / static_cast<double>(other.b);
 
		return n1 < n2;
	}
 
 
 
	// не убирать const из const Rational& other!!!
	friend ostream& operator << (ostream& out, const Rational& other)
	{
		out << "(" << other.a << " / " << other.b << ")" << endl;
		return out;
	}
 
	friend istream& operator >> (istream& in, Rational& other)
	{
		in >> other.a >> other.b;
		return in;
	}
 
};
 
 
 
int main() 
{
	setlocale(LC_ALL, "ru");
	//Pair p1;
	//Pair p2;
 
	//cout << "Введите p1:" << endl;
	//cin >> p1;
 
	//cout << "Введите p2:" << endl;
	//cin >> p2;
 
 
	//// РЕЗУЛЬТАТ ВЫРАЖЕНИЯ - НОВАЯ ПАРА
	//cout << "Вычитание (p1 - p2): " << endl;
	//cout << p1 - p2 << endl;
 
	//cout << "Сложение (p1 + p2): " << endl;
	//cout << p1 + p2 << endl;
 
	//cout << "Умножение (p1 * p2): " << endl;
	//cout << p1 * p2 << endl;
 
	//cout << "Проверка на равенство (p1 == p2): " << endl;
	//if(p1 == p2)
	//{
	//	cout << "Пары равны!" << endl;
	//}
	//else
	//{
	//	cout << "Пары не равны!" << endl;
	//}
 
 
 
	//ТЕПЕРЬ РАБОТАЕМ С Rational
	cout << endl;
 
 
	cout << "ТЕПЕРЬ РАБОТАЕМ С Rational:" << endl;
	cout << endl;
 
	Rational r1;
	Rational r2;
 
	cout << "Введите r1: " << endl;
	cin >> r1;
 
	cout << "Введите r2: " << endl;
	cin >> r2;
 
	cout << "Новая операция сложения (r1 + r2): " << endl;
	cout << r1 + r2 << endl;
 
	cout << "Переопределенная операция вычитания (r1 - r2): " << endl;
	cout << r1 - r2 << endl;
 
	cout << "Новая операция деления (r1 / r2): " << endl;
	cout << r1 / r2 << endl;
 
 
 
 
	return 0;
}
