// LAB5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

#include "CircularList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Monomial A(5, 8);

	Monomial B("x1^2x2^3", 5, 12); // coeff = 1, fold = 176

	Monomial C("-12x2^2x3x1^11x4^5", 5, 12); // coeff = -12, fold = 231756

	Monomial D("3x1^5", 5, 12); // coeff = 3, fold = ((0+5)*5+0)*5+0 = 125

	Monomial H;

	Monomial K("x1^2x2^3", 2, 8);
	Monomial L("3x1^5", 2, 8);

	H = K.MultiplicityOfMonomials(L, 8);

	cout << B.ToString(5, 12) << endl;
	cout << C.ToString(5, 12) << endl;
	cout << D.ToString(5, 12) << endl;
	cout << H.ToString(2, 8) << endl;

	//A.ToString(5, 8);

	CircularList E;

	E.AddMonomial(&C);
	E.AddMonomial(&B);

	CircularList F(E);

	CircularList G;
	
	G = E;

	//E.AddMonomial(4, 123);

	E.AddMonomial("7x1^2x4^5", 5, 12);

	E = E * 2;

	//E = E + E;

	cout << "----------------" << endl;
	cout << E.ToString(5, 12) << endl;
	cout << "Note: max fold length is " << INT_MAX << endl;

	system("pause");
	return 0;
}
