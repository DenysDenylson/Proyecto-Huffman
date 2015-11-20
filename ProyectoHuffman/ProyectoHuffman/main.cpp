#include"TUAD.h"
#include"Lista8.h"
#include"ABB.h"

int main(){
/*
	ABB<char> arbol;
int opcion, frecuencia, res, el, nivel, existe=1;
char elem;
	do
	{
	system("cls");
	cout << "###############################################################################" << endl;
	cout << "#                                                                             #" << endl;
	cout << "#                                 ARBOL BINARIO                               #" << endl;
	cout << "#                                                                             #" << endl;
	cout << "###############################################################################" << endl;
	cout << "[1]  InsertarABB" << endl;
	cout << "[2]  RecorrerINORDER" << endl;
	cout << "[3]  RecorrerPREORDER" << endl;
	cout << "[4]  RecorrerPOSTORDER" << endl;
	cout << "[5]  MostrarNivelABB" << endl;
	cout << "[6]  ContarNodosABB" << endl;
	cout << "[7]  CalcularAlturaABB" << endl;
	cout << "[8]  MenorABB" << endl;
	cout << "[9]  MayorABB" << endl;
	cout << "[10]  EliminarDadoABB" << endl;
	cout << "[11] BuscarABB" << endl;
	cout << "[12] SALIR" << endl;
	cout << "Ingresar opcion: " ;
	cin >> opcion;
	switch (opcion)
	{
		   case 1:
				 cout<<"elemento:";
				 cin>>elem;cout<<endl;
				 cout<<"frecuencia: ";
				 cin>>frecuencia;
				 
				 arbol.insertarABB(arbol.RAIZ,elem,frecuencia);

				 
				 system("pause");
				 system("cls");
				 break;

			case 2:
				 arbol.recorrerIN(arbol.RAIZ);
				 cout<<endl;
				 system("pause");
				 system("cls");
				 break;

			case 3:
				 arbol.recorrerPRE(arbol.RAIZ);
				 cout<<endl;
				 system("pause");
				 system("cls");
				 break;

			case 4:
				 arbol.recorrerPOST(arbol.RAIZ);
				 cout<<endl;
				 system("pause");
				 system("cls");
				 break;

			case 5:
				 cout<<"Nivel:";
				 cin>>nivel;
				 arbol.mostrarNivel(arbol.RAIZ,nivel,1);
				 system("pause");
				 system("cls");
				 break;

			case 6:
				 res=arbol.contarNodosABB(arbol.RAIZ);
				 cout<<res<<endl;
				 system("pause");
				 system("cls");
				 break;

			case 7:
				 res=arbol.calcularAlturaABB(arbol.RAIZ);
				 cout<<res<<endl;
				 system("pause");
				 system("cls");
				 break;

			case 8:
				 res=arbol.menorABB(arbol.RAIZ,&existe);
				 if(existe==0){
				 cout<<"NO"<<endl;
				 }else{
				 cout<<res<<endl;}
				 system("pause");
				 system("cls");
				 break;

			case 9:
				 res=arbol.mayorABB(arbol.RAIZ,&existe);
				 if(existe==0){
				 cout<<"NO"<<endl;
				 }else{
				 cout<<res<<endl;}
				 system("pause");
				 system("cls");
				 break;

			case 10:
			 
				 system("pause");
				 system("cls");
				 break;

			case 11:
				 cout<<"elemento:";
				 cin>>el;
				 res=arbol.buscarABB(arbol.RAIZ,el);
				 cout<<res<<endl;
				 system("pause");
				 system("cls");
				 break;

			case 12:cout<<"Saliendo..."<<endl;
	}	  

}while(opcion <=12 && opcion!=12);
*/
	ListaForma8<char> lf8;
    ABB<char> arbol;
	char el;
	string cod;
	int opcion, res, existe = 0, frecuencia=0;

		do
		{
		system("cls");
		cout << "###############################################################################" << endl;
		cout << "#                                                                             #" << endl;
		cout << "#                                  LISTA FORMA8                               #" << endl;
		cout << "#                                                                             #" << endl;
		cout << "###############################################################################" << endl;
		//cout << "[1]   InsertarPRIN" << endl;
		//cout << "[2]   InsertarFIN" << endl;
		//cout << "[3]   EliminarPRIN" << endl;
		//cout << "[4]   EliminarFIN" << endl;
		cout << "[5]   MOSTRARLISTA" << endl;
		cout << "[6]   INSERTARENSULUGAR" << endl;
		//cout << "[7]   ELIMINARELEMENTODADO" << endl;
		cout << "[8]   cargar_de_TUAD_a_Lista8" << endl;
		cout << "[9]   crearABB" << endl;
		cout << "[10]  SALIR" << endl;
		cout << "[11]  LLENAR TABLA" << endl;
		cout << "Ingresar opcion: " ;
		cin >> opcion;
		switch (opcion)
		{
				 case 1:
					 cout<<"elemento:";
					 cin >> el; cout << endl;
					 cout << "frecuencia:";
					 cin >> frecuencia;
					 res=lf8.insertarPRIN(el,frecuencia);
					 cout<<res<<endl;
					 system("pause");
					 system("cls");
					 break;

				 case 2:
					 cout<<"elemento:";
					 cin >> el; cout << endl;
					 cout << "frecuencia:";
					 cin >> frecuencia;
					 res = lf8.insertarFIN(el, frecuencia);
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
					 lf8.mostrar();
					 system("pause");
					 system("cls");
					 break;

				 case 6:
					/* cout<<"elemento:";
					 cin >> el; cout << endl;
					 cout << "frecuencia:";
					 cin >> frecuencia;*/

					 res=lf8.insertarEnSuLUGAR('E',2);
					 cout<<res<<endl;
					 res=lf8.insertarEnSuLUGAR('D',5);
					 cout<<res<<endl;
					 res=lf8.insertarEnSuLUGAR('C',6);
					 cout<<res<<endl;
					 system("pause");
					 system("cls");
					 break;

				 case 7:
					 cout<<"elemento:";
					 cin>>el;
					 res=lf8.eliminarDADO(el);
					 cout<<res<<endl;
					 system("pause");
					 system("cls");
					 break;

				 case 8:
					 lf8.extraerCarsTUAD();
					 system("pause");
					 system("cls");
					 break; 

				 case 9:
					 cout<<lf8.crear_arbol();
					 cout<<endl;
					 //cod = arbol.crearCodigo(lf8.primer->arbol.RAIZ, 'C', "");
					 cod = lf8.primer->arbol.crearCodigo(lf8.primer->arbol.RAIZ, 'E', "");
					 cout<<cod<<endl;
					 system("pause");
					 system("cls");
					 break;
				 case 10:
					 cout<<"Saliendo..."<<endl;
					 break;
				 case 11:
					 lf8.llenarTabla();

					 system("pause");
					 system("cls");
					 break;
				 default:
					 opcion=10;
		}	  

		}while(opcion!=10);
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