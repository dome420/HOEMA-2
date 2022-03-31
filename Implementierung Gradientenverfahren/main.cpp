#include <iostream>
#include "ClassVektor.h"

using namespace std;

CMyVektor operator+(CMyVektor a, CMyVektor b);
CMyVektor operator*(double lambda, CMyVektor a);

int main() {

	CMyVektor V1;
	CMyVektor V2;

	int V_Size = 0;
	int Specified_Value_key = 0, double Value = 0;
	double Vector_Value = 0;

	
	do{
		cout << "Geben Sie die Vektor Groeße des ersten Vektors ein : ";
		cin >> V_Size;
		
	} while (V_Size <= 0);
	V1.creat_Dimension(V_Size);
	V_Size = 0;
	// (1) Werte eingabe für den ersten Vektor
	do {
		cout << "Geben Sie die Vektor Groeße des ersten Vektors ein : ";
		cin >> V_Size;

	} while (V_Size <= 0);
	V1.creat_Dimension(V_Size);
	// (1) Werte eingabe für den zweiten Vektor
	V_Size = 0;
	
	cout << endl;
	cout << "Eine bestimmte Komponente des Vektors setzen (key) : ";


}

CMyVektor operator+(CMyVektor a, CMyVektor b)
{

}
CMyVektor operator*(double lambda, CMyVektor a) 
{

}