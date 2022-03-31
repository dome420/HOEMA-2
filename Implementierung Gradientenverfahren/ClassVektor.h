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
        int creat_Dimension(vector<double> &V, int Dimension, int x){};
        int set_specified_Value(vector<double> &V, int key, int Value){};
        int get_specified_Value(int x) {};
        int get_length_Vector(const std::vector<double>& V) {};
    };


    CMyVektor::CMyVektor(/* args */){}

    CMyVektor::~CMyVektor(){}

// (2) Dimension bestimmen können
void creat_Dimension(int Dimension_x)
{
    if (Dimension < V.size())
    {
        Dimension = x;
        V.resize(Dimension);
    }
};
void set_specified_Value(vector<double> &V, int key, int Value)
{
        V[key] = Value;
};
double get_specified_Value(const vector<double> &V ,int key)
{
    // vom intervall anfang - ende des Vectors
    return V[key];
};
int get_length_Vector(const std::vector<double> &V)
{
    return V.size();
};