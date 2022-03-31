#pragma once
#include <vector>

    class CMyVektor
    {
    private:
        /* data */
        int Dimension = 0, Value = 0, key = 0;
        std::vector<double>V;

    public:
        CMyVektor();
        ~CMyVektor();

        //Public Method
        int creat_Dimension(int x) {};
        int set_specified_Value(int x) {};
        int get_specified_Value(int x) {};
        int get_length_Vector(const std::vector<double>& V) {};
    };


    CMyVektor::CMyVektor(/* args */){}

    CMyVektor::~CMyVektor(){}

void creat_Dimension(int x)
{
    if (x > Dimension)
    {
        Dimension = x;
        V.resize(Dimension);
    }
};
void set_specified_Value(const vector<double>& V, int key, int Value)
{

};
double get_specified_Value(const vector<double> &V ,int key)
{
    // vom intervall anfang - ende des Vectors
    if (std::count(V.begin(), V.end(), key))
    {
    }
};
int get_length_Vector(const std::vector<double>& V)
{

};