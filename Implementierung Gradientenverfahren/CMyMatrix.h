#pragma once
#include "ClassVektor.h"

class CMyMatrix: CMyVektor
{
	
	private:
	vector<vector<double> >Matrix; // Zweidimensionaler Vektor 
	int y_pos = 0, x_pos = 0;

	public:
	CMyMatrix();
	~CMyMatrix();
	void set_MatrixDim(int,int);
	void set_MatrixDimViaVektor(CMyVektor);
	int get_MatrixDim();
	void set_Matrix_Value(double,int,int);
	int get_Matrix_Value(int, int);
	friend CMyVektor operator*(CMyMatrix& A, CMyVektor& x); /* Matrix-Vektor-Multiplikation realisieren*/
	CMyMatrix inverse(vector<vector<double> >);

};