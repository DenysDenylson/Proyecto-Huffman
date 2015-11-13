#include"TUAD.h"
#include"Lista8.h"


int main(){

	ListaForma8<char> lf8;
	char el, res1;
	int opcion, res, existe=0;

		do
		{
		system("cls");
		cout << "###############################################################################" << endl;
		cout << "#                                                                             #" << endl;
		cout << "#                                  LISTA FORMA8                               #" << endl;
		cout << "#                                                                             #" << endl;
		cout << "###############################################################################" << endl;
		cout << "[1]   InsertarPRIN" << endl;
		cout << "[2]   InsertarFIN" << endl;
		cout << "[3]   EliminarPRIN" << endl;
		cout << "[4]   EliminarFIN" << endl;
		cout << "[5]   MenorREC" << endl;
		cout << "[6]   MenorNOREC" << endl;
		cout << "[7]   MOSTRARLISTA" << endl;
		cout << "[8]   INSERTARENSULUGAR" << endl;
		cout << "[9]   ELIMINARELEMENTODADO" << endl;
		cout << "[10]  INVERTIRLISTA" << endl;
		cout << "[11]  SALIR" << endl;
		cout << "Ingresar opcion: " ;
		cin >> opcion;
		switch (opcion)
		{
				 case 1:
					 cout<<"elemento:";
					 cin>>el;
					 res=lf8.insertarPRIN(el);
					 cout<<res<<endl;
					 system("pause");
					 system("cls");
					 break;

				 case 2:
					 cout<<"elemento:";
					 cin>>el;
					 res=lf8.insertarFIN(el);
					 cout<<res<<endl;
					 system("pause");
					 system("cls");
					 break;

				 case 3:
					 res=lf8.eliminarPRIN();
					 cout<<res<<endl;
					 system("pause");
					 system("cls");
					 break;

				 case 4:
					 res=lf8.eliminarFIN();
					 cout<<res<<endl;
					 system("pause");
					 system("cls");
					 break;

				case 5:
					 /*res=lf2.menorREC(&existe,lf2.getPrim(),lf2.getUlt());
					 cout<<existe<<endl;
					 if(existe==true){
					 cout<<"menor:"<<res<<endl;
					 }else{
					 cout<<"menor: Lista Vacia"<<endl;
					 }*/
					 system("pause");
					 system("cls");
					 break;

				case 6:
					 res1=lf8.menorNOREC(&existe);
					 cout<<existe<<endl;
					 cout<<"menor:"<<res1<<endl;
					 system("pause");
					 system("cls");
					 break; 

				 case 7:
					 lf8.mostrar();
					 system("pause");
					 system("cls");
					 break;

				 case 8:
					 cout<<"elemento:";
					 cin>>el;
					 res=lf8.insertarEnSuLUGAR(el);
					 cout<<res<<endl;
					 system("pause");
					 system("cls");
					 break;

				 case 9:
					 cout<<"elemento:";
					 cin>>el;
					 res=lf8.eliminarDADO(el);
					 cout<<res<<endl;
					 system("pause");
					 system("cls");
					 break;

				 case 10:
					 lf8.invertirLISTA();
					 cout<<res<<endl;
					 system("pause");
					 system("cls");
					 break; 

				 case 11:cout<<"Saliendo..."<<endl;
		}	  

		}while(opcion <=11 && opcion!=11);
	/*TUAD tuad;
	int opcion = 0;
	
	do{
		system("cls");
		cout << "###############################################################################" << endl;
		cout << "#                                                                             #" << endl;
		cout << "#                                 TUAD                                        #" << endl;
		cout << "#                                                                             #" << endl;
		cout << "###############################################################################" << endl;
		cout << "[1]  CargarTxtTUAD" << endl;
		cout << "[2]  MostrarTUAD" << endl;
		cout << "[3]  SALIR" << endl;
		cout << "Ingresar opcion: " ;
		cin >> opcion;
		
		switch (opcion){
				case 1:
					 tuad.cargarTxtTUAD();
					 system("pause");
					 system("cls");
					 break;
				case 2:
					 tuad.mostrarTUAD();
					 system("pause");
					 system("cls");
					 break;  

				case 3:
					cout<<"Saliendo..."<<endl;
					break;
				default:
					opcion = 3;
		}	  

	}while(opcion!=3);*/



	system("pause");
	system("cls");
    
	return 0;
}