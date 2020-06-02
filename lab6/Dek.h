#pragma once

#include<iostream>
#include<fstream>
#include <string>
using namespace std;

class Dek
{
public:
	Dek() {};
	virtual void add() = 0;
	virtual void list() = 0;
	virtual void del() = 0;
};

class Dek_int : public Dek
{
	int data;
	Dek_int *next, *prev;
public:
	Dek_int() {};
	void add();
	void list();
	void del();
};

class Dek_double : public Dek
{
	double data;
	Dek_double *next, *prev;
public:
	Dek_double() {};
	void add();
	void list();
	void del();
};