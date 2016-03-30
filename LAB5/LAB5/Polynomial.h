#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include "CircularList.h"

class Polynomial
{
private:
	CircularList circList;
	int maxCount;
	int maxPower;
	void stringDivision(string str, string *words, int &count); // Деление строки на слова
public:
	Polynomial(string str = "", int maxCount = 10, int maxPower = 10); // Конструтор
	Polynomial(const Polynomial &p) {}; // Конструктор копирования
	~Polynomial() {}; // Деструктор
	Polynomial &operator=(const Polynomial &p) {}; // Оператор присваивания

};

void Polynomial::stringDivision(string str, string *words, int &count) // Деление строки на слова
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

#endif