#include <iostream>
#include <cmath> 
#include <math.h>
#include <iomanip>
#include <stdio.h>



using namespace std;

double f(double);
double f(double x)
{

	return (pow(x, 4)) / 3 + log(x) * x - 5 * x;

}

double f1(double x);
double f1(double x)
{
	return 4 * pow(x, 3) / 3 + log(x) - 4;
}

int main() {
	double x0, xk, eps, del, x, fa, fb, f1a, f1b;
	int n = 0;
	int iter = 0;

	eps = 0.02;
	del = 0.01;
	x0 = 1.5;
	x = 2;
	int i = 0;

	fa = f(x0);
	fb = f(x);
	f1a = f1(x0);
	f1b = f1(x);
	xk = x - (f1(x)* (x0 - x)) / (f1(x0) - f1(x));

	while (abs(xk - x) > eps)
	{
		xk = x - (f1(x)* (x0 - x)) / (f1(x0) - f1(x));
		x = xk;
		iter++;
	}
	cout << "xmin = " << xk << endl << "f(xmin) = " << f(xk) << endl;
	cout << "iter = " << iter << endl;
	
	system("pause");
	return 0;
}


