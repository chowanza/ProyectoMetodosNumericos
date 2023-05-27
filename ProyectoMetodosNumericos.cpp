#include <iostream>
#include <windows.h>
#include <conio.h>
#include <limits>
#include <chrono>
#include <thread>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(int x, int y) {
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void marco(){
		SetConsoleTextAttribute(hConsole, 1);
	    // Draw the top border
	    for (int i = 0; i < 80; i++) {
	        gotoxy(i, 0);
	        std::cout << "*";
	    }
	    // Draw the bottom border
	    for (int i = 0; i < 80; i++) {
	        gotoxy(i, 29);
	        std::cout << "*";
	    }
	    // Draw the left border
	    for (int i = 1; i < 30; i++) {
	        gotoxy(0, i);
	        std::cout << "*";
	    }
	    // Draw the right border
	    for (int i = 1; i < 30; i++) {
	        gotoxy(79, i);
	        std::cout << "*";
	    }
	
}

void menu(){
	for (int i = 0; i < 100; i++) {
        gotoxy(10, 5);
        cout << "Cargando: " << i << "%" << endl;
        gotoxy(10, 6);
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

int main() {
    int choice;
    menu();
    do {
    	marco();
    	gotoxy(15, 4);
        SetConsoleTextAttribute(hConsole, 6);
        cout << "CALCULADORA DE METODO DE BISECCION Y GAUSS SEIDEL" << endl;
        gotoxy(10, 7);
        SetConsoleTextAttribute(hConsole, 15);
        cout << "1. METODO DE BISECCION" << endl;
        gotoxy(10, 8);
        cout << "2. METODO DE GAUSS SEIDEL" << endl;
        gotoxy(10, 9);
        cout << "3. SALIR" << endl;
        gotoxy(10, 11);
        cout << "Ingresa una opcion: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Ingresa un numero." << endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
            continue;
        }
        switch (choice) {
            case 1:
                system("cls");
                gotoxy(10, 5);
                SetConsoleTextAttribute(hConsole, 6);
                cout << "METODO DE BISECCION" << endl;
                SetConsoleTextAttribute(hConsole, 15);
                // Code for option 1
                break;
            case 2:
                system("cls");
                gotoxy(10, 5);
                SetConsoleTextAttribute(hConsole, 6);
                cout << "METODO DE GAUSS SEIDEL" << endl;
                SetConsoleTextAttribute(hConsole, 15);
                // Code for option 2
                break;
            case 3:
                // Code for option 3
                cout << "Nos vemos pronto!"; 
                break;
            default:
                cout << "Opcion Invalida. Intenta de nuevo." << endl;
                break;
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
        system("pause");
    } while (choice != 3);
    return 0;
}
