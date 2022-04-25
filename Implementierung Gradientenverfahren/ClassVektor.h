#pragma once
#include <vector>

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
        double get_length(CMyVektor& x); // return length of Vector with sqrt(pow(x[i],2)
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

// (2) Dimension bestimmen können
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
double get_length(CMyVektor& x)
{
    double length = 0;
    for (unsigned i = 0; i < x.get_dim(); i++)
    {
       length += pow(x[i], 2);
    }
    return sqrt(length);
}

double& CMyVektor::operator[](int index)
{
    return Vector[index];
}
std::ostream& operator<<(std::ostream& os, CMyVektor x)
{
    os << "(";
    for (size_t i = 0; i < x.get_dim(); i++) {
        os << x[i];
        if (i != x.Vector.size() - 1) {
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
CMyVektor gradientenverfahren(CMyVektor x, double (*funktion)(CMyVektor x), double lambda) 
{
    for (int i = 0; i < 25; i++) 
    {
        double fx = funktion(x);
        //gradient berechnen
        CMyVektor grad(x.get_dim());
        grad = gradient(x, funktion);

        double stepValue = funktion((x + (lambda*grad)));

        if (stepValue <= fx) 
        {
           
        }
        else if (stepValue > fx) 
        {

        }
        else
        {

        }


    }
}