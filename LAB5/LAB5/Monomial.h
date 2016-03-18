#ifndef _MONOMIAL_H_
#define _MONOMIAL_H_

#include "iostream"
#include "stringconvert.h"

class Monomial
{
private:
	int coeff; // �����������
	int fold; // �������
	Monomial *next; // ��������� �� ��������� �����
public:
	Monomial(int coeff = 0, int fold = -1); // �����������
	Monomial(string mstr, int maxPower, int maxCount); // �����������
	Monomial(const Monomial &m); // ����������� �����������
	~Monomial() {next = 0;}; // ���������� !!!
	Monomial &operator=(const Monomial &m); // �������� ������������
	int GetCoeff() const {return coeff;}; // ��������� ������������
	void SetCoeff(int cff) {coeff = cff;}; // ��������� ������������
	int GetFold() const {return fold;}; // ��������� �������
	void SetFold(int fld) {fold = fld;}; // ��������� �������
	Monomial GetNext() const {return *next;}; // ��������� ���������� ������
	void SetNext(Monomial *m) {next = m;}; // ��������� ���������� ������
	string ToString(int maxPower = 10, int maxCount = 10); // ������� ������ � ������
};

Monomial::Monomial(int coeff, int fold) : coeff(coeff), fold(fold), next(0) {}

Monomial::Monomial(string mstr, int maxPower, int maxCount)
{
	int * power = new int [maxCount];
	int l = 0;
	string var_i = "";
	string powStr = "";
	if (mstr == "")
	{
		coeff = 0;
		fold = -1;
	}
	else
	{
		for (int i = 0; i < maxCount; i++)
		{
			power[i] = 0;
			var_i = "x" + toString(i + 1);  // ���� �������� ���������� ���������� � 1
			l = mstr.find(var_i);
			if (l >= 0)
			{
				mstr.erase(l, var_i.length());
				if ((l < mstr.length()) && (mstr[l] != '^'))
					power[i] = 1;
				else
				{
					mstr.erase(l, 1);
					powStr = "";
					while ((l < mstr.length()) && (mstr[l] >= '0') && (mstr[l] <= '9'))
					{
						powStr = powStr + toString(mstr[l]);
						mstr.erase(l, 1);
					};
					power[i] = atoi(powStr.c_str());
				};
			};
		};
		fold = 0;
		for (int i = 0; i < maxCount - 1; i++)
			fold = (fold + power[i]) * maxPower;
		fold += power[maxCount - 1];
		if (mstr == "")
			coeff = 1;
		else
			if (mstr == "-")
				coeff = -1;
			else
				coeff = atoi(mstr.c_str());
	};
	delete [] power;
}

Monomial::Monomial(const Monomial &m)
{
	coeff = m.coeff;
	fold = m.fold;
	next = m.next;
}

Monomial &Monomial::operator=(const Monomial &m)
{
	coeff = m.coeff;
	fold = m.fold;
	next = 0;
	return *this;
}

string Monomial::ToString(int maxPower, int maxCount)
{
	int power = 0;
	int foldTmp = fold;
	string res = "";
	string x = "";
	for (int i = maxCount - 1; (i >= 0) && (foldTmp != 0); i--)
	{
		x = "x";
		if (i != 0)
			power = foldTmp % maxPower;
		else
			power = foldTmp;
		if (power > 0)
		{
			x = x + toString(i + 1);
			if (power > 1)
				x = x + "^" + toString(power);
			if (strcmp(res.c_str(), "")) // added
				res = "*" + res ; // added
			res = x + res;
		};
		foldTmp = foldTmp / maxPower;
	};
	if (coeff == 1)
		res = "" + res;
	else
		if (coeff == -1)
			res = "-" + res;
		else
			res = toString(coeff) + "*" + res; // added "*"
	return res;
}

#endif