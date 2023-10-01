#include "Time.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

    //КОНСТРУКТОРЫ
    Time::Time(): hours(0), minutes(0), seconds(0){}

    // конструктор + инициализация из чисел
    Time::Time(int _hours, int _minutes, int _seconds): hours(_hours), minutes(_minutes), seconds(_seconds){}

    //сеттеры
    void Time::setHours(int _hours)
    {
        hours = _hours;
    }

    void Time::setMinutes(int _minutes)
    {
        minutes = _minutes;
    }

    void Time::setSeconds(int _seconds)
    {
        hours = _seconds;
    }


    //геттеры
    int Time::getHours()
    {
        return hours;
    }

    int Time::getMinutes()
    {
        return minutes;
    }

    int Time::getSeconds()
    {
        return seconds;
    }


    //ИНИЦИАЛИЗАЦИЯ
    //инициализация из другого времени
    Time Time::fromTime(Time other)
    {
        return Time(other.hours, other.minutes, other.seconds);
    }

    //инициализация из секунд (total_seconds не меняется)
    Time Time::fromSecond(int total_seconds)
    {
        int h = total_seconds / 3600;
        total_seconds = total_seconds % 3600;
        int m = total_seconds / 60;
        int s = total_seconds % 60;

        return Time(h, m, s);
    }

    //инициализация строкой
    Time Time::fromString(string &data)
    {
        int next = 0;

        int h = 0, m = 0, s = 0;

        h = stoi(data.substr(next, data.find_first_of(':', next)));
        next = data.find_first_of(':', next) + 1;

        m = stoi(data.substr(next, data.find_first_of(':', next) - next));
        next = data.find_first_of(':', next) + 1;

        s = stoi(data.substr(next));

        return Time(h, m, s);
    }

    //перевод в секунды
    Time Time::toSeconds()
    {
        int s = hours * 3600 + minutes * 60 + seconds;
        return Time(0, 0, s);
    }

    //перевод в минуты
    Time Time::toMinutes()
    {
        int m = hours * 60 + minutes + (seconds > 0 ? 1: 0);
        return Time(0, m, 0);
    }

    //перегрузка операторов сравнения
    bool Time::operator == (Time &other)
    {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }

    bool Time::operator != (Time &other)
    {
        return hours != other.hours || minutes != other.minutes || seconds != other.seconds;
    }

    bool Time::operator < (Time &other)
    {
        if (hours != other.hours)
        {
            return hours < other.hours;
        }
        if(minutes != other.minutes)
        {
            return minutes < other.minutes;
        }
        return seconds < other.seconds;
    }

    bool Time::operator > (Time &other)
    {
        if (hours != other.hours)
        {
            return hours > other.hours;
        }
        if(minutes != other.minutes)
        {
            return minutes > other.minutes;
        }
        return seconds > other.seconds;
    }

    //перегрузка оператора присваивания
    Time Time::operator=(const Time &other){
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
    }

    //Вычисление разницы между двумя моментами времени в секундах
    Time Time::differenceInSeconds( Time other_time)
    {
        int total_seconds_this = hours * 3600 + minutes * 60 + seconds;
        int total_seconds_other = other_time.hours * 3600 + other_time.minutes * 60 + other_time.seconds;

        int total_seconds = abs(total_seconds_this - total_seconds_other);

        Time temp;
        temp.hours = total_seconds / 3600;
        total_seconds = total_seconds % 3600;
        temp.minutes = total_seconds / 60;
        temp.seconds = total_seconds % 60;

        return temp;
    }

    //Сложение времени и заданного кол-ва секунд
    void Time::addSeconds(int seconds_to_add)
    {
        int total_seconds = hours * 3600 + minutes * 60 + seconds;

        total_seconds += seconds_to_add;

        hours = total_seconds / 3600;

        total_seconds = total_seconds % 3600;

        minutes = total_seconds / 60;

        seconds = total_seconds % 60;
    }

    //Вычитание из времени заданного кол-ва секунд
    void Time::substractSecond(int seconds_to_substract)
    {
        int total_seconds = hours * 3600 + minutes * 60 + seconds;
        total_seconds = total_seconds - seconds_to_substract;

        if (total_seconds < 0)
        {
            total_seconds += 86400; // 86400 секунд в сутках
        }
        hours = total_seconds / 3600;
        total_seconds = total_seconds % 3600;
        minutes = total_seconds / 60;
        seconds = total_seconds % 60;
    }

    //перевод в строку
    string Time::TimeToString()
    {
        string result = to_string(hours) + " : " + to_string(minutes) + " : " + to_string(seconds);
        return result;
    }

    //перегрузка оператора вывода
    std::ostream& operator<<(std::ostream& out, const Time& time)
    {
        out << setw(2) << time.hours << ":" << setw(2) << time.minutes << ":" << setw(2) << time.seconds << endl;
        return out;
    }

    //перегрузка оператора ввода
    std::istream& operator>>(std::istream& in,  Time& time)
    {
        int h, m, s;
        char colon;

        in >> h >> colon >> m >> colon >> s;

        if (in) {
            time.hours = h;
            time.minutes = m;
            time.seconds = s;
        }

        return in;
    }