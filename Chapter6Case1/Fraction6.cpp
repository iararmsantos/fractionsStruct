/*
This program show how a array of fraction struct work, also this reduce the fraction to mixed fraction, 
and display the fractions using functions.
By: Iara Santos
Data: 02/08/2020
*/
#include<iostream>
using namespace std;

struct Fraction {
	int numerator;
	int denominator;
	int wholeNum;
};

const int NUMFIELD = 10;


int main() {
	//declaring variable	
	Fraction enterFractionValue();
	Fraction data[NUMFIELD];
	Fraction* ptr;
	ptr = data;
	void displayFraction(Fraction data);
	void reduceFraction(Fraction * f, int count);	
	int count = 0;

	//input data
	data[count] = enterFractionValue();	
	while ((data + count)->wholeNum != 0 || (data + count)->numerator != 0) {	
		++count;
		data[count] = enterFractionValue();		
	}	
	cout << endl;
	cout << "*** Fractions ***" << endl;

	//display data
	for (int i = 0; i < count; i++) {
		cout << i + 1 << "# fraction: ";
		displayFraction(data[i]);
	}
	cout << endl;

	//transform from mixed to improper fraction
	//it is necessary to reduce to greater common divisor and to do maths
	for (int i = 0; i < count; i++) {
		if (data[i].wholeNum != 0) {
			data[i].numerator = data[i].wholeNum * data[i].denominator + data[i].numerator;
			data[i].wholeNum = 0;
		}
	}
	
	cout << "*** Reduced Fractions ***" << endl;
	reduceFraction(ptr, count);

	//display data
	for (int i = 0; i < count; i++) {
		cout << i + 1 << "# fraction: ";
		displayFraction(data[i]);
	}
	cout << endl;
	return 0;
}
//receive Fraction input
Fraction enterFractionValue() {
	Fraction f;

	cout << "Enter fraction whole number: ";
	cin >> f.wholeNum;
	cout << "Enter fraction numerator: ";
	cin >> f.numerator;
	cout << "Enter fraction denominator > 0: ";
	cin >> f.denominator;
	while (f.denominator == 0) {
		cout << "Enter fraction denominator > 0: ";
		cin >> f.denominator;
	}
	return f;
}

void reduceFraction(Fraction* f, int NUMFIELD) {
	//reducing fractions divide the multiplication of den and num(greater number) until modulo 0
	int multDN;
	for (int i = 0; i < (f+i)->denominator; i++) {
		multDN = (f + i)->denominator * (f + i)->numerator;
		for (int j = multDN; j > 1; j--) {
			if (((f + i)->numerator % j) == 0 && ((f + i)->denominator % j) == 0) {
				(f + i)->numerator = (f + i)->numerator / j;
				(f + i)->denominator = (f + i)->denominator / j;
			}
		}
	}
	for (int j = 0; j < NUMFIELD; j++) {
		(f + j)->wholeNum += ((f + j)->numerator / (f + j)->denominator);
		(f + j)->numerator = ((f + j)->numerator % f->denominator);
	}	
	cout << endl;
}

//display data
void displayFraction(Fraction data) {

	if (data.wholeNum != 0 && data.numerator != 0) {
		cout << data.wholeNum << " " << data.numerator << "/" << data.denominator << endl;
	}
	else if (data.wholeNum != 0 && data.numerator == 0) {
		cout << data.wholeNum << endl;
	}
	else if (data.wholeNum == 0 && data.numerator >= 1) {
		cout << data.numerator << "/" << data.denominator << endl;
	}
	else {
		cout << 0 << endl;
	}
}

