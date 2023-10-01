#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Time{
private:
    int hours;
    int minutes;
    int seconds;

public:

    //КОНСТРУКТОРЫ
    Time(): hours(0), minutes(0), seconds(0){}

    // конструктор + инициализация из чисел
    Time(int _hours, int _minutes, int _seconds): hours(_hours), minutes(_minutes), seconds(_seconds){}

    //ИНИЦИАЛИЗАЦИЯ
    //инициализация из другого времени
    Time fromTime(const Time &other)
    {
        return Time(other.hours, other.minutes, other.seconds);
    }

    //инициализация из секунд (total_seconds не меняется)
    Time fromSecond(int total_seconds)
    {
        int h = total_seconds / 3600;
        total_seconds = total_seconds % 3600;
        int m = total_seconds / 60;
        int s = total_seconds % 60;

        return Time(h, m, s);
    }

    //инициализация строкой
    Time fromString(string &data)
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
    Time toSeconds()
    {
        int s = hours * 3600 + minutes * 60 + seconds;
        return Time(0, 0, s);
    }

    //перевод в минуты
    Time toMinutes()
    {
        int m = hours * 60 + minutes + (seconds >= 30 ? 1: 0);
        return Time(0, m, 0);
    }

    //перегрузка операторов сравнения
    bool operator == (Time &other)
    {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }

    bool operator != (Time &other)
    {
        return hours != other.hours || minutes != other.minutes || seconds != other.seconds;
    }

    bool operator < (Time &other)
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

    bool operator > (Time &other)
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

    //Вычисление разницы между двумя моментами времени в секундах
    Time differenceInSeconds( Time& other_time)
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
    void addSeconds(int seconds_to_add)
    {
        int total_seconds = hours * 3600 + minutes * 60 + seconds;

        total_seconds += seconds_to_add;

        hours = total_seconds / 3600;

        total_seconds = total_seconds % 3600;

        minutes = total_seconds / 60;

        seconds = total_seconds % 60;
    }

    //Вычитание из времени заданного кол-ва секунд
    void substractSecond(int seconds_to_substract)
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

    //перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const Time& time)
    {
        out << setw(2) << time.hours << ":" << setw(2) << time.minutes << ":" << setw(2) << time.seconds << endl;
        return out;
    }

};




int main() {

    Time temp(12, 44, 37);

    string time_str = "12:34:56";
    Time t1 = t1.fromString(time_str);

    int n = 7250;
    Time t2 = t2.fromSecond(n);


    cout << "temp: " <<temp << endl;
    cout << "t1: " << t1 << endl;

    cout << "t2: "<< t2 << endl;

    Time t3 = t1.toMinutes();
    cout << "t3: " << t3 << endl;


/*
    TESTS:
    cout << "Difference between t1 and t2: " <<  t1.differenceInSeconds(t2) << endl;

    t1.addSeconds(3650);
    cout << "t1 after adding seconds: " << t1 << endl;

    t2.substractSecond(3700);
    cout << "t2 after substruct seconds: " << t2 << endl;*/

    return 0;
}
