#include <iostream>
#include "Root.h"
#include "Linear.h"
#include "Square.h"
using namespace std;


/*
 25 страница 125
*/


void printRoots(Root& equation){
    equation.displayResult();
}

int main()
{
    setlocale(LC_ALL, "ru");

/*
    Linear linearEquation;
    Square squareEquation;
*/

/*    linearEquation.inputCoefficients();
    squareEquation.inputCoefficients();

    Root* ptrLinear = &linearEquation;
    Root* ptrSquare = &squareEquation;*/

    Root* ptrLinear = new Linear;
    Root* ptrSquare = new Square;

    ptrLinear->inputCoefficients();
    ptrSquare->inputCoefficients();

    cout << endl;

    cout << *ptrLinear << endl;
    ptrLinear->displayResult();

    cout << *ptrSquare << endl;
    ptrSquare->displayResult();

    //printRoots(*ptrLinear);
    //printRoots(*ptrSquare);

    //cout << linearEquation << endl;
    //cout << squareEquation << endl;

    return 0;
}
