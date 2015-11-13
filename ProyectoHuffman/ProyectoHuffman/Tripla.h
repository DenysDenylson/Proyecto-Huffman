#ifndef TRIPLA_H
#define TRIPLA_H
#include<iostream>
#include<stdio.h>
#include"ABB.h"
using namespace std;
template<class T>
class Tripla{
public:
	T el;
	int frecuencia;
	ABB<char> arbol;
	Tripla<T> *sig;
	Tripla<T> *ant;
public:
	Tripla();
	~Tripla();
};

template<class T>
Tripla<T>::Tripla()
{
	sig=NULL;
	ant=NULL;
}

template<class T>
Tripla<T>::~Tripla()
{
}

#endif