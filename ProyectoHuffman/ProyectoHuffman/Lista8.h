#ifndef LISTAFORMA8_H
#define LISTAFORMA8_H
#include"Tripla.h"
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
	int insertarFIN(T el);
	int eliminarPRIN();
	int eliminarFIN();
	int eliminarDADO(T el);
	T menorNOREC(int *existe);
	//int insertarEnSuLUGAR(T el);
	void invertirLISTA();
	void mostrar();
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
		primer->frecuencia = frecuencia;
	}else{
		Tripla<T> *aux=primer;
		primer=new Tripla<T>;
		aux->ant=primer;
		primer->sig=aux;
		primer->el=el;
		primer->frecuencia = frecuencia;
	}
	return res;
}

template<class T>
int ListaForma8<T>::insertarFIN(T el)
{
	int res=1;
	if(ultimo==NULL){
		ultimo=new Tripla<T>;
		primer=ultimo;
		ultimo->el=el;
	}else{
		Tripla<T> *aux=ultimo;
		ultimo=new Tripla<T>;
		aux->sig=ultimo;
		ultimo->ant=aux;
		ultimo->el=el;
	}
	return res;
}
//
//template<class T>
//int ListaForma8<T>::insertarEnSuLUGAR(T el)
//{
//	int res=1;
//	if(primer==NULL){
//		insertarPRIN(el);
//	}else{
//		if (el<primer->el){
//			insertarPRIN(el);
//		}else{
//			if (el>ultimo->el){
//				insertarFIN(el);
//			}else{
//				Tripla<T> *aux=primer->sig;
//				while (aux->el<el && aux!=ultimo){
//					aux=aux->sig;
//				}
//				Tripla<T> *nuevo;
//				nuevo=new Tripla<T>;
//				nuevo->sig=aux;
//				nuevo->ant=aux->ant;
//				(aux->ant)->sig=nuevo;
//				aux->ant=nuevo;
//				nuevo->el=el;
//			}
//		}
//	}
//	return res;
//}

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
			primer->ant=NULL;
			delete aux;
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
void ListaForma8<T>::invertirLISTA()
{
	Tripla<T> *i;
	i=ultimo;
	ListaForma8 l2;
	while (i!=primer){		
		l2.insertarFIN(i->el);
		i=i->ant;	
		eliminarFIN();
	}
	l2.insertarFIN(primer->el);
	eliminarPRIN();
	l2.mostrar();

}

template<class T>
void ListaForma8<T>::mostrar()
{
	if(primer==NULL){
		cout<<"L={}"<<endl;
	}else{
		Tripla<T> *aux=primer;
		cout<<"L={";
		while (aux->sig!=NULL){
			cout<<aux->el<<"=>"<<aux->frecuencia<<",";
			aux=aux->sig;
		}
		cout << ultimo->el << "=>" << aux->frecuencia << "}" << endl;
	}	
}

#endif