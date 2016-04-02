#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include "CircularList.h"

class Polynomial
{
private:
	CircularList circList;
	int maxCount;
	int maxPower;
	void stringDivision(string str, string *words, int &count); // ������� ������ �� �����
public:
	Polynomial(string str = "", int maxCount = 10, int maxPower = 10); // ����������
	Polynomial(const Polynomial &p) {}; // ����������� �����������
	~Polynomial() {}; // ����������
	Polynomial &operator=(const Polynomial &p) {return *this;}; // �������� ������������
	void Input(string str); // ���������� ������
	string Output(); // ����� ��������
	Polynomial operator+(const Polynomial &p); // �������� ��������
	Polynomial operator-(const Polynomial &p); // �������� ���������
	Polynomial operator*(int k); // �������� ��������� �� �����
	Polynomial operator*(const Polynomial &p); // �������� ���������
};

void Polynomial::stringDivision(string str, string *words, int &count) // ������� ������ �� �����
{
	string Symbols = " +-";
	count = 0;
	str = str + " ";
	words[0] = "";
	for (int i = 0; i < str.length(); i++)
	{
		int g = Symbols.find(str[i]);
		if (str[i] == '-')			
				words[count] = "-" + words[++count];
		else 
		{
			if (g < 0)
				words[count] = words[count] + str[i];
			else
			{
				if (str[i] == ' ')
				{
					if (words[count] != "")
						words[++count] = "";
				}
				else
				{
					if (words[count] != "")
						words[++count] = str[i];
					else
						words[count] = str[i];
					words[++count] = "";
				}
			}
		}
	}
}

Polynomial::Polynomial(string str, int maxCount, int maxPower)
{
	this->maxCount = maxCount;
	this->maxPower = maxPower;
	string *monomialsInStr = new string[str.length() / 2 + 1];
	int count = 0;
	stringDivision(str, monomialsInStr, count);
	for (int i = 0; i < count; i++)
	{
		if ((strcmp(monomialsInStr[i].c_str(), "-") != 0) && (strcmp(monomialsInStr[i].c_str(), "+") != 0))
			circList.AddMonomial(monomialsInStr[i], maxCount, maxPower);
	};
	delete [] monomialsInStr;
}

void Polynomial::Input(string str)
{
	circList.AddMonomial(str, maxCount, maxPower);
}

string Polynomial::Output()
{
	return circList.ToString(maxCount, maxPower);
}

Polynomial Polynomial::operator+(const Polynomial &p)
{
	Polynomial tmp(*this);
	tmp.circList = circList + p.circList;
	return tmp;
}

Polynomial Polynomial::operator-(const Polynomial &p)
{
	Polynomial tmp(*this);
	tmp.circList = circList - p.circList;
	return tmp;
}

Polynomial Polynomial::operator*(int k)
{
	Polynomial tmp(*this);
	tmp.circList = circList * k;
	return tmp;
}

Polynomial Polynomial::operator*(const Polynomial &p)
{
	Polynomial tmp(*this);
	tmp.circList = circList.MultiplicationOfCls(p.circList, maxPower);
	return tmp;
}

#endif