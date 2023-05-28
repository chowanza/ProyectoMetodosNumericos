#include<iostream>
#include<conio.h>
#ifndef todografico
#define todografico
#include<windows.h>
#include<stdio.h>
#define color SetConsoleTextAttribute
HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE) ;
int Color=0;
using namespace std;
void Gotoxy(int x ,int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hCon,dwPos);
}
void Sercolor(){
	
		//funcion para colocar colores en letras
for(int i=0;i<243;i++){
	color(hConsole,i); cout<<i<<".)"<<char(219)<<endl;

}
}
void dibujarCuadro(int x1,int y1,int x2,int y2){
	int i;
	
    for (i=x1;i<x2;i++){
		Gotoxy(i,y1); cout << "\304"; //linea horizontal superior
		Gotoxy(i,y2); cout << "\304"; //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
		Gotoxy(x1,i); cout <<"\263"; //linea vertical izquierda
		Gotoxy(x2,i); cout <<"\263"; //linea vertical derecha
	}
	
    Gotoxy(x1,y1); cout<< "\332"; 
    Gotoxy(x1,y2); cout<< "\300";
    Gotoxy(x2,y1); cout<< "\277";
    Gotoxy(x2,y2); cout<< "\331";
}

/*
#include <stdlib.h>
#include <windows.h>
#include <iostream>
using namespace std;

//PROTOTIPOS DE LAS FUNCIONES
void dibujarCuadro(int x1,int y1,int x2,int y2);
void gotoxy(int x,int y);
void suma();

//FUNCION PRINCIPAL MAIN
int main(){
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	system("COLOR B0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(30,2); cout << "SUMA DE DOS NUMEROS";
	suma();
	
	gotoxy (2,12); system("pause");
	return 0;
}

//FUNCION SUMA
void suma(){
	int n1,n2,total;
	
	gotoxy (2,6); cout << "Ingrese un numero: ";
	cin >> n1;
	
	gotoxy (2,8); cout << "Ingrese un numero: ";
	cin >> n2;
	
	total = n1+n2;
	gotoxy (2,10); cout << "La suma total es: " << total;
}


//FUNCION GOTOXY
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }

 
//FUNCION QUE DIBUJA EL CUADRO
void dibujarCuadro(int x1,int y1,int x2,int y2){
	int i;
	
    for (i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "\304"; //linea horizontal superior
		gotoxy(i,y2); cout << "\304"; //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); cout <<"\263"; //linea vertical izquierda
		gotoxy(x2,i); cout <<"\263"; //linea vertical derecha
	}
	
    gotoxy(x1,y1); cout<< "\332"; 
    gotoxy(x1,y2); cout<< "\300";
    gotoxy(x2,y1); cout<< "\277";
    gotoxy(x2,y2); cout<< "\331";
}

*/
#endif



	