#ifndef LAB4_PAIR_H
#define LAB4_PAIR_H
#include <iostream>
using namespace std;


class Pair{
public:

    int a;
    int b;

    //конструкторы
    Pair();

    Pair(int _a, int _b);

    // проверка на равенство
    bool operator == (const Pair &other) const;


    //перемножение полей
    Pair operator * (const Pair &other) const;

    //вычитание пар
    Pair operator - (const Pair &other) const;

    //печать
    void printPair();

    //ГЕТТЕРЫ
    int getA();

    int getB();

    //СЕТТЕРЫ
    int setA(int A);

    int setB(int B);

    //ОПЕРАТОР ПРИСВАИВАНИЯ
    Pair& operator=(const Pair& other);

    //ОПЕРАТОР КОПИРОВАНИЯ
    Pair(const Pair&other);

    //перегрузка вывода
    friend std::ostream& operator<<(std::ostream &out, const Pair& other);

    //перегрузка ввода
    friend std::istream& operator >> (std::istream& in, Pair &other);

};


#endif //LAB4_PAIR_H
