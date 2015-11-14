#ifndef NODO_H
#define NODO_H
#include<stdio.h>
using namespace std;
template<class T>
class Nodo{
public:
	T el;
	int frecuencia;
	Nodo<T> *S_IZQ;
	Nodo<T> *S_DER;
public:
	Nodo();
	~Nodo();
};

template<class T>
Nodo<T>::Nodo()
{	
	el=NULL;
	frecuencia=0;
	S_IZQ=NULL;
	S_DER=NULL;
}

template<class T>
Nodo<T>::~Nodo()
{
}

#endif