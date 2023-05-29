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
#include <iomanip>
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
//animacion de cargar
void cargando(){                                                           
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                     
                                                                           
	for (int i = 0; i < 100; i++) {
        gotoxy(1, 5);
        cout << "Cargando: " << i << "%" << endl;
        gotoxy(1, 6);
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
//creacion del menu
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
	cout<<"LUIS CANDIALES CI: 28.671.144";
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
//imprime los puntos del metodo de biseccion
void imprimePuntos(double (*f)(double), double a, double b, int max_iter) {
   int puntos = max_iter + 1;
   
   double ancho = (b - a) / max_iter;
   
   cout << "\n";
   SetConsoleTextAttribute(hConsole, 6);
   cout << "\tx\tf(x)\n" << endl;
   SetConsoleTextAttribute(hConsole, 15);
   for (int i = 0; i < puntos; i++) {
      cout << "\t" << a << "\t" << f(a) << endl;
      a = a + ancho;
   }
}
//calcula el metodo de biseccion
double biseccion(double (*f)(double), double a, double b, double tol, int max_iter) {
    if (f(a) * f(b) >= 0) {
        cout << "El método de bisección puede fallar." << endl;
        return NAN;
    }
    double a_n = a;
    double b_n = b;
    SetConsoleTextAttribute(hConsole, 6);
    cout << setw(10) << "Iteracion" << setw(10) << "a" << setw(10) << "b" << setw(10) << "m" << setw(10) << "f(m)" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    for (int n = 1; n < max_iter; n++) {
        double m_n = (a_n + b_n) / 2;
        double f_m_n = f(m_n);
        cout << setw(10) << n << setw(10) << a_n << setw(10) << b_n << setw(10) << m_n << setw(10) << f_m_n << endl;
        if (f(a_n) * f_m_n < 0) {
            a_n = a_n;
            b_n = m_n;
        } else if (f(b_n) * f_m_n < 0) {
            a_n = m_n;
            b_n = b_n;
        } else if (f_m_n == 0) {
            cout << "Se encontro una solución exacta." << endl;
            return m_n;
        } else {
            cout << "El metodo de bisección fallo." << endl;
            return NAN;
        }
        if (abs(b_n - a_n) <= tol) {
            return m_n;
        }
    }
    return 0;
}
//invoca el procedimiento a ejecutar el metodo de biseccion
void Biseccion() {
	double a, b, tol;
    int max_iter;

    cout << "Ingrese el valor de a: ";
    while (!(cin >> a)) {
        cout << "Entrada invalida. Ingrese el valor de a: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese el valor de b: ";
    while (!(cin >> b)) {
        cout << "Entrada invalida. Ingrese el valor de b: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese el valor de tol: ";
    while (!(cin >> tol)) {
        cout << "Entrada invalida. Ingrese el valor de tol: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese el valor de max_iter: ";
    while (!(cin >> max_iter)) {
        cout << "Entrada invalida. Ingrese el valor de max_iter: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<double (*)(double)> funciones = {
        [](double x) { return x * x - 2; },
        [](double x) { return sin(x); },
        [](double x) { return cos(x); },
        [](double x) { return exp(x); },
        [](double x) { return exp(-1 * x) - cos(3 * x) - 0.5; },
        [](double x) { return pow(x,3) - pow(x,2) - (3 * x) - 3; },
        [](double x) { return exp(3 * x) - 4; }
    };

    int opcion_funcion;

    cout << "Elija una funcion:" << endl;
    cout << "1. f(x) = x^2 - 2" << endl;
    cout << "2. f(x) = sin(x)"<<endl;
    cout<<  "3. f(x)= cos(x)"<<endl;
    cout<<  "4. f(x)= exp(x)"<<endl;
    cout << "5. f(x)= (1/e^x) - cos(3x) - (1/2)"<<endl;
    cout << "6. f(x)= x^3 - x^2 - 3x - 3"<<endl;
    cout << "7. f(x)= e^3x - 4"<<endl;
	cout << "Ingrese una opcion--->";
    while (!(cin >> opcion_funcion)) {
      cout<<"Entrada invalida. Elija una funcion:"<<endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }

    auto f=funciones[opcion_funcion-1];
	
	imprimePuntos(f,a,b,max_iter);
	
    double raiz=biseccion(f,a,b,tol,max_iter);
	SetConsoleTextAttribute(hConsole, 6);
    cout<<"La raiz aproximada es:"<<raiz<<endl;
    SetConsoleTextAttribute(hConsole, 15);
}
//transforma una matriz a matriz diagonalmente dominante
bool hacer_matriz_dominante(vector<vector<double>>& matriz, vector<double>& b) {
    int n = matriz.size();
    for (int i = 0; i < n; i++) {
        double max_valor = 0;
        int max_fila = i;
        for (int j = i; j < n; j++) {
            double suma = 0;
            for (int k = 0; k < n; k++) {
                if (k != i) {
                    suma += abs(matriz[j][k]);
                }
            }
            if (abs(matriz[j][i]) > suma && abs(matriz[j][i]) > max_valor) {
                max_valor = abs(matriz[j][i]);
                max_fila = j;
            }
        }
        if (max_valor == 0) {
            return false;
        }
        swap(matriz[i], matriz[max_fila]);
        swap(b[i], b[max_fila]);
    }
    return true;
}

//metodo de gauss seidel
void GaussSeidel(){
	
	int n;
    cout << "Ingrese el tamanio del sistema: ";
    while (!(cin >> n))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intentelo de nuevo: ";
    }

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        	cout << "-->:";
            while (!(cin >> A[i][j])) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada invalida. Intentelo de nuevo: ";
            }
        }
    }

    cout << "Ingrese el vector de terminos independientes:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "-->:";
        while (!(cin >> b[i])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Intentelo de nuevo: ";
        }
    }
    
    if (hacer_matriz_dominante(A, b)) {
        cout << "La matriz se hizo diagonalmente dominante:" << endl;
        for (auto fila : A) {
            for (auto elemento : fila) {
                cout << elemento << " ";
            }
            cout << endl;
        }
        cout << "El vector b se ajustó en consecuencia:" << endl;
        for (auto elemento : b) {
            cout << elemento << " ";
        }
        cout << endl;
    } else {
        cout << "No se pudo hacer la matriz diagonalmente dominante." << endl;
    }

    cout << "Ingrese el vector solucion inicial:" << endl;
    for (int i = 0; i < n; i++)
    {
    	cout << "-->:";
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
        cout << "Iteracion " << k + 1 << ":" << endl;
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
            cout << "x[" << i << "] = " << x[i] << endl;
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

//menu
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
		                Biseccion();
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


//invoca el menu
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
