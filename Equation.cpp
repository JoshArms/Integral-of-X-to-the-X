#include "Equation.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Equation::Equation(){ }

double Equation::findVal(double x) const{ return pow(x,x); }

//uses a RRAM to estimate the value of a given integral
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

//uses a LRAM to estimate the value of a given integral
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

//uses a MRAM to estimate the value of a given integral
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
