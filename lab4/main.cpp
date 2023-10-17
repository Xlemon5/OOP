//#include <iostream>
#include "Pair.h"
#include "Rational.h"
using namespace std;



int main() {

    Pair p1;
    Pair p2;

    cout << "Введите p1:" << endl;
    cin >> p1;

    cout << "Введите p2:" << endl;
    cin >> p2;

    cout << p2 << endl;

/*    // РЕЗУЛЬТАТ ВЫРАЖЕНИЯ - НОВАЯ ПАРА
    cout << "Вычитание (p1 - p2): " << endl;
    cout << p1 - p2 << endl;

    cout << "Сложение (p1 + p2): " << endl;
    cout << p1 + p2 << endl;

    cout << "Умножение (p1 * p2): " << endl;
    cout << p1 * p2 << endl;

    cout << "Проверка на равенство (p1 == p2): " << endl;
    if(p1 == p2)
    {
        cout << "Пары равны!" << endl;
    }
    else
    {
        cout << "Пары не равны!" << endl;
    }*/



/*
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
*/



    return 0;
}
