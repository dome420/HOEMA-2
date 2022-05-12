#pragma once   /*Praktikum 2 Created By Dominique */
#include "ClassVektor.h"

class CMyMatrix
{
	
	private:
	std::vector<CMyVektor>Matrix; // Zweidimensionaler Vektor 
	int y_pos = 0, x_pos = 0;
	
	public:
	inline CMyMatrix();
	CMyMatrix(int,int);

	int get_anzahl_zeile();
	int get_anzahl_spalte();

	inline CMyMatrix inverse();
	inline CMyVektor operator *(CMyVektor vector);
	inline CMyVektor& operator[](int index);
	inline friend std::ostream& operator <<(std::ostream& stream, CMyMatrix& matrix);
	/*friend CMyMatrix operator*=( CMyMatrix M, double value);*/
	
	
};
