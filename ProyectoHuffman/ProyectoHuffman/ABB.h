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
	void insertarABB(Nodo<T> *&RAIZ, T el);
	void recorrerIN(Nodo<T> *RAIZ);
	void recorrerPRE(Nodo<T> *RAIZ);
	void recorrerPOST(Nodo<T> *RAIZ);
	void mostrarNivel(Nodo<T> *RAIZ,int nivel, int cont);
	int contarNodosABB(Nodo<T> *RAIZ);
	int calcularAlturaABB(Nodo<T> *RAIZ);
	T menorABB(Nodo<T> *RAIZ, int *existe);
	T mayorABB(Nodo<T> *RAIZ, int *existe);
	int eliminarDadoABB(Nodo<T> *&RAIZ, T el);
	int buscarABB(Nodo<T> *RAIZ, T el);
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
void ABB<T>::insertarABB(Nodo<T> *&RAIZ, T el)
{
	if (RAIZ==NULL){
		RAIZ=new Nodo<T>;
		RAIZ->el=el;
	}else{
		if (el<RAIZ->el){
			insertarABB(RAIZ->S_IZQ,el);
		}else{
			if (el>RAIZ->el){
				insertarABB(RAIZ->S_DER,el);
			}
		}
	}
}

template <class T>
void ABB<T>::recorrerIN(Nodo<T> *RAIZ)
{
	if(RAIZ!=NULL){
		recorrerIN(RAIZ->S_IZQ);
		cout<<RAIZ->el<<",";
		recorrerIN(RAIZ->S_DER);
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
		cout<<RAIZ->el<<",";
		recorrerPRE(RAIZ->S_IZQ);
		recorrerPRE(RAIZ->S_DER);
	}
}

template <class T>
void ABB<T>::recorrerPOST(Nodo<T> *RAIZ)
{
	if(RAIZ!=NULL){
		recorrerPOST(RAIZ->S_IZQ);
		recorrerPOST(RAIZ->S_DER);
		cout<<RAIZ->el<<",";
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
T ABB<T>::menorABB(Nodo<T> *RAIZ, int *existe)
{
	T menor;
	if (RAIZ==NULL){
		*existe=0;
	}else{
		if(RAIZ->S_IZQ==NULL)
		{
			menor=RAIZ->el;
			*existe=1;
		}else{
			menor=menorABB(RAIZ->S_IZQ,existe);
		}
	}
	return menor;
}

template <class T>
T ABB<T>::mayorABB(Nodo<T> *RAIZ, int *existe)
{
	T mayor;
	if (RAIZ==NULL){
		*existe=0;
	}else{
		if(RAIZ->S_DER==NULL)
		{
			mayor=RAIZ->el;
			*existe=1;
		}else{
			mayor=mayorABB(RAIZ->S_DER,existe);
		}
	}
	return mayor;
}

template <class T>
int ABB<T>::eliminarDadoABB(Nodo<T> *&RAIZ, T el)
{

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