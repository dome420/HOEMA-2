#pragma once
#include "ClassVektor.h"

class C_DGLSolver
{
public:
	// Default
	C_DGLSolver();
	// f_DGL_System
	 C_DGLSolver(int Ordnung, CMyVektor(*f_DGL_System)(CMyVektor y, double x));
	//F_DGL_nterOrdnung
	 C_DGLSolver(int Ordnung, double (*f_DGL_nterOrdnung)(CMyVektor y, double x));
	~C_DGLSolver();

private:
	int Anzahl_Ordnung;

	CMyVektor(*f_DGL_System)(CMyVektor y, double x);
	double (*f_DGL_nterOrdnung)(CMyVektor y, double x);

	CMyVektor ableitungen(CMyVektor y, double x);// A2



};

