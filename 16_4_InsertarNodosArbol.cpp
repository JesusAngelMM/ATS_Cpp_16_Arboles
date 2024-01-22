//Librerias
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

//Estructura
struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
};

//Prototipos de Función
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void menu();

//Variables globales
Nodo *raiz = NULL;

//Función Principal
int main(){
    menu();
    return 0;
}

//Funciones
void menu(){
    int dato, opc;

    do{
        cout<<".:MENU:."<<endl;
        cout<<"1. Insertar un elemento"<<endl;
        cout<<"0. Salir del programa"<<endl;
        cout<<"Digite su opcion: "; cin>>opc;

        switch (opc){
            case 1:
                cout<<"\n\tDigite un numero: "; cin>>dato;
                insertarNodo(raiz, dato);
                cout<<"\n";
                system("pause");
            break;
        }
        system("cls");
    }while(opc != 0);
}

Nodo *crearNodo(int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> dato = n;
    nuevo_nodo -> izq = NULL;
    nuevo_nodo -> der = NULL;

    return nuevo_nodo;
}

void insertarNodo(Nodo *&raiz, int n){
    if(raiz == NULL){  //El padre está vacío
        Nodo *nuevo_nodo = crearNodo(n);  //raiz = crearNodo(n);
        raiz = nuevo_nodo;
    }
    else{
        if(raiz -> dato < n){
            //Insertar a la izquierda
            insertarNodo(raiz -> izq, n);
        }
        else{
            //Insertar a la derecha
            insertarNodo(raiz -> der, n);
        }
    }
}
