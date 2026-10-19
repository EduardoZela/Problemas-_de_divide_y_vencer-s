#include <iostream>

using namespace std;


long long potencia10(int n) {

    long long resultado = 1;

    for (int i = 0; i < n; i++) {
        resultado *= 10;
    }

    return resultado;
}

void multiplicacion_escolar(long long A, long long B){

    cout<<A*B<<endl;

}

int tamano(long long A){

    //por si el valor ingresado es negativo o cero
    if(A < 0){

        cout<< "el numero tiene q ser positivo y mayor a cero" << endl;  
        exit(EXIT_FAILURE);       
    }

    int contador = 1;

    //bucle para contar los digitos
    while(true){

        A = A / 10 ;

        if( A == 0 ){
            break;
        }

        contador++;
    }
    
    return contador;
}

long long divide(long long A, long long B){

    // divide en dos mitadoes cada uno
    
    cout << "divide(" << A << ", " << B << ")" << endl;

    int size_A = tamano(A);
    int size_B = tamano(B);  

    if( size_A == 1 || size_B == 1 ){
        return A*B;
    }

    long long a = A / (potencia10(size_A/2));
    long long b = A % (potencia10(size_A/2));
    long long c = B / (potencia10(size_B/2));
    long long d = B % (potencia10(size_B/2));

    long long z0 = divide(b,d);                   
    long long z1 = divide((a+b),(c+d));           
    long long z2 = divide(a,c);                 
    
    long long intermedio = z1 - z2 - z0;

    return (z2 * potencia10(size_A) + intermedio * potencia10(size_A/2) + z0);
}

int main(){


    string A = "1234";
    string B = "5678";

    cout << "respuesta: " << divide(1324,5678);
    
    return 0;
}