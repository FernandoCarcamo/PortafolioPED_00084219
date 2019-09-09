#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;


int main (){
    int a, suma = 0;
    cout<<"Ingrese un numero: ";
    cin>>a;
    
    for(int i = a; i!=0; i--){
        
        suma += i;
        
    
    }
    cout<<suma<<endl;
    return 0;
}
