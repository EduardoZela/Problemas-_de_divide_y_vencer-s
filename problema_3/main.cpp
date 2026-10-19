#include <iostream>
#include <vector>

using namespace std;


void mergeSort(vector<int>& lista, vector<int>& tmp, int inicio, int final, int &contador) {

    //caso base
    if (final - inicio <= 1) {
        cout<< "llego a caso base"<<endl;
        return ;
    }
    //halla la mitad
    int mitad = (inicio + final) / 2;

    //parte la lista de manera recursiva
    mergeSort(lista, tmp, inicio, mitad, contador); // lista izquierda
    mergeSort(lista, tmp, mitad , final, contador); // lista derecha


    int i = inicio, j = mitad, k = inicio;

    while (i < mitad && j < final) {

        if (lista[i] <= lista[j]){

            tmp[k++] = lista[i++];
        }else {
            contador += mitad - i;
            tmp[k++] = lista[j++];
        }
    }

    //cuando hay una lista vacia y falta llenar la otra
    //la lista de la izquierda
    while (i < mitad){
        
        tmp[k++] = lista[i++];
    }

    //la lista de la derecha
    while (j < final){ 

        tmp[k++] = lista[j++];
    }

    for (int x = inicio; x < final; x++){
        cout<<tmp[x]<< "  ";
        lista[x] = tmp[x];
    }
    cout<<endl;
    return ;
}

void entrada(){

    int n;


    while(true){

        cout << "Inserta el tamaño del arreglo."<<endl;

        cin>>n;

        if(n == 0){

            cout << endl << "------------------------" << endl;
            cout << "El programa termino." << endl;
            cout << endl << "------------------------" << endl;

            break;
        }

        vector<int> lista;
        
        cout << "A continuacion inserta los valores del vector uno por uno. " << endl;

        for(int i = 0; i < n; i++){

            int valor;
            cin >> valor;

            lista.push_back(valor);
        }

        cout << endl << "------------------------" << endl;

        int contador = 0;
        vector<int> tmp(lista.size());
        mergeSort( lista , tmp , 0 , lista.size() , contador);

        cout << endl << "la cantidad de rotaciones son : " << contador << endl;
        
        cout << endl << "------------------------" << endl;
    }
}

int main(){

    entrada();

    return 0;
}