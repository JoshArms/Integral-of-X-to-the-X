#include "Equation.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Equation::Equation(){ }
//Function: findVal(double)
//Purpose: returns the value of the equation you are approximating
//					This makes it easy to change the equation if you would like to approxmate something else
//Parameters: value of x you would like to find
//returns: value if the Function at x
double Equation::findVal(double x) const{ return pow(x,x); }
//Function: rightRAM(double, double, int)
//Purpose: uses a RRAM to estimate the value of a given integral
//Parameters: double low: lower number to start the approximation at (x=a)
//						double high: higher number to end the approximation at (x=b)
//						int partitions: number of peices we will break it into for the approximation
//returns: approximation of the integral of X^(X) from low to high with partitions partitions
double Equation::rightRAM(double low,double high,int partitions) const{
	double add = (high-low)/((double)partitions);
	double i = low;
	double total = 0.0;
	while(i<high){
		double value = this->findVal(i);
		total+=(value);
		i+=add;
	}
	return ((total/partitions));
}
//Function: leftRAM(double, double, int)
//Purpose: uses a LRAM to estimate the value of a given integral
//Parameters: double low: lower number to start the approximation at (x=a)
//						double high: higher number to end the approximation at (x=b)
//						int partitions: number of peices we will break it into for the approximation
//returns: approximation of the integral of X^(X) from low to high with partitions partitions
double Equation::leftRAM(double low,double high,int partitions) const{
	double add = (high-low)/((double)partitions);
	double i = low+add;
	double total = 0.0;
	while(i<=high){
		double value = this->findVal(i);
		total+=(value);
		i+=add;
	}
	return ((total/partitions));
}
//Function: midRAM(double, double, int)
//Purpose: uses a MRAM to estimate the value of a given integral
//Parameters: double low: lower number to start the approximation at (x=a)
//						double high: higher number to end the approximation at (x=b)
//						int partitions: number of peices we will break it into for the approximation
//returns: approximation of the integral of X^(X) from low to high with partitions partitions
double Equation::midRAM(double low,double high,int partitions) const{
	double add = (high-low)/((double)partitions);
	double i = low+add;
	double total = 0.0;
	while(i<=high){
		double value = (this->findVal(i)+this->findVal(i+add));
		value = value/2;
		total+=(value);
		i+=add;
	}
	return ((total/partitions));
}
