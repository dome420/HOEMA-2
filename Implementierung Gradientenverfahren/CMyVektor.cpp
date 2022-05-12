#include "ClassVektor.h"

void CMyVektor::set_Dimension(int Dimension /* Aktuelle Dim*/)
{
    Vector.resize(Dimension);
}

int CMyVektor::get_dim()
{
    return  Vector.size();
}

double CMyVektor::get_length()
{
    double length = 0;
    for (unsigned i = 0; i < Vector.size(); i++)
    {
        length += pow(Vector[i], 2);
    }
    return sqrt(length);
}

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
CMyVektor CMyVektor::operator +(CMyVektor& b) {
    CMyVektor result = *this;
    if (this->get_dim() == b.get_dim()) {
        for (int i = 0; i < this->get_dim(); i++) {
            result[i] += b.Vector[i];
        }
        return result;
    }
    std::cout << "ERROR: Vektoren koennen nur addiert werden, wenn sie die gleiche Dimension haben." << std::endl;
    exit(-3);
}
CMyVektor CMyVektor::operator -(CMyVektor& b) {
    CMyVektor result = *this;
    if (this->get_dim() == b.get_dim()) {
        for (int i = 0; i < this->get_dim(); i++) {
            result[i] -= b.Vector[i];
        }
        return result;
    }
    std::cout << "ERROR: Vektoren koennen nur subtrahiert werden, wenn sie die gleiche Dimension haben." << std::endl;
    exit(-3);
}
CMyVektor CMyVektor::operator *(double lambda) {
    CMyVektor result = *this;
    for (unsigned i = 0; i < this->get_dim(); i++) {
        result[i] *= lambda;
    }
    return result;
}
CMyVektor CMyVektor::operator /(double lambda) {
    CMyVektor result = *this;
    for (unsigned i = 0; i < this->get_dim(); i++) {
        result[i] /= lambda;
    }
    return result;
}
inline CMyVektor gradient(CMyVektor x, double (*funktion)(CMyVektor x))
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

/*Vector , Funktionswertberechnung mit Vector x, lambda */
inline void gradientenverfahren(CMyVektor x, double (*funktion)(CMyVektor x), double lambda = 1.0, int schritt = 0)
{
    double fx = funktion(x); // Funktionswert mit Vector X

    //gradient berechnen
    CMyVektor grad_x(x.get_dim());
    grad_x = gradient(x, funktion); // Gradient an der stelle ...


    //double firststep = funktion(VectorStep);
    double gradlen = grad_x.get_length(); // Laenge des Gradienten
    if (gradlen < 1e-5)
    {
        cout << "Ende wegen ||grad f(x)||<1e-5 bei" << endl;
        cout << "\tlambda = " << lambda << endl;
        cout << "\tf(x) = " << fx << endl;
        cout << "\tgrad f(x) = " << grad_x << endl;
        cout << "\t||grad f(x)|| = " << gradlen << endl;
        return;
    }
    if (schritt == 25)
    {
        cout << "Ende wegen counter 25 bei" << endl;
        cout << "\tlambda = " << lambda << endl;
        cout << "\tf(x) = " << fx << endl;
        cout << "\tgrad f(x) = " << grad_x << endl;
        cout << "\t||grad f(x)|| = " << gradlen << endl;
        return;
    }
    else
    {
        /* Ausgabe der Aktuellen Werte*/
        cout << "Schritt: " << schritt << std::endl;
        cout << "\tx = " << x << endl;
        cout << "\tlambda = " << lambda << endl;
        cout << "\tf(x) = " << fx << endl; // ausgabe des Funktionswertes.
        cout << "\tgrad f(x) = " << grad_x << endl;
        cout << "\t||grad f(x)||" << grad_x.get_length() << endl << endl;

        // Berechnung des neuen Wertes P(X,Y) -> um ein schritt weiter zu gehen
        CMyVektor x_neu = ((grad_x * lambda) + x);
        cout << "\tx_neu = " << x_neu << endl;

        // Neuen Funktionswert neu berechnen 
        double fx_neu = funktion(x_neu);
        cout << "\tf(x_neu)= " << fx_neu << endl << endl;

        /*Ist der Funktionswert nach dem Testschritt von x_neu kleiner oder gleich dem aktuellen
        Funktionswert(fx), so halbiert man die Schrittweite. */
        double tmp = fx_neu;
        if (fx_neu <= fx)
        {
            while (tmp <= fx)
            {
                lambda /= 2;
                x_neu = ((grad_x * lambda) + x);
                tmp = funktion(x_neu);
                cout << "\tTest mit halbierter Schrittweite " << "(lambda = " << lambda << " ):" << endl;
                cout << "\tx_test = " << x_neu << endl;
                cout << "\tf(x_test) = " << tmp << endl;
            }
            schritt++;
            gradientenverfahren(x_neu, funktion, lambda, schritt);
        }
        else if (fx_neu > fx)
        {
            CMyVektor tmp_v = (((grad_x * lambda * 2)) + x);
            double fx_tmp_V = funktion(tmp_v);

            //lambda *= 2;
            cout << "\tTest mit doppelter Schrittweite " << "(lambda = " << lambda * 2 << " ):" << endl;
            cout << "\tx_test = " << tmp_v << endl;
            cout << "\tf(x_test) = " << fx_tmp_V << endl;
            if (fx_tmp_V <= fx_neu)
            {

                cout << "\tbehalte alte Schrittweite\n\n";
                schritt++;
                gradientenverfahren(x_neu, funktion, lambda, schritt);
            }
            else
            {
                schritt++;
                gradientenverfahren(tmp_v, funktion, lambda * 2, schritt);
            }

        }
    }
}