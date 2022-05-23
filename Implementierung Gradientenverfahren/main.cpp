#include <iostream>
#include <math.h>
#include <conio.h>

/*includierte Header*/
#include "CMyMatrix.h"
#include "C_DGLSolver.h"

/*includierte CPP*/
#include "CmyVektor.cpp"
#include "Matrix.cpp"
#include "C_DGLSolver.cpp"

using namespace std;

//Berechnet den Funktionswert mit einem Vektor
inline double funktion1(CMyVektor a) 
{
	double x = a[0];
	double y = a[1];

	double ergebnis = sin(x * y) + sin(x) + cos(y);
	return ergebnis;
}

//Berechnet den Funktionswert mit einem Vektor
inline double funktion2(CMyVektor b)
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
	tmp.set_Dimension(c.get_dim());
	double x = c[0];
	double y = c[1];
	tmp[0] = pow(x,3)*pow(y,3) - 2 * y;
	tmp[1] = x - 2;
	return tmp;
}
double erster_Ordnung_u_(CMyVektor y,int x_end = 2)
{
	double result = (y[1] * 2) - (y[0] * x_end);
	return result;
}
CMyVektor erster_Ordnung_v_(CMyVektor y, int x_end = 2)
{
	double result = (y[0] * y[1]) - (2 * pow(x_end, 3));
	return result;
}
int main() {
	int choice_fkt = 0;
	char cmd_clear;

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
	CMyVektor V3;
	V3.set_Dimension(2);
	V3[0] = 1;
	V3[1] = 1;
	//----------------- 
	CMyVektor DG;
	DG.set_Dimension(2);
	DG[0] = 1;
	DG[1] = 1;
	
	C_DGLSolver DGL(0,f_DGL_system(DG,2.0));
	while (true)
	{

		cout << "0 zum Beenden des Programms\n"
			 << "1: Funktion 1 Vektor-2D, lambda = 1.0\n"
			 << "2: Funktion 2 Vektor-3D, lambda = 0.1\n"
			 << "3: Funktion 3 Jakobi Matrix\n"
			 << "4: Funktion 4 Newton Verfahren\n";
			
		cin >> choice_fkt;

		switch (choice_fkt)
		{
		case 1:
			gradientenverfahren(V1, funktion1);
			cout << endl;
			std::cout << "Fenster leeren\n";
			cin >> cmd_clear;
			if (cmd_clear == 'j') {
				system("CLS");
			}
			break;
		case 2:
			gradientenverfahren(V2, funktion1, 0.1);
			cout << endl;
			std::cout << "Fenster leeren\n";
			cin >> cmd_clear;
			if (cmd_clear == 'j') {
				system("CLS");
			}
			break;
		case 3:
			// Fkt Aufruf Jacobi - Matrix berechnen
			//jacobi(V3, funktion3_jacobi);
			cout << endl;
			std::cout << "Fenster leeren\n";
			cin >> cmd_clear;
			if (cmd_clear == 'j') {
				system("CLS");
			}
			break;
		case 4:
			// Funktionsaufruf Newtonverfahren
			newton(V3,funktion4_newton);
			cout << endl;
			std::cout << "wollen sie das Fenster leeren, dann "<< "j eingeben.\n";
			cin >> cmd_clear;
			if (cmd_clear == 'j') {
				system("CLS");
			}
			//newton();
			break;
		case 5: 

		default:
			break;
		}
	}
	system("pause");
	return 0;
	
}


