#include <iostream>
#include "ClassVektor.h"

using namespace std;

CMyVektor operator+(CMyVektor a, CMyVektor b);
CMyVektor operator*(double lambda, CMyVektor a);

int main() {

	CMyVektor V1;
	CMyVektor V2;
	V1.set_Dimension(2);
	V1.set_specified_Value(0, 1);
	V1.set_specified_Value(1, 1);
	V2.set_Dimension(2);
	V2.set_specified_Value(0, 1);
	V2.set_specified_Value(1, 1);

	//int V_Size = 0,int Specified_Value_key = 0, double Value = 0,double Vector_Value = 0;
	double lamda = 2;
	char input;

	/*while (input != 'q')
	{
		do {
			cout << "Geben Sie die Vektor Groeße des ersten Vektors ein : ";
			cin >> V_Size;

		} while (V_Size <= 0);

		V1.set_Dimension(V_Size);
		V_Size = 0;
		// (1) Werte eingabe für den ersten Vektor
		do {
			cout << "Geben Sie die Vektor Groeße des ersten Vektors ein : ";
			cin >> V_Size;

		} while (V_Size <= 0);
		V1.set_Dimension(V_Size);
		// (1) Werte eingabe für den zweiten Vektor
		V_Size = 0;

		cout << endl;
		cout << "Eine bestimmte Komponente des Vektors setzen (key) : ";
	}*/
	

	CMyVektor C;
	C.set_Dimension(V1.get_length_Vector());
	C= V1 + V2;
	std::cout << "Addition : "<< "(";;
	for (int i = 0; i < C.get_length_Vector(); i++)
	{
		
			std::cout  << C[i] << " ";
		
		
	}
	std::cout << ")" << endl;
	C = lamda * C;
	std::cout << "Skalarprodukt: "<< C[0]<< " ";

}

CMyVektor operator+(CMyVektor a, CMyVektor b)
{
	int ai = 0, bi = 0;
	int counter = 0;
	CMyVektor c;
	c.set_Dimension(a.get_length_Vector());
	// Wenn Dimension Gleich dann addition
	if (a.get_length_Vector() == b.get_length_Vector())
	{
		while (counter < a.get_length_Vector())
		{
			c[counter] = a[ai] + b[bi];
			counter++;
		}
		return c;
	}

}
CMyVektor operator*(double lambda, CMyVektor a) 
{
	CMyVektor c;
	c.set_Dimension(1);
	for (unsigned i = 0; i < a.get_length_Vector(); i++)
	{
		c[0] += lambda * a[i];
	}
	return c;
}
