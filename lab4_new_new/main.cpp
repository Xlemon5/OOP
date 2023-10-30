#include <iostream>
#include "Pair.h"
#include "Rational.h"
using namespace std;



int main()
{
    setlocale(LC_ALL, "ru");
    Pair p1;
    Pair p2;

    cout << "Введите p1:" << endl;
    cin >> p1;

    cout << "Введите p2:" << endl;
    cin >> p2;


    //// РЕЗУЛЬТАТ ВЫРАЖЕНИЯ - НОВАЯ ПАРА
    cout << "Вычитание (p1 - p2): " << endl;
    Pair* vychit = p1 - p2;
    cout << *vychit << endl;

    cout << "Сложение (p1 + p2): " << endl;
    Pair* sum = p1 + p2;
    cout << *sum << endl;

    cout << "Умножение (p1 * p2): " << endl;
    Pair* ymnozh = p1 * p2;
    cout << *ymnozh << endl;

    cout << "Деление (p1 / p2): " << endl;
    Pair* del = p1 / p2;
    cout << *del << endl;


    cout << "Проверка на равенство (p1 == p2): " << endl;
    if(p1 == p2)
    {
    	cout << "Пары равны!" << endl;
    }
    else
    {
    	cout << "Пары не равны!" << endl;
    }



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
    Rational* sumr = r1 + r2;
    cout << *sumr << endl;

    cout << "Переопределенная операция вычитания (r1 - r2): " << endl;
    Rational* vychitr = r1 - r2;
    cout << *vychitr << endl;

    cout << "Новая операция деления (r1 / r2): " << endl;
    Rational* delr = r1/r2;
    cout << *delr << endl;

    cout << "Умнож (r1 * r2): " << endl;
    Rational* ymnzhr = r1*r2;
    cout << *ymnzhr << endl;

    if (r1 > r2)
    {
        cout << "да" << endl;
    }
    else
    {
        cout << "нет" << endl;
    }


    return 0;
}
