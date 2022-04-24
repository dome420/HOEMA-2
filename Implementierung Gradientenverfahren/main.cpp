#include <iostream>
#include "ClassVektor.h"

using namespace std;


int main() {
	// Addition und Multiplikation
	CMyVektor V1;
	CMyVektor V2;
	V1.set_Dimension(2);
	V1.set_specified_Value(0, 1);
	V1.set_specified_Value(1, 1);
	V2.set_Dimension(2);
	V2.set_specified_Value(0, 1);
	V2.set_specified_Value(1, 1);
	CMyVektor V3;
	V3.set_Dimension(V1.get_dim());
	int lambda = 2;
	V3 = V1 + V2;
	CMyVektor lam = lambda * V2;
	cout << V3 << endl << lam;

	// gradient
}


