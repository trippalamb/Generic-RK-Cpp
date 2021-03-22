// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RK.h"
#include "Pendulum.h"

using namespace GenericRK;
using namespace BasicODESystems;

int main()
{
    double p0 = -71975.2875240052;
    double v0 = -28118.9977611020;
    double startTime = 0.0;
    double endTime = 20.0;

    RKConfig config(RKMethods::CashKarp, 1.0e-4, 1.0, 1.0e-4, 0.9);
    Pendulum pendulum(startTime, p0, v0, config);
    pendulum.timestep(endTime);

    double* output = pendulum.getState();
    double* correct = pendulum.solution(endTime);

    cout << output[0] << " " << output[1] << " " << output[2] << " " << output[3] << "\n";
    cout << correct[0] << " " << correct[1] << " " << correct[2] << " " << correct[3] << "\n";

}

