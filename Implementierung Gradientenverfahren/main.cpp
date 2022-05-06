#include <iostream>
#include "ClassVektor.h"
#include "CMyMatrix.h"

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
CMyVektor funktion3(CMyVektor c)
{

}

int main() {
	int choice_fkt = 0;

	CMyVektor V1;
	V1.set_Dimension(2);
	V1.set_specified_Value(0, 0.2);
	V1.set_specified_Value(1, -2.1);
	//------------------
	CMyVektor V2;
	V2.set_Dimension(3);
	V2.set_specified_Value(0,0.0);
	V2.set_specified_Value(1, 0.0);
	V2.set_specified_Value(2, 0.0); 
	//----------------- 


	cout << "1: Funktion 1 Vektor-2D, lambda = 1.0\n"
		 << "2: Funktion 2 Vektor-3D, lambda = 0.1\n"
		 << "3: Funktion 3 Jakobi Matrix\n"
		 << "4: Funktion 4 Newton Verfahren\n";
	cin >> choice_fkt;

	switch (choice_fkt)
	{
	case 1:
		gradientenverfahren(V1, funktion1);
		break;
	case 2:
		gradientenverfahren(V2, funktion1,0.1);
		break;
	case 3:
		///  Jacobi
		break;
	case 4:
		///  newton
		break;
	default:
		break;
	}
	system("pause");
	return 0;
	
}


