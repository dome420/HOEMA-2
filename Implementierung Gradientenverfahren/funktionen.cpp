#include <iostream>
#include <math.h>

#include "funktionen.h"
#include "CMyMatrix.h"

CMyVektor function(CMyVektor pos) {
    if (pos.getDim() != 4) {
        std::cout << "Funktion akzeptiert nur 4D Vektoren.\n";
        exit(-2);
    }

    CMyVektor result(3);
    result[0] = pos[0] * pos[1] * exp(pos[2]);
    result[1] = pos[1] * pos[2] * pos[3];
    result[2] = pos[3];

    return result;
}

CMyVektor gradient(CMyVektor x, double(*funktion)(CMyVektor pos)) {
    CMyVektor grad(x.getDim());
    grad = x;
    double h = 1e-4;
    double funktionX = funktion(x);

    for (int i = 0; i < x.getDim(); i++) {
        CMyVektor gradTmp = x;
        gradTmp[i] += h;

        double tmp = (funktion(gradTmp) - funktionX) / h;
        grad[i] = tmp;
    }
    return grad;
}

CMyMatrix jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor pos)) {
    CMyVektor startPos = funktion(x);
    CMyMatrix result(startPos.getDim(), x.getDim());

    const double h = 1e-4;
    const double hNeu = (1 / h);

    for (int i = 0; i < x.getDim(); i++) {
        CMyVektor tmp = x;
        tmp[i] += h;

        CMyVektor wackeln = funktion(tmp);
        CMyVektor ergebnisse = (wackeln - startPos) * hNeu;

        for (int j = 0; j < ergebnisse.getDim(); j++) {
            result[j][i] = ergebnisse[j];
        }
    }

    return result;
}

CMyVektor functionJacobi(CMyVektor pos) {
    CMyVektor result(2);

    result[0] = pow(pos[0], 3) * pow(pos[1], 3) - (pos[1] * 2);
    result[1] = pos[0] - 2;

    return result;
}

CMyVektor newtonverfahren(CMyVektor x, CMyVektor (*funktion)(CMyVektor pos), int counter = 0) {
    CMyMatrix jacobiX = jacobi(x, funktion);

    if (jacobiX.getM() != 2 || jacobiX.getN() != 2) {
        std::cout << "Diese Funktion kann nur mit 2x2 Matrizen rechnen.\n";
        exit(-4);
    }

    CMyVektor funktionswertX = funktion(x);

    CMyMatrix jacobiInvers = jacobiX.invers();
    CMyVektor deltaX = jacobiInvers * (funktionswertX * (-1));

    CMyVektor newX = x + deltaX;
    CMyVektor funktionswertNewX = funktion(newX);

    if (funktionswertX.getLength() < 1e-5) {
        std::cout << std::endl;
        std::cout << "Ende wegen ||f(x)|| < 1e-5 bei:\n";
        std::cout << "\tx = " << x << std::endl;
        std::cout << "\tf(x) = " << funktionswertX << std::endl;
        std::cout << "\t||f(x)|| = " << funktionswertX.getLength() << std::endl;
        exit(0);
    }

    if (counter == 50) {
        std::cout << std::endl;
        std::cout << "Ende wegen Schrittzahl = 50 bei:\n";
        std::cout << "\tx = " << x << std::endl;
        std::cout << "\tf(x) = " << funktionswertX << std::endl;
        std::cout << "\t||f(x)|| = " << funktionswertX.getLength() << std::endl;
        exit(0);
    }

    std::cout << std::endl;
    std::cout << "Schritt " << counter << ":\n";
    std::cout << "\tx = " << x << std::endl;
    std::cout << "\tf(x) = " << funktionswertX << std::endl;
    std::cout << "\tf'(x) =\n" << jacobiX << std::endl;
    std::cout << "\t(f'(x))^(-1) =\n" << jacobiInvers << std::endl;
    std::cout << "\tdx = " << deltaX << std::endl;
    std::cout << "\t||f(x)|| = " << funktionswertX.getLength() << std::endl;

    newtonverfahren(newX, funktion, ++counter);
}