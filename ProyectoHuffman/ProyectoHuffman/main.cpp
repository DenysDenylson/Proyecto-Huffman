#include"TUAD.h"



int main(){

	TUAD tuad;
	int opcion;
	
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

				case 3:cout<<"Saliendo..."<<endl;
		}	  

	}while(opcion <=3 && opcion!=3);

	system("pause");
	system("cls");
	return 0;
}