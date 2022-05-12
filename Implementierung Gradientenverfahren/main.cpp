#include <iostream>
#include <math.h>

/*includierte Header*/
#include "CMyMatrix.h"

/*includierte CPP*/
#include "CmyVektor.cpp"
#include "CMyMatrix.cpp"

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
/// Test für Jacobi
CMyVektor funktion3_jacobi(CMyVektor c)
{
	CMyVektor tmp;
	double x1 = c[0];
	double x2 = c[1];
	double x3 = c[2];
	double x4 = c[3];
	tmp[0] = x1 * x2 * exp(x3);
	tmp[1] = x2 * x3 * x4;
	tmp[3] = x4;
	return tmp;
}
/*Test Funktion für newton verfahren*/
CMyVektor funktion4_newton(CMyVektor c) 
{
	CMyVektor tmp;
	double x = c[0];
	double y = c[1];
	tmp[0] = pow(x,3)*pow(y,3) - 2 * y;
	tmp[1] = x - 2;
	return tmp;
}

int main() {
	int choice_fkt = 0;

	CMyVektor V1;
	V1.set_Dimension(2);
	V1[0] = 0.2;
	V1[1] = -2.1;
	//------------------
	CMyVektor V2;
	V2.set_Dimension(3);
	V2[0]=0.0;
	V2[1]= 0.0;
	V2[2] = 0.0;
	//----------------- 
	CMyMatrix V3(0,1);


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
		// Fkt Aufruf Jacobi - Matrix berechnen
		//jacobi(V3, funktion3_jacobi);
		break;
	case 4:
		// Funktionsaufruf Newtonverfahren
		//newton();
		break;
	default:
		break;
	}
	system("pause");
	return 0;
	
}


