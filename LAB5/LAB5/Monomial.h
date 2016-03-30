#ifndef _MONOMIAL_H_
#define _MONOMIAL_H_

#include "iostream"
#include "stringconvert.h"

class Monomial
{
private:
	int coeff; // Коэффициент
	int fold; // Свертка
	Monomial *next; // Указатель на следующий моном
public:
	Monomial(int coeff = 0, int fold = -1); // Конструктор
	Monomial(string mstr, int maxCount, int maxPower); // Конструктор
	Monomial(const Monomial &m); // Конструктор копирования
	~Monomial() {next = 0;}; // Деструктор !!!
	Monomial &operator=(const Monomial &m); // Оператор присваивания
	int GetCoeff() const {return coeff;}; // Получение коэффициента
	void SetCoeff(int cff) {coeff = cff;}; // Установка коэффициента
	int GetFold() const {return fold;}; // Получение свертки
	void SetFold(int fld) {fold = fld;}; // Установка свертки
	Monomial *GetNext() const {return next;}; // Получение следующего монома
	void SetNext(Monomial *m) {next = m;}; // Установка следующего монома
	Monomial MultiplicationOfMonomials(const Monomial &m, int maxPower); // Умножение мономов
	string ToString(int maxCount = 10, int maxPower = 10); // Перевод монома в строку
};

Monomial::Monomial(int coeff, int fold) : coeff(coeff), fold(fold), next(0) {}

Monomial::Monomial(string mstr, int maxCount, int maxPower)
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
			var_i = "x" + toString(i + 1);
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

Monomial Monomial::MultiplicationOfMonomials(const Monomial &m, int maxPower)
{
	Monomial tmp;
	tmp.coeff = coeff * m.coeff;
	int foldFirst = this->fold;
	int foldSecond = m.fold;
	while (foldFirst != 0 && foldSecond != 0)
	{
		int d1 = foldFirst % maxPower;
		int d2 = foldSecond % maxPower;
		if (d1 + d2 > maxPower)
			throw exception();
		foldFirst /= maxPower;
		foldSecond /= maxPower;
	}
	tmp.fold = fold + m.fold;
	return tmp;
}

string Monomial::ToString(int maxCount, int maxPower)
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
			if (strcmp(res.c_str(), ""))
				res = "*" + res ;
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
			res = toString(coeff) + "*" + res;
	return res;
}

#endif