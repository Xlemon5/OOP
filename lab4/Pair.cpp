#include "Pair.h"
#include <iostream>
using namespace std;

    //конструкторы

    Pair::Pair(): a(0), b(0){}

    Pair::Pair(int _a, int _b): a(_a), b(_b){}


    // проверка на равенство
    bool Pair::operator == (const Pair &other) const
    {
        return (a == other.a) && (b == other.b);
    }

    //перемножение полей
    Pair Pair::operator * (const Pair &other) const {
        return Pair(a * other.a, b * other.b);
    }

    //вычитание пар
    Pair Pair::operator - (const Pair &other) const
    {
        return Pair(a - b, other.a - other.b);
    }

    //печать
    void Pair::printPair()
    {
        cout << "(" << a <<", " << b << ")" << endl;
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

    //ОПЕРАТОР ПРИСВАИВАНИЯ
    Pair& Pair::operator=(const Pair& other){
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
    std::ostream& operator<<(std::ostream &out, const Pair& other)
    {
        out << "(" << other.a <<", " << other.b << ")" << endl;
        return out;
    }

    //перегрузка ввода
    std::istream& operator >> (std::istream& in, Pair &other)
    {
        in >> other.a >> other.b;
        return in;
    }
