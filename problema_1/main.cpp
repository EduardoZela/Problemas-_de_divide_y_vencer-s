#include <iostream>
#include <vector>

using namespace std;

void agregar(int a, int b, int operando, vector<int>& R){

     switch(operando){

        case '+':
            R.push_back(a+b);
            break;
        case '-':
            R.push_back(a-b);
            break;

        case '*':
            R.push_back(a*b);
            break;
    }
}

vector<int> recursiva( vector<int> entrada, int indice_inicio, int indice_final ){

    vector<int> R;

    for(int i = indice_inicio; i < indice_final; i++){

        if( entrada[i] == '+' || entrada[i] == '-' || entrada[i] == '*' ){

            vector<int> A = recursiva(entrada, indice_inicio, i-1);
            vector<int> B = recursiva(entrada, i+1, indice_final);

            for(int j = 0; j < A.size() ; j++){

                for(int k = 0; k < B.size() ; k++){

                    agregar(A[j], B[k], entrada[i], R);
                }
            }
        }        
    }
    if(R.empty()){
        
        R.push_back(entrada[indice_inicio]);      
    }
    return R;
}

void print(vector<int>& V){

    for( int i = 0 ; i < V.size() ; i++ ){

        cout << V[i] <<" ";
    }

    cout<<endl;
}

int main(){

    
    vector<int> entrada={2,'*',3,'-',4,'*',5};

    vector<int> resultado = recursiva( entrada, 0, entrada.size() );

    print(resultado);
        

    return 0;
}