#include "bill.h"
#include "Time.h"
using namespace std;

//конструктор
Bill::Bill(string _lN, string _pN, double _tarif, double _discount, Time _start, Time _end):lastName(_lN), phoneNum(_pN), tarifPerMinute(_tarif), discount(_discount),startTime(_start), endTime(_end)
{
    calculateAmount();
}

//пустой конструктор
Bill::Bill()
:lastName(""), phoneNum(""), tarifPerMinute(0.0), discount(0.0), startTime(), endTime(), payableAmount(0.0){}

// расчитываем стоимость
void Bill::calculateAmount()
{
    int totalMinutes = (endTime.toMinutes().getMinutes() - startTime.toMinutes().getMinutes());
    double totalCost = totalMinutes * tarifPerMinute;

    payableAmount = totalCost - (totalCost * (discount / 100));
}

//Реализация метода toString() из условия задачи
string Bill::toString()
{
    string result = "Плательщик: " + lastName + "\n";
    result += "Номер телефона: " + phoneNum + "\n";
    result += "Тариф: " + to_string(tarifPerMinute) + "\n";
    result += "Скидка: " + to_string(discount) + "% \n";
    result += "Время начала разговора: " + startTime.TimeToString() + "\n";
    result += "Время окончания разговора: " + endTime.TimeToString() + "\n";
    result += "Сумма к оплате: " + to_string(payableAmount) + " руб \n";
    return result;
}

//ГЕТТЕРЫ
string Bill::getLastName()
{
    return lastName;
}

string Bill::getPhoneNumber()
{
    return phoneNum;
}

double Bill::getTarif()
{
    return tarifPerMinute;
}

double Bill::getDiscount()
{
    return discount;
}

Time Bill::getStartTime()
{
    return startTime;
}

Time Bill::getEndTime()
{
    return endTime;
}

double Bill::getPayableAmount()
{
    return payableAmount;
}


//СЕТТЕРЫ
void Bill::setLastName(string lName)
{
    lastName = lName;
}

void Bill::setPhoneNumber(string pNum)
{
    phoneNum = pNum;
}

void Bill::setTarif(double tarif)
{
    tarifPerMinute = tarif;
    calculateAmount();
}

void Bill::setDiscount(double discnt)
{
    discount = discnt;
    calculateAmount();
}

void Bill::setStartTime(Time start)
{
    startTime = start;
    calculateAmount();
}

void Bill::setEndTime(Time end)
{
    endTime = end;
    calculateAmount();
}

void Bill::setPayableAmount(double amount)
{
    payableAmount = amount;
}

//перегрузка оператора присваивания
Bill Bill::operator=(const Bill &other){
    lastName = other.lastName;
    phoneNum = other.phoneNum;
    tarifPerMinute = other.tarifPerMinute;
    discount = other.discount;
    startTime = other.startTime;
    endTime = other.endTime;
    payableAmount = other.payableAmount;

    return *this;
}

//перегрузка оператора ввода
std::istream& operator >> (istream& in, Bill &bill)
{
    std::cout << "Введите информацию о счете в формате:\n";
    std::cout << "Фамилия номер тариф скидка начальное_время(::) конечное_время(::)\n";
    in >> bill.lastName >> bill.phoneNum >> bill.tarifPerMinute >> bill.discount >>
       bill.startTime >> bill.endTime;
    bill.calculateAmount();
    return in;
}