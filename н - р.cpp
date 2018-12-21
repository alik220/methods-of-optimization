#include <iostream>
#include <cmath> 
#include <math.h>
#include <iomanip>
#include <stdio.h>
// H - P
using namespace std;

double f ( double );
double f ( double x )
{
	
return (pow(x,4))/3 + log(x) * x - 5 * x;

}

double f1 ( double x );
double f1 ( double x )
{
	return 4*pow(x,3)/3 + log(x) - 4;
}

double f2 ( double x );
double f2 ( double x )
{
	return 4*pow(x,2) + 1/x;
}

int main() {
	double x0, xk, eps, del, x, fa, fb, f1a, f1b;
	int n = 0;
	int iter = 0;
	eps = 0.02;
	del = 0.01;
	x0 = 1.5;
	

	xk = x0 - (f1(x0)/f2(x0));
	while ( abs( f1 (xk) ) > eps )
	{
		iter++;
		xk = x0 - (f1(x0)/f2 (x0));
		x0 = xk;
	}
	cout << "xmin = " << xk << endl;
	cout << "f(xmin) = " << f(xk) << endl << "iter = " << iter << endl;


	system("pause");
	return 0;
}