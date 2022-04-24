#pragma once
#include <vector>

    class CMyVektor
    {
    private:
        /* data */
        std::vector<double>Vector;
    public:
        // Constructor & Destructor
        CMyVektor();
        ~CMyVektor();

        //setter
        void set_Dimension(int Dimension /* Aktuelle Dim*/); // Set Dimension of a Vector
        void set_specified_Value(int index, int Value); // overwrites a new value at a specific index
        //getter
        int get_dimension() { return Vector.size();}; // return vector size("dim")
        double get_specified_Value(int key); // return value at a specific index
        int get_dim(); // return Vector size ("dim")
        double get_length(CMyVektor& x); // return length of Vector with sqrt(pow(x[i],2)
        //überladungen
        double& operator [](int index);
        friend std::ostream& operator<<(std::ostream& os, CMyVektor x);
     
    };


    CMyVektor::CMyVektor()
    {
        Vector.assign(1, 0.0);
    }
  
    CMyVektor::~CMyVektor()
    {
        Vector.clear();
    }

// (2) Dimension bestimmen können
void CMyVektor::set_Dimension(int Dimension /* Aktuelle Dim*/)
{
        Vector.resize(Dimension);
};
void CMyVektor::set_specified_Value(int index, int Value)
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
double get_length(CMyVektor& x)
{
    double length = 0;
    for (unsigned i = 0; i < x.get_dim(); i++)
    {
       length += pow(x[i], 2);
    }
    return sqrt(length);
}
int CMyVektor::get_dim()
{
    return Vector.size();
};

double& CMyVektor::operator [](int index)
{
    return Vector[index];
}
std::ostream& operator<<(std::ostream& os, CMyVektor x)
{
    os << "(";
    for (size_t i = 0; i < x.get_dimension(); i++) {
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
    int ai = 0, bi = 0;
    int counter = 0;
    CMyVektor c;
    c.set_Dimension(a.get_dim());
    // The dimension of the vector should be the same
    if (a.get_dim() == b.get_dim())
    {
        while (counter < a.get_dim())
        {
            c[counter] = a[ai] + b[bi];
            counter++;
            ai++;
            bi++;
        }
        return c;
    }
}
CMyVektor operator*(double lambda, CMyVektor a)
{
    CMyVektor c;
    c.set_Dimension(a.get_dim());
    for (unsigned i = 0; i < a.get_dim(); i++)
    {
        c[i] += lambda * a[i];
    }
    return c;
}