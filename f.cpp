#include <iostream>
#include <cmath>

using namespace std;

const int MAX_ITER = 1000;

double f(double x1, double x2)
{
	return 2 * pow(x1, 2) + pow(x2, 2) + x1 * x2 + x1 + x2;
}

double dx1(double x1, double x2)
{
	return  4 * x1 + x2 + 1;
}

double dx2(double x1, double x2)
{
	return  x1 + 2 * x2 + 1;
}

double norma(double x1, double x2)
{
	return sqrt(pow(x1, 2) + pow(x2, 2));
}

double gradConstShag(double x01, double x02, double eps)
{
	double x1 = x01;
	double x2 = x02;

	int iter = 0;

	double px1 = x1;
	double px2 = x2;

	const double shag = 0.05;

	while (iter++ < MAX_ITER)
	{
		x1 -= shag * dx1(px1, px2);
		x2 -= shag * dx2(px1, px2);
		cout << "iter = " << iter << endl;
		cout << "[x1, x2] = [" << x1 << ", " << x2 << "]" << endl;
		cout << "f(x1, x2) = " << f(x1, x2) << endl << endl;

		if (norma(x1 - px1, x2 - px2) <= eps)
		{
			break;
		}

		px1 = x1;
		px2 = x2;
	}

	cout << "iter = " << iter << endl;
	return f(x1, x2);
}

double rasryad(double x01, double x02, const double eps)
{
	double x1 = x01;
	double x2 = x02;

	int iter = 0;

	double px1 = x1;
	double px2 = x2;

	while (iter++ < MAX_ITER)
	{
		x1 -= (1.0 / iter) * dx1(x1, x2);
		x2 -= (1.0 / iter) * dx2(x1, x2);
		cout << "it = " << iter << endl;
		cout << "[x1, x2] = [" << x1 << ", " << x2 << "]" << endl;
		cout << "f(x1, x2) = " << f(x1, x2) << endl << endl;

		cout << norma(x1 - px1, x2 - px2) << ' ' << eps << endl;
		if (norma(x1 - px1, x2 - px2) <= eps)
		{
			break;
		}

		px1 = x1;
		px2 = x2;
	}

	cout << "iter = " << iter << endl;
	return f(x1, x2);
}

int main()
{
	const double x1 = 0;
	const double x2 = 0;
	const double E = 0.005;

	cout << "***********GRADIENT WITH CONST STEP*****************" << endl;
	double gc = gradConstShag(x1, x2, E);
	cout << "********************************f(xmin) = " << gc << endl << endl;

	cout << "***********************DIVERGENT ROW*********************************" << endl;
	double rs = rasryad(x1, x2, E);
	cout << "********************************f(xmin) = " << rs << endl << endl;


	system("pause");
	return 0;
}