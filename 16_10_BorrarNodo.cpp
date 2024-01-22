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
    Nodo *padre;
};

//Prototipos de Función
void menu();
Nodo *crearNodo(int, Nodo *);
void insertarNodo(Nodo *&, int, Nodo*);
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void eliminar(Nodo *, int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *, Nodo *);
void destruirNodo(Nodo *);
void eliminarTodo(Nodo *);


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
        cout<<"4. Recorrer en PreOrden"<<endl;
        cout<<"5. Recorrer en InOrden"<<endl;
        cout<<"6. Recorrer en postOrden"<<endl;
        cout<<"7. Eliminar un Nodo del arbol"<<endl;
        cout<<"8. Eliminar todo el arbol"<<endl;
        cout<<"0. Salir del programa"<<endl;
        cout<<"Digite su opcion: "; cin>>opc;

        switch (opc){
            case 1:
                cout<<"\n\tDigite un numero: "; cin>>dato;
                insertarNodo(raiz, dato, NULL);
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
            case 5:
                cout<<"\n\tMostrando el recorrido en InOrden: \n\n";
                inOrden(raiz);
                cout<<"\n";
                system("pause");
            break;
            case 6:
                cout<<"\n\tMostrando el recorrido en PostOrden: \n\n";
                postOrden(raiz);
                cout<<"\n";
                system("pause");
            break;
            case 7:
                cout<<"\n\tDigite el numero a eliminar: "; cin>>dato;
                eliminar(raiz, dato);
                cout<<"\n";
                system("pause");
            break;
            case 8:
                cout<<"\n\tEliminando arbol ...\n\n";
                eliminarTodo(raiz);
                raiz = NULL;  // Asignar la raíz a NULL después de eliminar
                cout<<"\n";
                system("pause");
            break;
        }
        system("cls");
    }while(opc != 0);
}

Nodo *crearNodo(int n, Nodo *padre){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> dato = n;
    nuevo_nodo -> izq = NULL;
    nuevo_nodo -> der = NULL;
    nuevo_nodo -> padre = padre;

    return nuevo_nodo;
}

void insertarNodo(Nodo *&raiz, int n, Nodo *padre) {
    if (raiz == NULL) {
        raiz = crearNodo(n, padre);
    } else {
        if (n < raiz->dato) {
            // Insertar a la izquierda
            insertarNodo(raiz->izq, n, raiz);
        } else {
            // Insertar a la derecha
            insertarNodo(raiz->der, n, raiz);
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

void inOrden(Nodo *raiz){
    if(raiz == NULL){
        return;
    }
    else{
        inOrden(raiz -> izq);
        cout<<raiz -> dato <<" - ";
        inOrden(raiz -> der);
    }
}

void postOrden(Nodo *raiz){
    if(raiz == NULL){
        return;
    }
    else{
        postOrden(raiz -> izq);
        postOrden(raiz -> der);
        cout<<raiz -> dato <<" - ";
    }
}

void eliminar(Nodo *raiz, int n){
    if(raiz == NULL){  //Si el árbol está vacío
        return;  //No haces nada
    }
    else if(n < raiz -> dato){  //Si el valor es menor
        eliminar(raiz -> izq, n);  //Buscar por la izq
    }
    else if(n > raiz -> dato){  //Si el valor es mayor
        eliminar(raiz -> der, n);  //Cuevar por la der
    }
    else{  //Si ya encontraste el valor
        eliminarNodo(raiz);  //Eliminar Nodo encontrado
    }
}

//Función para determinar el nodo más izquierdo posible
Nodo *minimo(Nodo *raiz){
    if(raiz == NULL){  //Si el árbol está vacio
        return NULL;  //Retornas NULL
    }
    if(raiz -> izq){  //Si tiene hijo izq
        return minimo(raiz -> izq);  //Buscamos la parte más izquierda posible
    }
    else{  //Si no tiene hijo izquierdo
        return raiz;  //Retornamos el mismo Nodo
    }
}

void eliminarNodo(Nodo *nodoEliminar){
    if(nodoEliminar -> izq && nodoEliminar -> der){  //Si el nodo tiene hijo izq y der
        Nodo *menor = minimo(nodoEliminar -> der);  //Buscamos el manor
        nodoEliminar -> dato = menor -> dato;  //Cambiamos el valor
        eliminarNodo(menor);
    }
    else if(nodoEliminar -> izq){  //Si tiene hijo izquierdo
        reemplazar(nodoEliminar, nodoEliminar -> izq);
        destruirNodo(nodoEliminar);
    }
    else if(nodoEliminar -> der){  //Si tiene hijo derecho
        reemplazar(nodoEliminar, nodoEliminar -> der);
        destruirNodo(nodoEliminar);
    }
    else{  //Un Nodo no tiene hijos
        reemplazar(nodoEliminar, NULL);
        destruirNodo(nodoEliminar);
    }
}

//Función para reemplazar dos nodos
void reemplazar(Nodo *raiz, Nodo *nuevo_Nodo){
    if(raiz -> padre){  //Si el Nodo tiene padre
        //raiz -> padre hay que asignarle su nuevo hijo
        if(raiz -> dato == raiz -> padre -> izq -> dato){  //Eliminar el Nodo izquierdo
            raiz -> padre -> izq = nuevo_Nodo;  //Se cambia de hijo
        }
        else if(raiz -> dato == raiz -> padre -> der -> dato){
            raiz -> padre -> der = nuevo_Nodo;  //Se cambia de hijo
        }
    }
    if(nuevo_Nodo){
        //Procedemos a asignarle su nuevo padre
        nuevo_Nodo -> padre = raiz -> padre;  //Se cambia de padre
    }
}

//Función para destruir Nodo
void destruirNodo(Nodo *nodo){
    nodo -> izq = NULL;
    nodo -> der = NULL;

    delete nodo;
}

// Eliminar un árbol binario utilizando postorden
void eliminarTodo(Nodo *raiz){
    if(raiz == NULL){
        return;
    }
    else{
        eliminarTodo(raiz->izq);
        eliminarTodo(raiz->der);
        delete raiz;
    }
}
