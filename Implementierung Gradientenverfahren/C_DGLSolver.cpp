#include "C_DGLSolver.h"
#include "ClassVektor.h"

// CMyVektor(*f DGL System)(CMyVektor y, double x)   -> Funktion, die die rechte Seite eines DGL-Systems repraesentiert 
// double (*f DGL nterOrdnung)(CMyVektor y, double x) ->  Funktion, die eine DGL hoeherer Ordnung repraesentiert

C_DGLSolver::C_DGLSolver()
{
}
// f_DGL_System Constructor
inline C_DGLSolver::C_DGLSolver(int Ordnung, CMyVektor(*f_DGL_System)(CMyVektor y, double x))
{
	Anzahl_Ordnung = Ordnung;

}
//F_DGL_nterOrdnung
inline C_DGLSolver::C_DGLSolver(int Ordnung, double (*f_DGL_nterOrdnung)(CMyVektor y, double x)) 
{
	Anzahl_Ordnung = Ordnung;
}
C_DGLSolver::~C_DGLSolver()
{
}

CMyVektor C_DGLSolver::ableitungen(CMyVektor y, double x)
{
	C_DGLSolver DGL;
	if (Anzahl_Ordnung == 1)
	{
		CMyVektor tmp = DGL.f_DGL_System(y, x);
	}
	else if (Anzahl_Ordnung > 1) {
		CMyVektor tmp = DGL.f_DGL_nterOrdnung(y, x);
	}
	
	/* Bedingungen 
	*/
	return CMyVektor();
}
