#ifndef _CIRCULARLIST_H_
#define _CIRCULARLIST_H_

#include "Monomial.h"

class CircularList
{
private:
	Monomial *first;
public:
	CircularList(); // Конструктор
	CircularList(const CircularList &cl); // Конструктор копирования 
	~CircularList(); // Деструктор
	CircularList &operator=(const CircularList &cl); // Оператор присваивания
	void AddMonomial(Monomial *m); // Добавление монома
	void AddMonomial(int coeff, int fold); // Добавление монома, заданного сверткой и коэффициентом
	void AddMonomial(string mstr, int maxCount, int maxPower); // Добавление монома, заданного в виде строки
	CircularList operator+(const CircularList &cl) const; // Оператор сложения
	CircularList operator-(const CircularList &cl) const; // Оператор вычитания
	CircularList operator*(const CircularList &cl) const; // Оператор умножения полиномов
	CircularList operator*(int k) const; // Оператор умножения полинома на число
	string ToString(int maxCount, int maxPower); // Перевод полинома в строку
};

CircularList::CircularList()
{
	first = new Monomial();
	first->SetNext(first);
}

CircularList::CircularList(const CircularList &cl)
{
	first = new Monomial();
	first->SetNext(first); 
	Monomial *last = first;
	Monomial *current = cl.first->GetNext();
	while (current->GetFold() != -1)
	{
		Monomial *copy = new Monomial(*current);
		last->SetNext(copy);
		copy->SetNext(first);
		last = copy;
		current = current->GetNext();
	}
}

CircularList::~CircularList()
{
	Monomial *tmp = first->GetNext();
	first = 0; //delete tmp;
}

CircularList &CircularList::operator=(const CircularList &cl)
{
	Monomial *tmp = first->GetNext();
	//delete tmp;
	first = 0;
	this->CircularList::CircularList(cl);
	return *this;
}

void CircularList::AddMonomial(Monomial *m)
{
	Monomial *prev = first;
	Monomial *current;
	current = first->GetNext();
	while (current->GetFold() > m->GetFold())
	{
		prev = current;
		current = current->GetNext();
	}
	if (current->GetFold() < m->GetFold())
	{
		m->SetNext(current);
		prev->SetNext(m);
	}
	else
	{
		current->SetCoeff(current->GetCoeff() + m->GetCoeff());
		if (current->GetCoeff() == 0)
		{
			prev->SetNext(current->GetNext());
			current->SetNext(0);
			delete current;
		}
		delete m;
	}
}

void CircularList::AddMonomial(int coeff, int fold)
{
	Monomial *tmp = new Monomial(coeff, fold);
	AddMonomial(tmp);
}

void CircularList::AddMonomial(string mstr, int maxCount, int maxPower)
{
	Monomial *tmp = new Monomial(mstr, maxCount, maxPower);
	AddMonomial(tmp);
}

CircularList CircularList::operator+(const CircularList &cl) const
{
	CircularList tmp(*this);
	Monomial *current = cl.first->GetNext();
	Monomial *currentCopy;
	while (current->GetFold() != -1) // ???
	{
		currentCopy = new Monomial(*current);
		tmp.AddMonomial(currentCopy);
		current = current->GetNext();
	}
	return tmp;
}

CircularList CircularList::operator-(const CircularList &cl) const
{
	return (*this + cl * (-1));
}

//CircularList CircularList::operator*(const CircularList &cl) const

CircularList CircularList::operator*(int k) const
{
	CircularList tmp(*this);
	Monomial *current;
	current = tmp.first->GetNext();
	while (current != tmp.first)
	{
		current->SetCoeff(current->GetCoeff() * k);
		current = current->GetNext();
	}
	return tmp;
}

string CircularList::ToString(int maxCount, int maxPower)
{
	string s = "";
	Monomial *current = first->GetNext();
	while (current->GetFold() != -1)
	{
		if (strcmp(s.c_str(), "")) // added
				s += " + "; // added
		s += current->ToString(maxCount, maxPower);
		current = current->GetNext();
	}
	return s;
}

#endif