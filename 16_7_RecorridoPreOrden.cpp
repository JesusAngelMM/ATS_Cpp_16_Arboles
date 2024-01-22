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
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int);
void preOrden(Nodo *);


//Variables globales
Nodo *raiz = NULL;

//Función Principal
int main(){
    menu();
    return 0;
}

//Funciones
void menu(){
    int dato, opc, contador = 0;

    do{
        cout<<".:MENU:."<<endl;
        cout<<"1. Insertar un elemento"<<endl;
        cout<<"2. Mostrar el arbol completo"<<endl;
        cout<<"3. Buscar un elemento"<<endl;
        cout<<"4. Recorrer en Pre Orden"<<endl;
        cout<<"0. Salir del programa"<<endl;
        cout<<"Digite su opcion: "; cin>>opc;

        switch (opc){
            case 1:
                cout<<"\n\tDigite un numero: "; cin>>dato;
                insertarNodo(raiz, dato);
                cout<<"\n";
                system("pause");
            break;
            case 2:
                cout<<"\n\tMostrando el arbol completo: \n\n";
                mostrarArbol(raiz, contador);
                cout<<"\n";
                system("pause");
            break;
            case 3:
                cout<<"\n\tDigite un numero: "; cin>>dato;
                if(busqueda(raiz, dato)){
                    cout<<"\n\t\tElemento "<<dato<<" SI encontrado"<<endl;
                }
                else{
                    cout<<"\n\t\tElemento "<<dato<<" NO encontrado"<<endl;
                }
                cout<<"\n";
                system("pause");
            break;
            case 4:
                cout<<"\n\tMostrando el recorrido en PreOrden: \n\n";
                preOrden(raiz);
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

void insertarNodo(Nodo *&raiz, int n) {
    if (raiz == NULL) {
        raiz = crearNodo(n);
    } else {
        if (n < raiz->dato) {
            // Insertar a la izquierda
            insertarNodo(raiz->izq, n);
        } else {
            // Insertar a la derecha
            insertarNodo(raiz->der, n);
        }
    }
}

void mostrarArbol(Nodo *raiz, int cont){
    if(raiz == NULL){
        return;
    }
    else{
        mostrarArbol(raiz -> der, cont + 1);
            for(int i = 0; i < cont; i++){
                cout<<"   ";
            }
        cout<<raiz -> dato<<endl;
        mostrarArbol(raiz ->izq, cont + 1);
    }
}

bool busqueda(Nodo *raiz, int n){
    if(raiz == NULL){
        return false;
    }
    else if(raiz -> dato == n){
        return true;
    }
    else if(n < raiz -> dato){
        return busqueda(raiz -> izq, n);
    }
    else{
        return busqueda(raiz -> der, n);
    }
}

void preOrden(Nodo *raiz){
    if(raiz == NULL){
        return;
    }
    else{
        cout<<raiz -> dato <<" - ";
        preOrden(raiz -> izq);
        preOrden(raiz -> der);
    }
}