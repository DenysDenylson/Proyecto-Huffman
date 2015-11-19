#ifndef LISTAFORMA8_H
#define LISTAFORMA8_H
#include"Tripla.h"
#include"TUAD.h"
using namespace std;
template<class T>
class ListaForma8{
private:
	Tripla<T> *primer;
	Tripla<T> *ultimo;
public:
	ListaForma8();
	~ListaForma8();	
	int insertarPRIN(T el, int frecuencia);
	int insertarFIN(T el, int frecuencia);
	int eliminarPRIN();
	int eliminarFIN();
	int eliminarDADO(T el);
	T menorNOREC(int *existe);
	int insertarEnSuLUGAR(T el, int frecuencia);
	void extraerCarsTUAD();
	void mostrar();
	bool crear_arbol();
};

template<class T>
ListaForma8<T>::ListaForma8()
{
	primer=NULL;
	ultimo=NULL;
}

template<class T>
ListaForma8<T>::~ListaForma8()
{
	if(primer!=NULL){
	  if(primer->sig==NULL){
		  delete primer;
	  }else{
		  Tripla<T> *aux=primer;
		  while (aux->sig!=NULL){
			  Tripla<T> *aux2;
			  aux2=aux->sig;
			  delete aux;
			  aux=aux2;
		  }
		  delete aux;
		  primer=NULL;
		  ultimo=NULL;
	  }
	}
}

template<class T>
int ListaForma8<T>::insertarPRIN(T el, int frecuencia)
{
	int res=1;
	if(primer==NULL){
		primer=new Tripla<T>;
		ultimo=primer;
		primer->el=el;
		primer->frecuencia=frecuencia;
		primer->arbol.insertarABB(primer->arbol.RAIZ, el, frecuencia);
	}else{
		Tripla<T> *aux=primer;
		primer=new Tripla<T>;
		aux->ant=primer;
		primer->sig=aux;
		primer->el=el;
		primer->frecuencia=frecuencia;
		primer->arbol.insertarABB(primer->arbol.RAIZ, el, frecuencia);
	}
	return res;
}

template<class T>
int ListaForma8<T>::insertarFIN(T el, int frecuencia)
{
	int res=1;
	if(ultimo==NULL){
		ultimo=new Tripla<T>;
		primer=ultimo;
		ultimo->el=el;
		ultimo->frecuencia=frecuencia;
		ultimo->arbol.insertarABB(ultimo->arbol.RAIZ, el, frecuencia);
	}else{
		Tripla<T> *aux=ultimo;
		ultimo=new Tripla<T>;
		aux->sig=ultimo;
		ultimo->ant=aux;
		ultimo->el=el;
		ultimo->frecuencia=frecuencia;
		ultimo->arbol.insertarABB(ultimo->arbol.RAIZ, el, frecuencia);
	}
	return res;
}

template<class T>
int ListaForma8<T>::insertarEnSuLUGAR(T el, int frecuencia)
{
	int res=1;
	if(primer==NULL){
		insertarPRIN(el, frecuencia);
	}else{
		if (frecuencia<primer->frecuencia){
			insertarPRIN(el, frecuencia);
		}else{
			if (frecuencia>ultimo->frecuencia){
				insertarFIN(el, frecuencia);
			}else{
				Tripla<T> *aux=primer->sig;
				while (aux->frecuencia<frecuencia && aux!=ultimo){
					aux=aux->sig;
				}
				Tripla<T> *nuevo;
				nuevo=new Tripla<T>;
				nuevo->sig=aux;
				nuevo->ant=aux->ant;
				(aux->ant)->sig=nuevo;
				aux->ant=nuevo;
				nuevo->el=el;
				nuevo->frecuencia=frecuencia;
				nuevo->arbol.insertarABB(nuevo->arbol.RAIZ, el, frecuencia);
			}
		}
	}
	return res;
}

template<class T>
int ListaForma8<T>::eliminarPRIN()
{
	int res=1;
	if(primer==NULL){
		res=0;
	}else{
		if(primer==ultimo){
			delete primer;
			primer=NULL;
			ultimo=NULL;
		}else{
			Tripla<T> *aux=primer;
			primer=primer->sig;
			primer->ant=aux;
			//primer->ant=NULL;
			//delete aux;
		}
	}
	return res;
}

template<class T>
int ListaForma8<T>::eliminarFIN()
{
	int res=1;
	if(ultimo==NULL){
		res=0;
	}else{
		if (ultimo==primer){
			delete ultimo;
			primer=NULL;
			ultimo=NULL;
		}else{
			Tripla<T> *aux;
			aux=ultimo;
			ultimo=ultimo->ant;
			ultimo->sig=NULL;
			delete aux;
		}
	}
	return res;
}

template<class T>
int ListaForma8<T>::eliminarDADO(T el)
{
	int res=1;
	if (primer!=NULL){
		if (el==primer->el){
			eliminarPRIN();
		}else{
			if (el==ultimo->el){
				eliminarFIN();
			}else{
				Tripla<T> *aux=primer->sig;
				while (aux->el!=el && aux!=ultimo){
					aux=aux->sig;
				}
				if(aux->el==el){
					aux->ant->sig=aux->sig;
					aux->sig->ant=aux->ant;
					delete aux;
				}
			}
		}
	}
	return res;
}

template<class T>
T ListaForma8<T>::menorNOREC(int *existe)
{
	T menor;
	if (primer==NULL){
		*existe=0;
	}else{
		menor=primer->el;
		Tripla<T> *aux=primer->sig;
		while (aux!=NULL){
			if (menor>aux->el){
				menor=aux->el;
			}
			aux=aux->sig;
		}
		if (menor>ultimo->el){
			menor=ultimo->el;
		}
		*existe=1;
	}
	return menor;
}

template<class T>
void ListaForma8<T>::extraerCarsTUAD()
{
	TUAD tuad;
	tuad.cargarTxtTUAD();
	char let;
	for(int i=0 ; i<26 ; i++){
		let=i+65;
		insertarEnSuLUGAR(let, tuad.vec[i]);
	}
}


template<class T>
void ListaForma8<T>::mostrar()
{
	if(primer==NULL){
		cout<<"L={}"<<endl;
	}else{
		Tripla<T> *aux=primer;
		cout<<"L={"<<endl;
		while (aux->sig!=NULL){
			cout<<aux->el<<"("<<aux->frecuencia<<") ABB => "<<endl;
			aux->arbol.recorrerPRE(aux->arbol.RAIZ); cout<<endl;
			aux=aux->sig;
		}
		cout<<ultimo->el<<"("<<ultimo->frecuencia<<") ABB => "<<endl;	
		ultimo->arbol.recorrerPRE(ultimo->arbol.RAIZ); cout<<endl;
		cout<<"}"<<endl;
	}	
}

template<class T>
bool ListaForma8<T>::crear_arbol()
{
	bool res;
	if(primer==NULL){
		res=false;
	}else{
		if (primer==ultimo){
			res=true;
		}else{
			while (primer!=ultimo){
				Nodo<T> *aux1=primer->arbol.RAIZ;
				Nodo<T> *aux2=primer->sig->arbol.RAIZ;

				int nueva_frec=aux1->frecuencia+aux2->frecuencia;

				Tripla<T> *nuevo;
				nuevo=new Tripla<T>;

				nuevo->arbol.insertarABB(nuevo->arbol.RAIZ,NULL,nueva_frec);
				nuevo->arbol.RAIZ->S_IZQ=aux1;
				nuevo->arbol.RAIZ->S_DER=aux2;
						
				// ES COMO UN INSERTAR EN SU LUGAR LLAMAR A LA FUNCION NO SE PODRIA PORQUE NO RECIBE UNA TRIPLA		
				Tripla<T> *aux=primer;
				while (aux->frecuencia<nueva_frec && aux->sig!=NULL){
					aux=aux->sig;
				}
				if(aux!=ultimo){
					nuevo->sig=aux;
					nuevo->ant=aux->ant;
					(aux->ant)->sig=nuevo;
					aux->ant=nuevo;
					nuevo->frecuencia=nueva_frec;
				}else{
					nuevo->ant=aux;
					aux->sig=nuevo;
					ultimo=nuevo;
					nuevo->frecuencia=nueva_frec;
				}
				// FIN INSERTAR EN SU LUGAR

				int res1=eliminarPRIN(); 
				int res2=eliminarPRIN();

			}
			res=true;			
		}
	}
	return res;
}
#endif