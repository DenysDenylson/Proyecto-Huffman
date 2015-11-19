#ifndef ABB_H
#define ABB_H
#include<iostream>
#include"Nodo.h"
using namespace std;
template<class T>
class ABB{
public:
	Nodo<T> *RAIZ;
public:
	ABB();
	~ABB();
	void eliminarABB(Nodo<T> *&RAIZ);
	void insertarABB(Nodo<T> *&RAIZ, T el,int frecuencia);
	void recorrerPRE(Nodo<T> *RAIZ);
	void mostrarNivel(Nodo<T> *RAIZ,int nivel, int cont);
	int contarNodosABB(Nodo<T> *RAIZ);
	int calcularAlturaABB(Nodo<T> *RAIZ);
	int buscarABB(Nodo<T> *RAIZ, T el);
	//void armarArbolDerecho(Nodo<T> arbol);
};

template<class T>
ABB<T>::ABB()
{
	RAIZ=NULL;
}

template<class T>
void ABB<T>::eliminarABB(Nodo<T> *&RAIZ)
{
	if (RAIZ!=NULL){
		eliminarABB(RAIZ->S_IZQ);
		eliminarABB(RAIZ->S_DER);
		delete RAIZ;
		RAIZ=NULL;
	}
}

template<class T>
ABB<T>::~ABB()
{
	eliminarABB(RAIZ);
}

template<class T>
void ABB<T>::insertarABB(Nodo<T> *&RAIZ, T el, int frecuencia)
{
	if (RAIZ==NULL){
		RAIZ=new Nodo<T>;
		RAIZ->el=el;
		RAIZ->frecuencia=frecuencia;
	}else{
		//if (el<RAIZ->el){
		if(RAIZ->S_IZQ==NULL){
			insertarABB(RAIZ->S_IZQ, el, frecuencia);
		}else{
			//if (el>RAIZ->el){
			if(RAIZ->S_DER==NULL){
				insertarABB(RAIZ->S_DER, el, frecuencia);
			}
		}
	}
}

template <class T>
void ABB<T>::mostrarNivel(Nodo<T> *RAIZ,int nivel, int cont)
{
	if(RAIZ==NULL){
	  cout<<""<<endl;
	}else{
		if(cont==nivel){
			mostrarNivel(RAIZ->S_IZQ,nivel,cont+1);
			cout<<RAIZ->el<<",";
			mostrarNivel(RAIZ->S_DER,nivel,cont+1);
		}else{
			mostrarNivel(RAIZ->S_IZQ,nivel,cont+1);
			mostrarNivel(RAIZ->S_DER,nivel,cont+1);
		}
	}
}

template <class T>
void ABB<T>::recorrerPRE(Nodo<T> *RAIZ)
{
	if(RAIZ!=NULL){
		cout<<RAIZ->el<<"("<<RAIZ->frecuencia<<")"<<",";
		recorrerPRE(RAIZ->S_IZQ);
		recorrerPRE(RAIZ->S_DER);
	}
}

template <class T>
int ABB<T>::contarNodosABB(Nodo<T> *RAIZ)
{
	int res;
	if (RAIZ==NULL){
		res=0;
	}else{
		int res1=contarNodosABB(RAIZ->S_IZQ);
		int res2=contarNodosABB(RAIZ->S_DER);
		res=res1+res2+1;
	}
	return res;
}

template <class T>
int ABB<T>::calcularAlturaABB(Nodo<T> *RAIZ)
{
	int res;
	if (RAIZ==NULL){
		res=0;
	}else{
		int A1=1+calcularAlturaABB(RAIZ->S_IZQ);
		int A2=1+calcularAlturaABB(RAIZ->S_DER);
		if (A1>A2){
			res=A1;
		}else{
			res=A2;
		}
	}
	return res;
}

template <class T>
int ABB<T>::buscarABB(Nodo<T> *RAIZ, T el)
{
	int res;
	if (RAIZ==NULL){
		res=0;
	}else{
		if (RAIZ->el==el){
			res=1;
		}else{
			if (el<RAIZ->el){
				res=buscarABB(RAIZ->S_IZQ,el);
			}else{
				res=buscarABB(RAIZ->S_DER,el);
			}
		}
	}
	return res;
}


#endif