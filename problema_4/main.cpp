//Par de puntos más cercano 
//Dado un conjunto de puntos en el plano, encuentre la distancia euclidiana entre los dos puntos más cercanos. La solución debe ser Θ(n lg n): dividir por la coordenada x, resolver cada mitad y revisar la franja central.


#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double euclidiana(long long x0, long long y0, long long x1, long long y1){

    long long x = x1 - x0;
    long long y = y1 - y0;

    double hipotenusa =  sqrt((y * y)+ (x * x));

    return hipotenusa;
}

void merge_sort(vector<long long>& lista, vector<long long>& temporal, int inicio, int final){

    //casi base
    if( final - inicio <= 1 ){ // cuando estamos en un punto

        return;
    }

    int mitad = (inicio + final ) / 2; 

    // con esto solo trabajo con x
    merge_sort(lista, temporal, inicio  , mitad  );
    merge_sort(lista, temporal, mitad  , final  );

    int i = inicio * 2, j = mitad * 2, k = inicio * 2;

    while (i < mitad * 2 && j < final * 2) {

        if (lista[i] <= lista[j]){

            temporal[k++] = lista[i++];
            temporal[k++] = lista[i++];
        }else {
            // contador += mitad - i;
            temporal[k++] = lista[j++];
            temporal[k++] = lista[j++];
        }
    }

    //la lista de la derecha
    while (i < mitad * 2){ // si la lista izqueirda no esta vacia
        
        temporal[k++] = lista[i++];
        temporal[k++] = lista[i++];
    }

    //la lista de la derecha
    while (j < final * 2){ // si la lista derecha no esta vacia

        temporal[k++] = lista[j++];
        temporal[k++] = lista[j++];
    }

    for (int i = inicio * 2; i < final * 2; i++){

        cout << temporal[i] <<  "  ";
        lista[i] = temporal[i];
    }

    cout<<endl;

    return ;

}


void entrada(){

    int n;
    long long x;
    long long y;

    while (true){

        cout << "Diga el numero de puntos q usted quiere ingresar." << endl;

        cin >> n;

        if( n == 0){ // es el finalizador

            cout << "Acaba de finalizar el programa. " << endl;
            break;
        }

        if ( n == 1){

            cout << "INFINITY" << endl;

        }else{ 
            vector<long long> puntos(2*n); 

            for (int  i = 0; i < n; i++){

                cin >> x;
                cin >> y;

                puntos[i*2] = x;
                puntos[i*2 +1] = y;
            }     

            vector <long long> temporal(puntos.size());
            merge_sort(puntos, temporal,0, n);

            double minimo = euclidiana(puntos[0],puntos[1],puntos[2],puntos[3]);
            
            

            for (int i = 0; i < (n * 2)-3; i = i + 2){
                if( minimo > euclidiana(puntos[i + 2],puntos[i+1+2],puntos[i+2+2],puntos[i+3+2]) ){

                    minimo = euclidiana(puntos[i + 2],puntos[i+1+2],puntos[i+2+2],puntos[i+3+2]);
                }
                
            }

            if(minimo >= 10000){
                cout << "INFINITY" << endl;
            }
            else{
                cout<< minimo << endl;
            }
            
        }        
    }
}

int main(){

    cout.setf(ios::fixed);
    cout.precision(4);

    entrada();

    return 0;
}