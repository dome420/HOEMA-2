#pragma once
#include <vector>
#include <iostream>

    class CMyVektor
    {
    private:
        /* data */
        std::vector<double>Vector;
        
    public:
        // Constructor & Destructor
        CMyVektor()
        {
            Vector.assign(1, 0.0);
        };
        CMyVektor(int dimension, double wert = 0.0)
        {
            Vector.assign(dimension, wert);
        }
        ~CMyVektor();

        //setter
        void set_Dimension(int Dimension /* Aktuelle Dim*/); // Set Dimension of a Vector
        void set_specified_Value(int index, double Value); // overwrites a new value at a specific index
        //getter
        size_t get_dim(); // return vector size("dim")
        double get_specified_Value(int key); // return value at a specific index
        double get_length(); // return length of Vector with sqrt(pow(x[i],2)
        //überladungen
        double& operator[](int index);
        friend std::ostream& operator<<(std::ostream& os, CMyVektor x);
        friend CMyVektor operator*(double lambda, CMyVektor& x);
        //CMyVektor operator=(CMyVektor& a);
    };
  
    CMyVektor::~CMyVektor()
    {
        Vector.clear();
    }


void CMyVektor::set_Dimension(int Dimension /* Aktuelle Dim*/)
{
        Vector.resize(Dimension);
};

void CMyVektor::set_specified_Value(int index, double Value)
{
        Vector[index] = Value;
};

double CMyVektor::get_specified_Value(int key)
{
    // vom intervall anfang - ende des Vectors
    for (unsigned i = 0; i < Vector.size(); i++)
    {
        if (Vector[i] == key) {
            return Vector[i];
        }
    }
};

size_t CMyVektor::get_dim() 
{
   return  Vector.size();
};

double CMyVektor::get_length()
{
    double length = 0;
    for (unsigned i = 0; i < Vector.size(); i++)
    {
       length += pow(Vector[i], 2);
    }
    return sqrt(length);
}

#include "ClassVektor.h"


using namespace std;

double& CMyVektor::operator[](int index)
{
    return Vector[index];
}
std::ostream& operator<<(std::ostream& os, CMyVektor x)
{
    os << "(";
    for (int i = 0; i < x.get_dim(); i++) {
        os << x[i];
        if (i != x.get_dim() - 1) {
            os << ";";
        }
    }
    os << ")";
    return os;
}
CMyVektor operator+(CMyVektor a, CMyVektor b)
{
    CMyVektor c;
    c.set_Dimension(a.get_dim());
    // The dimension of the vector should be the same
    if (a.get_dim() == b.get_dim())
    {
        for (size_t i = 0; i < a.get_dim(); i++) {
            c[i] = a[i] + b[i];
        }
    }
    return c;
}
CMyVektor operator*(double lambda, CMyVektor& x)
{
    for (unsigned i = 0; i < x.get_dim(); i++)
    {
        x[i] *= lambda;
    }
    return x;
}

CMyVektor gradient(CMyVektor x, double (*funktion)(CMyVektor x))
{
    CMyVektor result;
    result.set_Dimension(x.get_dim());
    double h = 1e-8;
    double fx = funktion(x);

    for (unsigned i = 0; i < x.get_dim(); i++)
    {
        CMyVektor xtmp;
        xtmp.set_Dimension(x.get_dim());
        xtmp = x;
        xtmp[i] += h;

        double tmp = ((funktion(xtmp) - fx) / h);

        result[i] = tmp;
    }
    return result;
}

/// Berechnung muss überschaut werde.
/*Vector , Funktionswertberechnung mit Vector x, lambda */
void gradientenverfahren(CMyVektor x, double (*funktion)(CMyVektor x), double lambda = 1.0, int schritt = 0)
{
    double fx = funktion(x); // Funktionswert mit Vector X

    //gradient berechnen
    CMyVektor grad_x(x.get_dim());
    grad_x = gradient(x, funktion); // Gradient an der stelle ...

   
    //double firststep = funktion(VectorStep);
    double gradlen = grad_x.get_length(); // Laenge des Gradienten
   //Ausgabe
   // 2 ifs
    if (schritt == 25)
    {
        cout << "Ende wegen counter 25 bei" << endl;
        cout << "\tlambda = " << lambda << endl;
        cout << "\tf(x) = " << fx << endl;
        cout << "\tgrad f(x) = " << grad_x << endl;
        cout << "\t||grad f(x)|| = " << gradlen<< endl ;
        return;
    }
    if (gradlen < 1e-5)
    {
        cout << "Ende wegen ||grad f(x)||<1e-5 bei" << endl;
        cout << "\tlambda = " << lambda << endl;
        cout << "\tf(x) = " << fx << endl;
        cout << "\tgrad f(x) = " << grad_x << endl;
        cout << "\t||grad f(x)|| = " << gradlen << endl;
        return;
    }
        /* Ausgabe der Aktuellen Werte*/
        cout << "Schritt: " << schritt << std::endl;
        cout << "\tx = " << x << endl;
        cout << "\tlambda = " << lambda << endl;
        cout << "\tf(x) = " << fx << endl; // ausgabe des Funktionswertes.
        cout << "\tgrad f(x) = " << grad_x << endl;
        cout << "\t||grad f(x)||" << grad_x.get_length() << endl << endl;

        // Berechnung des neuen Wertes P(X,Y) -> um ein schritt weiter zu gehen
        CMyVektor x_neu = (x + (lambda * grad_x));
        cout << "\tx_neu = " << x_neu << endl;

        // Neuen Funktionswert neu berechnen 
        double fx_neu = funktion(x_neu);
        cout << "\tf(x_neu)= " << fx_neu << endl<<endl;

        /*Ist der Funktionswert nach dem Testschritt von x_neu kleiner oder gleich dem aktuellen
        Funktionswert(fx), so halbiert man die Schrittweite. */
        if (fx_neu <= fx) 
        {
            lambda /= 2;
            cout << "\tTest mit halbierter Schrittweite " << "(lambda = " << lambda << " ):" << endl;
            CMyVektor x_test = (x + (lambda * grad_x));
            cout << "\tx_test = " << x_test << endl;
            double fx_test = funktion(x_test);
            cout << "\tf(x_test) = " << fx_test << endl;
            if (fx_test > fx_neu) {
                //
                fx = fx_test; 
                x = x_test;
                cout << "\tbehalte alte Schrittweite\n\n";
            }
            schritt++;
            gradientenverfahren(x, funktion, lambda, schritt);

        }
        else if (fx_neu > fx) 
        {

            lambda *= 2;
            cout << "\tTest mit doppelter Schrittweite " << "(lambda = " << lambda << " ):" << endl;
            CMyVektor x_test = (x + (lambda * grad_x));
            cout << "\tx_test = " << x_test << endl;
            double fx_test = funktion(x_test);
            cout << "\tf(x_test) = " << fx_test << endl;

            if (fx_test < fx_neu) {
                fx = fx_neu;
                x = x_neu;
                lambda /= 2;
                cout << "\tbehalte alte Schrittweite\n\n";
            }
            schritt++;
            gradientenverfahren(x, funktion, lambda, schritt);
        }
        schritt++;
    
}