#include <iostream>
#include <cmath>

using namespace std;

double f(double x1, double x2)
{
	return 2 * pow(x1, 2) + pow(x2, 2) + x1 * x2 + x1 + x2;
}

double dx1(double x1, double x2)
{
	return 4 * x1 + x2 + 1;
}

double dx2(double x1, double x2)
{
	return x1 + 2 * x2 + 1;
}

double funcMin(pair<double, double> x, pair<double, double> dk, double alpha)
{
	return f(x.first + alpha * dk.first, x.second + alpha * dk.second);
}


double dichotomy(double a, double b, const double E, pair<double, double> x1, pair<double, double> x2)
{
	const double delta = E / 10;

	double c = (a + b - delta) / 2;
	double d = (a + b + delta) / 2;

	while ((b - a) > 2 * E)
	{
		double fC = funcMin(x1, x2, c);
		double fD = funcMin(x1, x2, d);
		fC < fD ? b = d : a = c;
		c = (a + b - delta) / 2;
		d = (a + b + delta) / 2;
	}

	double alpha = (c + d) / 2;
	return alpha;
}

double norma(double x1, double x2)
{
	return sqrt(pow(x1, 2) + pow(x2, 2));
}

double Gradient(double x1, double x2, const double E)
{
	int k = 0;

	pair<double, double> dk = { -dx1(x1, x2), -dx2(x1, x2) };

	double px1 = x1;
	double px2 = x2;

	while (true)
	{
		double alpha = dichotomy(-1000, 1000, E / 10, { x1, x2 }, dk);
		x1 += alpha * dk.first;
		x2 += alpha * dk.second;

		if (norma(x1 - px1, x2 - px2) <= E)
		{
			break;
		}

		cout << "iter = " << (k + 1) << endl;
		cout << "[x1, x2] = [" << x1 << ", " << x2 << "]" << endl;
		cout << "f(x1, x2) = " << f(x1, x2) << endl;

		double bk = 0;
		if ((k + 1) % 2 != 0)
		{
			bk = norma(x1, x2) / norma(px1, px2);
		}

		dk.first = -dx1(x1, x2) + bk * dk.first;
		dk.second = -dx2(x1, x2) + bk * dk.second;

		px1 = x1;
		px2 = x2;

		k++;
	}
	return f(x1, x2);
}

int main()
{
	double x1 = 0;
	double x2 = 0;
	const double E = 0.5;

	cout << "GRADIENT METHOD" << endl;
	double res = Gradient(x1, x2, E);
	cout << "f(xmin) = " << res << endl;

	system("pause");
	return 0;
}