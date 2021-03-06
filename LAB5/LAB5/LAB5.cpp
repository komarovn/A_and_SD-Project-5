// LAB5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

#include "Polynomial.h"

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	Monomial A(5, 8);

	Monomial B("x1^2x2^3", 5, 12); // coeff = 1, fold = 176

	Monomial GH("x1", 5, 10); // coeff = 1, fold = 10000

	Monomial C("-12x2^2x3x1^11x4^5", 5, 12); // coeff = -12, fold = 231756

	Monomial D("3x1^5", 5, 12); // coeff = 3, fold = ((0+5)*5+0)*5+0 = 125

	Monomial H;

	Monomial K("x1^2x2^3", 2, 8);
	Monomial L("3x1^5", 2, 8);

	H = K.MultiplicationOfMonomials(L, 8);

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

	CircularList M;
	M.AddMonomial("x1^2x2x3^3", 3, 9);
	//M.AddMonomial("x1x2^5", 3, 9);
	M.AddMonomial("x1x2^4", 3, 9);

	Monomial N("x1^2x2^2x3^4", 3, 9);

	//M = M.MultiplicationOfClAndMonomial(N, 9);

	M = M.MultiplicationOfCls(M, 9);

	//E = E + E;

	cout << "----------------" << endl;
	cout << E.ToString(5, 12) << endl;
	cout << M.ToString(3, 9) << endl;
	cout << "Note: max fold length is " << INT_MAX << endl;

	Polynomial P("x1+x2x3-x2^2", 4, 5);
	Polynomial Q("x1+x2x3-x2^2", 4, 5);

	P = P * 4;

	cout << P.Output() << endl;
	*/
	 int maxCount = 3;
	 int maxPower = 5;
			Polynomial *P = new Polynomial("x1", maxCount, maxPower);
			Polynomial *Q = new Polynomial("-x2", maxCount, maxPower);
			 Polynomial A("", maxCount, maxPower);
			 A = 
				 (*P) + (*Q);
			 cout << A.Output() << endl;
	system("pause");
	return 0;
}
