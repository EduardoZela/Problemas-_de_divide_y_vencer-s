#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


void swap(int &a , int &b)
{
    int tmp=a;
    a=b;
    b=tmp;
}

int Aleatorio(int min , int max)
{
    return min+rand()%(max-min +1);
}

int QuickSelect( vector<int> V, int ini, int final,int k)
{ 
    //caso base
    if(ini==final)
    {
        return V[ini];
    }
    

    int p=Aleatorio(ini, final);
    int i=ini;
    int j=ini;
    //particion
    swap(V[p],V[final]);

    while(j<final)
    {
        if(V[j]< V[final])
        {
            swap(V[j],V[i]);
            i++;
        }
        j++;
    }
    swap(V[i],V[final]);


    //comprobacion
    if(k==i)
    {
        return V[i];
    }else if(k<i)
    {
        return QuickSelect(V,ini,i-1,k);
    }else{
        return QuickSelect(V,i+1,final,k);
    }
}


int main()
{

    srand(time(0));
    int n;
    int k;
    cout<<"Ingresa el tamaño del vector "<<endl;
    cin>> n;
    cout<<"\n Ingrese el k-esimo elemento "<<endl;
    cin>> k;
    vector<int> lista(n);
    cout<<"ingresa LOS elementos del vector"<<endl;
    for(int i=0;i< n;i++)
    {
        cin>> lista[i];
    }
    cout<<"El k-esimo elemento es:"<<QuickSelect(lista,0,n-1,n-k);



    return 0;
}