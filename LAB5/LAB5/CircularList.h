#ifndef _CIRCULARLIST_H_
#define _CIRCULARLIST_H_

#include "Monomial.h"

class CircularList
{
private:
	Monomial *first;
	CircularList MultiplicationOfClAndMonomial(const Monomial &m, int maxPower); // ��������� �������� �� �����
public:
	CircularList(); // �����������
	CircularList(const CircularList &cl); // ����������� ����������� 
	~CircularList(); // ����������
	CircularList &operator=(const CircularList &cl); // �������� ������������
	void AddMonomial(Monomial *m); // ���������� ������
	void AddMonomial(int coeff, int fold); // ���������� ������, ��������� �������� � �������������
	void AddMonomial(string mstr, int maxCount, int maxPower); // ���������� ������, ��������� � ���� ������
	CircularList operator+(const CircularList &cl) const; // �������� ��������
	CircularList operator-(const CircularList &cl) const; // �������� ���������
	CircularList MultiplicationOfCls(const CircularList &cl, int maxPower); // ��������� ���������
	CircularList operator*(int k) const; // �������� ��������� �������� �� �����
	string ToString(int maxCount, int maxPower); // ������� �������� � ������
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
	first = 0;
}

CircularList &CircularList::operator=(const CircularList &cl)
{
	Monomial *tmp = first->GetNext();
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
	while (current->GetFold() != -1)
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

CircularList CircularList::operator*(int k) const
{
	CircularList tmp(*this);
	Monomial *current = tmp.first->GetNext();
	while (current != tmp.first)
	{
		current->SetCoeff(current->GetCoeff() * k);
		current = current->GetNext();
	}
	return tmp;
}

CircularList CircularList::MultiplicationOfClAndMonomial(const Monomial &m, int maxPower)
{
	CircularList clBefore(*this);
	CircularList clAfter;
	Monomial *current = clBefore.first->GetNext();
	Monomial *currentCopy;
	while (current != clBefore.first)
	{
		currentCopy = new Monomial(*current);
		*currentCopy = current->MultiplicationOfMonomials(m, maxPower);
		clAfter.AddMonomial(currentCopy);
		current = current->GetNext();
	}
	return clAfter;
}

CircularList CircularList::MultiplicationOfCls(const CircularList &cl, int maxPower)
{
	CircularList clBefore(*this);
	CircularList clAfter;
	Monomial *current = cl.first->GetNext();
	while (current != cl.first)
	{
		clAfter = clAfter + clBefore.MultiplicationOfClAndMonomial(*current, maxPower);
		current = current->GetNext();
	} 
	return clAfter;
}

string CircularList::ToString(int maxCount, int maxPower)
{
	string s = "";
	Monomial *current = first->GetNext();
	while (current->GetFold() != -1)
	{
		if (strcmp(s.c_str(), ""))
		{
			if (current->GetCoeff() < 0)
				s = s + "";
			else 
				s = s + "+";
		};
		s += current->ToString(maxCount, maxPower);
		current = current->GetNext();
	}
	return s;
}

#endif