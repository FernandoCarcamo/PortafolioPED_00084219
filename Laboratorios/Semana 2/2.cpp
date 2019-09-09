#include <iostream>

using namespace std;

double raizcuadrada(double r, double r2, int n) {
    double aux;
    double newn;
    aux = r - r2;
    if (aux<0.0001){
        return r2;
    }
    
    newn = (((n / 5) + 5) / (2));
    return raizcuadrada(r2, newn, n);
}

int main() {
    int n;
    double r;
    double t;
    cout << "Ingrese un numero: ";
    cin>>n;

    r = (((n / 5) + 5) / (2));
    t = raizcuadrada(5, r, n);
    cout<<"La raiz cuadrada de el numero ingresado es: "<< t <<endl;
    
    

    return 0;
}
