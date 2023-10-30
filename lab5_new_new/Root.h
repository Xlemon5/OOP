#ifndef LAB5_NEW_ROOT_H
#define LAB5_NEW_ROOT_H


class Root {
protected:
    double* coefficients;
    int size;

public:
    Root(int _size);

    Root(double a, double b);

    Root(double a, double b, double c);

    ~Root();

    Root(const Root& other);

    Root& operator =(const Root& other);

    void enterCoef();

    virtual void inputCoefficients() = 0;
    virtual void displayResult() = 0;
    virtual void calculateRoots() = 0;
};



#endif //LAB5_NEW_ROOT_H
