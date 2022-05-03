#include "CMyMatrix.h"

CMyMatrix::CMyMatrix()
{
}

CMyMatrix::~CMyMatrix()
{
}

void CMyMatrix::set_MatrixDim(int x, int y)
{
	Matrix[x][y];  
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

CMyMatrix CMyMatrix::inverse(vector<vector<double>>)
{
	return CMyMatrix();
}

CMyVektor operator*(CMyMatrix& A,CMyVektor& x)
{
	CMyMatrix result;
	result.set_MatrixDim(A.get_MatrixDim());

	for (unsigned spalte = 0; spalte < x.get_dim();  spalte++)
	{
		for (unsigned zeile = 0; zeile < x.get_dim(); zeile++)
		{
			result[spalte][zeile] = A[spalte][zeile] * x[zeile];
		}
	}
	return result;
}
