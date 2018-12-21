#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

double f(double x)
{
	return 1 / 3 * pow(x, 4) - 5 * x + x * log(x);
}

/*pair<double, double> passiveSearch(double a, double b, const double E)
{
	int n = floor((b - a) / E) + 1;

	double pointArray[n];
	pointArray[0] = a;

	for (int i = 1; i < n; i++)
	{
		pointArray[i] = pointArray[i - 1] + E;
	}

	double minFunc = INT_MAX;

	int minFuncPoint = 0;

	for (int i = 0; i < n; i++)
	{
		double result = func(pointArray[i]);

		cout << "point = " << pointArray[i] << "\t function value = " << result << endl;

		if (result < minFunc)
		{
			minFunc = result;
			minFuncPoint++;
		}

		else
		{
			break;
		}
	}

	double resultPoint = pointArray[minFuncPoint - 1];
	return { resultPoint, func(resultPoint) };
}*/

pair<double, double> dichotomy (double a, double b, const double E)
{
	const double delta = 0.01;
	double c = (a + b - delta) / 2;
	double d = (a + b + delta) / 2;
	int iter;

	while ((b - a) > 2 * E)
	{
		iter++;
		double fC = f(c);
		double fD = f(d);
		cout << "c = " << c << "\t f(c) = " << fC << ", d = " << d << ' ' << "f(d) = " << fD << endl;
		fC < fD ? b = d : a = c;
		c = (a + b - delta) / 2;
		d = (a + b + delta) / 2;
		cout << "new c = " << c << "\t new d = " << d << endl;

	}

	double res = (a + b) / 2;
	return { res, f(res) };

}


pair<double, double> goldenSection (double a, double b, const double E)
{
	double c = a + (b - a) * (3 - sqrt(5)) / 2;
	double d = a + (b - a) * (sqrt(5) - 1) / 2;

	while (b - a > 2 * E)
	{
		double fC = f(c);
		double fD = f(d);
		cout << "c = " << c << " f(c) = " << fC << ", d = " << d << ' ' << "f(d) = " << fD << endl;
		if (fC < fD)
		{
			b = d;
			d = c;
			c = a + (b - a) * (3 - sqrt(5)) / 2;
		}
		if (fC >= fD)
		{
			a = c;
			c = d;
			d = a + b - c;
			d = a + (b - a) * (sqrt(5) - 1) / 2;
		}
		cout << "new c = " << c << "\t new d = " << d << endl;
	}

	double res = (a + b) / 2;
	return { res, f(res) };
}

using namespace std;

int main()
{
	const double E = 0.02;
	double a = 1.5;
	double b = 2;



	pair<double, double> dic = dichotomy(a, b, E);
	cout << "*****************************Dihotomy: xmin = " << dic.first << ", f(xmin) = " << dic.second << endl << endl;

	pair<double, double> gs = goldenSection(a, b, E);
	cout << "*****************************GoldenSection: xmin =  " << gs.first << ", f(xmin) = " << gs.second << endl << endl;

	system("pause");
	return 0;
}