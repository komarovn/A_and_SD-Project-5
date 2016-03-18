// LAB5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

#include "CircularList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Monomial A(5, 8);

	Monomial B("x1^2x2^3", 4, 4); // coeff = 1, fold = 176

	Monomial C("-12x2^2x3x1^11x4^5", 12, 5); // coeff = -12, fold = 231756

	Monomial D("3x1^5", 5, 3); // coeff = 3, fold = ((0+5)*5+0)*5+0 = 125

	cout << B.ToString(4, 4) << endl;
	cout << C.ToString(12, 5) << endl;
	cout << D.ToString(5, 3) << endl;

	A.ToString(5, 8);

	CircularList E;

	E.AddMonomial(&C);
	E.AddMonomial(&B);

	system("pause");
	return 0;
}
