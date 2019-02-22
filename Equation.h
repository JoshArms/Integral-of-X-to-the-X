//header file for Equation.cpp
#ifndef EQUATION_H
#define EQUATION_H

#include <string>

using namespace std;

class Equation{
	private:
		double findVal(double) const;
	public:
		Equation();
    double rightRAM(double, double, int) const;
    double leftRAM(double, double, int) const;
    double midRAM(double, double, int) const;
};

#endif
