#pragma once   /*Praktikum 2 Created By Dominique */
#include "ClassVektor.h"
#include <vector>

class CMyMatrix: public CMyVektor
{
	
	private:
	vector<CMyVektor>Matrix; // Zweidimensionaler Vektor 
	int y_pos = 0, x_pos = 0;
	

	public:
	CMyMatrix();
	CMyMatrix(int,int);
	void set_MatrixDim(int,int);
	void set_MatrixDimViaVektor(CMyVektor);
	int get_MatrixDim();
	void set_Matrix_Value(double,int,int);
	int get_Matrix_Value(int, int);
	friend CMyVektor operator*(CMyMatrix A, CMyVektor x); /* Matrix-Vektor-Multiplikation realisieren*/
	CMyMatrix inverse(CMyMatrix);
	double det();
	CMyMatrix jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor x));
	int get_zeile();
	int get_spalte();
};