#include <iostream>
#include <string>

using namespace std;

// 0   |  1  |  2  |  3  |  4  |   5  |  6  |  7 |   8  |  9
// 48  | 49  | 50  | 51  | 52  |  53  | 54  | 55 |  56  | 57

string potencia10(int n) {

    string base = "";

    for(int i = 0 ; i < n ; i++){

        base = base + '0';
    }

    return base;
}

string multiplicacion_un_digito(string a, string b){

    if( a == "0" || b == "0" ){
        
        return "0";
    }


    int A = a[0] - '0';
    int B = b[0] - '0';

    int producto = A * B;

    string respuesta = "";

    //si es un solo digito
    if( (producto / 10) == 0){

        char digito = producto + '0';
        respuesta = respuesta + digito;
    }else{
    //si son dos digitos

        int decena = producto / 10;
        int unidad = producto % 10;

        char digito = decena + '0';

        respuesta = respuesta + digito;

        digito = unidad + '0'; 

        respuesta = respuesta + digito;

    }   

    cout << a << " * " << b << " : " << respuesta <<endl;

    return respuesta;
}

void rellenar_con_0(string &a, string &b){

    //si no tienen la misma cantidad de digitos
    if( a.size() < b.size()) {

        int diferencia = b.size() - a.size();
        string ceros = "";
        for (int i = 0; i < diferencia; i++){
            
            ceros = ceros + "0";
        }
        a = ceros + a;
        
    }else if( a.size() > b.size() ){

        int diferencia = a.size() - b.size();
        string ceros = "";
        for (int i = 0; i < diferencia; i++){
            
            ceros = ceros + "0";
        }
        b = ceros + b;
       
    }else{
        cout<< a << " y " << b << " tienen los mismo digitos"<<endl;
    }
    
}

string quitar_ceros(string numero){

    if( numero[0] == '0' && numero.size() != 1){
        
        int contador = 0;

        for(int i = 0; i < numero.size() - 1; i++){

            if(numero[i] != '0'){
                break;
            }

            contador = contador +1;
        }
        //elimina el primer caracter q en este caso seria 0
        numero = numero.erase(0, contador);
    }

    return numero;
}

string suma( string a,  string b){

    
    rellenar_con_0(a,b);

    string respuesta = "";

    int  contador = 0; 

    //para recorrer el string desde la unidad hasta la centena por ejemplo
    for (int i = a.size() - 1; i >= 0 ; i--){
        
        int A = a[i] - '0';
        int B = b[i] - '0';

        int suma = A + B + contador;
        contador = 0;

        //si la suma es una unindad
        if(suma/10 == 0 ){

            char digito = suma + '0';
            respuesta = digito + respuesta ;

        }else{ //si la suma es decena

            contador = suma / 10;
            char digito = (suma % 10) + '0';
            respuesta = digito + respuesta ;
        }
    }

    //si todavia llevamos algo pero ya acabamos de recorrer el numero
    if(contador != 0){

        char digito = contador + '0';
        respuesta = digito + respuesta;
    }

    return respuesta;
}

string resta(string a, string b){
    
    //rellenamos todo con 0
    rellenar_con_0(a,b);

    int contador = 0;
    string respuesta = "";

    for (int i = a.size() - 1; i >= 0; i--){
        
        int A = a[i] - '0';
        int B = b[i] - '0';

        int resta  = 0;

        resta = A - B - contador;

        if(resta < 0){ // si es negativo

            resta   += 10;
            contador = 1;
        }else{

            contador = 0;
        }

        char digito =  resta + '0';
        respuesta = digito + respuesta;
    }
    
    
    respuesta = quitar_ceros(respuesta);
    

    return respuesta;
}

string  Karatsuba(string A, string  B){

    // divide en dos mitadoes cada uno
    
    cout << "divide( " << A << ", " << B << ")" << endl;


    rellenar_con_0(A,B);

    int size_A = A.size();
    int size_B = B.size();  


    // CASO BASE
    if( size_A == 1 || size_B == 1 ){
        return multiplicacion_un_digito( A,B );
    }
    

    //el substr(pocision, cantidad) lo que hace es extraer una subcadena del string con dos valores, la pocision donde inicie a extraer y la cantidad de char´s q extraera, 

    //lo q hacemos es a / b
    string  a = A.substr(0, A.size() - A.size()/2);  
    // lo q hacemos es a % b
    string  b = A.substr(A.size() - A.size()/2 , A.size()/2); 
    string  c = B.substr(0, B.size() - B.size()/2);  
    string  d = B.substr(B.size() - B.size()/2 , B.size()/2);

    string  z0 = Karatsuba(b,d);                   
    string  z1 = Karatsuba(suma(a,b),suma(c,d));           
    string  z2 = Karatsuba(a,c);                 
    
    string  intermedio = resta ( z1 , suma(z2, z0)) ;

    

    //  return ( ( z2 * 10 º (size_A) ) + ( intermedio * ( 10 º(size_A/2) ) ) + z0);
    return   quitar_ceros( suma (( z2 + potencia10(2* (size_A/2)) )  , suma ( intermedio + potencia10(size_A/2) , z0 ) )  );
    
}

int main(){


    string A = "12";
    string B = "3";

    string respuesta  = Karatsuba(A,B); 
    cout << respuesta <<endl;
    return 0;
}