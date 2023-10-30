#include <iostream>
#include "Root.h"
#include "Linear.h"
#include "Square.h"
using namespace std;


void printRoots(Root& equation){
    equation.displayResult();
}

int main()
{
    setlocale(LC_ALL, "ru");

    Linear linearEquation;
    Square squareEquation;

    linearEquation.inputCoefficients();
    squareEquation.inputCoefficients();

    Root* ptrLinear = &linearEquation;
    Root* ptrSquare = &squareEquation;

    cout << endl;

    cout << linearEquation << endl;
    ptrLinear->displayResult();

    cout << squareEquation << endl;
    ptrSquare->displayResult();

    //printRoots(*ptrLinear);
    //printRoots(*ptrSquare);

    //cout << linearEquation << endl;
    //cout << squareEquation << endl;

    return 0;
}
