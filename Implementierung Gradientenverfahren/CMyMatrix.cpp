#include "CMyMatrix.h"  /*Praktikum 2 Created By Dominique */

CMyMatrix::CMyMatrix()
{
}

CMyMatrix::CMyMatrix(int y,int x)
{
	y_pos = y;
	x_pos = x;
	Matrix.assign(y, CMyVektor(x));
}
void CMyMatrix::set_MatrixDim(int x, int y)
{
	Matrix.resize(x * y);
}
int CMyMatrix::get_MatrixDim()
{
	return Matrix.size();
}

void CMyMatrix::set_Matrix_Value(double Value, int position_x, int position_y)
{
	Matrix[position_x][position_y] = Value;
}

int CMyMatrix::get_Matrix_Value(int position_x, int position_y)
{
	return Matrix[position_x][position_y];
}
int CMyMatrix::get_zeile()
{
	return y_pos;
}
int CMyMatrix::get_spalte()
{
	return x_pos;
}
CMyMatrix inverse(CMyMatrix& mx)
{
	CMyMatrix result;
	result.set_MatrixDim(2, 2);
	if (mx.get_zeile() == 2 && mx.get_zeile() == 2) { // Prüfung auf Quadratische Matrize M=N
	/// ///////
		result.set_Matrix_Value(mx.get_Matrix_Value(1, 1), 0, 0);
		result.set_Matrix_Value((-1) * mx.get_Matrix_Value(0, 1), 0, 1);
		result.set_Matrix_Value((-1) * mx.get_Matrix_Value(1, 0), 1, 0);
		result.set_Matrix_Value(mx.get_Matrix_Value(0, 0), 1, 1);

		int det_ = mx.det();

		return ((1.0 / mx.det()) * result);
	}
	else
	{
		throw std::runtime_error("Hat nicht die gleichen anzahl an Zeilen wie Spalten. Somit nicht Quadratisch.\n");
	}

}

CMyVektor operator*(CMyMatrix A,CMyVektor x)
{
	CMyVektor result;
	for (unsigned spalte = 0; spalte < x.get_dim();  spalte++)
	{
		for (unsigned zeile = 0; zeile < A.get_MatrixDim(); zeile++)
		{
			result[zeile] += A.get_Matrix_Value(spalte,zeile) * x[zeile];
		}
	}
	return result;
}
/*
* |a b |
* |c d |
* -->  a*d-c*b
*/
double CMyMatrix::det() // 2x2 Matrix   
{
	int det = 0;

	det = this->get_Matrix_Value(0,0) * this->get_Matrix_Value(1, 1);
	det -= this->get_Matrix_Value(1,0) * this->get_Matrix_Value(0,1);
	return det;
}

/// //
CMyMatrix operator*(double value, CMyMatrix& M)
{
	for (size_t y = 0; y < M.get_spalte(); y++)
	{
		for (size_t x = 0; x < M.get_zeile(); x++)
		{
			
			M.set_Matrix_Value(M.get_Matrix_Value(x, y) * value, x, y);
		}
	}
	return M;
} 
CMyMatrix jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor x),const double h = 1e-4)
{
	
		CMyMatrix result;
		result.set_MatrixDim(2, 2);

		for (unsigned y = 0; y < 2; y++)
		{
			CMyVektor xtmp;
			xtmp = x;
			for (size_t x = 0; x < 2; x++)
			{
				
				xtmp[x] += h;

				double tmp = ((funktion(xtmp) - fx) / h);

				result[i] = tmp;
			}
			
		}
		return result;
}
