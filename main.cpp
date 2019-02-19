#include <iostream>
#include <string>
#include <cmath>
#include "Equation.h"

using std::cout;
using std::cin;
using std::endl;

const int PARTS = 10;

int main(){
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

  if(b==a){
    cout << "Invalid Input: a = b" <<endl;
    return 0;
  }else if(b<a){
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
