#include"TUAD.h"
#include<fstream>

TUAD::TUAD()
{
	for (int i = 0; i < 50; i++){
		vec[i]=0;
	}
}

TUAD::~TUAD()
{
}

void TUAD::cargarTxtTUAD()
{
	ifstream archivo("texto.txt");
	char car;
	int res;
	while (!archivo.eof()){
       car=archivo.get();
	   res=insertarTUAD(car);
	}
	archivo.close();
}

int TUAD::funcionTUAD(char l)
{
	int let=l;
	if (let>=65 && let<=90)
		return let-65;
	if (let>=97 && let<=122)
		return let-97;
}

int TUAD::insertarTUAD(char l)
{
	vec[funcionTUAD(l)]++;
	return 1;
}

void TUAD::mostrarTUAD()
{
	char let;
	for(int i=0; i<26; i++){
		let=i+65;
		cout<<let<<"="<<vec[i]<<endl;
	}
}
