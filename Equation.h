#ifndef EQUATION_H
#define EQUATION_H

#include <string>

using namespace std;

class Equation{
	private:
	public:
		Equation();
		Equation(string);
		double findVal(double) const;
    double rightRAM(double, double, int) const;
    double leftRAM(double, double, int) const;
    double midRAM(double, double, int) const;
};

#endif
