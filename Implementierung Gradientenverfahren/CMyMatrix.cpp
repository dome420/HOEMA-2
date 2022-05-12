#include "CMyMatrix.h"  /*Praktikum 2 Created By Dominique */

CMyMatrix::CMyMatrix()
{
}

inline CMyMatrix::CMyMatrix(int y,int x)
{
	y_pos = y;
	x_pos = x;
	Matrix.assign(y, CMyVektor(x));
}
inline int CMyMatrix::get_anzahl_zeile()
{
	return y_pos;
}
inline int CMyMatrix::get_anzahl_spalte()
{
	return x_pos;
}
inline CMyMatrix CMyMatrix::inverse()
{
	if (y_pos != 2 || x_pos != 2) {
		std::cout << "Diese Funktion ist nur fuer 2x2 Matrizen gedacht!\n";
		exit(-1);
	}

	double a = Matrix[0][0];
	double b = Matrix[0][1];
	double c = Matrix[1][0];
	double d = Matrix[1][1];

	double lambda = 1 / (a * d - b * c);

	CMyMatrix result(2, 2);

	result[0][0] = lambda * d;
	result[0][1] = lambda * b * (-1);
	result[1][0] = lambda * c * (-1);
	result[1][1] = lambda * a;

	return result;

}

CMyVektor CMyMatrix::operator *(CMyVektor vector) 
{
	if (get_anzahl_zeile() != vector.get_dim()) {
		std::cout << "\n\nUm Matrix*Vektor zu rechnen muessen die n Dim der Matrix und die Dimension des Vektors uebereinstimmen.\n\n";
		exit(-2);
	}

	CMyVektor result(get_anzahl_zeile());

	for (int i = 0; i < get_anzahl_zeile(); i++)
		for (int j = 0; j < get_anzahl_spalte(); j++)
			result[i] += (*this)[i][j] * vector[j];

	return result;
}
std::ostream& operator <<(std::ostream& stream, CMyMatrix& matrix) {
	for (int i = 0; i < matrix.get_anzahl_zeile(); i++)
		stream << "\t" << matrix[i] << std::endl;

	return stream;
}

CMyVektor& CMyMatrix::operator[](int index) 
{
	return Matrix[index];
}
inline CMyMatrix jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor pos)) {
	CMyVektor startPos = funktion(x);
	CMyMatrix result(startPos.get_dim(), x.get_dim());

	const double h = 1e-4;
	const double hNeu = (1 / h);

	for (int i = 0; i < x.get_dim(); i++) {
		CMyVektor tmp = x;
		tmp[i] += h;

		CMyVektor wackeln = funktion(tmp);
		CMyVektor ergebnisse = (wackeln - startPos) * hNeu;

		for (int j = 0; j < ergebnisse.get_dim(); j++) 
		{
			result[j][i] = ergebnisse[j];
		}
	}

	return result;
}
/* Das Newton-Verfahren kann auch benutzt werden, um Nullstellen von mehrdimensionalen Funktionen zu bestimmen */
inline void newton(CMyVektor x, CMyVektor(*funktion)(CMyVektor x),int counter = 0)
{
	CMyVektor tmp = x;
	CMyVektor fx = (funktion(tmp));
	CMyVektor dx;

	if (counter == 25) {
		std::cout << "Abbruch wegen counter == 25 : \n";
	}
	else if (dx.get_length() > 1e-5) {
		std::cout << "Abbruch wegen >1e-5\n";
	}
	std::cout << "Schritt: " << counter << std::endl;
	std::cout << "\tx = " << x << std::endl;
	std::cout << "\tf(x) = " << fx << std::endl;
	CMyMatrix fx_1 = jacobi(tmp, funktion);
	std::cout << "\tf'(x) = " << fx_1 << std::endl; // Matrix
	dx = fx_1.inverse() * fx;
	std::cout << "\t||f(x)|| = " << dx.get_length() << std::endl;
	newton(dx, funktion, counter++);
}
