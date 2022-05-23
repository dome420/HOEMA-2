#include "C_DGLSolver.h"
#include "ClassVektor.h"

// CMyVektor(*f DGL System)(CMyVektor y, double x)   -> Funktion, die die rechte Seite eines DGL-Systems repraesentiert 
// double (*f DGL nterOrdnung)(CMyVektor y, double x) ->  Funktion, die eine DGL hoeherer Ordnung repraesentiert

C_DGLSolver::C_DGLSolver()
{
}
// f_DGL_System Constructor
inline C_DGLSolver::C_DGLSolver(bool Ordnung, CMyVektor(*f_DGL_System)(CMyVektor y, double x))
{
	if (Ordnung == false) {
		Anzahl_Ordnung = Ordnung;
	}

}
//F_DGL_nterOrdnung
inline C_DGLSolver::C_DGLSolver(bool Ordnung, double (*f_DGL_nterOrdnung)(CMyVektor y, double x)) 
{
	if (Ordnung) {
		Anzahl_Ordnung = Ordnung;
	}
}
C_DGLSolver::~C_DGLSolver()
{
}

CMyVektor C_DGLSolver::ableitung_visibell(CMyVektor y, double x)
{
	return ableitungen(y,x);
}

CMyVektor C_DGLSolver::ableitungen(CMyVektor y, double x)
{
	C_DGLSolver DGL;
	CMyVektor result;

	if (Anzahl_Ordnung == 0)
	{
		result = DGL.f_DGL_System(y, x);
	}
	else{
		result =DGL.f_DGL_nterOrdnung(y, x);
	}
	
	return result;
}