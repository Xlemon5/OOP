#pragma once
#include<iostream>
using namespace std;

class Pair {

public:
	int a;
	int b;

	Pair();
	Pair(int x, int y);

	int getA();

	int getB();

	void setA(int A);

	void setB(int B);

	Pair& operator =(const Pair& other);

	Pair(const Pair& other);

	bool operator ==(const Pair& other);

	bool operator !=(const Pair& other);

	Pair operator *(const Pair& other) const;

	Pair operator +(const Pair& other) const;

	Pair operator -(const Pair& other) const;

	friend ostream& operator << (ostream& out, const Pair& other);

	friend istream& operator >> (istream& in, Pair& other);

};

