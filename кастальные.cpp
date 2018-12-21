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
	double a, b, eps, del, c, d, fd, fc, fa, fb, f1a, f1b, f1c, f1d;
	int n = 0;
	int iter = 0;
	eps = 0.02;
	del = 0.01;
	a = 1.5;
	b = 2;
	int i = 0;
	fa = f(a);
	fb = f(b);
	f1a = f1(a);
	f1b = f1(b);
	c = (fb - fa + a * f1a - b * f1b) / (f1a - f1b);


	//cout << f1a << endl << f1b;
	if (f1(a) * f1(b) < 0)
	{
		while (abs(fb - fa) > eps)
		{
			iter++;
			if (f1(c) > 0)
			{
				b = c;
				fb = f(c);
				f1b = f1(c);
				c = (fb - fa + a * f1a - b * f1b) / (f1a - f1b);
			}
			else
			{
				if (f(c) < 0)
				{
					a = c;
					fa = f(c);
					f1a = f1(c);
					c = (fb - fa + a * f1a - b * f1b) / (f1a - f1b);
					f1c = f1(c);
				}
				// (f(c) = 0)
			}
		}

		cout << "xmin =  " << c << endl;
		cout << "fmin = " << f(c) << endl;
	}
	else
	{
		if (f1(a) < f1(b))
		{
			cout << "xmin =  " << a << endl;
			cout << "fmin = " << f(a) << endl;
		}
		if (f1(a) > f1(b))
		{
			cout << "xmin =  " << b << endl;
			cout << "fmin = " << f(b) << endl;
		}
	}
	cout << "iter = " << iter << endl;


	system("pause");
	return 0;
}