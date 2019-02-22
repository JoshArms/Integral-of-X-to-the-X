#include <iostream>
#include <string>
#include <cmath>
#include "Equation.h"

using std::cout;
using std::cin;
using std::endl;

const int PARTS = 10; //determines the amount of partitions for the approximation

int main(){
	//initializes variables
	Equation eq = Equation();
  double a = 0.0;
  double b = 0.0;
  double rram = 0.0;
	double lram = 0.0;
	double mram = 0.0;
  int multiplier = 1;

  cout << "This program will find the integral of X^(X) from point a to point b using " << PARTS << " partitions" <<endl;
  cout << "Enter a: ";
  cin >> a;
  cout << "Enter b: ";
  cin >> b;
  cout << endl;

  if(b==a){ //the integral is zero
    cout << "Invalid Input: a = b" <<endl;
    return 0;
  }else if(b<a){ //the algorithm doesn't work if a>b
								 //but the inetgral of f(x)dx from b to a = the negative inetgral of f(x)dx from a to b
								 //so if we multiple the answer by -1 and switch a and b, we will find the answer
    multiplier = -1;
    double temp = a;
    a = b;
    b = temp;
  }

  cout << "RRAM: ";
  rram = multiplier * eq.rightRAM(a,b,PARTS);
  cout << rram << endl;
  cout << "LRAM: ";
  lram = multiplier * eq.leftRAM(a,b,PARTS);
  cout << lram << endl;
  cout << "MRAM: ";
  mram = multiplier * eq.midRAM(a,b,PARTS);
  cout << mram << endl;

	double error = abs(rram - lram);

	cout << endl << "Maximum Error: " << error << endl;


	return 0;
}
