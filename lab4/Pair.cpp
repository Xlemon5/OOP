#include "Pair.h"
// #include <iostream>
using namespace std;

    //конструкторы

    Pair::Pair(int x, int y): a(x), b(y){}


    //перемножение полей
    Pair Pair::operator * (const Pair &other) const {
        return Pair(a * other.a, b * other.b);
    }

    Pair Pair::operator + (const Pair &other) const
    {
        return Pair(a + other.a, b + other.b);
    }

    //вычитание пар
    Pair Pair::operator - (const Pair &other) const
    {
        return Pair(a - b, other.a - other.b);
    }


    //ГЕТТЕРЫ
    int Pair::getA(){
        return a;
    }

    int Pair::getB(){
        return b;
    }

    //СЕТТЕРЫ
    int Pair::setA(int A){
        a = A;
    }

    int Pair::setB(int B){
        b = B;
    }


    // проверка на равенство
    bool Pair::operator == (const Pair &other) const
    {
        return (a == other.a) && (b == other.b);
    }

    bool Pair::operator != (const Pair &other) const
    {
        return (a != other.a) || (b != other.b);
    }

    //ОПЕРАТОР ПРИСВАИВАНИЯ
    Pair& Pair::operator =(const Pair& other){
        a = other.a;
        b = other.b;

        return *this;
    }

    //ОПЕРАТОР КОПИРОВАНИЯ
    Pair::Pair(const Pair&other){
        a = other.a;
        b = other.b;
    }

    //перегрузка вывода
    std::ostream& operator <<(std::ostream &out, const Pair& other)
    {
        out << "(" << other.a <<", " << other.b << ")" << endl;
        return out;
    }


    //перегрузка ввода
    istream& operator >>(istream& in, const Pair &other);

istream &operator>>(istream &in, const Pair &other)
{
    in >> other.a >> other.b;
    return in;
}
