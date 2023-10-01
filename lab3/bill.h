#ifndef LAB3_BILL_H
#define LAB3_BILL_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Time.h"

class Bill{
private:
    std::string lastName;
    std::string phoneNum;
    double tarifPerMinute; //тариф
    double discount;
    Time startTime;
    Time endTime;
    double payableAmount; //сумма к оплате

public:

    //конструктор
    Bill(std::string _lN, std::string _pN, double _tarif, double _discount, Time _start, Time _end);

    //пустой конструктор
    Bill();

    // расчитываем стоимость
    void calculateAmount();

    //Реализация метода toString() из условия задачи
    std::string toString();

    //ГЕТТЕРЫ
    std::string getLastName();

    std::string getPhoneNumber();

    double getTarif();

    double getDiscount();

    Time getStartTime();

    Time getEndTime();

    double getPayableAmount();


    //СЕТТЕРЫ
    void setLastName(std::string lName);

    void setPhoneNumber(std::string pNum);

    void setTarif(double tarif);

    void setDiscount(double discnt);

    void setStartTime(Time start);

    void setEndTime(Time end);

    void setPayableAmount(double amount);

    //перегрузка оператора присваивания
    Bill operator=(const Bill &other);

    //перегрузка оператора ввода
    friend std::istream& operator >> (std::istream& in, Bill &bill);

};


#endif //LAB3_BILL_H