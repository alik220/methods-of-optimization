#include <iostream>
#include <cmath>

using namespace std;

double f(double x1, double x2)
{
	return 2*pow(x1,2) + pow(x2, 2) + x1*x2 + x1 + x2;
}

double dx1(double x1, double x2)
{
	return 4 * x1 + x2 + 1;
}

double dx2(double x1, double x2)
{
	return x1 + 2*x2 + 1;
}

double norma(double x1, double x2)
{
	return sqrt(pow(x1, 2) + pow(x2, 2));
}

double funcMin1(double x1, double x2, double alpha) //îäíîìåð-ÿ
{
	return f(x1 - alpha * dx1(x1, x2), x2 - alpha * dx2(x1, x2));
}

double funcMin2(pair<double, double> x, pair<double, double> y, double alpha)
{
	return f(x.first + alpha * (y.first - x.first), x.second + alpha * (y.second - x.second));
}

double dichotomy1(double a, double b, const double E, double x1, double x2)
{
	const double delta = E / 10;
	double c = (a + b - delta) / 2;
	double d = (a + b + delta) / 2;

	while (b - a > 2 * E)
	{
		double fC = funcMin1(x1, x2, c);
		double fD = funcMin1(x1, x2, d);
		fC < fD ? b = d : a = c;
		c = (a + b - delta) / 2;
		d = (a + b + delta) / 2;
	}

	double res = (a + b) / 2;
	return res;
}

double dichotomy2(double a, double b, const double E, pair<double, double> x, pair<double, double> y)
{
	const double delta = E / 100;
	double c = (a + b - delta) / 2;
	double d = (a + b + delta) / 2;

	while (b - a > 2 * E)
	{
		double fC = funcMin2(x, y, c);
		double fD = funcMin2(x, y, d);
		fC < fD ? b = d : a = c;
		c = (a + b - delta) / 2;
		d = (a + b + delta) / 2;
	}

	return (c + d) / 2;
}

pair<double, double> TwoIter(double x01, double x02, double eps)
{
	double x1 = x01;
	double x2 = x02;

	double px1 = x1;
	double px2 = x2;

	for (int i = 0; i < 2; i++)
	{
		double alpha = dichotomy1 (-1000, 1000, eps / 1000, x1, x2);
		x1 -= alpha * dx1(px1, px2);
		x2 -= alpha * dx2(px1, px2);

		if (norma(x1 - px1, x2 - px2) < eps)
		{
			break;
		}

		px1 = x1;
		px2 = x2;
	}


	return { x1, x2 };
}

pair<double, double> OneIter(double x01, double x02, double eps)
{
	double x1 = x01;
	double x2 = x02;

	double px1 = x1;
	double px2 = x2;

	for (int i = 0; i < 1; i++)
	{
		double alpha = dichotomy1(-1000, 1000, eps / 1000, x1, x2);
		x1 -= alpha * dx1(px1, px2);
		x2 -= alpha * dx2(px1, px2);

		if (norma(x1 - px1, x2 - px2) < eps)
		{
			break;
		}

		px1 = x1;
		px2 = x2;
	}
	return { x1, x2 };
}

double fastGradient(double x01, double x02, const double E)
{
	double x1 = x01;
	double x2 = x02;

	int it = 1;

	while (true)
	{
		pair<double, double> yk = TwoIter (x1, x2, E / 10);
		pair<double, double> Y0minusX0 = { yk.first - x1, yk.second - x2 };
		double optAlpha = dichotomy2 (-1000, 1000, E / 10, { x1, x2 }, { yk.first, yk.second });

		x1 += Y0minusX0.first * optAlpha;
		x2 += Y0minusX0.second * optAlpha;

		cout << "it = " << it++ << endl;
		cout << "[y1, y2] = [" << yk.first << ", " << yk.second << "]" << endl;
		cout << "[x1, x2] = [" << x1 << ", " << x2 << "]" << endl;
		cout << "[yk - xk] = [" << (Y0minusX0.first - x1) << ", " << (Y0minusX0.second - x2) << "]" << endl;
		cout << "f(x1, x2) = " << f(x1, x2) << endl;

		if (norma(dx1(x1, x2), dx2(x1, x2)) <= E)
		{
			break;
		}
	}
	return f(x1, x2);
}

double ovragMethod(double x1, double x2, const double E)
{
	int it = 1;

	while (true)
	{
		double xVolna1 = x1 * 1.1;
		double xVolna2 = x2 * 1.1;

		pair<double, double> y = OneIter(x1, x2, E / 10);
		pair<double, double> yVolna = OneIter(xVolna1, xVolna2, E / 10);

		double optAlpha = dichotomy2(-1000, 1000, E / 100, y, yVolna);

		x1 = y.first + optAlpha * (yVolna.first - y.first);
		x2 = y.second + optAlpha * (yVolna.second - y.second);

		cout << "it = " << it++ << endl;
		cout << "[x1, x2] = [" << x1 << ", " << x2 << "]" << endl;
		cout << "optAlpha = " << optAlpha << endl;

		if (norma(dx1(x1, x2), dx2(x1, x2)) <= E)
		{
			break;
		}
	}
	return f(x1, x2);
}

int main()
{
	double x1 = 0;
	double x2 = 0;
	const double E = 0.05;

	cout << "****************FAST GRADIENT DESCENT*************************" << endl;
	double res1 = fastGradient(x1, x2, E);
	cout << "f(xmin) = " << res1 << endl;

	cout << "******************OVRAG METHOD********************************" << endl;
	double res2 = ovragMethod(x1, x2, E);
	cout << "f(xmin) = " << res2 << endl;

	system("pause");
	return 0;
}
