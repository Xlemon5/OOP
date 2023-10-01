#include <iostream>
#include "Time.h"
#include "bill.h"
using namespace std;


// если минута не полная, то добавляем к минутам 1 (реализовано в методе toMinutes в классе Time)

int main() {

    Bill bill;
    string temp_string = "";
    double temp_double = 0;
    Time temp_time(0,0,0);
    
    int chose = 0;


    do{
        cout << "МЕНЮ: " << endl;
        cout << "0 - ВЫХОД" << endl;
        cout << "1 - ПОМЕНЯТЬ ФАМИЛИЮ" << endl;
        cout << "2 - ПОМЕНЯТЬ НОМЕР ТЕЛЕФОНА" << endl;
        cout << "3 - ПОМЕНЯТЬ СТОИМОСТЬ ТАРИФА" << endl;
        cout << "4 - ПОМЕНЯТЬ СКИДКУ" << endl;
        cout << "5 - ПОМЕНЯТЬ ВРЕМЯ НАЧАЛА ЗВОНКА" << endl;
        cout << "6 - ПОМЕНЯТЬ ВРЕМЯ КОНЦА ЗВОНКА" << endl;
        cout << "7 - ВВЕСТИ ДАННЫЕ С КЛАВИАТУРЫ" << endl;
        cout << "8 - ВЫВЕСТИ ДАННЫЕ НА ЭКРАН" << endl;
        cout << endl;

        cout << "Введите команду: " << endl;
        cin >> chose;

        switch (chose)
        {
            case 1:
                cout << "Введите новую фамилию: " << endl;
                cin >> temp_string;
                bill.setLastName(temp_string);
                break;
                
            case 2:
                cout << "Введите новый номер: " << endl;
                cin >> temp_string;
                bill.setPhoneNumber(temp_string);
                break;

            case 3:
                cout << "Введите новую стоимость тарифа: " << endl;
                cin >> temp_double;
                bill.setTarif(temp_double);
                break;

            case 4:
                cout << "Введите новую скидку: " << endl;
                cin >> temp_double;
                bill.setDiscount(temp_double);
                break;

            case 5:
                cout << "Введите новое время начала звонка: " << endl;
                cin >> temp_time;
                bill.setStartTime(temp_time);
                break;

            case 6:
                cout << "Введите новое время конца звонка: " << endl;
                cin >> temp_time;
                bill.setEndTime(temp_time);
                break;
            case 7:
                cin >> bill;
                break;

            case 8:
                cout << bill.toString();
                cout << endl;
        }
    }while (chose != 0);

    cout << bill.toString();

    return 0;
}
