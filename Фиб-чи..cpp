#include <iostream>
#include <cmath> 
#include <math.h>
#include <iomanip>
#include <stdio.h>



using namespace std;

int Fib(int num)
{
	if (num == 1 || num == 2)
		return 1;
	else
		return Fib(num - 1) + Fib(num - 2);
}

double f1(double);
double f1(double x)
{

	return (pow(x, 4)) / 3 + log(x) * x - 5 * x;

}

int main() {
	double a, b, eps, del, c, d, fd, fc, xmin, xm;
	int n = 3;
	int iter = 2;
	eps = 0.02;
	del = 0.01;
	a = 1.5;
	b = 2;
	int i = 0;


	while (Fib(n) <= (11 * (b - a)) / 20 * eps)
	{
		n++;
	}
	//cout << n << endl << Fib (n) << endl;

	c = a + (b - a) * Fib(n + 1) / Fib(n + 3);
	c = round(c * 100) / 100;
	d = a + (b - a) * Fib(n + 2) / Fib(n + 3);
	d = round(d * 100) / 100;
	fc = f1(c);
	fc = round(fc * 100) / 100;
	fd = f1(d);
	fd = round(fd * 100) / 100;
	//cout << c << endl << d << endl;

		//for ( i; i <= n; i ++ )
	while (c != d)
	{
		iter++;
		i++;
		if (fc < fd)
		{
			b = d;
			d = c;
			c = a + (b - a) * Fib(n - i + 1) / Fib(n + 3 - i);
			c = round(c * 100) / 100;
			fd = fc;
			fc = f1(c);
			fc = round(fc * 100) / 100;

		}
		else
		{
			a = c;
			c = d;
			d = a + (b - a) * Fib(n + 2 - i) / Fib(n + 3 - i);
			d = round(d * 100) / 100;
			fc = fd;
			fd = f1(d);
			fd = round(fd * 100) / 100;
		}
		//cout << fc << endl << fd << endl;
	}
	xm = (a + b) / 2;
	cout << "xmin = " << xm << endl << "iter = " << iter << endl;
	
	
	
	
	
	
	
	
	
	
	/*if ( fc > fd )
	{
		a = c;
		b = d;
		xmin = ( a + b )/2;
	}

	if ( fc < fd )
	{
		a = a;
		b = d;
		xmin = ( a + b )/2;

	}
	xmin = round ( xmin * 100 ) / 100;
	cout << xmin << endl;*/



	system("pause");
	return 0;
}