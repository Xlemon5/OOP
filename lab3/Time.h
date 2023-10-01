#ifndef LAB3_TIME_H
#define LAB3_TIME_H

#include <iostream>
#include <string>
#include <iomanip>


class Time{
private:
    int hours;
    int minutes;
    int seconds;

public:

    //КОНСТРУКТОРЫ
    Time();

    // конструктор + инициализация из чисел
    Time(int _hours, int _minutes, int _seconds);

    //сеттеры
    void setHours(int _hours);

    void setMinutes(int _minutes);

    void setSeconds(int _seconds);


    //геттеры
    int getHours();

    int getMinutes();

    int getSeconds();


    //ИНИЦИАЛИЗАЦИЯ
    //инициализация из другого времени
    Time fromTime(Time other);

    //инициализация из секунд (total_seconds не меняется)
    Time fromSecond(int total_seconds);

    //инициализация строкой
    Time fromString(std::string &data);

    //перевод в секунды
    Time toSeconds();

    //перевод в минуты
    Time toMinutes();

    //перегрузка операторов сравнения
    bool operator == (Time &other);

    bool operator != (Time &other);


    bool operator < (Time &other);

    bool operator > (Time &other);

    //Вычисление разницы между двумя моментами времени в секундах
    Time differenceInSeconds( Time other_time);

    //Сложение времени и заданного кол-ва секунд
    void addSeconds(int seconds_to_add);

    //Вычитание из времени заданного кол-ва секунд
    void substractSecond(int seconds_to_substract);

    //перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const Time& time);

    //перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& in, Time& time);


    //перевод в строку
    std::string TimeToString();

    //перегрузка оператора присваивания
    Time operator=(const Time &other);


};


#endif //LAB3_TIME_H
