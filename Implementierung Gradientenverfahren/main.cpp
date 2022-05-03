#include <iostream>
#include "ClassVektor.h"

using namespace std;

//Berechnet den Funktionswert mit einem Vektor
double funktion1(CMyVektor a) 
{
	double x = a[0];
	double y = a[1];

	double ergebnis = sin(x * y) + sin(x) + cos(y);
	return ergebnis;
}

//Berechnet den Funktionswert mit einem Vektor
double funktion2(CMyVektor b)
{
	double x1 = b[0];
	double x2 = b[1];
	double x3 = b[2];

	double ergebnis = -(2 * pow(x1, 2) - 2 * (x1 * x2) + pow(x2, 2) + pow(x3, 2) - 2 * x1 - 4 * x3);
	return ergebnis;
}

int main() {
	// Addition und Multiplikation
	CMyVektor V1;
	V1.set_Dimension(2);
	V1.set_specified_Value(0, 0.2);
	V1.set_specified_Value(1, -2.1);
	//------------------
	/*CMyVektor V2;
	V2.set_Dimension(2);
	V2.set_specified_Value(0, 1);
	V2.set_specified_Value(1, 1);*/
	//-----------------
	CMyVektor V3;
	V3.set_Dimension(V1.get_dim());
	gradientenverfahren(V1,funktion1);
	system("pause");
	return 0;
	
}


