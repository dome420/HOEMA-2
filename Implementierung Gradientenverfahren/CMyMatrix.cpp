#include "CMyMatrix.h"

CMyMatrix::CMyMatrix()
{
}

CMyMatrix::CMyMatrix(int y)
{
	y_pos = y;
	Matrix.assign(y, CMyVektor());
}
void CMyMatrix::set_MatrixDim(int x, int y)
{
	x_pos = x,
	y_pos = y;
	Matrix.assign(y_pos, x_pos);
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
int det(CMyMatrix& x) // 2x2 Matrix
{
	int det = 0;
	det = x.get_Matrix_Value(0,0) * x.get_Matrix_Value(1, 1);
	det -= x.get_Matrix_Value(1,0) * x.get_Matrix_Value(0,1);
	return det;
}
CMyMatrix jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor x))
{

}