#pragma once
#include <vector>

    class CMyVektor
    {
    private:
        /* data */
        int Dimension = 0, Value = 0, key = 0;
        std::vector<double>Vector;
    public:
        CMyVektor();
        ~CMyVektor();

        //Public Method
        void set_Dimension(int Dimension /* Aktuelle Dim*/);
        void set_specified_Value(int index, int Value);
        double get_specified_Value(int key);
        int get_length_Vector();
        double& operator [](int index);
    };


    CMyVektor::CMyVektor(/* args */){}

    CMyVektor::~CMyVektor(){}

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
int CMyVektor::get_length_Vector()
{
    return Vector.size();
};

double& CMyVektor::operator [](int index)
{
    return Vector[index];
}