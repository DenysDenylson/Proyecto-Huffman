#ifndef TUAD_H
#define TUAD_H
#include<iostream>
#include<stdio.h>
using namespace std;
class TUAD{
private:
	int vec[1000];
public:
	TUAD();
	~TUAD();
	int funcionTUAD(char l);
	int insertarTUAD(char l);
	void cargarTxtTUAD();
	void mostrarTUAD();
};

#endif