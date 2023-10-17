#ifndef LAB4_PAIR_H
#define LAB4_PAIR_H
#include <iostream>
using namespace std;


class Pair{
public:

    int a;
    int b;

    //конструкторы
    Pair(int x = 0, int y = 0);


    Pair operator * (const Pair &other) const;

    Pair operator - (const Pair &other) const;

    Pair operator + (const Pair &other) const;


    // проверка на равенство
    bool operator == (const Pair &other) const;

    bool operator != (const Pair &other) const;

    //ГЕТТЕРЫ
    int getA();

    int getB();

    //СЕТТЕРЫ
    void setA(int A);

    void setB(int B);

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
