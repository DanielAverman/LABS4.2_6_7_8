#include "Dek.h"

Dek_int *Ihead = NULL;
Dek_double *Dhead = NULL;

void Dek_int::add() 
{
	Dek_int *tmp;
	tmp = new Dek_int;
	cout << "Input int number: ";
	cin >> tmp->data;
	if (Ihead == NULL)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		Ihead = tmp;
	}
	else
	{
		Dek_int *dop = Ihead;
		while (dop->next != NULL)
			dop = dop->next;
		dop->next = tmp;
		tmp->prev = dop;
		tmp->next = NULL;
	}
}

void Dek_int::list()
{
	Dek_int *tmp = Ihead;
	if (Ihead = NULL)
	{
		cout << "Empty" << endl;
		return;
	}
	else {
		while (tmp != NULL) {
			cout << tmp->data << ' ';
			tmp = tmp->next;
		}
		cout << endl;
	}
}

void Dek_int::del()
{
	Dek_int *tmp = Ihead;
	if (Ihead == NULL)
	{
		cout << "Empty" << endl;
		return;
	}
	else {
		if (Ihead->next == NULL) {
			delete Ihead;
			Ihead = NULL;
		}
		else {
			Ihead = Ihead->next;
			Ihead->prev = NULL;
			delete tmp;
		}
	}
}

void Dek_double::add()
{
	Dek_double *tmp;
	tmp = new Dek_double;
	cout << "Input int number: ";
	cin >> tmp->data;
	if (Dhead == NULL)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		Dhead = tmp;
	}
	else
	{
		Dek_double *dop = Dhead;
		while (dop->next != NULL)
			dop = dop->next;
		dop->next = tmp;
		tmp->prev = dop;
		tmp->next = NULL;
	}
}

void Dek_double::list()
{
	Dek_double *tmp = Dhead;
	if (Dhead = NULL)
	{
		cout << "Empty" << endl;
		return;
	}
	else {
		while (tmp != NULL) {
			cout << tmp->data << ' ';
			tmp = tmp->next;
		}
		cout << endl;
	}
}

void Dek_double::del()
{
	Dek_double *tmp = Dhead;
	if (Dhead == NULL)
	{
		cout << "Empty" << endl;
		return;
	}
	else {
		if (Dhead->next == NULL) {
			delete Dhead;
			Dhead = NULL;
		}
		else {
			Dhead = Dhead->next;
			Dhead->prev = NULL;
			delete tmp;
		}
	}
}

void main()
{
	int n;
	Dek *p;
	cout << "1.int|2.double?" << endl;
	cin >> n;
	if (n == 1)
	{
		Dek_int a;
		p = &a;
	}
	else {
		Dek_double a;
		p = &a;
	}
	do {
		cout << "1.Add" << endl;
		cout << "2.List" << endl;
		cout << "3.Delete" << endl;
		cout << "4.Exit" << endl;
		cout << "Input number: ";
		cin >> n;
		switch (n)
		{
		case 1: p->add(); break;
		case 2: p->list(); break;
		case 3: p->del(); break;
		case 4: return;
		}
	} while (true);
}