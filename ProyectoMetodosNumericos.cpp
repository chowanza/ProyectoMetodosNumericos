/*PROYECTO DE METODOS NUMERICOS REALIZADO POR CARLOS MARTINEZ Y LUIS CANDIALES
EN LA UNIVERSIDAD GRAN MARISCAL DE AYACUCHO DE GUAYANA. EL OBJETIVO DEL PROYECTO
ES REALIZAR LOS METODOS ITERATIVOS DE BISECCION Y GAUSS SEIDEL. JUNIO DE 2023*/
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <limits>
#include <chrono>
#include <thread>
#include <cmath>
#include "rlutil.h"
#include "logoproyecto.h"
#include <vector>
#include <queue>
#define INF 1<<30
using namespace std; 
//variables globales-------------------------------------------------
int opcio = 1;
int opc=1;
//funciones----------------------------------------------------------
void cargando(){                                                           
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                     
                                                                           
	for (int i = 0; i < 100; i++) {
        gotoxy(2, 5);
        cout << "Cargando: " << i << "%" << endl;
        gotoxy(2, 6);
        for (int j = 0; j <= i; j++) {
            if (j < 20) {
                cout << "\033[1;31m=";
            } else if (j < 40) {
                cout << "\033[1;33m=";
            } else if (j < 60) {
                cout << "\033[1;32m=";
            } else if (j < 80) {
                cout << "\033[1;34m=";
            } else {
                cout << "\033[1;35m=";
            }
        }
        Sleep(20);
        system("cls");
    }
    gotoxy(40, 12);
    cout << "CARGA COMPLETA!" << endl;
    sleep(2);
    system("cls");
}

void completo() {
	system("color 0F");
	dibujarCuadro( 20,8,60,22);
	dibujarCuadro( 18,7,62,23);
	/////////////////////

	dibujarCuadro( 8,5,82,40);
	dibujarCuadro( 10,32,70,34);
	dibujarCuadro( 10,32,70,36);
	//dibujarCuadro( 10,22,70,28);
	dibujarCuadro( 10,32,42,38);
	Gotoxy(12,33);
	cout<<"CREADO POR:";
	Gotoxy(12,35);
	cout<<"CARLOS MARTINEZ CI: 28.375.833";
	Gotoxy(12,37);
	cout<<"LUIS CANDIALES CI 28.671.144";
	Gotoxy(44,33);
	cout<<"PROFESORA:";
	Gotoxy(44,35);
	cout<<"YUMILVA ROJAS";

} 

void showItem(const char* text, int posx,int posy,bool select) {

	if(select) {
		rlutil::setBackgroundColor(rlutil::COLOR::RED);
		rlutil::locate(posx-2,posy);
		cout<<char(175)<<" "<<text<<" "<<char(174)<<endl;
		rlutil::setBackgroundColor(rlutil::COLOR::BLACK);//BLACK
	} else {
		rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
		rlutil::locate(posx-2,posy);
		cout<<"  "<<text<<"  "<<endl;

	}
	rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void GaussSeidel(){
	
	int n;
	cout << endl;
    cout << "Ingrese el tamano del sistema: ";
    while (!(cin >> n))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intentelo de nuevo: ";
    }

    double A[n][n];
    double b[n];
    double x[n];
    int max_iter = 100;
    double tol;
    cout << "Ingrese la tolerancia: ";
    while (!(cin >> tol))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intentelo de nuevo: ";
    }

    cout << "Ingrese la matriz de coeficientes:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            while (!(cin >> A[i][j]))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada invalida. Intentelo de nuevo: ";
            }
        }
    }

    cout << "Ingrese el vector de terminos independientes:" << endl;
    for (int i = 0; i < n; i++)
    {
        while (!(cin >> b[i]))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Intentelo de nuevo: ";
        }
    }

    cout << "Ingrese el vector solucion inicial:" << endl;
    for (int i = 0; i < n; i++)
    {
        while (!(cin >> x[i]))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Intentelo de nuevo: ";
        }
    }

    for (int k = 0; k < max_iter; k++)
    {
        double err = 0;
        for (int i = 0; i < n; i++)
        {
            double s = b[i];
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    s -= A[i][j] * x[j];
                }
            }
            double x_new = s / A[i][i];
            err += pow(x_new - x[i], 2);
            x[i] = x_new;
        }
        if (sqrt(err) < tol)
        {
            break;
        }
        else if (k == max_iter - 1)
        {
            cout << "El metodo no converge despues de " << max_iter << " iteraciones." << endl;
            break;
        }
    }
    cout << "Solucion:" << endl;
    SetConsoleTextAttribute(hConsole, 6);
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    double est_err = 0;
    for (int i = 0; i < n; i++)
    {
        double s = b[i];
        for (int j = 0; j < n; j++)
        {
            s -= A[i][j] * x[j];
        }
        est_err += pow(s, 2);
    }
    est_err = sqrt(est_err);
	
    cout << "Error de estimacion: " << est_err << endl;
	SetConsoleTextAttribute(hConsole, 15);
	
}

void menu() {
	system("color 0F");
	opcio = 1;
	int y=0, i=0;
	int abc=0;

	do {
		system("color 0F");
		gotoxy(22, 4);
		SetConsoleTextAttribute(hConsole, 6);
        cout << "CALCULADORA DE METODO DE BISECCION Y GAUSS SEIDEL" << endl;
		completo();
		rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::hidecursor();
		showItem(" BISECCION  ",30,10,y==0);//35
		showItem(" GAUS SEIDEL",30,11,y==1);//35
		showItem("  SALIR ",30,12,y==2);//35

		switch(rlutil::getkey()) {
			
			case 14: { //arriba
				rlutil::locate(28,10+y);
				cout<<" "<<endl;
				y--;
				if(y<0) {
					y=0;
				}
				break;
			}
			case 15: { //abajo
				rlutil::locate(28,10+y);
				cout<<" "<<endl;//quitar el parapadeo y quitar el cls
				y++;
				if(y>2) {
					y=2;
				}
				break;
			}
			case 1: { //enter
				system("cls");
				switch(y) {
					case 0: {
						system("cls");
		                gotoxy(10, 5);
		                SetConsoleTextAttribute(hConsole, 6);
		                cout << "METODO DE BISECCION" << endl;
		                SetConsoleTextAttribute(hConsole, 15);
		                	system("pause");
							opcio=0;
						system("cls");
		                // Code for option 1
                		break; 
					}
					case 1: {
						system("cls");
		                gotoxy(10, 5);
		                SetConsoleTextAttribute(hConsole, 6);
		                cout << "METODO DE GAUSS SEIDEL" << endl;
		                SetConsoleTextAttribute(hConsole, 15);
		                GaussSeidel();
		                system("pause");
						opcio=0;
		                system("cls");
                		break; 
					}
					case 2: {
						system ("cls");
						cout<<"SALIENDO...";
						exit(0);
				
						break;
					}
				}
			}
		}
	} while(opcio!=0 ); 
	
	getch();
		system("cls");
	if(y!=2) {
		Gotoxy(22,20);
		cout<<"PARA VOLVER AL MENU PRINCIPAL COLOQUE 1 / PARA SALIR COLOQUE 0";
		Gotoxy(22,22);
		cin>>opc;
	}

	system("cls");

} 

void returnMenu() {
	do {
		//completo();
		menu();
	} while(opc!=0);

} 

//main--------------------------------------------------------------
int main () {
	cargando(); 
	returnMenu();
	
} 
