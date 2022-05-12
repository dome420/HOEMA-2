#pragma once  /*Praktikum 1 Created By Dominique */
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
  

        //setter
        inline void set_Dimension(int Dimension /* Aktuelle Dim*/); // Set Dimension of a Vector
        //getter
        inline int get_dim(); // return vector size("dim")
        inline double get_length(); // return length of Vector with sqrt(pow(x[i],2)

      
        inline double& operator[](int index);
        inline friend std::ostream& operator<<(std::ostream& os, CMyVektor x);
        inline CMyVektor operator *(double lambda);
        inline CMyVektor operator +( CMyVektor& b);
        inline CMyVektor operator -( CMyVektor& b);
        inline CMyVektor operator /(double lambda);
        
    };


